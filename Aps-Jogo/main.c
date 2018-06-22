//Integrantes: Hendrick e Gabrieli Machado

/*Sera um jogo onde o seu objetivo e passar por uma torre de desafios,
 batalhando com os mais diversos tipos de monstros unicos que o jogo possuira.

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include "Monstros.h"
#include "Personagem.h"
#include <windows.h>


int main(){

    keybd_event(VK_MENU  , 0x36, 0, 0);
    keybd_event(VK_RETURN, 0x1C, 0, 0);
    keybd_event(VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU  , 0x38, KEYEVENTF_KEYUP, 0);

    srand((unsigned) time(NULL));
    setlocale(LC_ALL,"");

    PERSONAGEM *meu_aventureiro;

    inicio();
    historia_incio();
    julgamento();
    meu_aventureiro = criar_personagem();//Função

    torre_negra(meu_aventureiro);
    torre_negra(meu_aventureiro);
    torre_negra(meu_aventureiro);
    torre_negra(meu_aventureiro);
    torre_negra(meu_aventureiro);
    torre_negra(meu_aventureiro);
    torre_negra(meu_aventureiro);
    torre_negra(meu_aventureiro);
    torre_negra(meu_aventureiro);
    torre_negra(meu_aventureiro);

    void charada(){
    char s;
   printf("                               ninguem nunca me viu, talvez verá, voce precisou de mim, agora terá seu fim, apenas vivo sairá, se a mim derrotar.
          "                               Agora como me destruirá?");
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


    //ver_monstros(meu_aventureiro);


    return 0;

}
