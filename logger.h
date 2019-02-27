//Сохранение истории ходов
//Загрузка сейва
//Формирование png

#include "stdbool.h"
#include "config.h"
#include <string.h>

void saveLog(bool**, config , int );

bool** loadLog(bool**, char* , config );

void removeOldLog();