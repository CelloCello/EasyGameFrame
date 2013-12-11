#pragma once
#include "StageUnit.h"

/*
 *	�n�J�e�����q����
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
	hgeGUI*			m_StartMenu;		//�}�l�����
	hgeFont*		m_StartMenuFont;	//�}�l��檺�r��
	HEFFECT			m_SelectSound;		//��ܮɪ�����
};
