#pragma once

class hgeGUIMenuItem : public hgeGUIObject
{
	public:
		float xR;
		float yR;

		hgeGUIMenuItem(int id, hgeFont *fnt, HEFFECT snd,
			float x, float y, float delay, char *title);
		hgeGUIMenuItem();
		virtual void  Render();
		virtual void  Update(float dt);

		//virtual float GetX();
		//virtual float GetY();
		//virtual void SetX(float x);
		//virtual void SetY(float y);


		virtual void  Enter();
		void  ShowItem();
		virtual void  Leave();
		virtual bool  IsDone();
		virtual void  Focus(bool bFocused);
		virtual void  MouseOver(bool bOver);
		virtual void RectSet(float x, float y);
		virtual bool  MouseLButton(bool bDown);
		virtual bool  KeyClick(int key, int chr);

	private:
	  hgeFont *fnt;
	  HEFFECT snd;
	  float delay;
	  char *title;

	  hgeColor scolor, dcolor, scolor2, dcolor2, color;
	  hgeColor sshadow, dshadow, shadow;
	  float soffset, doffset, offset;
	  float timer, timer2;
};
