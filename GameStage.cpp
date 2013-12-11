#include ".\gamestage.h"
#include <time.h>
#include "GameManager.h"
#include "MemDef.h"

GameStage::GameStage(void):Ami(NULL)
{
	for ( int i=0 ; i<20 ; ++i )
		fall[i] = NULL;
}

GameStage::~GameStage(void)
{

}
//--------------------------------------------------------------------------------------------------
void GameStage::Init()
{
	//ResourceManager::GetInstance()->Load("aaa");
	//TextureUnit* tu_ = ResourceManager::GetInstance()->GetTexture(1001);
	////HTEXTURE tex1 = m_Hge->Texture_Load("data\\image\\testimg.png");
	//Ami = new hgeAnimation(tu_->m_TexID,3,3,0,0,80,64);
	//Ami->SetMode(HGEANIM_LOOP);
	//Ami->SetColor(0xFFFFFFFF);
	//Ami->Play();

	ResourceManager::GetInstance()->Load("aaa");
	PlrObj = ResourceManager::GetInstance()->CreateGameObj(1001);
	PlrObj->m_Anim->SetMode(HGEANIM_LOOP);
	PlrObj->m_Anim->SetColor(0xFFFFFFFF);
	PlrObj->m_Anim->Play();
	
	m_Hge = GameManager::m_Hge;
	HTEXTURE tex1 = m_Hge->Texture_Load("data\\image\\testimg.png");
	Ami = new hgeAnimation(tex1,3,3,0,0,80,64);
	Ami->SetMode(HGEANIM_LOOP);
	Ami->SetColor(0xFFFFFFFF);
	Ami->Play();

	int posArr[12] = {10,50,100,150,200,250,300,350,400,450,500,550};
	HTEXTURE tex = m_Hge->Texture_Load("data\\image\\particles.png");
	srand ( time(NULL) );
	for ( int i=0 ; i<20 ; ++i )
	{
		fall[i] = new hgeSprite(tex,96.0,64.0,32,32);
		fall[i]->SetBlendMode(BLEND_ALPHAADD | BLEND_COLORMUL | BLEND_ZWRITE);
		fall[i]->SetZ(0.5f);			// Set up z-coordinate of vertices
		//fall[i]->SetColor(0xFFFFA000);	// Set up color. The format of DWORD col is 0xAARRGGBB
		fPosX[i] = posArr[ rand()%12 ];
		fPosY[i] = 0;
		list.push_back(i);
	}

	
	
	PosX=0, PosY=500;

	HTEXTURE bk = m_Hge->Texture_Load("data\\image\\background.png");
	background = new hgeSprite(bk,0,0,800,600);
	//background->SetBlendMode(BLEND_ALPHAADD | BLEND_COLORMUL | BLEND_ZWRITE);
}
//--------------------------------------------------------------------------------------------------
void GameStage::Fini()
{
	SAFE_DELETE(Ami);
	SAFE_DELETE(background);
	for ( int i=0 ; i<20 ; ++i )
		SAFE_DELETE(fall[i]);
}
//--------------------------------------------------------------------------------------------------
bool GameStage::FrameUpdate(float dt)
{
	// Process keys
	static float MoveGap_ = 12;
	if (m_Hge->Input_GetKeyState(HGEK_ESCAPE)) return true;
	if ( m_Hge->Input_GetKeyState(HGEK_LEFT) )
		PosX -= MoveGap_;
	if ( m_Hge->Input_GetKeyState(HGEK_RIGHT) )
		PosX += MoveGap_;

	if(PosX>730)
		PosX=730-(PosX-730);
	if(PosX<16)
		PosX=16+16-PosX; 

	PlrObj->m_Anim->Update(dt);
	Ami->Update(dt);

	return false;
}
//--------------------------------------------------------------------------------------------------
void GameStage::RenderUpdate()
{
	//每三秒掉一個
	static vector<int> tempList_;
	static DWORD start_ = ::GetTickCount();
	if ( (::GetTickCount() - start_) > 1000 )
	{
		if ( list.empty() )
		{
			tempList_.clear();
			for ( int i=0 ; i<20 ; ++i )	
			{
				fPosY[i] = 0;
				list.push_back(i);
			}
		}

		tempList_.push_back( list.back() );
		list.pop_back();
		start_ = ::GetTickCount();
	}

	background->Render(0,0);
	PlrObj->m_Anim->Render(PosY,PosX);
	Ami->Render(PosX,PosY);
	for ( int i=0 ; i<tempList_.size() ; ++i )
	{
		int pos_ = tempList_[i];
		fPosY[pos_] += 5;
		fall[pos_]->Render(fPosX[pos_],fPosY[pos_]);
	}
}
//--------------------------------------------------------------------------------------------------
