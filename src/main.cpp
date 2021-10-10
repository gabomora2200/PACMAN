#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "juego2.h"
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace sf;

const int M = 23;
const int N = 20;
int tamanos = 18;

int main()
{
	
	RenderWindow window(VideoMode(N * tamanos, M * tamanos), "PAC - MAN!");
	window.setFramerateLimit(60);
	//TEXTURAS//

	Texture MiPacMan;
	MiPacMan.loadFromFile("photos/background.jpg");
	Sprite sTile(MiPacMan);
	sTile.setColor(Color(255, 255, 255, 64));

	//FUENTES///

	Font font1;
	font1.loadFromFile("fuentes/Roboto-Light.ttf");
	sf::Text text;
	text.setFont(font1);
	text.setString("PAC++ MAN");
	text.setPosition(5 * 18, 1 * 18);

	Font font3;
	font3.loadFromFile("fuentes/Roboto-Light.ttf");
	sf::Text text2;
	text2.setFont(font3);
	text2.setString("Mapa 1 (A) ");
	text2.setPosition(5 * 18, 8 * 18);

	Font font2;
	font2.loadFromFile("fuentes/Roboto-Light.ttf");
	sf::Text text3;
	text3.setFont(font2);
	text3.setString("Mapa 2 (B) ");
	text3.setPosition(5 * 18, 10 * 18);

	Font font4;
	font4.loadFromFile("fuentes/Roboto-Light.ttf");
	sf::Text text4;
	text4.setFont(font4);
	text4.setString("Exit!!! (ESC) ");
	text4.setPosition(5 * 18, 20 * 18);

	Font font5;
	font5.loadFromFile("fuentes/Roboto-Light.ttf");
	sf::Text text5;
	text5.setFont(font4);
	text5.setString("SCORE (C) ");
	text5.setPosition(5 * 18, 12 * 18);

	// Sonidos //

	

	//////////////////////////////////////////////////////////////

	while (window.isOpen())
	{

		Event e;

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			if (e.type == Event::KeyPressed)
				if (e.key.code == Keyboard::Escape)

					if (Keyboard::isKeyPressed(Keyboard::Escape))
						window.close();

			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				juegoA(window);
			};
			if (Keyboard::isKeyPressed(Keyboard::B))
			{
				juegoB(window);
			};
			if (Keyboard::isKeyPressed(Keyboard::C))
			{
				Scores(window);
			}
		}

		window.clear();
		
		window.draw(sTile);
		window.draw(text);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.display();
	}

	return 0;
}
