#include <stdio.h>
#include <stdlib.h>
#include "Personagem.h"
#include "Monstros.h"

static void subir_lvl_ladino(struct personagem *ladino){

    static int hp=0, dano=0, armor=0, inte=0, agili=0;
    int i, numeroDeUps = 4;
    char escolha;

    ladino->lvl++;
    ladino->HP = 10 + hp;
    ladino->forca = 4 + dano;
    ladino->armadura = 5 + armor;
    ladino->inteligencia = 4 + inte;
    ladino->agilidade = 10 + agili;
    ladino->staminia = 10;

    printf("                              Parabens!!! Voce Subiu de lvl\n"
"                                                                 .''.            \n"
"                                     .''.      .        *''*    :_\/_:     .      \n"
"                                    :_\/_:   _\(/_  .:.*_\/_*   : /\ :  .'.:.'.   \n"
"                                .''.: /\ :   ./)\   ':'* /\ * :  '..'.  -=:o:=-   \n"
"                               :_\/_:'.:::.    ' *''*    * '.\'/.' _\(/_'.':'.'   \n"
"                               : /\ : :::::     *_\/_*     -= o =-  /)\    '  *   \n"
"                                '..'  ':::'     * /\ *     .'/.\'.   '            \n"
"                                    *            *..*         :                   \n");

    for(i = 0; i < 4; i++){

        printf("                              Voce possui: %d pontos para upar\n\n", numeroDeUps);
        printf("                              1- Mais 1 de HP\n");
        printf("                              2- Mais 1 de Forca\n");
        printf("                              3- Mais 1 de armadura\n");
        printf("                              4- Mais 1 de inteligencia\n");
        printf("                              5- Mais 1 de agilidade\n");

        printf("                              Digite sua escolha: ");
        escolha = getch();
        printf("\n");

        while(escolha <  49 || escolha > 53){

            printf("                              Nao existe esta opcao!!!\n");
            escolha = getch();

        }

        if(escolha == '1'){
            ladino->HP++;
            printf("                              \nHP = %d\n", ladino->HP);
            hp++;
        }
        if(escolha == '2'){
            ladino->forca++;
            printf("\n                              Forca = %d\n", ladino->forca);
            dano++;
        }
        if(escolha == '3'){
            ladino->armadura++;
            printf("\n                              Armadura = %d\n", ladino->armadura);
            armor++;
        }
        if(escolha == '4'){
            ladino->inteligencia++;
            printf("\n                              Intelifencia = %d\n", ladino->inteligencia);
            inte++;
        }
        if(escolha == '5'){
            ladino->agilidade++;
            printf("\n                              Agilidade = %d\n", ladino->agilidade);
            agili++;
        }
        numeroDeUps--;
        limpa_tela();
    }
    ladino->aventureiro_nome(ladino);
}

static void menu_ladino(struct personagem *ladino){

    printf("                              Seu turno \n\n");
    printf("                              Escolha o seu ataque:\n");
    printf("                              1-Golpe Rápido com Adaga (-2 Stamina)\n");
    printf("                              2-Flechas Rápidas (-2 Stamina)\n");
    printf("                              3-Chuva de Flechas (-3 Stamina)\n");
    printf("                              4-Corte Mortal (-5 Stamina)\n");
    printf("                              5-Descansar\n");
    printf("\n");

}

static void nome_ladino(struct personagem *ladino){

    printf("                              Nome = %s\n", ladino->nome);
    printf("                              Classe = %s\n", ladino->classe);
    printf("                              LVL = %d\n", ladino->lvl);
    printf("                              HP = %d\n", ladino->HP);
    printf("                              Forca = %d\n", ladino->forca);
    printf("                              Armadura = %d\n", ladino->armadura);
    printf("                              Inteligencia = %d\n", ladino->inteligencia);
    printf("                              Agilidade = %d\n", ladino->agilidade);
    printf("                              Staminia = %d\n", ladino->staminia);
    printf("\n");

}

static int ladino_ataque_fraco(struct personagem *ladino){

    int X, Z;

    if(ladino->staminia < 2){

        printf("                              Voce nao conseguiu atacar\n");
        return -1;
    }

    if(ladino->staminia >= 2){

    Z = rand() % 4;

    if(Z == 0){

        X = ladino->lvl + rand() % ladino->agilidade;
        X = X * 2;

        printf("                              Golpe Rápido com Adaga Critico = %d\n", X);

        ladino->staminia = ladino->staminia - 2;

        return X;

    }

        X = 1 + rand() % ladino->agilidade;

        printf("                              Golpe Rápido com Adaga = %d\n", X);

        ladino->staminia = ladino->staminia - 2;

        return X;
    }
}

static int ladino_ataque_forte(struct personagem *ladino){

    int X, Z;

    if(ladino->staminia < 2){

        printf("                              Voce nao conseguiu atacar\n");
        return -1;

    }

    if(ladino->staminia >= 2){

    Z = rand() % 4;

    if(Z == 1){

        X = ladino->lvl + rand() % ladino->agilidade;
        X = X * 2;

        printf("                              Flechas Rápidas Critico = %d\n", X);

        ladino->staminia = ladino->staminia - 2;

        return X;

    }

    X = ladino->lvl + rand() % ladino->agilidade;

    printf("                              Flechas Rápidas = %d\n", X);

    ladino->staminia = ladino->staminia - 2;

    return X;

    }

}

static int ladino_magia1(struct personagem *ladino){

    int X, Z;

    if(ladino->staminia < 3){

        printf("                              Voce nao conseguiu atacar\n");
        return -1;

    }

    if(ladino->staminia >= 3){

    Z = rand() % 4;

    if(Z == 2){

        X = rand() % ladino->agilidade;
        X = X + 5;
        X = X * 2;

        printf("                              Chuva de Flechas Critico = %d\n", X);

        ladino->staminia = ladino->staminia - 3;

        return X;

    }

    X = rand() % ladino->agilidade;
    X = X + 5;

    printf("                              Chuva de Flechas = %d\n", X);

    ladino->staminia = ladino->staminia - 3;

    return X;

    }
}


static int ladino_magia2(struct personagem *ladino){

    int X, Z;

    if(ladino->staminia < 5){

        printf("                              Voce nao conseguiu atacar\n");
        return -1;

    }

    if(ladino->staminia >= 5){

        Z = rand() % 4;

        if(Z == 3){

            X = ladino->agilidade;
            X = X * 2;

            printf("                              Corte Mortal Critico = %d\n", X);

            ladino->staminia = ladino->staminia - 5;

            return X;

        }

    X = ladino->agilidade;

    printf("                              Corte Mortal = %d\n", X);

    ladino->staminia = ladino->staminia - 5;

    return X;

    }

}

static int ladino_passiva(struct personagem *ladino, struct monstros *monstro){

    return 0;

}

static void ladino_descanso(struct personagem *ladino){

    if(ladino->staminia == 10){
        printf("                              Voce ja esta descansado\n");
    }

    if(ladino->staminia == 9){
        ladino->staminia++;
        printf("                              Voce recuperou 1 de stamina\n");
    }
    if(ladino->staminia < 9){
        ladino->staminia = ladino->staminia + 2;
        printf("                              Voce recuperou 2 de stamina\n");
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
