#include "logger.h"

void saveLog(bool** matrix, config conf, int n_it){
    char fname[20];
    snprintf(fname, 20, "log/log_%d%s", n_it, ".txt");
    FILE *file = fopen(fname, "w");
    fprintf(file, "%d %d\n", conf->row, conf->col);
    for(int i = 1; i <= conf->row; i++){
        for(int j = 1; j <= conf->col; j++)
            fprintf(file, "%d ", matrix[i][j]);
        fprintf(file, "\n");
    }
    fclose(file);
}

bool** loadLog(bool** matrix, char* fname, config conf){
    FILE* file = fopen(fname, "r");
    printf("KOKOKO");
    for(int i = 1; i <= conf->row; i++)
        for(int j = 1; j <= conf->col; j++){
            fscanf(file, "%d", &matrix[i][j]);
            printf("%d\n", matrix[i][j]);
        }
    return matrix;
}

void removeOldLog(){
    int i = 0;
    char fname[20];
    do{
        snprintf(fname, 20, "log/log_%d%s", i, ".txt");
        i++;
    }while(remove(fname) == 0);
}