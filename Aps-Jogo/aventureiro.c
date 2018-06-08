#include <stdio.h>
#include <stdlib.h>
#include "Personagem.h"
#include "Monstros.h"

static void subir_lvl_aventureiro(struct personagem *aventureiro){

    static int hp=0, dano=0, armor=0, inte=0, agili=0;
    int i, pontos, numeroDeUps = 5;

    aventureiro->lvl++;
    aventureiro->HP = 14 + hp;
    aventureiro->forca = 5 + dano;
    aventureiro->armadura = 3 + armor;
    aventureiro->inteligencia = 5 + inte;
    aventureiro->agilidade = 5 + agili;

    printf("Parabens!!!\nVoce Subiu de lvl\n\n");

    for(i = 0; i < 5; i++){

        printf("Voce possui: %d pontos para upar\n\n", numeroDeUps);
        printf("1- Mais 1 de HP\n");
        printf("2- Mais 1 de Forca\n");
        printf("3- Mais 1 de armadura\n");
        printf("4- Mais 1 de inteligencia\n");
        printf("5- Mais 1 de agilidade\n");

        scanf("%d", &pontos);

        if(pontos == 1){
            aventureiro->HP++;
            printf("\nHP = %d\n", aventureiro->HP);
            hp++;
        }
        if(pontos == 2){
            aventureiro->forca++;
            printf("\nForca = %d\n", aventureiro->forca);
            dano++;
        }
        if(pontos == 3){
            aventureiro->armadura++;
            printf("\nArmadura = %d\n", aventureiro->armadura);
            armor++;
        }
        if(pontos == 4){
            aventureiro->inteligencia++;
            printf("\nIntelifencia = %d\n", aventureiro->inteligencia);
            inte++;
        }
        if(pontos == 5){
            aventureiro->agilidade++;
            printf("\aAgilidade = %d\n", aventureiro->agilidade);
            agili++;
        }
        numeroDeUps--;
        system("PAUSE");
        system("cls");
    }
    aventureiro->aventureiro_nome(aventureiro);
}

static void menu_aventureiro(struct personagem *aventureiro){

    printf("Seu turno \n\n");
    printf("Escolha o seu ataque:\n");
    printf("1-Espadada\t");
    printf("3-Bola de fogo\n");
    printf("2-Escudada\t");
    printf("4-Jogar lanca\n");
    printf("5-Descansar\n");
    printf("\n");

}

static void nome_aventureiro(struct personagem *aventureiro){

    printf("Nome = %s\n", aventureiro->nome);
    printf("Classe = %s\n", aventureiro->classe);
    printf("LVL = %d\n", aventureiro->lvl);
    printf("HP = %d\n", aventureiro->HP);
    printf("Forca = %d\n", aventureiro->forca);
    printf("Armadura = %d\n", aventureiro->armadura);
    printf("Inteligencia = %d\n", aventureiro->inteligencia);
    printf("Agilidade = %d\n", aventureiro->agilidade);
    printf("Staminia = %d\n", aventureiro->staminia);
    printf("\n");

}

static int aventureiro_ataque_fraco(struct personagem *aventureiro){

    int X;

    if(aventureiro->staminia < 2){

        printf("Voce nao conseguiu atacar\n");
        return -1;
    }

    if(aventureiro->staminia >= 2){

        X = 1 + rand() % aventureiro->forca;

        printf("Espadada na cara = %d\n", X);

        aventureiro->staminia = aventureiro->staminia - 2;

        return X;
    }
}

static int aventureiro_ataque_forte(struct personagem *aventureiro){

    int X;

    if(aventureiro->staminia < 2){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(aventureiro->staminia >= 2){

    X = aventureiro->armadura + rand() % aventureiro->forca;

    printf("Escudada = %d\n", X);

    aventureiro->staminia = aventureiro->staminia - 2;

    return X;

    }

}

static int aventureiro_magia1(struct personagem *aventureiro){

    int X;

    if(aventureiro->staminia < 2){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(aventureiro->staminia >= 2){

    X = rand() % aventureiro->forca;

    printf("Bola de fogo = %d\n", X);

    aventureiro->staminia = aventureiro->staminia - 2;

    return X;

    }
}


static int aventureiro_magia2(struct personagem *aventureiro){

    int X;

    if(aventureiro->staminia < 1){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(aventureiro->staminia >= 1){

    X = rand() % aventureiro->forca;

    printf("Jogar lanca = %d\n", X);

    aventureiro->staminia = aventureiro->staminia - 1;

    return X;

    }

}

static void aventureiro_passiva(struct personagem *aventureiro, struct monstros *monstro){

    static int cont = 0;
    static int X, Y;

    if(cont == 0){
        X = (aventureiro->HP*30)/100;
        Y = (aventureiro->HP*50)/100;
        cont++;
    }

    if(aventureiro->HP <= X && cont == 1){
        aventureiro->HP = aventureiro->HP + Y;
        printf("Beseker ativado!!!\n");
        printf("%s possui agora de %d vida \n", aventureiro->nome, aventureiro->HP);
        cont++;
    }

    if(monstro->HP <= 0){
        cont = 0;
    }
}

static void aventureiro_descanso(struct personagem *aventureiro){

    if(aventureiro->staminia == 10){
        printf("Voce ja esta descansado\n");
    }

    if(aventureiro->staminia == 9){
        aventureiro->staminia++;
        printf("Voce recuperou 1 de stamina\n");
    }
    if(aventureiro->staminia < 9){
        aventureiro->staminia = aventureiro->staminia + 2;
        printf("Voce recuperou 2 de stamina\n");
    }
}

PERSONAGEM *new_aventureiro(char *nome, char *classe, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    //-> ponteiro do tipo de uma estrutura que esta recebendo tal valor

    PERSONAGEM *aventureiro = (PERSONAGEM *) malloc(sizeof(PERSONAGEM));

    aventureiro->nome = nome;
    aventureiro->classe = classe;
    aventureiro->lvl = lvl;
    aventureiro->HP = HP;
    aventureiro->forca = forca;
    aventureiro->armadura = armadura;
    aventureiro->inteligencia = inteligencia;
    aventureiro->agilidade = agilidade;
    aventureiro->staminia = 10;

    aventureiro->subir_lvl = subir_lvl_aventureiro;
    aventureiro->aventureiro_menu = menu_aventureiro;
    aventureiro->aventureiro_nome = nome_aventureiro;
    aventureiro->ataque_fraco = aventureiro_ataque_fraco;
    aventureiro->ataque_forte = aventureiro_ataque_forte;
    aventureiro->aventureiro_magia1 = aventureiro_magia1;
    aventureiro->aventureiro_magia2 = aventureiro_magia2;
    aventureiro->aventureiro_passiva = aventureiro_passiva;
    aventureiro->descansar = aventureiro_descanso;

    return aventureiro;

}
