#pragma once
#include "hgesprite.h"
#include "hgeanim.h"
#include "GameManager.h"
#include "GLog.h"

HGE *hge = 0;
hgeSprite* Spr = NULL;
hgeSprite* Spr1 = NULL;
hgeAnimation* Ami = NULL;


float x=100.0f, y=100.0f;
float dx=0.0f, dy=0.0f;

const float speed=20;
const float friction=0.98f;

void boom() 
{
	//int pan=int((x-400)/4);
	//float pitch=(dx*dx+dy*dy)*0.0005f+0.2f;
	//hge->Effect_PlayEx(snd,100,pan,pitch);
}



bool FrameFunc()
{
	// Get the time elapsed since last call of FrameFunc().
	// This will help us to synchronize on different
	// machines and video modes.
	float dt=hge->Timer_GetDelta();

	// Process keys
	if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;
	if (hge->Input_GetKeyState(HGEK_LEFT)) dx-=speed*dt;
	if (hge->Input_GetKeyState(HGEK_RIGHT)) dx+=speed*dt;
	if (hge->Input_GetKeyState(HGEK_UP)) dy-=speed*dt;
	if (hge->Input_GetKeyState(HGEK_DOWN)) dy+=speed*dt;
	//if (hge->Input_GetKeyState(HGEK_LEFT)) dx=-speed*dt;
	//if (hge->Input_GetKeyState(HGEK_RIGHT)) dx=speed*dt;
	//if (hge->Input_GetKeyState(HGEK_UP)) dy=-speed*dt;
	//if (hge->Input_GetKeyState(HGEK_DOWN)) dy=speed*dt;


	// Do some movement calculations and collision detection	
	dx*=friction; dy*=friction; x+=dx; y+=dy;
	if(x>784) {x=784-(x-784);dx=-dx;boom();}
	if(x<16) {x=16+16-x;dx=-dx;boom();}
	if(y>584) {y=584-(y-584);dy=-dy;boom();}
	if(y<16) {y=16+16-y;dy=-dy;boom();}

	//x+=dx; y+=dy;
	//if(x>784) {x=784;dx=0;boom();}
	//if(x<16) {x=16;dx=0;boom();}
	//if(y>584) {y=584;dy=0;boom();}
	//if(y<16) {y=16;dy=0;boom();}

	// Set up quad's screen coordinates
	Ami->Update(dt);
	

	// Continue execution
	// return true就不會做RenderFunc
	return false;
}

//繪圖迴圈
bool RenderFunc()
{
	// Begin rendering quads.
	// This function must be called
	// before any actual rendering.
	hge->Gfx_BeginScene();

	// Clear screen with black color
	hge->Gfx_Clear(128);

	// Render quads here. This time just
	// one of them will serve our needs.
	//Spr->Render(x-16,y-16);
	//Spr1->Render(500,300);
	Spr->Render(100,100);
	Ami->Render(x-40,y-32);

	static int sx_ = 300;
	static int sy_ = 0;
	static float sg_ = 9.8;
	static float passtime_ = 0;
	static DWORD start_ = ::GetTickCount();
	if ( (::GetTickCount() - start_) > 10 )
	{
		passtime_ += 0.01;
		sy_ += 0.5 * sg_ * passtime_* passtime_;
		//Spr1->Render(sx_,sy_);
		start_ = ::GetTickCount();
	}
	Spr1->Render(sx_,sy_);
	

	// End rendering and update the screen
	hge->Gfx_EndScene();

	// RenderFunc should always return false
	return false;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//hge = hgeCreate(HGE_VERSION);
	//hge->System_SetState(HGE_SCREENWIDTH, 800);
	//hge->System_SetState(HGE_SCREENHEIGHT,600);
	//hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	//hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	//hge->System_SetState(HGE_WINDOWED, true);
	//hge->System_SetState(HGE_USESOUND, false);
	//hge->System_SetState(HGE_FPS, 60);
	//hge->System_SetState(HGE_TITLE,"GameDemo - 小美人魚 v0.1a");

	//if(hge->System_Initiate())
	//{
	//	HTEXTURE tex = hge->Texture_Load("particles.png");
	//	HTEXTURE tex1 = hge->Texture_Load("testimg.png");
	//	if( !tex || !tex1 )
	//	{
	//		// If one of the data files is not found, display
	//		// an error message and shutdown.
	//		MessageBox(NULL, "Can't load one of the following files:\nMENU.WAV, PARTICLES.PNG, FONT1.FNT, FONT1.PNG, TRAIL.PSI", "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
	//		hge->System_Shutdown();
	//		hge->Release();
	//		return 0;
	//	}

	//	// Set up quad which we will use for rendering sprite
	//	Spr = new hgeSprite(tex,96.0,64.0,32,32);
	//	Spr->SetBlendMode(BLEND_ALPHAADD | BLEND_COLORMUL | BLEND_ZWRITE);
	//	Spr->SetZ(0.5f);			// Set up z-coordinate of vertices
	//	Spr->SetColor(0xFFFFA000);	// Set up color. The format of DWORD col is 0xAARRGGBB

	//	Spr1 = new hgeSprite(tex,96.0,64.0,32,32);
	//	Spr1->SetBlendMode(BLEND_ALPHAADD | BLEND_COLORMUL | BLEND_ZWRITE);
	//	Spr1->SetZ(0.5f);			// Set up z-coordinate of vertices
	//	Spr1->SetColor(0xFFFFA000);	// Set up color. The format of DWORD col is 0xAARRGGBB

	//	Ami = new hgeAnimation(tex1,3,3,0,0,80,64);
	//	Ami->SetMode(HGEANIM_LOOP);
	//	Ami->SetColor(0xFFFFFFFF);
	//	Ami->Play();

	//	//系統主迴圈
	//	hge->System_Start();

	//	delete Spr;
	//	delete Spr1;
	//	delete Ami;
	//}
	//else
	//{	
	//	MessageBox(NULL, hge->System_GetErrorMessage(), "Error",
	//		MB_OK | MB_ICONERROR | MB_APPLMODAL);
	//}

	////關閉
	//hge->System_Shutdown();
	//hge->Release();

	GameManager gm_;
	gm_.Init();
	GLog::m_Hge = gm_.m_Hge;
	if ( !gm_.Run() )
	{
		MessageBox(NULL, hge->System_GetErrorMessage(), "Error",
			MB_OK | MB_ICONERROR | MB_APPLMODAL);
	}

	return 0;

}