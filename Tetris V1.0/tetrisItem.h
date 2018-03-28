#include<hge.h>
#include<hgegui.h>
#include <hgefont.h>
#include <hgecolor.h>
#include<hgerect.h>
#include <vector>
#include "tetrisIcon.h"

#include "tetrisBoard.h"



class TetrisItem: public hgeGUIObject
{
	public:
//		
//		//~TetrisItem();
		TetrisItem(int id, float x, float y);

		Matrix _item;
		float _start_pos_x;
		float _start_pos_y;
		virtual void  Render();
		void  createItem();
//		void clear();
};
