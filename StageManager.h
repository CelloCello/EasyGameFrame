#pragma once
#include <map>
#include <WTypes.h>
#include "ASingleton.h"
#include "StageUnit.h"

using namespace std;


/*
 *	�޲z�C�������q
 *	�i�Ѥ��P�� StageUnit �Ӫ�ܤ��P���q�n������, �n�e�o����
 *	���t�d�޲z���q, ���t�d StageUnit ���ͦ�
 */

class StageManager : public ASingleton<StageManager>
{
public:
	StageManager(void);
	~StageManager(void);

	void		Fini();
	void		SetStageNum(BYTE Num);				//�]�wStage���`��
	void		ChangeStage(BYTE ID);				//�����C�����q
	void		Add(BYTE ID,StageUnit* Stage);		//�s�W�@��
	StageUnit*	GetCurrStage() { return m_CurrStage; }
	
private:
	void	FreeAllStage();

private:
	//typedef map<BYTE,StageUnit*>		STAGE_MAP;	//�s��,Stage
	//typedef STAGE_MAP::value_type		STAGE_VAL;

	//STAGE_MAP		m_StageMap;			//�Ҧ�Stage��map

	BYTE			m_StageNum;			//Stage�`��
	StageUnit**		m_StageList;		//�Ҧ�Stage
	StageUnit*		m_CurrStage;		//�ثe��Stage
};
