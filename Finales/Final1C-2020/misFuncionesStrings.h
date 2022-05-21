#ifndef MISFUNCIONESSTRINGS_H
#define MISFUNCIONESSTRINGS_H

//Devuelve la cantidad de caracteres de una cadena
int cant_caracteres(char* str);

//Devuelve las ocurrencias del caracter c en la cadena str
int ocurrencias_caracter(char* str, char c);

//Indica si una cadena contiene el caracter c
bool contiene_caracter(char* str, char c);

//Indica si dos cadenas son iguales
bool comparacion_cadenas(char* str1, char* str2);

#endif