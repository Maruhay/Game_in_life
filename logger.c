#include "logger.h"

#define FNAME "log.txt"

void saveLog(bool** matrix, config conf, int n_it){
    FILE *file;
    if(n_it > 0)
        file = fopen(FNAME, "a");
    else{
        n_save = 0;
        file = fopen(FNAME, "w");
        fprintf(file, "%d %d %d\n", conf->row, conf->col, conf->n_it);
    }
    fprintf(file, "%d\n", n_it);
    for(int i = 1; i <= conf->row; i++){
        for(int j = 1; j <= conf->col; j++)
            fprintf(file, "%d ", matrix[i][j]);
        fprintf(file, "\n");
    }
    n_save++;
    fclose(file);
}