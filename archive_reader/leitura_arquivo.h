/*
 ============================================================================
 Name        : leitura_arquivo.c
 Author      :
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "../lista_enc/lista_enc.h"

#ifndef LEITURA_ARQUIVO_H_INCLUDED
#define LEITURA_ARQUIVO_H_INCLUDED

typedef struct zip_codes zip_code;
typedef struct paises_zip_codes paises_zip_code;

void le_arquivo(char* caminho_do_arquivo, paises_zip_code* country);
void imprime_zip_code(zip_code **dados, int tamanho);

zip_code **country_get_data(paises_zip_code* country);
void country_set_data(paises_zip_code* country, zip_code** data);
int country_get_tamanho(paises_zip_code* country);

char *get_place_name(zip_code **dados, int i);


#endif // LEITURA_ARQUIVO_H_INCLUDED
