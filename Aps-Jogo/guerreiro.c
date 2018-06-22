#include <stdio.h>
#include <stdlib.h>
#include "Personagem.h"
#include "Monstros.h"

static void subir_lvl_guerreiro(struct personagem *guerreiro){

    static int hp=0, dano=0, armor=0, inte=0, agili=0;
    int i, numeroDeUps = 4;
    char escolha;

    guerreiro->lvl++;
    guerreiro->HP = 15 + hp;
    guerreiro->forca = 7 + dano;
    guerreiro->armadura = 5 + armor;
    guerreiro->inteligencia = 4 + inte;
    guerreiro->agilidade = 4 + agili;
    guerreiro->staminia = 10;

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
        printf("                              Como recompença pela luta, terá pontos\n "
               "                             para aumentar sua habilidade!!!\n");
        printf("                              Voce possui: %d pontos para upar:\n\n", numeroDeUps);
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
            guerreiro->HP++;
            printf("\n                              HP = %d\n", guerreiro->HP);
            hp++;
        }
        if(escolha == '2'){
            guerreiro->forca++;
            printf("\n                              Forca = %d\n", guerreiro->forca);
            dano++;
        }
        if(escolha == '3'){
            guerreiro->armadura++;
            printf("\n                              Armadura = %d\n", guerreiro->armadura);
            armor++;
        }
        if(escolha == '4'){
            guerreiro->inteligencia++;
            printf("\n                              Intelifencia = %d\n", guerreiro->inteligencia);
            inte++;
        }
        if(escolha == '5'){
            guerreiro->agilidade++;
            printf("\a                              Agilidade = %d\n", guerreiro->agilidade);
            agili++;
        }
        numeroDeUps--;
        limpa_tela();
    }
    guerreiro->aventureiro_nome(guerreiro);
}

static void menu_guerreiro(struct personagem *guerreiro){
    printf("                              Seu turno \n\n");
    printf("                              Escolha o seu ataque:\n");
    printf("                              1-Espadada (-2 Stamina)\n");
    printf("                              2-Golpe com escudo (-3 Stamina)\n");
    printf("                              3-Golpe Devastador (-4 Stamina)\n");
    printf("                              4-Ataque do Dragão (-7 Stamina)\n");
    printf("                              5-Descansar\n");
    printf("\n");

}

static void nome_guerreiro(struct personagem *guerreiro){

    printf("                              Nome = %s\n", guerreiro->nome);
    printf("                              Classe = %s\n", guerreiro->classe);
    printf("                              LVL = %d\n", guerreiro->lvl);
    printf("                              HP = %d\n", guerreiro->HP);
    printf("                              Forca = %d\n", guerreiro->forca);
    printf("                              Armadura = %d\n", guerreiro->armadura);
    printf("                              Inteligencia = %d\n", guerreiro->inteligencia);
    printf("                              Agilidade = %d\n", guerreiro->agilidade);
    printf("                              Staminia = %d\n", guerreiro->staminia);
    printf("\n");

}

static int guerreiro_ataque_fraco(struct personagem *guerreiro){

    int X;

    if(guerreiro->staminia < 2){

        printf("                              Voce nao conseguiu atacar\n");
        return -1;
    }

    if(guerreiro->staminia >= 2){

        X = 2 + rand() % guerreiro->forca;

        printf("                              Golpe com a espada = %d\n", X);

        guerreiro->staminia = guerreiro->staminia - 2;

        return X;
    }
}

static int guerreiro_ataque_forte(struct personagem *guerreiro){

    int X;

    if(guerreiro->staminia < 3){

        printf("                              Voce nao conseguiu atacar\n");
        return -1;

    }

    if(guerreiro->staminia >= 3){

        X = guerreiro->armadura + rand() % guerreiro->forca;

        printf("                              Escudada = %d\n", X);

        guerreiro->staminia = guerreiro->staminia - 3;

        return X;

    }

}

static int guerreiro_magia1(struct personagem *guerreiro){

    int X;

    if(guerreiro->staminia < 4){

        printf("                              Voce nao conseguiu atacar\n");
        return -1;

    }

    if(guerreiro->staminia >= 4){

        X = rand() % guerreiro->forca;
        X = X * 2;

        printf("                              Golpe devastador = %d\n", X);

        guerreiro->staminia = guerreiro->staminia - 4;

        return X;

    }
}


static int guerreiro_magia2(struct personagem *guerreiro){

    int X;

    if(guerreiro->staminia < 7){

        printf("                              Voce nao conseguiu atacar\n");
        return -1;

    }

    if(guerreiro->staminia >= 7){

        X = 1 + rand() % guerreiro->forca;
        X = X * guerreiro->forca;

        printf("                              Ataque do Dragão = %d\n", X);

        guerreiro->staminia = guerreiro->staminia - 7;

        return X;

    }

}

static int guerreiro_passiva(struct personagem *guerreiro, struct monstros *monstro){

    static int cont = 0;
    static int X, Y;

    if(cont == 0){
        X = (guerreiro->HP*30)/100;
        Y = (guerreiro->HP*70)/100;
        cont++;
    }

    if(monstro->HP > 0 && guerreiro->HP <= X && cont == 1){
        guerreiro->HP = guerreiro->HP + Y;
        printf("                              Beseker ativado!!!\n");
        printf("                              %s possui agora de %d vida \n", guerreiro->nome, guerreiro->HP);
        cont++;
    }

    if(monstro->HP <= 0){
        cont = 0;
    }

    return 0;
}

static void guerreiro_descanso(struct personagem *guerreiro){

    if(guerreiro->staminia == 10){
        printf("                              Voce ja esta descansado\n");
    }

    if(guerreiro->staminia == 9){
        guerreiro->staminia++;
        printf("                              Voce recuperou 1 de stamina\n");
    }
    if(guerreiro->staminia < 9){
        guerreiro->staminia = guerreiro->staminia + 2;
        printf("                              Voce recuperou 2 de stamina\n");
    }
}

PERSONAGEM *new_guerreiro(char *nome, char *classe, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    //-> ponteiro do tipo de uma estrutura que esta recebendo tal valor

    PERSONAGEM *guerreiro = (PERSONAGEM *) malloc(sizeof(PERSONAGEM));

    guerreiro->nome = nome;
    guerreiro->classe = classe;
    guerreiro->lvl = lvl;
    guerreiro->HP = HP;
    guerreiro->forca = forca;
    guerreiro->armadura = armadura;
    guerreiro->inteligencia = inteligencia;
    guerreiro->agilidade = agilidade;
    guerreiro->staminia = 10;

    guerreiro->subir_lvl = subir_lvl_guerreiro;
    guerreiro->aventureiro_menu = menu_guerreiro;
    guerreiro->aventureiro_nome = nome_guerreiro;
    guerreiro->ataque_fraco = guerreiro_ataque_fraco;
    guerreiro->ataque_forte = guerreiro_ataque_forte;
    guerreiro->aventureiro_magia1 = guerreiro_magia1;
    guerreiro->aventureiro_magia2 = guerreiro_magia2;
    guerreiro->aventureiro_passiva = guerreiro_passiva;
    guerreiro->descansar = guerreiro_descanso;

    return guerreiro;

}
