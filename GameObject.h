#pragma once
#include "hgeanim.h"
#include "GameDefine.h"

/*
 *	遊戲基礎物件, 以
 *	表示遊戲內物件的位置、動畫、框…的東西
 */

class VolumeElement;

class GameObject
{
public:
	GameObject(void);
	~GameObject(void);

	void	CloneTo(GameObject* Obj);
	void	Fini();

public:
	hgeAnimation*	m_Anim;		//動畫物件
	unsigned short	m_KindID;	//種類編號

	//框列表
	VolumeElement*	m_VolList[MAX_OBJ_VOL];
};
