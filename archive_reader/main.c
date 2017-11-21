/*
 ============================================================================
 Name        : main.c
 Author      :
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leitura_arquivo.h"
#include "quicksort.h"



#define DEBUG
//#undef DEBUG

#ifdef DEBUG
	#include <time.h>
	#include <limits.h>
	#include <stdint.h>
	#include <unistd.h>

    struct timespec t_debug_1;
    struct timespec t_debug_2;

    double sum_t_debug_1, sum_t_debug_2, media_tempo_f;
#endif



typedef struct paises_zip_codes{
	zip_code** dados;
	int tamanho;
} paises_zip_code;


int main()
{
	int i = 0;
	paises_zip_code paises[83];
	char endereco[] = "../zipcodes_archives/";
    
    //char endereco[] = "/Users/aninhabanderchuk/Google Drive/Engenharia Eletrônica/* 5˚ Fase */5. Programação de Computadores II/PRG: Trabalho Final - CEP/ZIP_CODE_search/zipcodes_archives/";
    
	char endereco_temp[500];

	char nome_arquivos[83][3] = {	"AD", "AR", "AS", "AT", "AU", "AX", "BD", "BE", "BG", "BM", "BR", "BY", "CA",
									"CH", "CO", "CR", "CZ", "DE", "DK", "DO", "DZ", "ES", "FI", "FO", "FR", "GB",
									"GF", "GG", "GL", "GP", "GT", "GU", "HR", "HU", "IE", "IM", "IN", "IS", "IT",
									"JE", "JP", "LI", "LK", "LT", "LU", "LV", "MC", "MD", "MH", "MK", "MP", "MQ",
									"MT", "MX", "MY", "NC", "NL", "NO", "NZ", "PH", "PK", "PL", "PM", "PR", "PT",
									"RE", "RO", "RU", "SE", "SI", "SJ", "SK", "SM", "TH", "TR", "UA", "US", "UY",
									"VA", "VI", "WF", "YT", "ZA"    };

#ifdef DEBUG
    clock_gettime(CLOCK_MONOTONIC ,&t_debug_1);
#endif

	for(i = 0; i < 83; i++){
		strcpy(endereco_temp, endereco);
		strcat(endereco_temp, nome_arquivos[i]);
		strcat(endereco_temp, ".txt");

		paises[i].dados = le_arquivo(endereco_temp, &paises[i].tamanho);
	}

#ifdef DEBUG
	clock_gettime(CLOCK_MONOTONIC ,&t_debug_2);


	sum_t_debug_1 = (double)(unsigned)t_debug_1.tv_nsec / 1000000.0;
	sum_t_debug_1 += ((double)(unsigned)t_debug_1.tv_sec * 1000);

	sum_t_debug_2 = (double)(unsigned)t_debug_2.tv_nsec / 1000000.0;
	sum_t_debug_2 += ((double)(unsigned)t_debug_2.tv_sec * 1000);

	media_tempo_f = sum_t_debug_2 - sum_t_debug_1;


	printf("Tempo leitura dos arquivos: \t\t%.3fms\n\n", media_tempo_f);
	clock_gettime(CLOCK_MONOTONIC ,&t_debug_1);
#endif

	for(i = 0; i < 83; i++){
		quicksort(paises[i].dados, 0, (paises[i].tamanho - 1));
	}

#ifdef DEBUG
	clock_gettime(CLOCK_MONOTONIC ,&t_debug_2);


	sum_t_debug_1 = (double)(unsigned)t_debug_1.tv_nsec / 1000000.0;
	sum_t_debug_1 += ((double)(unsigned)t_debug_1.tv_sec * 1000);

	sum_t_debug_2 = (double)(unsigned)t_debug_2.tv_nsec / 1000000.0;
	sum_t_debug_2 += ((double)(unsigned)t_debug_2.tv_sec * 1000);

	media_tempo_f = sum_t_debug_2 - sum_t_debug_1;


	printf("Tempo de execucao quicksort: \t\t%.3fms\n\n", media_tempo_f);
	clock_gettime(CLOCK_MONOTONIC ,&t_debug_1);
#endif


	printf("\n\n\n");
	imprime_zip_code(paises[3].dados, paises[3].tamanho);



    return 0;
}
