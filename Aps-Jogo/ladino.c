#include <stdio.h>
#include <stdlib.h>
#include "Personagem.h"
#include "Monstros.h"

static void subir_lvl_ladino(struct personagem *ladino){

    static int hp=0, dano=0, armor=0, inte=0, agili=0;
    int i, pontos, numeroDeUps = 5;

    ladino->lvl++;
    ladino->HP = 14 + hp;
    ladino->forca = 5 + dano;
    ladino->armadura = 3 + armor;
    ladino->inteligencia = 5 + inte;
    ladino->agilidade = 5 + agili;

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
            ladino->HP++;
            printf("\nHP = %d\n", ladino->HP);
            hp++;
        }
        if(pontos == 2){
            ladino->forca++;
            printf("\nForca = %d\n", ladino->forca);
            dano++;
        }
        if(pontos == 3){
            ladino->armadura++;
            printf("\nArmadura = %d\n", ladino->armadura);
            armor++;
        }
        if(pontos == 4){
            ladino->inteligencia++;
            printf("\nIntelifencia = %d\n", ladino->inteligencia);
            inte++;
        }
        if(pontos == 5){
            ladino->agilidade++;
            printf("\aAgilidade = %d\n", ladino->agilidade);
            agili++;
        }
        numeroDeUps--;
        system("PAUSE");
        system("cls");
    }
    ladino->aventureiro_nome(ladino);
}

static void menu_ladino(struct personagem *ladino){

    printf("Seu turno \n\n");
    printf("Escolha o seu ataque:\n");
    printf("1-Espadada\t");
    printf("3-Bola de fogo\n");
    printf("2-Escudada\t");
    printf("4-Jogar lanca\n");
    printf("5-Descansar\n");
    printf("\n");

}

static void nome_ladino(struct personagem *ladino){

    printf("Nome = %s\n", ladino->nome);
    printf("Classe = %s\n", ladino->classe);
    printf("LVL = %d\n", ladino->lvl);
    printf("HP = %d\n", ladino->HP);
    printf("Forca = %d\n", ladino->forca);
    printf("Armadura = %d\n", ladino->armadura);
    printf("Inteligencia = %d\n", ladino->inteligencia);
    printf("Agilidade = %d\n", ladino->agilidade);
    printf("Staminia = %d\n", ladino->staminia);
    printf("\n");

}

static int ladino_ataque_fraco(struct personagem *ladino){

    int X;

    if(ladino->staminia < 2){

        printf("Voce nao conseguiu atacar\n");
        return -1;
    }

    if(ladino->staminia >= 2){

        X = 1 + rand() % ladino->forca;

        printf("Espadada na cara = %d\n", X);

        ladino->staminia = ladino->staminia - 2;

        return X;
    }
}

static int ladino_ataque_forte(struct personagem *ladino){

    int X;

    if(ladino->staminia < 2){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(ladino->staminia >= 2){

    X = ladino->armadura + rand() % ladino->forca;

    printf("Escudada = %d\n", X);

    ladino->staminia = ladino->staminia - 2;

    return X;

    }

}

static int ladino_magia1(struct personagem *ladino){

    int X;

    if(ladino->staminia < 2){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(ladino->staminia >= 2){

    X = rand() % ladino->forca;

    printf("Bola de fogo = %d\n", X);

    ladino->staminia = ladino->staminia - 2;

    return X;

    }
}


static int ladino_magia2(struct personagem *ladino){

    int X;

    if(ladino->staminia < 1){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(ladino->staminia >= 1){

    X = rand() % ladino->forca;

    printf("Jogar lanca = %d\n", X);

    ladino->staminia = ladino->staminia - 1;

    return X;

    }

}

static void ladino_passiva(struct personagem *ladino, struct monstros *monstro){

    static int cont = 0;
    static int X, Y;

    if(cont == 0){
        X = (ladino->HP*30)/100;
        Y = (ladino->HP*50)/100;
        cont++;
    }

    if(ladino->HP <= X && cont == 1){
        ladino->HP = ladino->HP + Y;
        printf("Beseker ativado!!!\n");
        printf("%s possui agora de %d vida \n", ladino->nome, ladino->HP);
        cont++;
    }

    if(monstro->HP <= 0){
        cont = 0;
    }
}

static void ladino_descanso(struct personagem *ladino){

    if(ladino->staminia == 10){
        printf("Voce ja esta descansado\n");
    }

    if(ladino->staminia == 9){
        ladino->staminia++;
        printf("Voce recuperou 1 de stamina\n");
    }
    if(ladino->staminia < 9){
        ladino->staminia = ladino->staminia + 2;
        printf("Voce recuperou 2 de stamina\n");
    }
}

PERSONAGEM *new_ladino(char *nome, char *classe, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    //-> ponteiro do tipo de uma estrutura que esta recebendo tal valor

    PERSONAGEM *ladino = (PERSONAGEM *) malloc(sizeof(PERSONAGEM));

    ladino->nome = nome;
    ladino->classe = classe;
    ladino->lvl = lvl;
    ladino->HP = HP;
    ladino->forca = forca;
    ladino->armadura = armadura;
    ladino->inteligencia = inteligencia;
    ladino->agilidade = agilidade;
    ladino->staminia = 10;

    ladino->subir_lvl = subir_lvl_ladino;
    ladino->aventureiro_menu = menu_ladino;
    ladino->aventureiro_nome = nome_ladino;
    ladino->ataque_fraco = ladino_ataque_fraco;
    ladino->ataque_forte = ladino_ataque_forte;
    ladino->aventureiro_magia1 = ladino_magia1;
    ladino->aventureiro_magia2 = ladino_magia2;
    ladino->aventureiro_passiva = ladino_passiva;
    ladino->descansar = ladino_descanso;

    return ladino;

}
