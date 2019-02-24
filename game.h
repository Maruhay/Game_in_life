//Главная функция, которую вызывает main
//2 функции двух видов соседств
//Вывод в консоль
//Функции для либо рандомного заполнения сетки, либо чтение из сейва

#ifndef _GAME_H_
#define _GAME_H_

#include "stdbool.h"
#include "config.h"

void matGen (bool ** , config conf);
void Neumann (bool ** , config conf);
void Moore (bool ** , config conf);

#endif