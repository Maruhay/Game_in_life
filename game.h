//Главная функция, которую вызывает main
//2 функции двух видов соседств
//Вывод в консоль
//Функции для либо рандомного заполнения сетки, либо чтение из сейва
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "stdbool.h"
#include "config.h"

void matGen(bool ** , config conf);

bool cmpMat(bool** , bool** , config conf);

bool** Neumann(bool ** , config conf);

bool** Moore(bool ** , config conf);

void printMatrix(bool** matrix, config conf);

void startGame(config conf, char* saveName);