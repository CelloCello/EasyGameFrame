#include ".\loginstage.h"
#include "hgegui.h"
#include "hgefont.h"
#include "menuitem.h"
#include "StageManager.h"
#include "GameDefine.h"
#include "MemDef.h"

LoginStage::LoginStage(void):m_StartMenu(NULL), m_StartMenuFont(NULL)
{
}

LoginStage::~LoginStage(void)
{

}
//--------------------------------------------------------------------------------------------------
void LoginStage::Init()
{
	//選單字型
	m_StartMenuFont = new hgeFont("data\\font\\font1.fnt");
	//選單音效
	m_SelectSound = m_Hge->Effect_Load("data\\sound\\menu.wav");

	//選單
	m_StartMenu = new hgeGUI();
	m_StartMenu->AddCtrl(new hgeGUIMenuItem(1,m_StartMenuFont,m_SelectSound,400,200,0.0f,"Play"));
	m_StartMenu->AddCtrl(new hgeGUIMenuItem(2,m_StartMenuFont,m_SelectSound,400,240,0.1f,"Options"));
	m_StartMenu->AddCtrl(new hgeGUIMenuItem(3,m_StartMenuFont,m_SelectSound,400,360,0.2f,"Exit"));

	m_StartMenu->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	//m_StartMenu->SetCursor(spr);
	m_StartMenu->SetFocus(1);
	m_StartMenu->Enter();

}
//--------------------------------------------------------------------------------------------------
void LoginStage::Fini()
{
	SAFE_DELETE(m_StartMenu);
	SAFE_DELETE(m_StartMenuFont);
	//m_Hge->Effect_Free(m_SelectSound);
}
//--------------------------------------------------------------------------------------------------
bool LoginStage::FrameUpdate(float dt)
{
	static int lastid=0;

	// If ESCAPE was pressed, tell the GUI to finish
	if ( m_Hge->Input_GetKeyState(HGEK_ESCAPE) )
	{
		lastid=3;
		m_StartMenu->Leave();
	}

	// We update the GUI and take an action if
	// one of the menu items was selected
	int id = m_StartMenu->Update(dt);
	
	if(id == -1)
	{
		switch(lastid)
		{
		case 1:
			StageManager::GetInstance()->ChangeStage(GS_GAME);
			break;
		case 2:
			m_StartMenu->SetFocus(1);
			m_StartMenu->Enter();
			break;

		case 3: 
			return true;
			break;
		}
	}
	else if(id)
	{
		lastid = id;
		m_StartMenu->Leave(); 
	}


	return false;
}
//--------------------------------------------------------------------------------------------------
void LoginStage::RenderUpdate()
{
	m_StartMenu->Render();
	m_StartMenuFont->SetColor(0xFFFFFFFF);
	m_StartMenuFont->printf(5, 5, HGETEXT_LEFT, "dt:%.3f\nFPS:%d", m_Hge->Timer_GetDelta(), m_Hge->Timer_GetFPS());
}
//--------------------------------------------------------------------------------------------------