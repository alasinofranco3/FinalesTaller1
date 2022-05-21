#ifndef MISTRING_H
#define MISTRING_H

#include <stdio.h>
#include <stdbool.h>

int cant_caracteres(char* cadena);
bool comparacion(char* cadena1,char* cadena2);
bool contiene_caracter(char* cadena, char caracter);
bool contiene_subcadena(char* cadena, char* subcadena);

#endif