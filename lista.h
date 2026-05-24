#include "no.h"

typedef struct lista {
    t_no *primeiro;
    t_no *ultimo;
} t_lista;

void inicia_lista (t_lista *pl);

int lista_vazia (t_lista *pl);

void insere_inicio (int e, t_lista *pl);

void insere_fim (int e, t_lista *pl);

int remove_inicio (t_lista *pl);

int tamanho_lista (t_lista *pl);

void exibe_lista (t_lista *pl);

