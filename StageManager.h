#pragma once
#include <map>
#include <WTypes.h>
#include "ASingleton.h"
#include "StageUnit.h"

using namespace std;


/*
 *	管理遊戲的階段
 *	可由不同的 StageUnit 來表示不同階段要做的事, 要畫得物件
 *	指負責管理階段, 不負責 StageUnit 的生死
 */

class StageManager : public ASingleton<StageManager>
{
public:
	StageManager(void);
	~StageManager(void);

	void		Fini();
	void		SetStageNum(BYTE Num);				//設定Stage的總數
	void		ChangeStage(BYTE ID);				//切換遊戲階段
	void		Add(BYTE ID,StageUnit* Stage);		//新增一筆
	StageUnit*	GetCurrStage() { return m_CurrStage; }
	
private:
	void	FreeAllStage();

private:
	//typedef map<BYTE,StageUnit*>		STAGE_MAP;	//編號,Stage
	//typedef STAGE_MAP::value_type		STAGE_VAL;

	//STAGE_MAP		m_StageMap;			//所有Stage的map

	BYTE			m_StageNum;			//Stage總數
	StageUnit**		m_StageList;		//所有Stage
	StageUnit*		m_CurrStage;		//目前的Stage
};
