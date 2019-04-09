#include "config.h"

<<<<<<< HEAD
//Живая - \u25d9
//Мёртвая - \u25cb

int main(int argc, char* argv[]){
        //Чтение линии полецень, создание переменной структуры Configuration,
        //Вызов ф-ии Game , передавая туда переменную Conf и путь к сохранению
=======
int main(int argc, char* argv[]){
        config conf = malloc(sizeof conf);
        clrscr();
        if(argc > 1){
                FILE* file = fopen(argv[1], "r");
                if(file == NULL){
                        printf("FILE %s not found. Matrix will be generated random\n", argv[1]);
                        chooseConfig(conf, false);
                }
                else
                        chooseConfig(conf, true);
                fclose(file);
        }
        else
                chooseConfig(conf, false);
        startGame(conf, argv[1]);
        free(conf);
>>>>>>> Maruhay
        return 0;
}