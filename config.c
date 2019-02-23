#include "config.h"

void defaultConfig(config conf){
    conf->col = 7;
    conf->row = 7;
    conf->n_it = 7;
    conf->rule = 'N';
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