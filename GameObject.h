#pragma once
#include "hgeanim.h"
#include "GameDefine.h"

/*
 *	�C����¦����, �H
 *	��ܹC�������󪺦�m�B�ʵe�B�ءK���F��
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
	hgeAnimation*	m_Anim;		//�ʵe����
	unsigned short	m_KindID;	//�����s��

	//�ئC��
	VolumeElement*	m_VolList[MAX_OBJ_VOL];
};
