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
int tamano = 18;

int mapa[M][N] = {
	//Pared izquierda
	{1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
	{1, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 0, 1, 2, 2, 2, 2, 2, 1},
	{1, 2, 1, 1, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 1},
	{1, 2, 1, 2, 2, 2, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 2, 2, 1},
	{1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 1, 2, 1, 2, 1},
	{1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 2, 1},
	{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1}, //ABAJO
	{1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 2, 2, 2, 1},
	{1, 2, 1, 2, 2, 2, 1, 2, 0, 0, 0, 1, 2, 2, 2, 2, 2, 1, 2, 1},
	{1, 2, 1, 1, 1, 2, 1, 2, 0, 0, 0, 1, 0, 1, 1, 2, 1, 1, 2, 1},
	{1, 2, 1, 1, 1, 2, 1, 2, 0, 0, 0, 1, 2, 1, 1, 2, 1, 1, 2, 1},
	{1, 2, 1, 2, 2, 2, 1, 2, 0, 0, 0, 1, 2, 2, 2, 2, 2, 1, 2, 1},
	{1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 2, 2, 2, 1},
	{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1},
	{1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 2, 1},
	{1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 1, 2, 1, 2, 1},
	{1, 2, 1, 2, 2, 2, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 2, 2, 1},
	{1, 2, 1, 1, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 1},
	{1, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 0, 1, 2, 2, 2, 2, 2, 1},
	{1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1}

};

int mapa1[M][N] = {
	//Pared izquierda
	{1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1},
	{1, 3, 2, 3, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 2, 2, 3, 1},
	{1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 3, 1, 2, 2, 2, 2, 2, 1, 2, 1},
	{1, 2, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1},
	{1, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1},
	{1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1},
	{1, 3, 1, 3, 2, 2, 2, 2, 0, 2, 2, 2, 2, 3, 2, 2, 3, 1, 3, 1}, //ABAJO
	{1, 2, 1, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2, 1, 1, 2, 1, 2, 1},
	{1, 2, 1, 3, 2, 2, 2, 1, 0, 0, 0, 0, 1, 2, 1, 2, 2, 1, 2, 1},
	{1, 2, 1, 1, 1, 1, 2, 1, 0, 0, 0, 0, 1, 2, 1, 2, 1, 1, 2, 1},
	{1, 2, 1, 1, 1, 1, 2, 1, 0, 0, 0, 0, 1, 2, 1, 2, 1, 1, 2, 1},
	{1, 2, 1, 2, 3, 2, 2, 1, 0, 0, 0, 0, 1, 2, 1, 2, 2, 1, 2, 1},
	{1, 2, 1, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2, 1, 1, 2, 1, 2, 1},
	{1, 3, 1, 3, 2, 2, 2, 2, 0, 2, 2, 2, 2, 3, 2, 2, 3, 1, 3, 1},
	{1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1},
	{1, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1},
	{1, 2, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1},
	{1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 3, 1, 2, 2, 2, 2, 2, 1, 2, 1},
	{1, 3, 2, 3, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 2, 2, 3, 1},
	{1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1}

};

class Enemy
{
public:
	int x, y, fdir;

	Enemy()
	{
		x = y = 9 * tamano;
		fdir = 2;
	}

	void move(int mapa[23][20])
	{
		if (mapa[x / tamano][y / tamano] == 3)
		{
			fdir == 1;
		}
		if (fdir == 0)
		{
			if (mapa[(x / tamano) + 1][(y / tamano)] != 1)
			{
				x += 18;
			}
			else
			{
				fdir = rand() % 4;
			}
		}
		if (fdir == 1)
		{
			if (mapa[(x / tamano) - 1][(y / tamano)] != 1)
			{
				x -= 18;
			}
			else
			{
				fdir = rand() % 4;
			}
		}
		if (fdir == 2)
		{
			if (mapa[(x / tamano)][(y / tamano) + 1] != 1)
			{
				y += 18;
			}
			else
			{
				fdir = rand() % 4;
			}
		}
		if (fdir == 3)
		{
			if (mapa[(x / tamano)][(y / tamano) - 1] != 1)
			{
				y -= 18;
			}
			else
			{
				fdir = rand() % 4;
			}
		}
		if (mapa[x / tamano][y / tamano] == 0 || mapa[x / tamano][y / tamano] == 2)
		{
			if (x / tamano >= 19 && fdir == 0)
			{
				x = 2;
			}
			else if ((x / tamano) < 0 && fdir == 1)
			{
				x = 19 * 18;
			}
			else if (y / tamano > M)
			{
				y = 0;
			}
			else if (y / tamano < 0)
			{
				y = M - 1;
			}
		}
	}
};

void dibujarMapa(int C, int F, RenderWindow &window, int mapa[23][20],int color)
{
	Texture MiLaberinto;
	MiLaberinto.loadFromFile("photos/tiles.jpeg");
	Sprite sMap(MiLaberinto);

	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < F; j++)
		{
			if (mapa[i][j] == 1)
			{
				sMap.setTextureRect(IntRect(18 * color, 0, tamano, tamano));
				sMap.setPosition(i * 18, j * 18);
				window.draw(sMap);
			}
		}
	}
}

void dibujarComida(int C, int F, RenderWindow &window, int mapa[23][20])
{
	Texture MiLaberinto;
	MiLaberinto.loadFromFile("photos/tiles.jpeg");
	Sprite sMap(MiLaberinto);

	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < F; j++)
		{
			if (mapa[i][j] == 2)
			{
				sMap.setTextureRect(IntRect(72, 3, 6, 6));
				sMap.setPosition(i * 18, j * 18);
				window.draw(sMap);
			}
		}
	}
}

void dibujarFantasma(int enemyCount, RenderWindow &window, int x, int y, int i)
{
	Texture MiFantasma;
	MiFantasma.loadFromFile("photos/tiles.jpeg");
	Sprite sFtsm(MiFantasma);

	sFtsm.setTextureRect(IntRect(18 * i, 0, tamano, tamano));
	sFtsm.setPosition((x), (y));
	window.draw(sFtsm);
}


void dibujarPac(int x, int y, RenderWindow &window)
{
	Texture MiPacMan;
	MiPacMan.loadFromFile("photos/tiles.jpeg");
	Sprite sTile(MiPacMan);
	sTile.setTextureRect(IntRect(18 + 18 + 18 + 18, 0, tamano, tamano));
	sTile.setColor(Color(255, 255, 255, 200));
	sTile.setPosition(x * tamano, y * tamano);
	window.draw(sTile);
}

void gameOver(RenderWindow &Window, RenderWindow &window, int score)
{
	Puntajes(score);
	Texture GameOver;
	GameOver.loadFromFile("photos/gameover.png");
	Sprite sGame1(GameOver);

	Texture GameOver1;
	GameOver.loadFromFile("photos/gameover.png");
	Sprite sGame2(GameOver);

	sGame1.setTextureRect(IntRect(0, 0, 270, 200));
	sGame1.setPosition(1 * 18, 1 * 18);
	sGame2.setTextureRect(IntRect(270, 0, 500, 200));
	sGame2.setPosition(5 * 18, 5 * 18);
	window.draw(sGame1);
	window.draw(sGame2);
}

void Puntajes(int score)
{
	ofstream aux;
	ifstream lectura;
	int encontrado = 0;
	string numero;
	char lugar[5], puntaje[5], puntos[5];
	int points, conteo = 0;
	aux.open("auxiliar.txt",ios::out);
	lectura.open("Score.txt",ios::in);
	if(aux.is_open() && lectura.is_open())
	{
		while(!lectura.eof() && conteo != 5)
		{
			string linea;
			getline(lectura, linea);
			vector<string> strs;
			boost::split(strs,linea,boost::is_any_of(" "));

			if(strs.size() ==2)
			{
				strcpy(lugar, strs[0].c_str());
				strcpy(puntaje, strs[1].c_str());
				points = stoi(strs[1]);
				numero = to_string(score);
				strcpy(puntos, numero.c_str());
			}

			if(score > points && encontrado == 0)
			{
				aux<<lugar<<" "<<puntos<<endl;
				encontrado += 1;
			}
			else
			{
				aux<<lugar<<" "<<puntaje<<endl;
			}
			conteo += 1;
		}
	}

	aux.close();
	lectura.close();
	remove("Score.txt");
	rename("auxiliar.txt","Score.txt");
	return;
}

void scoreVidas(string str, string str1, RenderWindow &window)
{
	Font font1;
	font1.loadFromFile("fuentes/Roboto-Regular.ttf");
	sf::Text text;
	text.setFont(font1);
	text.setString("SCORE: ");
	text.setPosition(1 * 18, 20 * 18);

	Font font2;
	font2.loadFromFile("fuentes/Roboto-Regular.ttf");
	sf::Text text1;
	text1.setFont(font2);
	text1.setPosition(7 * 18, 20 * 18);

	Font font3;
	font3.loadFromFile("fuentes/Roboto-Regular.ttf");
	sf::Text text2;
	text2.setFont(font3);
	text2.setString("VIDAS: ");
	text2.setPosition(12 * 18, 20 * 18);

	Font font4;
	font4.loadFromFile("fuentes/Roboto-Regular.ttf");
	sf::Text text3;
	text3.setFont(font3);
	text3.setPosition(18 * 18, 20 * 18);

	text3.setString(str1);
	text1.setString(str);
	window.draw(text1);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
}

void juegoA(RenderWindow &window)
{
	srand(time(0));

	/////////////////Sonidos//////////////////////////

	SoundBuffer buffer;
	buffer.loadFromFile("sonidos/cancion_Inicio.wav");
	Sound sound;
	sound.setBuffer(buffer);

	SoundBuffer buffer1;
	buffer1.loadFromFile("sonidos/saminaminaeheh.wav");
	Sound sound1;
	sound1.setBuffer(buffer1);

	SoundBuffer buffer2;
	buffer2.loadFromFile("sonidos/sonidoBolaGrande.wav");
	Sound sound2;
	sound2.setBuffer(buffer2);

	SoundBuffer buffer3;
	buffer3.loadFromFile("sonidos/sonido_muerte.wav");
	Sound sound3;
	sound3.setBuffer(buffer3);

	SoundBuffer buffer4;
	buffer4.loadFromFile("sonidospacman_eatghost.wav");
	Sound sound4;
	sound4.setBuffer(buffer4);

	SoundBuffer buffer5;
	buffer5.loadFromFile("sonidos/pacman_eatfruit.wav");
	Sound sound5;
	sound5.setBuffer(buffer5);

	SoundBuffer victory;
	victory.loadFromFile("sonidos/victory.wav");
	Sound sound6;
	sound6.setBuffer(victory);

	//////////////////////////////////////////////

	int enemyCount = 5;
	Enemy fantasma[enemyCount];
	int score = 0;
	int pellets = 0;
	int vidas = 3;
	bool game = true;
	int x = 9, y = 12, dx = 0, dy = 0;
	float timer = 0;
	float delay = 0.25;
	Clock clock;

	if (window.isOpen())
	{
		sound.play();
	}

	while (window.isOpen())
	{
		float time1 = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time1;
		Event e;

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			if (e.type == Event::KeyPressed)
				if (e.key.code == Keyboard::Escape)

					for (int i = 1; i < M - 1; i++)
					{
						for (int j = 1; j < N - 1; j++)
						{
							x += 1;
							y += 1;
						}
					}
		}

		////////// entradas por teclado (flechas) ///////////////////

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			dx = -1;
			dy = 0;
		};
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			dx = 1;
			dy = 0;
		};
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			dx = 0;
			dy = -1;
		};
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			dx = 0;
			dy = 1;
		};

		if (!game)
			continue;

		////////////////////////////////////////////////////////////

		if (timer > delay)
		{
			x += dx;
			y += dy;

			// set de ifs que manejan el movimiento, ponen paredes y acota el laberinto.
			if (mapa[x][y] == 0 or mapa[x][y] == 2 or mapa[x][y] == 3)
			{
				if (x >= 19)
					x = 1;
				if (x <= 0)
					x = N - 1;
				if (y > M)
					y = 0;
				if (y < 0)
					y = M - 1;
			}
			else
			{
				x = x - dx;
				y = y - dy;
			}

			if (mapa[x][y] == 2)
			{
				mapa[x][y] = 0;
				sound1.play();
				score += 5;
				pellets += 1;
				//printf("%d\n", score);
			}
			if (pellets == 100)
			{
				sound6.play();
				game = false;
			}
			for (int i = 0; i < enemyCount; i++)
			{
				if (x == fantasma[i].x / tamano and y == fantasma[i].y / tamano)
				{
					vidas -= 1;
					x = 9, y = 12, dx = 0, dy = 0;
					fantasma[i].x = 9 * tamano;
					fantasma[i].y = 9 * tamano;
					fantasma[i].fdir = rand() % 4;
					//printf("%d\n", vidas);
					if (vidas == 0)
					{
						game = false;
						sound3.play();
					}
				}
			}
			for (int i = 0; i < enemyCount; i++)
			{
				fantasma[i].move(mapa);
			}

			timer = 0;
		}

		string str = to_string(score);
		string str1 = to_string(vidas);

		////////////// Pantalla /////////////////

		window.clear();
		dibujarMapa(M, N, window,mapa,6);
		dibujarComida(M, N, window,mapa);
		for (int i = 0; i < enemyCount; i++)
		{
			dibujarFantasma(enemyCount, window, fantasma[i].x, fantasma[i].y, i);
		}
		dibujarPac(x, y, window);
		if (!game)
		{
			gameOver(window, window, score);
		}
		scoreVidas(str, str1, window);

		window.display();

	} //cierra while superior

	return;
}

void juegoB(RenderWindow &window)
{
	srand(time(0));

	/////////////////Sonidos//////////////////////////

	SoundBuffer buffer;
	buffer.loadFromFile("sonidos/cancion_Inicio.wav");
	Sound sound;
	sound.setBuffer(buffer);

	SoundBuffer buffer1;
	buffer1.loadFromFile("sonidos/saminaminaeheh.wav");
	Sound sound1;
	sound1.setBuffer(buffer1);

	SoundBuffer buffer2;
	buffer2.loadFromFile("sonidos/sonidoBolaGrande.wav");
	Sound sound2;
	sound2.setBuffer(buffer2);

	SoundBuffer buffer3;
	buffer3.loadFromFile("sonidos/sonido_muerte.wav");
	Sound sound3;
	sound3.setBuffer(buffer3);

	SoundBuffer buffer4;
	buffer4.loadFromFile("sonidospacman_eatghost.wav");
	Sound sound4;
	sound4.setBuffer(buffer4);

	SoundBuffer buffer5;
	buffer5.loadFromFile("sonidos/pacman_eatfruit.wav");
	Sound sound5;
	sound5.setBuffer(buffer5);

	SoundBuffer victory;
	victory.loadFromFile("sonidos/victory.wav");
	Sound sound6;
	sound6.setBuffer(victory);

	//////////////////////////////////////////////

	int enemyCount = 4;
	Enemy fantasma1[enemyCount];
	int score = 0;
	int pellets = 0;
	int vidas = 3;
	bool game = true;
	int x = 9, y = 13, dx = 0, dy = 0;
	float timer = 0;
	float delay = 0.25;
	Clock clock;

	if (window.isOpen())
	{
		sound.play();
	}

	while (window.isOpen())
	{
		float time1 = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time1;
		Event e;

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			if (e.type == Event::KeyPressed)
				if (e.key.code == Keyboard::Escape)

					for (int i = 1; i < M - 1; i++)
					{
						for (int j = 1; j < N - 1; j++)
						{
							x += 1;
							y += 1;
						}
					}
		}

		////////// entradas por teclado (flechas) ///////////////////

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			dx = -1;
			dy = 0;
		};
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			dx = 1;
			dy = 0;
		};
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			dx = 0;
			dy = -1;
		};
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			dx = 0;
			dy = 1;
		};

		if (!game)
			continue;

		////////////////////////////////////////////////////////////

		if (timer > delay)
		{
			x += dx;
			y += dy;

			// set de ifs que manejan el movimiento, ponen paredes y acota el laberinto.
			if (mapa1[x][y] == 0 or mapa1[x][y] == 2 or mapa1[x][y] == 3)
			{
				if (x >= 19)
					x = 1;
				if (x <= 0)
					x = N - 1;
				if (y > M)
					y = 0;
				if (y < 0)
					y = M - 1;
			}
			else
			{
				x = x - dx;
				y = y - dy;
			}

			if (mapa1[x][y] == 2)
			{
				mapa1[x][y] = 0;
				sound1.play();
				score += 5;
				pellets += 1;
				//printf("%d\n", score);
			}
			if (pellets == 100)
			{
				sound6.play();
				game = false;
			}
			for (int i = 0; i < enemyCount; i++)
			{
				if (x == fantasma1[i].x / tamano and y == fantasma1[i].y / tamano)
				{
					vidas -= 1;
					x = 9, y = 13, dx = 0, dy = 0;
					fantasma1[i].x = 9 * tamano;
					fantasma1[i].y = 9 * tamano;
					fantasma1[i].fdir = rand() % 4;
					//printf("%d\n", vidas);
					if (vidas == 0)
					{
						game = false;
						sound3.play();
					}
				}
			}
			for (int i = 0; i < enemyCount; i++)
			{
				fantasma1[i].move(mapa1);
			}

			timer = 0;
		}

		string str = to_string(score);
		string str1 = to_string(vidas);

		////////////// Pantalla /////////////////

		window.clear();
		dibujarMapa(M, N, window,mapa1,5);
		dibujarComida(M, N, window,mapa1);
		for (int i = 0; i < enemyCount; i++)
		{
			dibujarFantasma(enemyCount, window, fantasma1[i].x, fantasma1[i].y, i);
		}
		dibujarPac(x, y, window);
		if (!game)
		{
			gameOver(window, window, score);
		}
		scoreVidas(str, str1, window);

		window.display();

	} //cierra while superior

	return;
}

void Scores(RenderWindow &window)
{
	ifstream lectura;
	int conteo = 0;
	string puntajes = "";
	lectura.open("Score.txt",ios::in);
	if(lectura.is_open())
	{
		while(!lectura.eof() && conteo != 5)
		{
			string linea;
			getline(lectura, linea);
			vector<string> strs;
			boost::split(strs,linea,boost::is_any_of(" "));

			if(strs.size() ==2)
			{
			puntajes += strs[1];
			puntajes += " ";
			}
			conteo += 1;
		}
	}

	lectura.close();
	string puntaje1(puntajes, 0, 3), puntaje2(puntajes, 4, 3), puntaje3(puntajes, 8, 3), puntaje4(puntajes, 12, 3), puntaje5(puntajes, 16, 3);
	
	Font font1;
	font1.loadFromFile("fuentes/Roboto-Light.ttf");
	sf::Text text;
	text.setFont(font1);
	text.setString("Puntajes mayores: ");
	text.setPosition(4 * 18, 1 * 18);

	Font font3;
	font3.loadFromFile("fuentes/Roboto-Light.ttf");
	sf::Text text2;
	text2.setFont(font3);
	text2.setString("1 - ");
	text2.setPosition(1 * 18, 5 * 18);

	Font font2;
	font2.loadFromFile("fuentes/Roboto-Light.ttf");
	sf::Text text3;
	text3.setFont(font3);
	text3.setString("2 - ");
	text3.setPosition(1 * 18, 8 * 18);

	Font font4;
	font4.loadFromFile("fuentes/Roboto-Light.ttf");
	sf::Text text4;
	text4.setFont(font3);
	text4.setString("3 - ");
	text4.setPosition(1 * 18, 11 * 18);

	Font font5;
	font5.loadFromFile("fuentes/Roboto-Light.ttf");
	sf::Text text5;
	text5.setFont(font3);
	text5.setString("4 - ");
	text5.setPosition(1 * 18, 14 * 18);
	
	Font font6;
	font6.loadFromFile("fuentes/Roboto-Light.ttf");
	sf::Text text6;
	text6.setFont(font3);
	text6.setString("5 - ");
	text6.setPosition(1 * 18, 17 * 18);
	
	Font font7;
	font7.loadFromFile("fuentes/Roboto-Light.ttf");
	sf::Text text7;
	text7.setFont(font3);
	text7.setString(puntaje1);
	text7.setPosition(5 * 18, 5 * 18);
	
	Font font8;
	font8.loadFromFile("fuentes/Roboto-Light.ttf");
	sf::Text text8;
	text8.setFont(font3);
	text8.setString(puntaje2);
	text8.setPosition(5 * 18, 8 * 18);
	
	Font font9;
	font9.loadFromFile("fuentes/Roboto-Light.ttf");
	sf::Text text9;
	text9.setFont(font3);
	text9.setString(puntaje3);
	text9.setPosition(5 * 18, 11 * 18);
	
	Font font10;
	font10.loadFromFile("fuentes/Roboto-Light.ttf");
	sf::Text text10;
	text10.setFont(font3);
	text10.setString(puntaje4);
	text10.setPosition(5 * 18, 14 * 18);
	
	Font font11;
	font11.loadFromFile("fuentes/Roboto-Light.ttf");
	sf::Text text11;
	text11.setFont(font3);
	text11.setString(puntaje5);
	text11.setPosition(5 * 18, 17 * 18);
	


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
		}

		window.clear();
		window.draw(text);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(text8);
		window.draw(text9);
		window.draw(text10);
		window.draw(text11);
		window.display();
	}

}
