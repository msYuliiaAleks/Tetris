
#include <hge.h>
#include <hgegui.h>
#include <hgefont.h>
#include "tetrisIcon.h"

TetrisIcon::TetrisIcon(std::string name,float x, float y)
{
	_name = name;
	_x=x;
	_y=y;
}
void TetrisIcon::textureLoad()
{
	_texIcon=hge->Texture_Load("grey.png");
}
void TetrisIcon::initSprite()
{
	_sprIcon = new hgeSprite(_texIcon,_x,_y,20,20); 
	_sprIcon->SetColor(0xDDDDDDDD);
	_sprIcon->SetHotSpot(1,1);
}
void TetrisIcon::Render()
{
	_sprIcon->Render(_x,_y);
}