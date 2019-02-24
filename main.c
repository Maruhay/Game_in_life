#include <stdio.h>
#include <stdlib.h>
#include "config.h"

//Живая - \u25d9
//Мёртвая - \u25cb

int main(int argc, char* argv[]){
        config conf = malloc(sizeof conf);
        if(argc < 2){
                chooseConfig(conf);
        }
        else ;//Иначе чтение сейва и снова надо спросить про конфигурацию
        bool **matrix = (bool **)malloc(conf->row * sizeof(bool *));
        matGen(matrix, conf);
        Neumann(matrix, conf);
        return 0;
}