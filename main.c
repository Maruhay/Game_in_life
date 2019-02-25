#include "config.h"

int main(int argc, char* argv[]){
        config conf = malloc(sizeof conf);
        printf("\e[1;1H\e[2J");
        if(argc < 2)
                chooseConfig(conf);
        else ;
        //Иначе чтение сейва и снова надо спросить про конфигурацию
        startGame(conf, argv[1]);
        return 0;
}