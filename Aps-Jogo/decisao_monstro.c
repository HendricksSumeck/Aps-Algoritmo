#include <stdio.h>
#include <stdlib.h>
#include "Monstros.h"
#include "Personagem.h"

void decisao_monstro(struct personagem *aventureiro, struct monstros *monstro){

    int X, max = -2, aux1, aux2, A, fit = -9999, B;
    int Dano_monstro, resistencia_armadura;
    int (*funcoes_monstro[]) (Monstro*) = {monstro->ataque_fraco, monstro->ataque_forte, monstro->monstro_magia1, monstro->monstro_magia2};

    if(monstro->HP > 0){

        printf("\n");
        printf("Turno do inimigo\n\n");

        for(X = 0; X < 4; X++){

            aux1 = funcoes_monstro[X](monstro);
            aux2 = melhor_opcao(monstro, aux1, X);
            //printf("Dano = %d\n", aux1);
            //printf("FIT = %d X\n", aux2);

            if(fit < aux2){
                fit = aux2;
                max = aux1;
                A = X;
            }

       }

        Dano_monstro = max;
        //("Maior = %d\n", maior);

        if(fit > 0 || monstro->staminia == 10){
            monstro->monstro_menu(A, Dano_monstro);
            monstro->monstro_muda_staminia(monstro, A);
            B = 10 + rand() % (50 - 10 +1);
            resistencia_armadura = (aventureiro->armadura * B) / 100;
            Dano_monstro = Dano_monstro - resistencia_armadura;
            printf("%s: Defendeu %d de dano\n", aventureiro->nome,resistencia_armadura);
            if(Dano_monstro <= 0){
                printf("%s: nao sofreu dano\n\n", aventureiro->nome);
            }else{
                aventureiro->HP = aventureiro->HP - Dano_monstro;
                printf("%s: Sofreu %d de dano\n\n", aventureiro->nome, Dano_monstro);
            }

        }else monstro->monstro_descanso(monstro);

    }
}

int melhor_opcao(struct monstros *monstro, int dano, int A){

    int X, i;
    int GG;

    GG = monstro->monstro_verifica_staminia(monstro, 10);
    X = dano_base(monstro);
    i = monstro->monstro_verifica_staminia(monstro, A);

    //printf("Stamina gasta %d\n", i);

    double AA = (i * 100 / GG);
    double DD = (dano * 100.0 / X);

    double B = AA + 0.8 * DD;
    double Dc = (B + 12.5) / (1.25 + 0.8);
    double Ac = 1.25 * Dc - 12.5;
    double Ac2 = 1.25 * DD - 12.5;
    double sinal = 1;

    if(Ac2 < AA){

        sinal = -1;

    }

    //NC = (X*30)/100;

    return (int) (sinal * (pow(Ac - AA, 2) + pow(Dc - DD, 2)));

}

int dano_base(struct monstros *monstro){

    int Media_dano;

    Media_dano = (monstro->forca + monstro->inteligencia + monstro->agilidade) / 3;

    return Media_dano;

}
