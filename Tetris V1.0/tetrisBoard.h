

#include <hge.h>
#include <hgegui.h>
#include <hgefont.h>
#include <hgecolor.h>
#include <hgerect.h>
#include <vector>
#pragma once
typedef std::vector< std::vector< TetrisIcon* > > Matrix;


class TetrisBoard: public hgeGUIObject
{
public:
	//static std::string BOARD;
	TetrisBoard(int id, float x, float y);//, Matrix board );

	Matrix _board;
	float _start_pos_x;
	float _start_pos_y;


	virtual void  Render();
	void  createBoard();
	void createMargin(int x,int y);
};