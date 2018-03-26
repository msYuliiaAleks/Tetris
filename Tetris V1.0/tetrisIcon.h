
#include <hge.h>
#include <hgegui.h>
#include <hgefont.h>
#include <string>

class TetrisIcon: public hgeGUIObject{
private:
	hgeSprite* _sprIcon; 
	HTEXTURE _texIcon;
	std::string _name;
	float _x;
	float _y;
public:
	TetrisIcon(std::string name,float x, float y);
	void textureLoad();
	void initSprite();
	virtual void Render();
};

