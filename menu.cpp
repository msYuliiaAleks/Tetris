#include "stdafx.h"
#include "Tetris V1.0/menuitem.h"
#include "Tetris V1.0/tetrisElement.h"
#include "Tetris V1.0/tetrisIcon.h"
#include "Tetris V1.0/tetrisBoard.h"

//typedef std::vector< std::vector< int > > Matrix;

enum{ NEWGAME =1,
CONTINUE= 2,
OPTIONS =3,
EXIT =4,
BACK =5,
MUSICON =6,
MUSICOFF =7,
PAUSE =8
};
const float speed=0.00003f;
float fpos=0; //лічильник руху актиної фігурки

HGE *hge=0;

hgeSprite* sprItem; 
HTEXTURE texItem;

HEFFECT				snd;
HEFFECT				sndMelody;
HEFFECT				sndEmpty;
HTEXTURE			tex;

hgeQuad				quad;

hgeGUI				*gui;
hgeFont				*fnt;
hgeSprite			*spr;

hgeGUIMenuItem *menuNewGame;
hgeGUIMenuItem *menuContinue;
hgeGUIMenuItem *menuOptions;
hgeGUIMenuItem *menuExit;
hgeGUIMenuItem *menuMusicOff;
hgeGUIMenuItem *menuMusicOn;
hgeGUIMenuItem *menuBack;


void exit(){}

void musicOn()
{
	snd = sndMelody;
	gui->ShowCtrl(MUSICOFF,false);
	gui->ShowCtrl(MUSICON,true);	
	gui->Enter();
}

void music0ff()
{
	snd = sndEmpty;
	gui->ShowCtrl(MUSICON,false);
	gui->ShowCtrl(MUSICOFF,true);
	gui->Enter();

}

void menuOption()
{
	gui->ShowCtrl(NEWGAME,false);
	gui->ShowCtrl(CONTINUE,false);
	gui->ShowCtrl(OPTIONS,false);
	gui->ShowCtrl(EXIT,false);

	gui->AddCtrl(menuMusicOff);
	gui->AddCtrl(menuMusicOn);
	gui->AddCtrl(menuBack);

	if(snd == sndEmpty)
	{
		gui->ShowCtrl(MUSICON,false);
		gui->ShowCtrl(MUSICOFF,true);
	}
	else
	{		
	gui->ShowCtrl(MUSICON,true);
	gui->ShowCtrl(MUSICOFF,false);
	}

	gui->Enter();
}

void mainMenu()
{	
	gui->ShowCtrl(MUSICON,false);
	gui->ShowCtrl(MUSICOFF,false);
	gui->ShowCtrl(BACK,false);
	gui->ShowCtrl(NEWGAME,true);
	gui->ShowCtrl(CONTINUE,true);
	gui->ShowCtrl(OPTIONS,true);
	gui->ShowCtrl(EXIT,true);
	gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	gui->Enter();

}

TetrisBoard *tetrisBoard = new TetrisBoard();
void createBoard()
{
	gui->ShowCtrl(NEWGAME,false);
	gui->ShowCtrl(CONTINUE,false);
	gui->ShowCtrl(OPTIONS,false);
	gui->ShowCtrl(EXIT,false);


tetrisBoard->gui = gui;
tetrisBoard->createBoard();
gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
gui->Enter();
tetrisBoard->createElement();
gui->Enter();


}
//TetrisElement *tetrisElement = new TetrisElement(1,270,50);
//
//void CreateElement()
//{
//	tetrisElement->gui = gui;
//	tetrisElement->createElement();
//	//gui->Enter();
//	
//	gui->Enter();
//}
//
//


bool checkClicks(int id)
{
	static int lastid=0;
	if(hge->Input_GetKeyState(HGEK_ESCAPE)) { lastid=3; gui->Leave(); }

	if(id == -1)
	{
		switch(lastid)
		{
		case NEWGAME:
			createBoard();
			//CreateElement();
			//TetrisPlay();
			break;
		case CONTINUE:
			//Continue();
			break;
		case OPTIONS:
			menuOption();
			break;
		case EXIT:
			exit();
			return true;
		case MUSICON:
			music0ff();
			break;
		case MUSICOFF:
			musicOn();
			break;
		case BACK:
			mainMenu();
			break;
		case PAUSE:
			//Pause();
			break;
		}

		lastid = 0;
	}
	else if(id) { lastid=id; gui->Leave(); }

	return false;
}
bool FrameFunc()
{
	float dt=hge->Timer_GetDelta();
	static float t=0.0f;
	float tx,ty;

 fpos+=speed/hge->Timer_GetDelta();
 if(fpos>1)
 {
	if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;
	if (hge->Input_GetKeyState(HGEK_UP)){tetrisBoard->turn();};
	if (hge->Input_GetKeyState(HGEK_LEFT)){tetrisBoard->toLeft();};
	if (hge->Input_GetKeyState(HGEK_DOWN)){tetrisBoard->toDown();};
	if (hge->Input_GetKeyState(HGEK_RIGHT)){tetrisBoard->toRight();};
	fpos=0;
 }

	checkClicks(gui->Update(dt));
	t+=dt;
	tx=50*cosf(t/60);
	ty=50*sinf(t/60);
	quad.v[0].tx=tx;        quad.v[0].ty=ty;
	quad.v[1].tx=tx+800/64; quad.v[1].ty=ty;
	quad.v[2].tx=tx+800/64; quad.v[2].ty=ty+600/64;
	quad.v[3].tx=tx;        quad.v[3].ty=ty+600/64;

	return false;
}

bool RenderFunc()
{
	// Render graphics
	hge->Gfx_BeginScene();
	hge->Gfx_RenderQuad(&quad);
	gui->Render();
	fnt->SetColor(0xFFFFFFFF);
	fnt->printf(5, 5, HGETEXT_LEFT, "dt:%.3f\nFPS:%d", hge->Timer_GetDelta(), hge->Timer_GetFPS());
	hge->Gfx_EndScene();

	return false;
}


void CreationMenu()
{	
	if(hge->System_Initiate())
	{
		// Load sound and textures
		quad.tex=hge->Texture_Load("bg.png");
		tex = hge->Texture_Load("cursor.png");
		sndMelody = hge->Effect_Load("menu.wav");
		sndEmpty = hge->Effect_Load("no_sound.mp3"); 
		snd=sndMelody;


		if(!quad.tex || !tex|| !snd)
		{
			// If one of the data files is not found, display
			// an error message and shutdown.
			MessageBox(NULL, "Can't load BG.PNG, CURSOR.PNG or MENU.WAV", "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
			hge->System_Shutdown();
			hge->Release();
		}

		// Set up the quad we will use for background animation
		quad.blend=BLEND_ALPHABLEND | BLEND_COLORMUL | BLEND_NOZWRITE;

		for(int i=0;i<4;i++)
		{
			// Set up z-coordinate of vertices
			quad.v[i].z=0.5f;
			// Set up color. The format of DWORD col is 0xAARRGGBB
			quad.v[i].col=0xFFFFFFFF;
		}

		quad.v[0].x=0; quad.v[0].y=0; 
		quad.v[1].x=800; quad.v[1].y=0; 
		quad.v[2].x=800; quad.v[2].y=600; 
		quad.v[3].x=0; quad.v[3].y=600; 


		// Load the font, create the cursor sprite
		fnt=new hgeFont("font1.fnt");
		spr=new hgeSprite(tex,0,0,32,32);
		gui=new hgeGUI();
		// Create and initialize the GUI
		
		menuNewGame = new hgeGUIMenuItem(NEWGAME,fnt,snd,400,200,0.0f,"New Game");
		menuContinue = new hgeGUIMenuItem(CONTINUE,fnt,snd,400,240,0.1f,"Continue");
		menuOptions = new hgeGUIMenuItem(OPTIONS,fnt,snd,400,280,0.2f,"Options");
		menuExit = new hgeGUIMenuItem(EXIT,fnt,snd,400,360,0.3f,"Exit");
		menuMusicOff = new hgeGUIMenuItem(MUSICOFF,fnt,snd,400,240,0.3f,"Music(off)");
		menuMusicOn = new hgeGUIMenuItem(MUSICON,fnt,snd,400,240,0.4f,"Music(on)");
		menuBack = new hgeGUIMenuItem(BACK,fnt,snd,400,280,0.5f,"Back");


		gui->AddCtrl(menuNewGame);
		gui->AddCtrl(menuContinue);
		gui->AddCtrl(menuOptions);
		gui->AddCtrl(menuExit);
		gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
		gui->SetCursor(spr);
		gui->SetFocus(1);
		gui->Enter();


		// Let's rock now!
		hge->System_Start();
		// Delete created objects and free loaded resources
		delete gui;
		delete fnt;
		delete spr;
		hge->Effect_Free(snd);
		hge->Texture_Free(tex);
		hge->Texture_Free(quad.tex);
	}

	
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	hge = hgeCreate(HGE_VERSION);
	hge->System_SetState(HGE_LOGFILE, "hge_tut06.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "Creating menus");
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_SCREENBPP, 32);
	CreationMenu();
	// Clean up and shutdown
	hge->System_Shutdown();
	hge->Release();
	return 0;
}
