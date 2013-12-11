#ifndef __GAMEDEF_H__
#define __GAMEDEF_H__

//遊戲定義
#define MAX_OBJ_VOL	5		//GameObject能擁有的框的上限

//遊戲階段
enum GAME_STAGE
{
	GS_LOGIN,		//初始登入畫面
	GS_GAME,		//主場
	GS_REWARD,		//結算

	GS_MAX
};


#endif // __GAMEDEF_H__