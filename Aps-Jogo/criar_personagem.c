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


    printf ("\n\n\n\n                              Como você aceitou a minha ajuda, irei cobrar a minha divida...\n"
            "                              Ágora você está em minha residencia, carinhosamente chamada Torre Negra...\n"
            "                              Aqui e onde você pagara sua divida...\n"
            "                              Lute com 10 criaturas, e as mate...\n"
            "                              E você estara livre para voltar para sua vida mediocre\n");
    printf("\n                              Entao qual o seu nome? ");
    scanf("  %[^\n]", NOME);

    if(strcmp(NOME, nomes[0]) == 0 || strcmp(NOME, nomes[1]) == 0){

        printf ("\n\n\n\n                              Quem diria, um nobre em minha residencia...\n"
                "                              Nunca esperaria ver um lorde do inferno aqui...\n"
                "                              Como um ser como você foi parar naquela situação lamentavel...\n"
                "                              Mas isso pouco importa vá lá e lute...\n"
                "                              Nos proporcione um otimo espetaculo...\n");

        meu_aventureiro = new_muriel(NOME, "Ninja", 1, 10, 10, 10, 10 ,10);

        return meu_aventureiro;

    }
      printf ("\n\n\n\n                              Um bom nome para você...\n"
              "                              Mas agora me conte quem e você, na verdade quem você era...\n");
    printf("\n                              Eu era um: ");

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

    printf("\n\n\n\n                              Muito bem %s...\n", meu_aventureiro->nome);
    printf("                              Vamos, vamos...\n"
           "                              Vá e lute, monstre o seu poder para o publico...\n");

    limpa_tela();
    return meu_aventureiro;
}
