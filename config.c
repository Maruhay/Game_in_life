#include "config.h"

void defaultConfig(config conf){
    conf->col = 15;
    conf->row = 15;
    conf->n_it = 100;
    conf->rule = 'M';
    conf->out = 0; //'0' - "0 or 1"; '1' - "\u25d9 or \u25cb"
}

void userConfig(config conf){
    //
    //Проверка на правильность введённых данных
    //
    printf("Number of rows: ");
    scanf("%d", &conf->row);
    printf("Number of columns: ");
    scanf("%d", &conf->col);
    printf("Number of iterations: ");
    scanf("%d", &conf->n_it);
    printf("Choose the rules: ");
    scanf(" %c", &conf->rule);
    printf("Choose outpoot method: ");
    scanf("%d", &conf->out);
}

void chooseConfig(config conf){
    char temp;
    bool isOk;
    do{
        printf("Do you want to load configurations from file? (y/n)\n");
        scanf(" %c", &temp);
        if(temp == 'y'){
            isOk = true;
            char fname[20];
            printf("Please enter name of file: ");
            scanf(" %s", fname);
            printf("FILE: %s\n ", fname);
            fileConfig(conf, fname);
        }
        else if (temp == 'n'){
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
            else{
                printf("Please type y or n\n");
                isOk = false;
        }
                        
    }while (isOk == false);
}

void fileConfig(config conf, char* fname){
    FILE *file;
    bool isOk = true; 
    if(file = fopen(fname, "r"))
        file = fopen(fname, "r");
    else{
        printf("File %s not found. Configurations are setuped as default\n", fname);
        defaultConfig(conf);
        return;
    }
    isOk = fscanf(file, "%d%d%d%c%d", &conf->col, &conf->row, &conf->n_it, &conf->rule, &conf->out);
    if(!isOk){
        printf("ERROR! Bad format of configuration's file. Configurations are setuped as default\n");
        defaultConfig(conf);
        return;
    }
    //
    //Проверка правильности введённых данных
    //
}