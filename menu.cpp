
#include <hge.h>
#include <hgegui.h>
#include <hgefont.h>
#include "menuitem.h"
#include "Tetris V1.0/tetrisItem.h"
#include <math.h>
#include "Tetris V1.0/tetrisIcon.h"
#include <vector>

typedef std::vector< std::vector< int > > Matrix;

#define NEWGAME 1
#define CONTINUE 2
#define OPTIONS 3
#define EXIT 4
#define BACK 5
#define	MUSICON 6
#define	MUSICOFF 7
#define	PAUSE 8


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



void CreateItem()
{
	texItem=hge->Texture_Load("grey.png");
   sprItem=new hgeSprite(texItem,1,1,20,20); 
   sprItem->SetColor(0xDDDDDDDD);
   sprItem->SetHotSpot(1,1);
	/*Matrix itemMatrix = {
    { 1, 1 },
	{ 1, 1 },};*/

Matrix itemMatrix;
for (int i = 0; i < 2; i++) 
{
   std::vector<int> row; // Create an empty row
    for (int j = 0; j < 2; j++) 
	{
        row.push_back(1); // Add an element (column) to the row
    }
    itemMatrix.push_back(row); // Add the row to the main vector
}

TetrisItem *tetrisItem = new TetrisItem(1, 100, 100, itemMatrix, sprItem);
tetrisItem->showItem();
gui->AddCtrl(tetrisItem);
//tetrisItem->RenderItem();


}

void MusicOn()
{
	snd = sndMelody;
	gui->ShowCtrl(MUSICOFF,false);
	gui->ShowCtrl(MUSICON,true);	
	//menuMusicOn->ShowItem();
	gui->Enter();


}

void Music0ff()
{
	snd = sndEmpty;
	gui->ShowCtrl(MUSICON,false);
	gui->ShowCtrl(MUSICOFF,true);
	//menuMusicOff->ShowItem();
	gui->Enter();

}

void MenuOptions()
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
	gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	gui->SetCursor(spr);
	gui->Enter();
}

void MainMenu()
{	
	gui->ShowCtrl(MUSICON,false);
	gui->ShowCtrl(MUSICOFF,false);
	gui->ShowCtrl(BACK,false);
	gui->ShowCtrl(NEWGAME,true);
	gui->ShowCtrl(CONTINUE,true);
	gui->ShowCtrl(OPTIONS,true);
	gui->ShowCtrl(EXIT,true);
	gui->Enter();

}


void CreateIcon()
{
	TetrisIcon *tetrisIcon =new TetrisIcon("qwe",20, 20);
	tetrisIcon->textureLoad();
	tetrisIcon->initSprite();
}



bool checkClicks(int id)
{
	static int lastid=0;
	if(hge->Input_GetKeyState(HGEK_ESCAPE)) { lastid=3; gui->Leave(); }

	if(id == -1)
	{
		switch(lastid)
		{
		case NEWGAME:
			CreateIcon();
			//TetrisPlay();
			break;
		case CONTINUE:
			//Continue();
			break;
		case OPTIONS:
			MenuOptions();
			break;
		case EXIT:
			return true;
		case MUSICON:
			Music0ff();
			break;
		case MUSICOFF:
			MusicOn();
			break;
		case BACK:
			MainMenu();
			break;
		case PAUSE:
			//Pause();
			break;
		}
	}
	else if(id) { lastid=id; gui->Leave(); }

	return false;
}
bool FrameFunc()
{
	float dt=hge->Timer_GetDelta();
	static float t=0.0f;
	float tx,ty;

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
