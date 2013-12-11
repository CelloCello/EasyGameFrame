#pragma once
#include "StageUnit.h"
#include "hgeanim.h"
#include "ResourceManager.h"
#include <vector>
using namespace std;

/*
 *	遊戲主場階段物件
 */

class GameStage : public StageUnit
{
public:
	GameStage(void);
	~GameStage(void);

	virtual void	Init();
	virtual void	Fini();
	virtual bool	FrameUpdate(float dt);
	virtual void	RenderUpdate();


private:
	GameObject*		PlrObj;
	hgeAnimation*	Ami;
	hgeSprite*		background;
	hgeSprite*		fall[20];
	int fPosX[20], fPosY[20];
	vector<int> list;
	int PosX, PosY;
};
