#include <stdio.h>
#include <stdlib.h>
#include "Personagem.h"
#include "Monstros.h"

static void subir_lvl_mago(struct personagem *mago){

    static int hp=0, dano=0, armor=0, inte=0, agili=0;
    int i, numeroDeUps = 4;
    char escolha;

    mago->lvl++;
    mago->HP = 8 + hp;
    mago->forca = 2 + dano;
    mago->armadura = 7 + armor;
    mago->inteligencia = 10 + inte;
    mago->agilidade = 3 + agili;
    mago->staminia = 10;

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
            mago->HP++;
            printf("\nHP = %d\n", mago->HP);
            hp++;
        }
        if(escolha == '2'){
            mago->forca++;
            printf("\nForca = %d\n", mago->forca);
            dano++;
        }
        if(escolha == '3'){
            mago->armadura++;
            printf("\nArmadura = %d\n", mago->armadura);
            armor++;
        }
        if(escolha == '4'){
            mago->inteligencia++;
            printf("\nIntelifencia = %d\n", mago->inteligencia);
            inte++;
        }
        if(escolha == '5'){
            mago->agilidade++;
            printf("\aAgilidade = %d\n", mago->agilidade);
            agili++;
        }
        numeroDeUps--;
        limpa_tela();
    }
    mago->aventureiro_nome(mago);
}

static void menu_mago(struct personagem *mago){

    printf("Seu turno \n\n");
    printf("Escolha o seu ataque:\n");
    printf("1-Bola de fogo\t");
    printf("2-Inferno\n");
    printf("3-Meteoro arcano\t");
    printf("4-Suspiro do Dragão\n");
    printf("5-Descansar\n");
    printf("\n");

}

static void nome_mago(struct personagem *mago){

    printf("Nome = %s\n", mago->nome);
    printf("Classe = %s\n", mago->classe);
    printf("LVL = %d\n", mago->lvl);
    printf("HP = %d\n", mago->HP);
    printf("Forca = %d\n", mago->forca);
    printf("Armadura = %d\n", mago->armadura);
    printf("Inteligencia = %d\n", mago->inteligencia);
    printf("Agilidade = %d\n", mago->agilidade);
    printf("Staminia = %d\n", mago->staminia);
    printf("\n");

}

static int mago_ataque_fraco(struct personagem *mago){

    int X;

    if(mago->staminia < 2){

        printf("Voce nao conseguiu atacar\n");
        return -1;
    }

    if(mago->staminia >= 2){

        X = rand() % mago->inteligencia;

        printf("Bola de Fogo = %d\n", X);

        mago->staminia = mago->staminia - 2;

        return X;
    }
}

static int mago_ataque_forte(struct personagem *mago){

    int X;

    if(mago->staminia < 4){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(mago->staminia >= 4){

    X = mago->forca + rand() % mago->inteligencia;

    printf("Área Infernal = %d\n", X);

    mago->staminia = mago->staminia - 4;

    return X;

    }

}

static int mago_magia1(struct personagem *mago){

    int X, Y, Z;

    if(mago->staminia <= 0){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(mago->staminia == 1){

        X = mago->lvl + rand() % 2;
        printf("1 Meteoro Arcano = %d\n", X);
        mago->staminia = mago->staminia - 1;
        return X;

    }

    if(mago->staminia == 2){

        X = mago->lvl + rand() % 2;
        Y = mago->lvl + rand() % 3;
        printf("2 Meteoros Arcanos = %d\n", X);
        mago->staminia = mago->staminia - 2;
        return X + Y;

    }

    if(mago->staminia >= 3){

    X = mago->lvl + rand() % 2;
    Y = mago->lvl + rand() % 3;
    Z = mago->lvl + rand() % 4;

    X = X + Y + Z;

    printf("3 Meteoros Arcanos = %d\n", X);

    mago->staminia = mago->staminia - 3;

    return X;

    }
}


static int mago_magia2(struct personagem *mago){

    int X;

    if(mago->staminia < 5){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(mago->staminia >= 5){

    X = rand() % mago->inteligencia * mago->lvl;

    printf("Suspiro do Dragão = %d\n", X);

    mago->staminia = mago->staminia - 5;

    return X;

    }

}

static int mago_passiva(struct personagem *mago, struct monstros *monstro){

    int X = 0, A;
    char z;

    if(monstro->HP > 0){

        printf("Ele puxa uma faca de seu bolso\n");
        printf("Você quer usar uma magia de sangue?\n");
        printf("0- Não\n");
        printf("1- Drenar Vida\n");
        printf("2- Amaterasu\n");
        printf("3- Toque Demoniaco\n");

        z = getch();

        while(z <  40 || z > 51){

            printf("Nao existe esta opcao!!!\n");
            z = getch();

        }

        if(z == '0'){
            return 0;
        }
        if(z == '1'){
            A = mago->inteligencia - monstro->inteligencia;
            if(A <= 0){
                printf("Você e muito fraco, não consegue drenar vida\n");
                printf("Você sofreu 2 de dano\n");
                mago->HP = mago->HP - 2;
            }else{
                printf("Você drenou %d de vida do %s\n", A, monstro->nome);
                monstro->HP = monstro->HP - A;
                mago->HP = mago->HP + A;
            }
            z = getch();
            return 1;
        }
        if(z == '2'){
            A = mago->inteligencia - monstro->inteligencia;
            printf("Amaterasu esta queimando %s sofreu %d de dano\n", monstro->nome, A);
            printf("Você sofreu 3 de dano\n");
            mago->HP = mago->HP - 3;
            monstro->HP = monstro->HP - A;
            z = getch();
            return 1;
        }
        if(z == '3'){
            A = mago->inteligencia;
            printf("%s foi tocado por um demonio sofrendo %d de dano\n", monstro->nome, A);
            printf("Você sofreu 5 de dano\n");
            mago->HP = mago->HP - 5;
            monstro->HP = monstro->HP - A;
            z = getch();
            return 1;
        }

    }

}

static void mago_descanso(struct personagem *mago){

    if(mago->staminia == 10){
        printf("Voce ja esta descansado\n");
    }

    if(mago->staminia == 9){
        mago->staminia++;
        printf("Voce recuperou 1 de stamina\n");
    }
    if(mago->staminia < 9){
        mago->staminia = mago->staminia + 2;
        printf("Voce recuperou 2 de stamina\n");
    }
}

PERSONAGEM *new_mago(char *nome, char *classe, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    //-> ponteiro do tipo de uma estrutura que esta recebendo tal valor

    PERSONAGEM *mago = (PERSONAGEM *) malloc(sizeof(PERSONAGEM));

    mago->nome = nome;
    mago->classe = classe;
    mago->lvl = lvl;
    mago->HP = HP;
    mago->forca = forca;
    mago->armadura = armadura;
    mago->inteligencia = inteligencia;
    mago->agilidade = agilidade;
    mago->staminia = 10;

    mago->subir_lvl = subir_lvl_mago;
    mago->aventureiro_menu = menu_mago;
    mago->aventureiro_nome = nome_mago;
    mago->ataque_fraco = mago_ataque_fraco;
    mago->ataque_forte = mago_ataque_forte;
    mago->aventureiro_magia1 = mago_magia1;
    mago->aventureiro_magia2 = mago_magia2;
    mago->aventureiro_passiva = mago_passiva;
    mago->descansar = mago_descanso;

    return mago;

}
