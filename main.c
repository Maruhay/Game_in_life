#include <stdio.h>
#include <stdlib.h>
#include "config.h"

//Живая - \u25d9
//Мёртвая - \u25cb

int main(int argc, char* argv[]){
        config conf = malloc(sizeof conf);
        if(argc < 2){
                char temp;
                bool isOk;
                do{
                        printf("Do you want to setup default configuration? (y/n)\n");
                        scanf(" %c", &temp);
                        if(temp == 'y'){
                                defaultConfig(conf);
                                isOk = true;
                        }
                        else if(temp == 'n'){
                                userConfig(conf);
                                isOk = true;
                        }
                        else{
                                printf("Please type y or n\n");
                                isOk = false;
                        }
                }while (isOk == false);    
        }
        else fileConfig(conf, argv[1]);
        bool **matrix = (bool **)malloc(conf->row * sizeof(bool *));
        matGen(matrix, conf);
        Neumann(matrix, conf);
        return 0;
}