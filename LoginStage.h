#pragma once
#include "StageUnit.h"

/*
 *	登入畫面階段物件
 */

class hgeGUI;
class hgeFont;

class LoginStage : public StageUnit
{
public:
	LoginStage(void);
	~LoginStage(void);

	virtual void	Init();
	virtual void	Fini();
	virtual bool	FrameUpdate(float dt);
	virtual void	RenderUpdate();

private:
	hgeGUI*			m_StartMenu;		//開始的選單
	hgeFont*		m_StartMenuFont;	//開始選單的字型
	HEFFECT			m_SelectSound;		//選擇時的音效
};
