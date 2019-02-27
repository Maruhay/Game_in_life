#include "config.h"
#include "game.h"
#include "stdbool.h"
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

#include <png.h>

void write_png_file();

void process_file(bool** , config conf);

void saveLog(bool**, config , int );

bool** loadLog(char* , config );

void removeOldLog();