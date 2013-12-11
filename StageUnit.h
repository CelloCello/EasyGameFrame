#pragma once
#include "hge.h"

/*
 *	�C�����q������
 *	�i�~�ӫ�s�@�ۤv�ݭn��stage
 */
class StageUnit
{
public:
	StageUnit(void);
	virtual ~StageUnit(void);

	virtual void	Init(){}
	virtual void	Fini(){}
	virtual bool	FrameUpdate(float dt);
	virtual void	RenderUpdate();

	void	SetHGE(HGE* hge){ m_Hge = hge; }

protected:
	HGE*			m_Hge;
};					