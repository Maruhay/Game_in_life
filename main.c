
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

//Живая - \u25d9
//Мёртвая - \u25cb

int main(int argc, char* argv[]){
        config conf = malloc(sizeof conf);
        userConfig(conf);
        bool **matrix = (bool **)malloc(conf->row * sizeof(bool *));
        for (int i = 1 ; i <= conf->row; i++)
                matrix[i] = (bool *)malloc(conf->col * sizeof(bool));
        matGen(matrix, conf);
        Neumann(matrix, conf);
        for (int i = 1 ; i <= conf->row; i++) {
                for (int j = 1; j <= conf->col; j++)
                        printf("%d ", matrix[i][j]);
                printf("\n");
    }
        return 0;
}