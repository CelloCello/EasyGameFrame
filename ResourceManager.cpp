#include ".\resourcemanager.h"
#include "GameManager.h"
#include "GLog.h"

ResourceManager::ResourceManager(void):m_TextureFactory(10),m_ObjFactory(100)
{
}

ResourceManager::~ResourceManager(void)
{
	Fini();
}
//--------------------------------------------------------------------------------------------------
//讀檔
void ResourceManager::Load(const char* FileName)
{
	//先隨便讀一些東西吧~
	HGE* hge_ = GameManager::m_Hge;
	HTEXTURE tex_ = hge_->Texture_Load("data\\image\\testimg.png");
	TextureUnit* tu_ = m_TextureFactory.GetOne();
	if ( tu_ )
	{
		tu_->m_TexID = tex_;
		m_TextureMap.insert( TEX_VAL(1001,tu_) );

		GameObject* BaseObj_ = new GameObject();
		BaseObj_->m_Anim = new hgeAnimation(tex_,3,3,0,0,80,64);
		BaseObj_->m_KindID = 1001;
		m_BaseObjMap[1001] = BaseObj_;
	}
}
//--------------------------------------------------------------------------------------------------
TextureUnit* ResourceManager::GetTexture(int ID)
{
	TEX_MAP::iterator iter_ = m_TextureMap.find(ID);
	if ( iter_ != m_TextureMap.end() )
	{
		return iter_->second;
	}

	return NULL;
}
//--------------------------------------------------------------------------------------------------
//產生新的物件
GameObject* ResourceManager::CreateGameObj(int ID)
{
	OBJ_MAP::iterator iter_ = m_BaseObjMap.find(ID);
	if ( iter_ != m_BaseObjMap.end() )
	{
		GameObject* NewObj_ = m_ObjFactory.GetOne();
		if ( !NewObj_ )
		{
			GLog::Print("[!] CreateGameObj生不出東西!<ID:%d>",ID);
			return NULL;
		}

		iter_->second->CloneTo(NewObj_);
		return NewObj_;
	}

	return NULL;
}
//--------------------------------------------------------------------------------------------------
bool ResourceManager::DestoryGameObj(GameObject* Obj)
{
	Obj->Fini();
	return m_ObjFactory.FreeOne(Obj);
}
//--------------------------------------------------------------------------------------------------
//結束,Singleton解構時會呼
void ResourceManager::Fini()
{
	//結束,Singleton解構時會呼
	GameObject* BaseObj_ = NULL;
	OBJ_MAP::iterator iter_;
	for ( iter_=m_BaseObjMap.begin() ; iter_!=m_BaseObjMap.end() ; iter_++ )
	{
		BaseObj_ = iter_->second;
		BaseObj_->Fini();
		delete BaseObj_;
	}
}
//--------------------------------------------------------------------------------------------------