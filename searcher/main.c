#include <stdio.h>
#include <stdlib.h>
#include "lista_enc/lista_enc.h"
#include "lista_enc/no.h"
#include "hash.h"

#define N_CHARACTERS 255
#define N_COUNTRIES 83

#undef DEBUG

int main(){
    char place_name[100];
    int country;
    char nome_arquivos[83][3] = {    "AD", "AR", "AS", "AT", "AU", "AX", "BD", "BE", "BG", "BM", "BR", "BY", "CA",
        "CH", "CO", "CR", "CZ", "DE", "DK", "DO", "DZ", "ES", "FI", "FO", "FR", "GB",
        "GF", "GG", "GL", "GP", "GT", "GU", "HR", "HU", "IE", "IM", "IN", "IS", "IT",
        "JE", "JP", "LI", "LK", "LT", "LU", "LV", "MC", "MD", "MH", "MK", "MP", "MQ",
        "MT", "MX", "MY", "NC", "NL", "NO", "NZ", "PH", "PK", "PL", "PM", "PR", "PT",
        "RE", "RO", "RU", "SE", "SI", "SJ", "SK", "SM", "TH", "TR", "UA", "US", "UY",
        "VA", "VI", "WF", "YT", "ZA"    };
    
    
    const char endereco_arquivo[] = "../zipcodes_archives/one_archive.txt"; //Felipe
    //char endereco_arquivo[] = "/Users/aninhabanderchuk/Google Drive/Engenharia Eletrônica/* 5˚ Fase */5. Programação de Computadores II/PRG: Trabalho Final - CEP/ZIP_CODE_search/zipcodes_archives/one_archive.txt"; //Ana
    
    no_t *hash_table[N_CHARACTERS][N_COUNTRIES];
    
    lista_enc_t *zipcode_list;
    
    int i, j;
    
    
    for(j = 0; j<255; j++){
        for(i = 0; i<83; i++){
            hash_table[j][i] = NULL;
        }
    }
    
    zipcode_list = create_hash_table(endereco_arquivo, hash_table, N_CHARACTERS, N_COUNTRIES);
    
#ifdef DEBUG
    for(j = 0; j<255; j++){
        for(i = 0; i<83; i++){
            if(hash_table[j][i] != NULL){
                printf("%d\t%d\t%p\t%s\t%s\n", j, i, hash_table[j][i], no_get_country_code(hash_table[j][i]), no_get_place_name(hash_table[j][i]));
            }
        }
        printf("\n\n");
    }
#endif
    
    
    puts("Programa para busca de CEP a partir do nome de uma cidade.\n");
    puts("Voce pode fazer a busca somente pelo nome da cidade ou a-\ndicionar tambem o pais para tornar a busca mais rapida.\n\n");
    puts("- - - Tabela de codigo referente a cada pais - - -");
    for(i = 0; i < 21; i++)
        printf("\n %02d:\t%s\t\t%d:\t%s\t\t%d:\t%s\t\t%d:\t%s\t",    i + 1, nome_arquivos[i], i + 22, nome_arquivos[i+21],
               i + 43, nome_arquivos[i+42], i + 64, nome_arquivos[i+63]);
    
    puts("\nDigite o nome da cidade da qual voce deseja realizar a busca:\n");
    scanf("%s", place_name);
    puts("Caso voce saiba, digite o nome do pais que ela pertence:\n");
    scanf("%d", &country);
    
    //char letter = 'S';
    
    //printf("%d\t%s", country, place_name);
    //printf("%p", hash_table[(unsigned char)letter][country]);
    search_city(hash_table, place_name, country);
    
    free_zipcode_list(zipcode_list);
    
    return 0;
}
