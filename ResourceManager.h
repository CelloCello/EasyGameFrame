#pragma once
#include "hge.h"
#include "ASingleton.h"
#include "ObjectFactory.h"
#include "GameObject.h"
#include <map>
using namespace std;

/*
 *	管理載入的texture...等的資料
 */

class TextureUnit;

class ResourceManager : public ASingleton<ResourceManager>
{
public:
	ResourceManager(void);
	virtual ~ResourceManager(void);

	void Init(){}
	void Fini();		//結束,Singleton解構時會呼

	void	Load(const char* FileName);			//讀檔
	TextureUnit*	GetTexture(int ID);
	GameObject*		CreateGameObj(int ID);				//產生新的物件
	bool			DestoryGameObj(GameObject* Obj);	//消滅物件

private:
	typedef map<int,TextureUnit*>		TEX_MAP;	//編號,貼圖
	typedef TEX_MAP::value_type			TEX_VAL;
	typedef map<int,GameObject*>		OBJ_MAP;	//編號,物件
	typedef OBJ_MAP::value_type			OBJ_VAL;

	ObjectFactory<TextureUnit>			m_TextureFactory;
	TEX_MAP								m_TextureMap;

	OBJ_MAP								m_BaseObjMap;	//基礎物件表,用來產生新的GameObject
	ObjectFactory<GameObject>			m_ObjFactory;	//遊戲物件工廠,用來限定總數
};


/*
 *	HGE texture的資料
 */
class TextureUnit
{
public:
	TextureUnit(){}
	~TextureUnit(){}

	HTEXTURE m_TexID;
};