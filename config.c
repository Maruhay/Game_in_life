#include "config.h"

void defaultConfig(config conf){
    conf->col = 7;
    conf->row = 7;
    conf->n_it = 7;
    conf->rule = 'N';
    conf->out = 0; //'0' - "0 or 1"; '1' - "\u25d9 or \u25cb"
}

void userConfig(config conf) {
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