#ifndef PERSONAGEM_H_INCLUDED
#define PERSONAGEM_H_INCLUDED

typedef struct personagem{

    char *nome;
    char *classe;
    int lvl;
    int HP;
    int forca;
    int armadura;
    int inteligencia;
    int agilidade;
    int staminia;

    void (*subir_lvl)(struct personagem *);
    void (*aventureiro_menu)();
    void (*aventureiro_nome)();
    int (*ataque_fraco)(struct personagem *);
    int (*ataque_forte)(struct personagem *);
    int (*aventureiro_magia1)(struct personagem *);
    int (*aventureiro_magia2)(struct personagem *);
    int (*aventureiro_passiva)(struct personagem *, struct monstros *);
    void (*descansar)(struct personagem *);

} PERSONAGEM;

PERSONAGEM *new_guerreiro(char *nome, char *classe, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade);
PERSONAGEM *new_mago(char *nome, char *classe, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade);
PERSONAGEM *new_ladino(char *nome, char *classe, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade);
PERSONAGEM *new_paladino(char *nome, char *classe, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade);
PERSONAGEM *new_muriel(char *nome, char *classe, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade);
PERSONAGEM *criar_personagem();
double randomico_gausiano (double mu, double sigma);

#endif // PERSONAGEM_H_INCLUDED
