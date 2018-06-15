#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Monstros.h"
#include "Personagem.h"

void inicio(void)
{
    FILE *txt;
    char t;

    char frase[1000];

    txt = fopen("textos/historia_inicio.txt", "r");

    while(fscanf(txt, "%c", &t) != EOF){

        printf("%c", t);

    }

    fclose(txt);




//int fclose(FILE *txt);

    // limpa_tela();
}
