//Структура конфигурации: размер сетки, кол-во итераций, тип соседства, тип вывода
//Чтение из файла конфигураций
//Ф-я установки конфигураций по-умолчанию
#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "stdbool.h"
typedef struct Config{
    int col;
    int row;
    int n_it;
    char rule;
    bool out;
} *config;

void defaultConfig(config conf);


#endif