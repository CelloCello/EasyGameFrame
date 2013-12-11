#pragma once
#include "hge.h"

/*
 *	遊戲階段的物件
 *	可繼承後製作自己需要的stage
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