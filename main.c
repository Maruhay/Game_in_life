
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

//Живая - \u25d9
//Мёртвая - \u25cb

int main(int argc, char* argv[]){
        config conf = malloc(sizeof conf);
        userConfig(conf);
        bool **matrix = (bool **)malloc(conf->row * sizeof(bool *));
        matGen(matrix, conf);
        Neumann(matrix, conf);
        return 0;
}