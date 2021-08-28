#ifndef SCANNER_h
#define SCANNER_h
#include  "scanner.h"



#define LARGO_BUFFER    512
typedef enum { FDT,SEP,CAD,ESP } Token;
int get_token(char*);
Token ver_lectura(char caracter);


#endif

