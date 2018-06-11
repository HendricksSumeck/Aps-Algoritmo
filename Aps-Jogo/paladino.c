#include <stdio.h>
#include <stdlib.h>
#include "Personagem.h"
#include "Monstros.h"

static void subir_lvl_paladino(struct personagem *paladino){

    static int hp=0, dano=0, armor=0, inte=0, agili=0;
    int i, numeroDeUps = 5;
    char escolha;

    paladino->lvl++;
    paladino->HP = 14 + hp;
    paladino->forca = 5 + dano;
    paladino->armadura = 3 + armor;
    paladino->inteligencia = 5 + inte;
    paladino->agilidade = 5 + agili;

    printf("Parabens!!!\nVoce Subiu de lvl\n\n");

    for(i = 0; i < 5; i++){

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
            printf("Escolha uma opcao valida\n");
            escolha = getch();
            printf("\n");

        }

        if(escolha == '1'){
            paladino->HP++;
            printf("\nHP = %d\n", paladino->HP);
            hp++;
        }
        if(escolha == '2'){
            paladino->forca++;
            printf("\nForca = %d\n", paladino->forca);
            dano++;
        }
        if(escolha == '3'){
            paladino->armadura++;
            printf("\nArmadura = %d\n", paladino->armadura);
            armor++;
        }
        if(escolha == '4'){
            paladino->inteligencia++;
            printf("\nIntelifencia = %d\n", paladino->inteligencia);
            inte++;
        }
        if(escolha == '5'){
            paladino->agilidade++;
            printf("\aAgilidade = %d\n", paladino->agilidade);
            agili++;
        }
        numeroDeUps--;
        limpa_tela();
    }
    paladino->aventureiro_nome(paladino);
}

static void menu_paladino(struct personagem *paladino){

    printf("Seu turno \n\n");
    printf("Escolha o seu ataque:\n");
    printf("1-Curar\t");
    printf("3-Lança Solar\n");
    printf("2-Bnção dos Ceus\t");
    printf("4-Punição Divina\n");
    printf("5-Descansar\n");
    printf("\n");

}

static void nome_paladino(struct personagem *paladino){

    printf("Nome = %s\n", paladino->nome);
    printf("Classe = %s\n", paladino->classe);
    printf("LVL = %d\n", paladino->lvl);
    printf("HP = %d\n", paladino->HP);
    printf("Forca = %d\n", paladino->forca);
    printf("Armadura = %d\n", paladino->armadura);
    printf("Inteligencia = %d\n", paladino->inteligencia);
    printf("Agilidade = %d\n", paladino->agilidade);
    printf("Staminia = %d\n", paladino->staminia);
    printf("\n");

}

static int paladino_ataque_fraco(struct personagem *paladino){

    int X;

    if(paladino->staminia < 2){

        printf("Voce nao conseguiu atacar\n");
        return -1;
    }

    if(paladino->staminia >= 2){

        X = 1 + rand() % paladino->forca;

        printf("Espadada na cara = %d\n", X);

        paladino->staminia = paladino->staminia - 2;

        return X;
    }
}

static int paladino_ataque_forte(struct personagem *paladino){

    int X;

    if(paladino->staminia < 2){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(paladino->staminia >= 2){

    X = paladino->armadura + rand() % paladino->forca;

    printf("Escudada = %d\n", X);

    paladino->staminia = paladino->staminia - 2;

    return X;

    }

}

static int paladino_magia1(struct personagem *paladino){

    int X;

    if(paladino->staminia < 2){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(paladino->staminia >= 2){

    X = rand() % paladino->forca;

    printf("Bola de fogo = %d\n", X);

    paladino->staminia = paladino->staminia - 2;

    return X;

    }
}


static int paladino_magia2(struct personagem *paladino){

    int X;

    if(paladino->staminia < 1){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(paladino->staminia >= 1){

    X = rand() % paladino->forca;

    printf("Jogar lanca = %d\n", X);

    paladino->staminia = paladino->staminia - 1;

    return X;

    }

}

static void paladino_passiva(struct personagem *paladino, struct monstros *monstro){

    static int cont = 0;
    static int X, Y;

    if(cont == 0){
        X = (paladino->HP*30)/100;
        Y = (paladino->HP*50)/100;
        cont++;
    }

    if(paladino->HP <= X && cont == 1){
        paladino->HP = paladino->HP + Y;
        printf("Beseker ativado!!!\n");
        printf("%s possui agora de %d vida \n", paladino->nome, paladino->HP);
        cont++;
    }

    if(monstro->HP <= 0){
        cont = 0;
    }
}

static void paladino_descanso(struct personagem *paladino){

    if(paladino->staminia == 10){
        printf("Voce ja esta descansado\n");
    }

    if(paladino->staminia == 9){
        paladino->staminia++;
        printf("Voce recuperou 1 de stamina\n");
    }
    if(paladino->staminia < 9){
        paladino->staminia = paladino->staminia + 2;
        printf("Voce recuperou 2 de stamina\n");
    }
}

PERSONAGEM *new_paladino(char *nome, char *classe, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    //-> ponteiro do tipo de uma estrutura que esta recebendo tal valor

    PERSONAGEM *paladino = (PERSONAGEM *) malloc(sizeof(PERSONAGEM));

    paladino->nome = nome;
    paladino->classe = classe;
    paladino->lvl = lvl;
    paladino->HP = HP;
    paladino->forca = forca;
    paladino->armadura = armadura;
    paladino->inteligencia = inteligencia;
    paladino->agilidade = agilidade;
    paladino->staminia = 10;

    paladino->subir_lvl = subir_lvl_paladino;
    paladino->aventureiro_menu = menu_paladino;
    paladino->aventureiro_nome = nome_paladino;
    paladino->ataque_fraco = paladino_ataque_fraco;
    paladino->ataque_forte = paladino_ataque_forte;
    paladino->aventureiro_magia1 = paladino_magia1;
    paladino->aventureiro_magia2 = paladino_magia2;
    paladino->aventureiro_passiva = paladino_passiva;
    paladino->descansar = paladino_descanso;

    return paladino;

}
