#pragma once
#include "tetrisIcon.h"

class TetrisElement: public hgeGUIObject
{
	private:
		int _numOfElementFromArr;
		int _numColorElement;
		float _start_pos_x;
		float _start_pos_y;
		std::vector< TetrisIcon* > _icon_list;

	public:		
		static const char* RED;
		static const char* BLUE;
		static const char* GREEN;
		int _x;
		int _y;

		TetrisElement();
		TetrisElement(int id, float x, float y);
		//~TetrisElement();

		int getHeightEl();
		int getWidthtEl();
		void  createElement();
		void move(int diff_x, int diff_y);
		void move();

		virtual void  Render();
//		void clear();
};
