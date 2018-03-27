#include <vector>
#include "tetrisItem.h"
#include<hge.h>
#include<hgegui.h>

TetrisItem::TetrisItem(int _id, float _x, float _y, Matrix _item, hgeSprite* _spr)
{
	id=_id;
	xI=_x;
	yI=_y;
	item =_item;
	spr =_spr;
}


void TetrisItem::showItem()
{
	rect.Set(xI, yI, xI, yI);
}
void TetrisItem::clear()
{

}
void TetrisItem::Render()
{
	spr->Render(yI,xI);
}