#pragma once

class TetrisIcon: public hgeGUIObject
{
	private:
		hgeSprite* _sprIcon; 
		HTEXTURE _texIcon;
		const char* _name;
		float _start_pos_x;

		float _start_pos_y;
		
		float _txt_w;
		float _txt_h;

	public:
		int _x;
		int _y;
		float _curr_pos_x;
		float _curr_pos_y;
		TetrisIcon(void);
		~TetrisIcon(void);

		void setStarPosX(float start_pos_x);

		void recalculatePosition(int element_x = 0, int element_y = 0);
		void crystalColor();
		void textureLoad();
		void initSprite();
		virtual void Render();
		void createIcon(const char* name,float start_pos_x, float start_pos_y, int x, int y);
};

