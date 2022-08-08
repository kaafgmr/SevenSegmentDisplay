#include "NoEntiendo.hpp"
#include "SevenSegments.hpp"
#include <iostream>
#include <vector>

std::vector<Segment*> CreateSevenSegments(float x, float y, int w, int h)
{
	std::vector<Segment*> Segments;

	Segments.push_back(new Segment(x - w, y - h - 20 - w * 2 - h/2, w * 2, h * 2));              //1
	Segments.push_back(new Segment(x + w + 5, y - (h / 2) - 5  - w * 2,h * 2, w * 2));           //2
	Segments.push_back(new Segment(x + w + 5, y + (h / 2) + 5, h * 2, w * 2));                   //3
	Segments.push_back(new Segment(x - w, y + (h / 2) + 5 + (w * 2) + 5, w * 2, h * 2));         //4
	Segments.push_back(new Segment(x - (h * 2) - w - 5, y + (h / 2) + 5, h * 2, w * 2));         //5
	Segments.push_back(new Segment(x - (h * 2) - w - 5, y - (h / 2) - 5 - w * 2, h * 2, w * 2)); //6
	Segments.push_back(new Segment(x - w, y - h, w * 2, h * 2));                                 //7

	return Segments;
}

void main()
{
	NOE_Inicia();

	int width = 130;
	int height = 20;
	float t = 0;
	std::vector<Segment*> SevenSegments = CreateSevenSegments(NOE_ObtenAnchoPantalla() / 2, NOE_ObtenAltoPantalla() / 2, width / 2, height / 2);
	std::vector<int> numbersIB = { 0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B };
	std::vector<int> NumberToDisplay;
	
	while(!NOE_ObtenTeclaPulsada(NOE_TECLA_ESCAPE))
	{
		NOE_Actualiza();

		t += NOE_ObtenTiempoDesdeActualizacion() / 1000.0f;
		int number = (int)t % 10;

		NumberToDisplay.clear();
		for (int i = 6; i >= 0; i--)
		{
			int test = ((numbersIB[number] >> i) & 1);

			NumberToDisplay.push_back(test);
		}


		for (int i = 0; i < SevenSegments.size(); i++)
		{
			SevenSegments[i]->changeState(NumberToDisplay[i]);
		}
		
		NOE_LimpiaPantalla(0, 0, 0);


		for (int i = 0; i < SevenSegments.size(); i++)
		{
			SevenSegments[i]->Draw();
		}

		NOE_MuestraPantalla();
	}
	
	NOE_Finaliza();
}