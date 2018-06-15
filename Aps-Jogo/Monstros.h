#ifndef MONSTROS_H_INCLUDED
#define MONSTROS_H_INCLUDED

typedef struct monstros{

    char *nome;
    int lvl;
    int HP;
    int forca;
    int armadura;
    int inteligencia;
    int agilidade;
    int staminia;

    void (*nome_monstro)();
    int (*ataque_fraco)(struct monstros *);
    int (*ataque_forte)(struct monstros *);
    int (*monstro_magia1)(struct monstros *);
    int (*monstro_magia2)(struct monstros *);
    void (*monstro_descanso)(struct monstros *);
    void (*monstro_menu)(int , int);
    void (*monstro_muda_staminia)(struct monstros *, int);
    int (*monstro_verifica_staminia)(struct monstros *, int);

} Monstro;

Monstro *new_ogro(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade);
Monstro *new_troll(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade);
Monstro *new_orc(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade);
Monstro *new_gigante(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade);
Monstro *new_goblin(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade);
Monstro *new_minotauro(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade);
Monstro *new_pirata(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade);
Monstro *new_djinn(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade);
Monstro *new_dragao(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade);
Monstro *new_demonio(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade);
Monstro *new_animal(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade);
Monstro *gerar_monstro();

#endif // MONSTROS_H_INCLUDED
