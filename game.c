#include "game.h"

void matGen(bool **matrix, config conf){
    srand(time(NULL));
    for (int i = 0 ; i < conf->row; i++) {
       matrix[i] = (bool *)malloc(conf->col * sizeof(bool));
        for (int j = 0; j < conf->col; j++)
            matrix[i][j] = rand() % 2;
    }
}

void Neumann(bool **matrix, config conf){

    for (int i = 0 ; i < conf->row; i++){
        for (int j = 0; j < conf->col; j++)
            printf("%d ", matrix[i][j]);
            printf("\n");
    }
}