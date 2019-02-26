//Сохранение истории ходов
//Загрузка сейва
//Формирование png

#include "stdbool.h"
#include "config.h"

int n_save;

void saveLog(bool**, config conf, int n_it);

bool** loadLog(char* fname, config conf);