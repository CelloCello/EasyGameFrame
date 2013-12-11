#pragma once
#include "hge.h"
#include "GameStage.h"
#include "LoginStage.h"

/*
 *	遊戲管理器, 整個專案的起始與結束都由此
 */

class StageManager;



class GameManager
{
public:
	GameManager(void);
	~GameManager(void);

	bool			Init();					//初始
	void			Fini();					//結束
	bool			Run();					//啟動
	static bool		FrameFunc();			//
	static bool		RenderFunc();			//繪圖迴圈

public:
	static HGE* m_Hge;

private:
	static StageManager*	m_StageMgr;

public:
	//stages
	LoginStage				m_LoginStage;
	GameStage				m_GameStage;

};
