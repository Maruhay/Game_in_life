#include "logger.h"

#define FNAME "log.txt"

void saveLog(bool** matrix, config conf, int n_it){
    FILE *file;
    if(n_it > 0)
        file = fopen(FNAME, "a");
    else{
        file = fopen(FNAME, "w");
        fprintf(file, "%d %d %d\n", conf->row, conf->col, conf->n_it);
    }
    fprintf(file, "%d\n", n_it);
    for(int i = 1; i <= conf->row; i++){
        for(int j = 1; j <= conf->col; j++)
            fprintf(file, "%d ", matrix[i][j]);
        fprintf(file, "\n");
    }
    fclose(file);
}

bool** loadLog(char* fname, config conf){
    FILE *file = fopen(fname, "r");
    int n_it;
    fscanf(file, "%d%d%d", &conf->row, &conf->col, &n_it);
    printf("SAVE FILE: %d %d %d\n", conf->row, conf->col, n_it);

    bool **matrix = (bool **)malloc(conf->row * sizeof(bool *));
    for (int i = 1; i <= conf->row; i++)
       matrix[i] = (bool *)malloc(conf->col * sizeof(bool));
       
    fclose(file);
    return matrix;
}