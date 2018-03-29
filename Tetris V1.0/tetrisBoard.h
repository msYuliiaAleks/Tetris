#pragma once
typedef std::vector< std::vector< TetrisIcon* > > Matrix;

class TetrisElement;
class TetrisIcon;

class TetrisBoard: public hgeGUIObject
{
public:
	//static std::string BOARD;
	static const char* BOARD;
	static const char* MARGIN;
	//TetrisBoard(float x, float y);//, Matrix board );
	Matrix _board;
	float _start_pos_x;
	float _start_pos_y;
	float txt_w ;
	float txt_h ;
	int _height;
	int _width;
	TetrisElement* currElement;
	std::vector<TetrisIcon*> arrElements;
	
	TetrisBoard();

	bool canMove(int diff_x, int diff_y);
	void toDown();
	void toLeft();
	void toRight();
	void turn();
	void createBoard();
	void createMargin(int x,int y);
	void createElement();

	virtual void  Render();
};