#include<hge.h>
#include<hgegui.h>
#include <hgefont.h>
#include <hgecolor.h>
#include<hgerect.h>
#include <vector>

typedef std::vector< std::vector< int > > Matrix;

class TetrisItem: public hgeGUIObject
{
	public:
		enum 
		{
			TYPE_UNKOWN = 0,
			TYPE_GREY = 1,
			TYPE_RED = 2
		};
		TetrisItem(int id, float x, float y, Matrix item, hgeSprite* spr);
		//~TetrisItem();

		void showItem();
		void clear();

		virtual void  Render();

	private:
		Matrix item;
		float xI;
		float yI;
		hgeSprite* spr;
};
