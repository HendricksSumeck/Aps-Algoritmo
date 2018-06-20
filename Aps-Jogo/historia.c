#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Monstros.h"
#include "Personagem.h"

void historia_incio(void){

    FILE *texto;
    char a;

    char frase[1000];

    texto = fopen("textos/hist.txt", "r");

    while(fscanf(texto, "%c", &a) != EOF){

        printf("%c", a);

    }
 fclose(texto);

}
