#include "config.h"

int main(int argc, char* argv[]){
        config conf = malloc(sizeof conf);
        printf("\e[1;1H\e[2J");
        if(argc > 1){
                FILE *file = fopen(argv[1], "r");
                if(file == NULL){
                        printf("File %s not found. Matrix will be generated random\n", argv[1]);
                        chooseConfig(conf, true);
                        startGame(conf, NULL);
                }
                fclose(file);
        }
        chooseConfig(conf, false);
        startGame(conf, argv[1]);
        return 0;
}