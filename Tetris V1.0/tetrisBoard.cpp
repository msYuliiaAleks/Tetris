#include "stdafx.h"
#include "tetrisIcon.h"
#include "tetrisBoard.h"
#include "tetrisElement.h"

const char* TetrisBoard::BOARD = "board.png";
const char* TetrisBoard::MARGIN = "margin.png";
TetrisBoard::TetrisBoard()
{
	_start_pos_x=270;
	_start_pos_y=50;
	height=20;
	width=10;
	txt_w=25 ;
	txt_h =25;

}
//TetrisBoard::TetrisBoard(float x, float y)//, Matrix board)
//{
//	_start_pos_x=x;
//	_start_pos_y=y;
//
//}

void  TetrisBoard::Render(){};
void TetrisBoard::createBoard()
{


	for (int y = 0; y < height; y++) 
	{
		std::vector<TetrisIcon*> row; 
		for (int x = 0; x < width; x++) 
		{
			createMargin(x,y);
			TetrisIcon *tetrisIcon = new TetrisIcon();
			tetrisIcon->createIcon(BOARD,_start_pos_x, _start_pos_y, x, y);
			tetrisIcon->crystalColor();
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
		tetrisIcon->createIcon(MARGIN,_start_pos_x-25, _start_pos_y, x, y);
		this->gui->AddCtrl(tetrisIcon);
	}
	if(x==9)
	{
		TetrisIcon *tetrisIcon = new TetrisIcon();
		tetrisIcon->createIcon(MARGIN,_start_pos_x+25, _start_pos_y, x, y);
		this->gui->AddCtrl(tetrisIcon);
	}
	if(y==0)
	{
		TetrisIcon *tetrisIcon = new TetrisIcon();
		tetrisIcon->createIcon(MARGIN,_start_pos_x, _start_pos_y-25, x, y);
		this->gui->AddCtrl(tetrisIcon);

	}
	if(y==19)
	{
		TetrisIcon *tetrisIcon = new TetrisIcon();
		tetrisIcon->createIcon(MARGIN,_start_pos_x, _start_pos_y+25, x, y);
		this->gui->AddCtrl(tetrisIcon);
	}
	if(x==0&&y==0)
	{
		TetrisIcon *tetrisIcon = new TetrisIcon();
		tetrisIcon->createIcon(MARGIN,_start_pos_x-25, _start_pos_y-25, x, y);
		this->gui->AddCtrl(tetrisIcon);
	}
	if(x==9&&y==19)
	{
		TetrisIcon *tetrisIcon = new TetrisIcon();
		tetrisIcon->createIcon(MARGIN,_start_pos_x+25, _start_pos_y+25, x, y);
		this->gui->AddCtrl(tetrisIcon);

	}

	if(x==0&&y==19)
	{
		TetrisIcon *tetrisIcon = new TetrisIcon();
		tetrisIcon->createIcon(MARGIN,_start_pos_x-25, _start_pos_y+25, x, y);
		this->gui->AddCtrl(tetrisIcon);
	}
	if(x==9&&y==0)
	{
		TetrisIcon *tetrisIcon = new TetrisIcon();
		tetrisIcon->createIcon(MARGIN,_start_pos_x+25, _start_pos_y-25, x, y);
		this->gui->AddCtrl(tetrisIcon);
	}

}

//TetrisElement *currElement=0;

void TetrisBoard::createElement()
{	
	currElement=new TetrisElement(1,_start_pos_x,_start_pos_y);
	currElement->gui = this->gui;
	currElement->createElement();
	currElement->move(3, 0);


	//_boardEl.push_back(tetrisElement->_element);
	//
}

void TetrisBoard::toRight()
{
	if (canMove(1, 0))
		currElement->move(1, 0);
}
void TetrisBoard::toLeft()
{
	if (canMove(-1, 0))
		currElement->move(-1, 0);
}
void TetrisBoard::toDown()
{
	if (canMove(0, 1))
		currElement->move(0, 1);
}
bool TetrisBoard::canMove(int diff_x, int diff_y)
{
	if (!currElement)
		return false;

	std::vector<TetrisIcon*>& icons = currElement->getIconList();
	for (UINT i = 0; i < icons.size(); ++i)
	{
		//check left border
		if ((icons[i]->_x + diff_x) < 0)
			return false;
	}

	return true;
}