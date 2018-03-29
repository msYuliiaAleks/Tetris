#include "stdafx.h"
#include "tetrisElement.h"
#include "readElement.h"
#include <ctime>

const char* TetrisElement::RED = "red.png";
const char* TetrisElement::BLUE = "blue.png";
const char* TetrisElement::GREEN = "green.png";
TetrisElement::TetrisElement(){};
TetrisElement::TetrisElement(int _id, float x, float y)//, Matrix board)
{
	id=_id;
	_start_pos_x=x;
	_start_pos_y=y;
	_x=0;
	_y=0;
}

void  TetrisElement::Render(){};

int TetrisElement::getHeightEl()
{
	int temp=0;
	for (UINT i = 0; i < _icon_list.size(); ++i) 
	{
		if(_icon_list[i]->_y>temp)
			temp=_icon_list[i]->_y;
	}
	return temp+1;
}
int TetrisElement::getWidthtEl()
{
	int temp=0;
	for (UINT i = 0; i < _icon_list.size(); ++i) 
	{
		if(_icon_list[i]->_x>temp)
			temp=_icon_list[i]->_x;
	}
	return temp+1;
}

void TetrisElement::createElement()
{
	srand( time( 0 ) ); 
	ReadElement *read = new ReadElement();
	read->ReadFile();
	_numOfElementFromArr = 0 + rand() % (read->ArrMatrixEl.size());
	_numColorElement = 0 + rand() % 3;
	//
	//for(int i=0;i<read->ArrMatrixEl.size();i++)
	//{
	std::vector<Point> element=read->ArrMatrixEl[_numOfElementFromArr];
	Point point;
	//	std::vector<TetrisIcon*> row; 
	for (UINT i = 0; i < element.size(); i++) 
	{
		point = element[i];
		TetrisIcon *tetrisIcon = new TetrisIcon();
		tetrisIcon->createIcon(GREEN,_start_pos_x, _start_pos_y, point.x, point.y);
		this->gui->AddCtrl(tetrisIcon);
		_icon_list.push_back(tetrisIcon);
		//		row.push_back(tetrisIcon);

	}
	/*	_element.push_back(row);
	}*/
}
void TetrisElement::move(int diff_x, int diff_y)
{
	_x += diff_x;
	_y += diff_y;

	for (UINT i = 0; i < _icon_list.size(); ++i) 
	{
		_icon_list[i]->recalculatePosition(_x, _y);
	}

}
void TetrisElement::move()
{
	std::vector< TetrisIcon* > _temp_icon_list;

	for (UINT i = 0; i < _icon_list.size(); ++i) 
	{
		//_icon_list[i]->recalculatePosition(_y, _x);
	}

}


/*ReadElement *read = new ReadElement();
read->ReadFile();
Element Element=read->ArrMatrixEl[0];
Point point;
for (int y = 0; y < Element.count_rows; y++) 
{
std::vector<TetrisIcon*> row; 
point = Element.points[0];
TetrisIcon *tetrisIcon = new TetrisIcon();
tetrisIcon->createIcon(RED,_start_pos_x, _start_pos_y, point.x, point.y);
this->gui->AddCtrl(tetrisIcon);
row.push_back(tetrisIcon);

}*/	
//Element
//	
//	{
//		
//		for (int x = 0; x <3; x++) 
//		{
//			if((Element[y][x])==1){
//			TetrisIcon *tetrisIcon = new TetrisIcon();
//			tetrisIcon->createIcon(RED,_start_pos_x, _start_pos_y, x, y);
//			this->gui->AddCtrl(tetrisIcon);
//			 
//			}
//		}
//		_Element.push_back(row); 
//		
//	}
