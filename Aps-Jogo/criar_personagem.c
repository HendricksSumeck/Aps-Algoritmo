#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Personagem.h"

PERSONAGEM *criar_personagem(){

    PERSONAGEM *meu_aventureiro;

    char *NOME;
    int A;
    char *nomes[] = {

        "Muriel",
        "muriel",

    };

    NOME = (char*) malloc(sizeof(char) * 20);//Criar estaticamente não funçiona

    char x;


    printf ("\n\n\n\n                              Se você esta aqui então respondeu SIM, agora será\n"
            "                              obrigado a lutar para mim...\n"
            "                              Uma luta irá acontecer, a sua vida está em risco\n"
            "                              Um monstro será escolhido e ninguém nunca viu\n"
            "                              algo parecido...\n");
    printf("\n                              Qual o seu nome? ");
    scanf("  %[^\n]", NOME);

    if(strcmp(NOME, nomes[0]) == 0 || strcmp(NOME, nomes[1]) == 0){

        meu_aventureiro = new_muriel(NOME, "Ninja", 1, 10, 10, 10, 10 ,10);

        return meu_aventureiro;

    }
      printf ("\n\n\n\n                              De uma classe tera que ser, e uma habilidade especial\n"
              "                              poderá ter");

    printf("\n                              Escolha a sua classe? ");

    printf("\n                              1-Guerreiro\n");
    printf("                              2-Mago\n");
    printf("                              3-Ladino\n");
    printf("                              4-Paladino\n");


    x = getch();
    printf("\n");

    while(x <  49 || x > 52){

            printf("                              Nao existe esta opcao!!!");
            x = getch();
            printf("\n");
    }



    if(x == '1'){

       meu_aventureiro = new_guerreiro(NOME, "Guerreiro", 1, 15, 7, 7, 4 ,4);

    }

    if(x == '2'){

        meu_aventureiro = new_mago(NOME, "Mago", 1, 8, 2, 7, 10, 3);

    }

    if(x == '3'){

        meu_aventureiro = new_ladino(NOME, "Ladino", 1, 10, 4, 5, 4, 10);

    }

    if(x == '4'){

        meu_aventureiro = new_paladino(NOME, "Paladino", 1, 12, 6, 6, 6, 6);

    }

    printf("\n");

    return meu_aventureiro;
}
