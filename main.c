#include "config.h"

int main(int argc, char* argv[]){
        config conf = malloc(sizeof conf);
        clrscr();
        if(argc < 2)
                chooseConfig(conf);
        else ;
        //Иначе чтение сейва и снова надо спросить про конфигурацию
        startGame(conf, argv[1]);
        free(conf);
        return 0;
}