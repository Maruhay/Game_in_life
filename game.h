//Главная функция, которую вызывает main
//2 функции двух видов соседств
//Вывод в консоль
<<<<<<< HEAD
//Функции для либо рандомного заполнения сетки, либо чтение из сейва
=======
//Функции для либо рандомного заполнения сетки, либо чтение из сейва
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "stdbool.h"
#include "config.h"

void matGen(bool** , config );

bool cmpMat(bool** , bool** , config );

bool** Neumann(bool** , config );

bool** Moore(bool** , config );

void clrscr();

void printMatrix(bool** , config );

void startGame(config , char* );
>>>>>>> Maruhay
