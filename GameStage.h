#pragma once
#include "StageUnit.h"
#include "hgeanim.h"
#include "ResourceManager.h"
#include <vector>
using namespace std;

/*
 *	�C���D�����q����
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
