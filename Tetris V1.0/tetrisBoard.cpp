#include <vector>
#include<hge.h>
#include<hgegui.h>
#include "tetrisIcon.h"
#include "tetrisBoard.h"

TetrisBoard::TetrisBoard(int _id, float x, float y)//, Matrix board)
{
	id=_id;
	_start_pos_x=x;
	_start_pos_y=y;
}

void  TetrisBoard::Render(){};

void TetrisBoard::createBoard()
{
	
	for (int y = 0; y < 20; y++) 
	{
		std::vector<TetrisIcon*> row; 
		for (int x = 0; x < 10; x++) 
		{
			createMargin(x,y);

			TetrisIcon *tetrisIcon = new TetrisIcon();
			tetrisIcon->createIcon(_start_pos_x, _start_pos_y, x, y);
			this->gui->AddCtrl(tetrisIcon);
			row.push_back(tetrisIcon); 
		}
		_board.push_back(row); 
	}

}
void TetrisBoard::createMargin(int x,int y)
{
	if(x==0)
	{
		TetrisIcon *tetrisIcon = new TetrisIcon();
		tetrisIcon->createIconMargin(_start_pos_x-25, _start_pos_y, x, y);
		this->gui->AddCtrl(tetrisIcon);
	}
	if(x==9)
	{
		TetrisIcon *tetrisIcon = new TetrisIcon();
		tetrisIcon->createIconMargin(_start_pos_x+25, _start_pos_y, x, y);
		this->gui->AddCtrl(tetrisIcon);
	}
	if(y==0)
	{
		TetrisIcon *tetrisIcon = new TetrisIcon();
		tetrisIcon->createIconMargin(_start_pos_x, _start_pos_y-25, x, y);
		this->gui->AddCtrl(tetrisIcon);

	}
	if(y==19)
	{
		TetrisIcon *tetrisIcon = new TetrisIcon();
		tetrisIcon->createIconMargin(_start_pos_x, _start_pos_y+25, x, y);
		this->gui->AddCtrl(tetrisIcon);
	}
	if(x==0&&y==0)
	{
		TetrisIcon *tetrisIcon = new TetrisIcon();
		tetrisIcon->createIconMargin(_start_pos_x-25, _start_pos_y-25, x, y);
		this->gui->AddCtrl(tetrisIcon);
	}
	if(x==9&&y==19)
	{
		TetrisIcon *tetrisIcon = new TetrisIcon();
		tetrisIcon->createIconMargin(_start_pos_x+25, _start_pos_y+25, x, y);
		this->gui->AddCtrl(tetrisIcon);

	}

	if(x==0&&y==19)
	{
		TetrisIcon *tetrisIcon = new TetrisIcon();
		tetrisIcon->createIconMargin(_start_pos_x-25, _start_pos_y+25, x, y);
		this->gui->AddCtrl(tetrisIcon);
	}
	if(x==9&&y==0)
	{
		TetrisIcon *tetrisIcon = new TetrisIcon();
		tetrisIcon->createIconMargin(_start_pos_x+25, _start_pos_y-25, x, y);
		this->gui->AddCtrl(tetrisIcon);
	}

}