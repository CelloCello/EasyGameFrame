#include ".\stagemanager.h"

StageManager::StageManager(void):m_StageNum(0),m_StageList(NULL),m_CurrStage(NULL)
{

}

StageManager::~StageManager(void)
{
	FreeAllStage();
}
//--------------------------------------------------------------------------------------------------
void StageManager::Fini()
{
	for ( int i=0 ; i<m_StageNum ; ++i )
	{
		if ( m_StageList[i] )
			m_StageList[i]->Fini();
	}
}
//--------------------------------------------------------------------------------------------------
//設定Stage的總數
void StageManager::SetStageNum(BYTE Num)
{
	FreeAllStage();
	m_StageNum = Num;
	m_StageList = new StageUnit*[Num];
	for ( int i=0 ; i<Num ; ++i )
		m_StageList[i] = NULL;
}
//--------------------------------------------------------------------------------------------------
//切換遊戲階段
void StageManager::ChangeStage(BYTE ID)
{
	m_CurrStage = m_StageList[ID];
	m_CurrStage->Init();
}
//--------------------------------------------------------------------------------------------------
//新增一筆
void StageManager::Add(BYTE ID,StageUnit* Stage)
{
	if ( ID < 0 || ID >= m_StageNum )
		return ;

	m_StageList[ID] = Stage;
}
//--------------------------------------------------------------------------------------------------
void StageManager::FreeAllStage()
{
	if ( m_StageNum > 0 && m_StageList )
		delete [] m_StageList;
}
//--------------------------------------------------------------------------------------------------