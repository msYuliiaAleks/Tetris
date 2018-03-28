
#include <hge.h>
#include <hgegui.h>
#include <hgefont.h>
#include "tetrisIcon.h"

TetrisIcon::TetrisIcon(void){}


void TetrisIcon::textureLoad()
{
	_texIcon=hge->Texture_Load(_name);
}
void TetrisIcon::initSprite()
{
	int txt_w = hge->Texture_GetWidth(_texIcon);
	int txt_h = hge->Texture_GetHeight(_texIcon);
	_curr_pos_x = _start_pos_x + txt_w *_x;
	_curr_pos_y = _start_pos_y + txt_h *_y;
	_sprIcon = new hgeSprite(_texIcon, 0, 0,txt_w,txt_h); 
	_sprIcon->SetHotSpot(1,1);
}
void TetrisIcon::Render()
{
	_sprIcon->Render(_curr_pos_x,_curr_pos_y);
}

void TetrisIcon::createIcon(char* name,float start_pos_x, float start_pos_y, int x, int y)
{	
	_name = name;
	_start_pos_x=start_pos_x;
	_start_pos_y=start_pos_y;
	_x = x;
	_y = y;
	textureLoad();
	initSprite();

}

void TetrisIcon::crystalColor()
{
	_sprIcon->SetColor(0xCCDDDDDD);
};
