#include "stdio.h"
#include "stdlib.h"

int main(){
        for(int i = 0; i< 10;i++){
                for(int j = 0; j < 10; j++)
                        if (j == 7 && i == 4) printf("\u25d9 ");
                                else printf("\u25cb ");
        printf("\n");
        }
        return 0;
}