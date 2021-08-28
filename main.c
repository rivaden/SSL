
#include "scanner.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char*argv[]) {
    if(argc != 2) {
        printf("Error en cantidad de parametros!");
        exit(EXIT_FAILURE);
    }
    if( ! get_token2(argv[1]) ) {
        printf("Error en el proceso del archivo: %s",argv[1]);
        exit(EXIT_FAILURE);
    }
    return 0;
}
