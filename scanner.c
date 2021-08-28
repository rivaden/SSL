#include "scanner.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LARGO_BUFFER    512

Token ver_lectura(char caracter) {
    Token retorno;
    if(caracter == ',') {
        retorno = SEP;
    } else {
        if(isspace(caracter) || caracter == '\n'||caracter =='\t'||caracter == '\r') {
            retorno = ESP;
        }
        else{
            if(caracter == EOF){
                retorno = FDT;
            }
            else{
                retorno = CAD;
            }
        }
    }
    return retorno;
}

int get_token2(char*nombre_archivo) {
    char buffer[LARGO_BUFFER];
    FILE* archivo;
    char car;
    int index=0;
    int salir = 0;//FALSE

    archivo = fopen(nombre_archivo,"r");
    if(archivo) {
        car = fgetc(archivo);
        while(!salir) {
            switch(ver_lectura(car)) {
                case FDT:
                    if(index > 0) {
                        buffer[index] = '\0';
                        printf("Cadena: %s\n",buffer);
                        index = 0;
                    }
                    printf("Fin de Texto:\n");
                    salir = 1;//TRUE
                    break;
                case SEP:
                    if(index > 0) {
                        buffer[index] = '\0';
                        printf("Cadena: %s\n",buffer);
                        index = 0;
                    }
                    printf("Separador: %c\n",car);
                    car = fgetc(archivo);
                    break;
                case CAD:
                    buffer[index++] = car;
                    car = fgetc(archivo);
                    break;
                case ESP:
                    if(index > 0) {
                        buffer[index] = '\0';
                        printf("Cadena: %s\n",buffer);
                        index = 0;
                    }
                    car = fgetc(archivo);
                    break;
                }
            }
        fclose(archivo);
    }
    return salir;
}
