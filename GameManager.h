#pragma once
#include "hge.h"
#include "GameStage.h"
#include "LoginStage.h"

/*
 *	�C���޲z��, ��ӱM�ת��_�l�P�������Ѧ�
 */

class StageManager;



class GameManager
{
public:
	GameManager(void);
	~GameManager(void);

	bool			Init();					//��l
	void			Fini();					//����
	bool			Run();					//�Ұ�
	static bool		FrameFunc();			//
	static bool		RenderFunc();			//ø�ϰj��

public:
	static HGE* m_Hge;

private:
	static StageManager*	m_StageMgr;

public:
	//stages
	LoginStage				m_LoginStage;
	GameStage				m_GameStage;

};
