#include <hge.h>
#include <hgegui.h>
#include <hgefont.h>
#include <string>
#pragma once

class TetrisIcon: public hgeGUIObject{
private:
	hgeSprite* _sprIcon; 
	HTEXTURE _texIcon;
	 char* _name;
	float _start_pos_x;
	float _start_pos_y;
	float _curr_pos_x;
	float _curr_pos_y;
	int _x;
	int _y;

public:
	TetrisIcon(char* name);
	TetrisIcon(void);

	void textureLoad();
	void initSprite();
	virtual void Render();
	void createIcon(float start_pos_x, float start_pos_y, int x, int y);
	void createIconMargin (float start_pos_x, float start_pos_y, int x, int y);

};

