#include "stdafx.h"
#include "tetrisIcon.h"

TetrisIcon::TetrisIcon(void){}
TetrisIcon::~TetrisIcon(void){}



void TetrisIcon::setStarPosX(float start_pos_x)
{
	_start_pos_x=start_pos_x;
};

void TetrisIcon::textureLoad()
{
	_texIcon=hge->Texture_Load(_name);
}
void TetrisIcon::initSprite()
{
	_txt_w = (float)hge->Texture_GetWidth(_texIcon);
	_txt_h = (float)hge->Texture_GetHeight(_texIcon);
	_sprIcon = new hgeSprite(_texIcon, 0.f, 0.f, _txt_w,_txt_h); 
	_sprIcon->SetHotSpot(1,1);
}
void TetrisIcon::Render()
{
	_sprIcon->Render(_curr_pos_x,_curr_pos_y);
}

void TetrisIcon::createIcon(const char* name,float start_pos_x, float start_pos_y, int x, int y)
{	
	_name = name;
	_start_pos_x=start_pos_x;
	_start_pos_y=start_pos_y;
	_x = x;
	_y = y;
	textureLoad();
	initSprite();
	recalculatePosition();
}
void TetrisIcon::recalculatePosition()
{
	_curr_pos_x = _start_pos_x + _txt_w *_x;
	_curr_pos_y = _start_pos_y + _txt_h *_y;
};
void TetrisIcon::crystalColor()
{
	_sprIcon->SetColor(0xCCDDDDDD);
};
