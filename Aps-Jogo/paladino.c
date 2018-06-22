#include <stdio.h>
#include <stdlib.h>
#include "Personagem.h"
#include "Monstros.h"

static void subir_lvl_paladino(struct personagem *paladino){

    static int hp=0, dano=0, armor=0, inte=0, agili=0;
    int i, numeroDeUps = 4;
    char escolha;

    paladino->lvl++;
    paladino->HP = 12 + hp;
    paladino->forca = 6 + dano;
    paladino->armadura = 6 + armor;
    paladino->inteligencia = 6 + inte;
    paladino->agilidade = 6 + agili;
    paladino->staminia = 10;

    printf("                              Parabens!!!\nVoce Subiu de lvl\n"
"                                   .''.            \n"
"       .''.      .        *''*    :_\/_:     .      \n"
"      :_\/_:   _\(/_  .:.*_\/_*   : /\ :  .'.:.'.   \n"
"  .''.: /\ :   ./)\   ':'* /\ * :  '..'.  -=:o:=-   \n"
" :_\/_:'.:::.    ' *''*    * '.\'/.' _\(/_'.':'.'   \n"
" : /\ : :::::     *_\/_*     -= o =-  /)\    '  *   \n"
"  '..'  ':::'     * /\ *     .'/.\'.   '            \n"
"      *            *..*         :                   \n");

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
            paladino->HP++;
            printf("\n                              HP = %d\n", paladino->HP);
            hp++;
        }
        if(escolha == '2'){
            paladino->forca++;
            printf("\n                              Forca = %d\n", paladino->forca);
            dano++;
        }
        if(escolha == '3'){
            paladino->armadura++;
            printf("\n                              Armadura = %d\n", paladino->armadura);
            armor++;
        }
        if(escolha == '4'){
            paladino->inteligencia++;
            printf("\n                              Intelifencia = %d\n", paladino->inteligencia);
            inte++;
        }
        if(escolha == '5'){
            paladino->agilidade++;
            printf("\a                              Agilidade = %d\n", paladino->agilidade);
            agili++;
        }
        numeroDeUps--;
        limpa_tela();
    }
    paladino->aventureiro_nome(paladino);
}

static void menu_paladino(struct personagem *paladino){

    printf("                              Seu turno \n\n");
    printf("                              Escolha o seu ataque:\n");
    printf("                              1-Curar\t");
    printf("                              2-Lança Solar\n");
    printf("                              3-Benção dos Ceus\t");
    printf("                              4-Punição Divina\n");
    printf("                              5-Descansar\n");
    printf("\n");

}

static void nome_paladino(struct personagem *paladino){

    printf("                              Nome = %s\n", paladino->nome);
    printf("                              Classe = %s\n", paladino->classe);
    printf("                              LVL = %d\n", paladino->lvl);
    printf("                              HP = %d\n", paladino->HP);
    printf("                              Forca = %d\n", paladino->forca);
    printf("                              Armadura = %d\n", paladino->armadura);
    printf("                              Inteligencia = %d\n", paladino->inteligencia);
    printf("                              Agilidade = %d\n", paladino->agilidade);
    printf("                              Staminia = %d\n", paladino->staminia);
    printf("\n");

}

static int paladino_ataque_fraco(struct personagem *paladino){

    int X;

    if(paladino->staminia < 3){

        printf("                              Voce nao conseguiu se curar\n");
        return -1;
    }

    if(paladino->staminia >= 3){

        X = 3 + paladino->lvl;
        paladino->HP = paladino->HP + X;

        printf("                              Você se Curou em = %d de HP\n", X);

        paladino->staminia = paladino->staminia - 3;

        return 0;
    }
}

static int paladino_ataque_forte(struct personagem *paladino){

    int X;

    if(paladino->staminia < 3){

        printf("                              Voce nao conseguiu atacar\n");
        return -1;

    }

    if(paladino->staminia >= 3){

    X = 1 + rand() % paladino->forca + paladino->inteligencia;

    printf("Lança Solar = %d\n", X);

    paladino->staminia = paladino->staminia - 3;

    return X;

    }

}

static int paladino_magia1(struct personagem *paladino){

    int X;
    char z;

    if(paladino->staminia < 4){

        printf("                              Voce nao conseguiu atacar\n");
        return -1;

    }

    if(paladino->staminia >= 4){

    printf("                              Escolha um atributo para ser abençoado em +1 ponto\n");
    printf("                              1- em força\n");
    printf("                              2- em inteligencia\n");
    z = getch();

    while(z <  49 || z > 50){

        printf("                              Nao existe esta opcao!!!\n");
        z = getch();

    }

    if(z == '1'){
    paladino->forca = paladino->forca + 1;
    printf("                              Benção dos Ceus agraciou vc com +1 em força\n");
    }
    if(z == '2'){
    paladino->inteligencia = paladino->inteligencia + 1;
    printf("                              Benção dos Ceus agraciou vc com +1 em inteligencia\n");
    }

    paladino->staminia = paladino->staminia - 4;

    return 0;

    }
}


static int paladino_magia2(struct personagem *paladino){

    int X;

    if(paladino->staminia < 4){

        printf("                              Voce nao conseguiu atacar\n");
        return -1;

    }

    if(paladino->staminia >= 4){

    X = (paladino->inteligencia + paladino->agilidade + paladino->forca) / 3;

    printf("                              Punição Divina = %d\n", X);

    paladino->staminia = paladino->staminia - 4;

    return X;

    }

}

static int paladino_passiva(struct personagem *paladino, struct monstros *monstro){

    static int cont = 0;
    static int X;
    int Z;

    if(cont == 0){
        X = (paladino->HP*30)/100;
        cont++;
    }

    if(monstro->HP > 0 && cont == 1 && paladino->HP <= X){

        printf("                              Sunshine\n");
        printf("                              Sofra o poder da minha magia gloriosa\n");
        Z = paladino->inteligencia + paladino->forca + paladino->lvl;
        monstro->HP = monstro->HP - Z;
        printf("                              %s sofreu %d de dano\n", monstro->nome, Z);
        limpa_tela();
        system("START https://universoestendido.com.br/wp-content/uploads/2018/02/escanor-vs-galan.jpg");

    }

    if(monstro->HP <= 0){
        cont = 0;
    }

    return 0;

}

static void paladino_descanso(struct personagem *paladino){

    if(paladino->staminia == 10){
        printf("                              Voce ja esta descansado\n");
    }

    if(paladino->staminia == 9){
        paladino->staminia++;
        printf("                              Voce recuperou 1 de stamina\n");
    }
    if(paladino->staminia < 9){
        paladino->staminia = paladino->staminia + 2;
        printf("                              Voce recuperou 2 de stamina\n");
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
