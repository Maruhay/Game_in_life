#include <stdio.h>
#include <stdlib.h>
#include "config.h"

//Живая - \u25d9
//Мёртвая - \u25cb

int main(int argc, char* argv[]){
        config conf = malloc(sizeof conf);
        defaultConfig(conf);
        
        return 0;
}