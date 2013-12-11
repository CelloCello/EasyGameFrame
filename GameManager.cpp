#include ".\gamemanager.h"
#include "GLog.h"
#include "ResourceManager.h"
#include "StageManager.h"
#include "GameDefine.h"

HGE* GameManager::m_Hge = NULL;
StageManager* GameManager::m_StageMgr = NULL;


GameManager::GameManager(void)
{
	m_Hge = NULL;
}

GameManager::~GameManager(void)
{
	Fini();
}
//--------------------------------------------------------------------------------------------------
//��l
bool GameManager::Init()
{
	m_Hge = hgeCreate(HGE_VERSION);
	if ( !m_Hge )
		return false;

	//HGE��l
	m_Hge->System_SetState(HGE_SCREENWIDTH, 800);
	m_Hge->System_SetState(HGE_SCREENHEIGHT,600);
	m_Hge->System_SetState(HGE_FRAMEFUNC, GameManager::FrameFunc);
	m_Hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	m_Hge->System_SetState(HGE_WINDOWED, true);
	m_Hge->System_SetState(HGE_USESOUND, false);
	m_Hge->System_SetState(HGE_FPS, 60);
	m_Hge->System_SetState(HGE_LOGFILE, "log.txt");
	m_Hge->System_SetState(HGE_TITLE,"GameDemo - Test v0.1a");

	return true;
}
//--------------------------------------------------------------------------------------------------
//����
void GameManager::Fini()
{
	if ( m_Hge )
	{
		//����
		m_Hge->System_Shutdown();
		m_Hge->Release();
		m_Hge = NULL;
	}
}
//--------------------------------------------------------------------------------------------------
//�Ұ�
bool GameManager::Run()
{
	//�t�Ϊ�l
	if ( !m_Hge->System_Initiate() )
		return false;

	GLog::Print("GameDemo Really Start!!!!!!");

	//�Ѽƪ�l(Resource�o�bSystem_Initiate����~Ū����F��)
	m_LoginStage.SetHGE(m_Hge);
	m_GameStage.SetHGE(m_Hge);
	m_StageMgr = StageManager::GetInstance();
	m_StageMgr->SetStageNum(GS_MAX);
	m_StageMgr->Add(GS_LOGIN,&m_LoginStage);
	m_StageMgr->Add(GS_GAME,&m_GameStage);
	m_StageMgr->ChangeStage(GS_LOGIN);


	//�t�ΥD�j��(�z�פW�|�d�b�o�̭��]�j��)
	m_Hge->System_Start();

	m_StageMgr->Fini();
	Fini();
	return true;
}
//--------------------------------------------------------------------------------------------------
bool GameManager::FrameFunc()
{
	// Get the time elapsed since last call of FrameFunc().
	// This will help us to synchronize on different
	// machines and video modes.
	float dt_ = m_Hge->Timer_GetDelta();

	StageUnit* CurrStage_ = m_StageMgr->GetCurrStage();
	return CurrStage_->FrameUpdate(dt_);

	


	// Continue execution
	// return true�N���|��RenderFunc
	//return false;
}
//--------------------------------------------------------------------------------------------------
//ø�ϰj��
bool GameManager::RenderFunc()
{
	// Begin rendering quads.
	// This function must be called
	// before any actual rendering.
	m_Hge->Gfx_BeginScene();

	// Clear screen with black color
	//m_Hge->Gfx_Clear(ARGB(1,0,255,0));
	m_Hge->Gfx_Clear(128);

	StageUnit* CurrStage_ = m_StageMgr->GetCurrStage();
	CurrStage_->RenderUpdate();
	

	
	// End rendering and update the screen
	m_Hge->Gfx_EndScene();

	// RenderFunc should always return false
	return false;
}
//--------------------------------------------------------------------------------------------------