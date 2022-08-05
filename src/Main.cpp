#include "NoEntiendo.hpp"
#include "SevenSegments.hpp"
#include <iostream>
#include <vector>

std::vector<Segment*> CreateSevenSegments(float x, float y, int w, int h)
{
	std::vector<Segment*> Segments;

	Segments.push_back(new Segment(x - w, y - h - 20 - w * 2 - h/2, w * 2, h * 2));     //1
	Segments.push_back(new Segment(x + w + 5, y - (h / 2) - 5  - w * 2,h * 2, w * 2));  //2
	Segments.push_back(new Segment(x + w + 5, y + (h / 2) + 5, h * 2, w * 2));          //3
	Segments.push_back(new Segment(x - w, y + (h / 2) + 5 + (w * 2) + 5, w * 2, h * 2));//4
	Segments.push_back(new Segment(x - (h * 2) - w - 5, y + (h / 2) + 5, h * 2, w * 2));//5
	Segments.push_back(new Segment(x - (h * 2) - w - 5, y - (h / 2) - 5 - w * 2, h * 2, w * 2)); //6
	Segments.push_back(new Segment(x - w, y - h, w * 2, h * 2));                        //7

	return Segments;
}

void main()
{
	NOE_Inicia();

	std::vector<Segment*> SevenSegments;
	int width = 130;
	int height = 20;

	SevenSegments = CreateSevenSegments(NOE_ObtenAnchoPantalla() / 2, NOE_ObtenAltoPantalla() / 2, width / 2, height / 2);
	
	while(!NOE_ObtenTeclaPulsada(NOE_TECLA_ESCAPE))
	{
	
		NOE_Actualiza();
		
		if (NOE_ObtenTeclaAbajo(NOE_TECLA_W))
		{
			for (int i = 0; i < SevenSegments.size(); i++)
			{
				SevenSegments[i]->changeState();
			}
		}

		
		NOE_LimpiaPantalla(255 / 2, 255 / 2, 255 / 2);


		for (int i = 0; i < SevenSegments.size(); i++)
		{
			SevenSegments[i]->Draw();
		}

		NOE_MuestraPantalla();
	}
	
	NOE_Finaliza();
}