#include "stdbool.h"
#include "config.h"
#include <string.h>

void saveLog(bool**, config , int );

bool** loadLog(char* , config );

void removeOldLog();