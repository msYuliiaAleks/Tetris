#pragma once
#include "tetrisIcon.h"

class TetrisElement: public hgeGUIObject
{
	private:
		int _numOfElementFromArr;
		int _numColorElement;
		float _start_pos_x;
		float _start_pos_y;
		

	public:		
		static const char* RED;
		static const char* BLUE;
		static const char* GREEN;
		int _x;
		int _y;
std::vector< TetrisIcon* > _icon_list;
		TetrisElement();
		~TetrisElement();

		int getHeightEl();
		int getWidthtEl();
		void  createElement();
		void move(int diff_x, int diff_y);
		void rotate();
		void setParameters(int id, float x, float y);

		virtual void  Render();
		void clear();
};
