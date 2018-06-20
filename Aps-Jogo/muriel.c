#include <stdio.h>
#include <stdlib.h>
#include "Personagem.h"
#include "Monstros.h"

static void subir_lvl_muriel(struct personagem *muriel){

    static int hp=0, dano=0, armor=0, inte=0, agili=0;
    int i, numeroDeUps = 4;
    char escolha;

    muriel->lvl++;
    muriel->HP = 10 + hp;
    muriel->forca = 10 + dano;
    muriel->armadura = 10 + armor;
    muriel->inteligencia = 10 + inte;
    muriel->agilidade = 10 + agili;
    muriel->staminia = 10;

    printf("Parabens!!!\nVoce Subiu de lvl\n\n");

    for(i = 0; i < 4; i++){

        printf("Voce possui: %d pontos para upar\n\n", numeroDeUps);
        printf("1- Mais 1 de HP\n");
        printf("2- Mais 1 de Forca\n");
        printf("3- Mais 1 de armadura\n");
        printf("4- Mais 1 de inteligencia\n");
        printf("5- Mais 1 de agilidade\n");

        printf("Digite sua escolha: ");
        escolha = getch();
        printf("\n");

        while(escolha <  49 || escolha > 53){

            printf("Nao existe esta opcao!!!\n");
            escolha = getch();

        }

        if(escolha == '1'){
            muriel->HP++;
            printf("\nHP = %d\n", muriel->HP);
            hp++;
        }
        if(escolha == '2'){
            muriel->forca++;
            printf("\nForca = %d\n", muriel->forca);
            dano++;
        }
        if(escolha == '3'){
            muriel->armadura++;
            printf("\nArmadura = %d\n", muriel->armadura);
            armor++;
        }
        if(escolha == '4'){
            muriel->inteligencia++;
            printf("\nIntelifencia = %d\n", muriel->inteligencia);
            inte++;
        }
        if(escolha == '5'){
            muriel->agilidade++;
            printf("\aAgilidade = %d\n", muriel->agilidade);
            agili++;
        }
        numeroDeUps--;
        limpa_tela();
    }
    muriel->aventureiro_nome(muriel);
}

static void menu_muriel(struct personagem *muriel){

    printf("Seu turno \n\n");
    printf("Escolha o seu ataque:\n");
    printf("1-Rasengan\t");
    printf("2-Chidori\n");
    printf("3-Magykyo Sharingan\t");
    printf("4-Katsu - Biribinha do Demonio\n");
    printf("5-Descansar\n");
    printf("\n");

}

static void nome_muriel(struct personagem *muriel){

    printf("Nome = %s\n", muriel->nome);
    printf("Classe = %s\n", muriel->classe);
    printf("LVL = %d\n", muriel->lvl);
    printf("HP = %d\n", muriel->HP);
    printf("Forca = %d\n", muriel->forca);
    printf("Armadura = %d\n", muriel->armadura);
    printf("Inteligencia = %d\n", muriel->inteligencia);
    printf("Agilidade = %d\n", muriel->agilidade);
    printf("Staminia = %d\n", muriel->staminia);
    printf("\n");

}

static int muriel_ataque_fraco(struct personagem *muriel){

    int X;

    if(muriel->staminia < 2){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(muriel->staminia >= 2){

        X = rand() % muriel->agilidade;
        X = X + muriel->lvl;

        printf("Rasengan = %d\n", X);

        muriel->staminia = muriel->staminia - 2;

        return X;

    }
}

static int muriel_ataque_forte(struct personagem *muriel){

    int X;

    if(muriel->staminia < 2){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(muriel->staminia >= 2){

        X = rand() % muriel->forca;
        X = X + muriel->lvl;

        printf("Chidori = %d\n", X);

        muriel->staminia = muriel->staminia - 2;

        return X;

    }

}

static int muriel_magia1(struct personagem *muriel){

    int X;

    if(muriel->staminia < 3){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(muriel->staminia >= 3){

        X = rand() % muriel->inteligencia;
        X = X + muriel->lvl;

        printf("Magykyo Sharingan = %d\n", X);

        muriel->staminia = muriel->staminia - 3;

        return X;

    }
}


static int muriel_magia2(struct personagem *muriel){

    int X;

    if(muriel->staminia < 5){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(muriel->staminia >= 5){

        X = (muriel->agilidade  + muriel->forca + muriel->inteligencia) / 3;

        printf("Katsu - Biribinha do Demonio = %d\n", X);

        muriel->staminia = muriel->staminia - 5;

        return X;

    }

}

static void muriel_passiva(struct personagem *muriel, struct monstros *monstro){

    int X;

    X = rand() % 3;

    if(monstro->HP > 0 && X == 0){

        monstro->HP = monstro->HP - 1;
        printf("Muriel Jogou uma shuriken\n");
        return 0;
    }

    if(monstro->HP > 0 && X == 1){

        monstro->HP = monstro->HP - 2;
        printf("Muriel Jogou duas shuriken\n");
        return 0;
    }

    if(monstro->HP > 0 && X == 2){

        monstro->HP = monstro->HP - 3;
        printf("Muriel Jogou treis shuriken\n");
        return 0;
    }

}

static int muriel_descanso(struct personagem *muriel){

    if(muriel->staminia == 10){
        printf("Voce ja esta descansado\n");
    }

    if(muriel->staminia == 9){
        muriel->staminia++;
        printf("Voce recuperou 1 de stamina\n");
    }
    if(muriel->staminia < 9){
        muriel->staminia = muriel->staminia + 2;
        printf("Voce recuperou 2 de stamina\n");
    }
}

PERSONAGEM *new_muriel(char *nome, char *classe, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    //-> ponteiro do tipo de uma estrutura que esta recebendo tal valor

    PERSONAGEM *muriel = (PERSONAGEM *) malloc(sizeof(PERSONAGEM));

    muriel->nome = nome;
    muriel->classe = classe;
    muriel->lvl = lvl;
    muriel->HP = HP;
    muriel->forca = forca;
    muriel->armadura = armadura;
    muriel->inteligencia = inteligencia;
    muriel->agilidade = agilidade;
    muriel->staminia = 10;

    muriel->subir_lvl = subir_lvl_muriel;
    muriel->aventureiro_menu = menu_muriel;
    muriel->aventureiro_nome = nome_muriel;
    muriel->ataque_fraco = muriel_ataque_fraco;
    muriel->ataque_forte = muriel_ataque_forte;
    muriel->aventureiro_magia1 = muriel_magia1;
    muriel->aventureiro_magia2 = muriel_magia2;
    muriel->aventureiro_passiva = muriel_passiva;
    muriel->descansar = muriel_descanso;

    return muriel;

}
