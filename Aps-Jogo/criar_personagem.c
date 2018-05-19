#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Personagem.h"

PERSONAGEM *criar_personagem(){

    PERSONAGEM *meu_aventureiro;

    char *NOME;

    NOME = (char*) malloc(sizeof(char) * 20);//Criar estaticamente não funçiona

    int x;

    printf("Qual o seu nome?: \n");
    scanf(" %[^\n]", NOME);

    printf("Escolha sua classe: \n");
    printf("1-Guerreiro\n");
    printf("2-Mago\n");
    printf("3-Ladrao\n");

    scanf("%d", &x);

    if(x == 1){

       meu_aventureiro = new_aventureiro(NOME, "Guerreiro", 1, 14, 5, 3, 3 ,3);

    }

    if(x == 2){

        meu_aventureiro = new_aventureiro(NOME, "Mago", 1, 6, 12, 4, 6, 6);

    }

    if(x == 3){

       meu_aventureiro = new_aventureiro(NOME, "Ladrao", 1, 8, 6, 6, 4, 4);

    }

    printf("\n");

    return meu_aventureiro;
}
