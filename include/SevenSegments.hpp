#ifndef __SEVENSEGMENTS_HPP__
#define __SEVENSEGMENTS_HPP__

class Segment
{
	public:
		Segment(float posX, float posY, int width, int height);
		void Draw();
		void changeState();
		float getPosX();
		float getPosY();
		~Segment();

	private:
		int x;
		int y;
		int state;
		int w;
		int h;
};

#endif