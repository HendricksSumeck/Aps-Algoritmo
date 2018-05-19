//Integrantes: Hendrick e Gabrieli Machado

/*Sera um jogo onde o seu objetivo e passar por uma torre de desafios,
 batalhando com os mais diversos tipos de monstros unicos que o jogo possuira.

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Monstros.h"
#include "Personagem.h"

int main(){

    srand((unsigned) time(NULL));

    PERSONAGEM *meu_aventureiro;
    Monstro *meus_monstros[2];

    //inicio();

    meu_aventureiro = criar_personagem();//Função

    //meu_aventureiro = new_aventureiro("Hendrick", "Guerreiro", 1, 14, 5, 3, 5, 5);

    //meu_aventureiro->aventureiro_nome(meu_aventureiro);//Função


    meus_monstros[0] = gerar_monstro(meu_aventureiro);

    //meus_monstros[0]->nome_monstro(meus_monstros[0]);//Função

    iniciar_batalha(meu_aventureiro, meus_monstros[0]);//Função
    //iniciar_batalha(meu_aventureiro, meus_monstros[1]);//Função

    //meu_aventureiro->subir_lvl(meu_aventureiro);
    //meu_aventureiro->aventureiro_nome(meu_aventureiro);
    //meus_monstros[0]->nome_monstro(meus_monstros[0]);

    return 0;

}
