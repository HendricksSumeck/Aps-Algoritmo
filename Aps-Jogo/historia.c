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
 limpa_tela();

}
void julgamento(void){

    FILE *txt;
    char b;

    char fr[1000];

    txt = fopen("textos/julgamento.txt", "r");

    while(fscanf(txt, "%c", &b) != EOF){

        printf("%c", b);

    }
   fclose(txt);
}
