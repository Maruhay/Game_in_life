#include "config.h"

void defaultConfig(config conf){
    conf->col = 7;
    conf->row = 7;
    conf->n_it = 7;
    conf->rule = 'N';
    conf->out = 0; //'0' - "0 or 1"; '1' - "\u25d9 or \u25cb"
}