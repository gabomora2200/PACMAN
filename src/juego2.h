#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace sf;

/*
 * @file juego2.hpp
 *
 * @author Gabriel Araya Mora
 * @author Ignacio Montenegro Quesada
 * @author Andres Arias Campos
 *
 * @version 0.1
 *
 * @copyright
 * Copyright (C) Parallax, Inc. 2012. All Rights MIT Licensed.
 *
 * @brief This program was created for the open platfom curse project. Its main function is to implement a pacman game in which the user is able to earn points by eating pellets and is able to die if touched by the ghosts.
*/

/**
 * @brief This function "dibujarMapa" is intended to draw the map in witch the user will play by recognizing " 1 " in the main matrix used for the map. 
 *
 */
void dibujarMapa(int C, int F, RenderWindow &window, int mapa[23][30],int color);


/**
 * @brief This function "dibujarComida" is intended to draw the fruit that the user will eat to earn points when playing by recognizing " 2 " and then changing them for " 0 " in the main matriz used for the map. 
 *
 */
void dibujarComida(int C, int F, RenderWindow &window, int mapa [23][30]);

/**
 * @brief This function "dibujarFantasma" is intended to draw the ghosts that will persue the user and kill Pac-Man. 
 *
 */
void dibujarFantasma(int enemyCount, RenderWindow &window, int x, int y,int i);

/**
 * @brief This function "dibujarPac" is intended to draw the main character Pac-Man. 
 *
 */
void dibujarPac(int x, int y, RenderWindow &window);

/**
 * @brief This function "gameOver" is intended to draw the game over once the game is either won or lost.
 *
 */
void gameOver(RenderWindow &Window, RenderWindow &window, int score);

/**
 * @brief This function "scoreVidas" is intended to draw the score and the lives. 
 *
 */
void scoreVidas(string str, string str1, RenderWindow &window);

/**
 * @brief This function "juegoA" is intended to create the game using Mapa1. 
 *
 */
void juegoA(RenderWindow &window);

/**
 * @brief This function "juegoA" is intended to create the game using Mapa2. 
 *
 */
void juegoB(RenderWindow &window);
void Puntajes(int score);
void Scores(RenderWindow &window);

/**
 * TERMS OF USE: MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
