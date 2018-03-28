#include <vector>
#include "tetrisItem.h"
#include<hge.h>
#include<hgegui.h>
#include "readItem.h"

#define RED "red.png"
#define	BLUE "blue.png"
#define	GREEN "green.png"
//
TetrisItem::TetrisItem(int _id, float x, float y)//, Matrix board)
{
	id=_id;
	_start_pos_x=x;
	_start_pos_y=y;
}

void  TetrisItem::Render(){};

//
//
void TetrisItem::createItem()
{
	ReadItem *read = new ReadItem();
	read->ReadFile();
	MatrixInt item=	read->ArrMatrixEl[0];

	for (int y = 0; y < (item.size()); y++) 
	{
		std::vector<TetrisIcon*> row; 
		for (int x = 0; x <3; x++) 
		{
			if((item[y][x])==1){
			TetrisIcon *tetrisIcon = new TetrisIcon();
			tetrisIcon->createIcon(RED,_start_pos_x, _start_pos_y, x, y);
			this->gui->AddCtrl(tetrisIcon);
			row.push_back(tetrisIcon); 
			}
		}
		_item.push_back(row); 
		
	}

}