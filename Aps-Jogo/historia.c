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
    char s, escolha;

    char fr[1000];

    txt = fopen("textos/julgamento.txt", "r");

    while(fscanf(txt, "%c", &b) != EOF){

        printf("%c", b);

    }
   fclose(txt);
   printf("\n");
   escolha = getch();
   while(escolha < '1' || escolha >'2'){
    printf("                      Faça sua escolha\n");
    escolha = getch();
   }
   if (escolha == '2'){

    system("cls");
    died();
    exit(0);

   }

   if(escolha == '1'){
    system("cls");
   }

}
void died(void){

FILE *YOU;
    char d;

    char fra[1000];

   YOU = fopen("textos/DIED.txt", "r");

    while(fscanf(YOU, "%c", &d) != EOF){

        printf("%c", d);
    }
   fclose(YOU);
}



void charada(void){
    char s;
   printf("                               ninguem nunca me viu, talvez verá, voce precisou de mim\n"
          "                               agora terá seu fim, apenas vivo sairá, se a mim derrotar.\n"
          "                               Agora como me destruirá?\n");
          scanf("%c", s);
        if (s==ganhando||s==vencendo||s==ganhando o jogo){
        FILE *sim;
         char c;

        char fra[1000];

        sim = fopen("textos/simnao.txt", "r");

        while(fscanf(sim, "%c", &c) != EOF){

        printf("%c", c);
       }
       fclose(sim);
        }


    }


