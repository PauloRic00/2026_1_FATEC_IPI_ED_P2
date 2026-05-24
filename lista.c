#include "lista.h"

void inicia_lista (t_lista *pl) {
    pl -> primeiro = NULL;
    pl -> ultimo = NULL;
}

int lista_vazia (t_lista *pl) {
    return pl -> primeiro == NULL;
}

void insere_inicio (int e, t_lista *pl) {
    t_no *novo = constroi_no(e);
    if (lista_vazia(pl)) {
        pl -> ultimo = novo;
    }
    novo -> proximo = pl -> primeiro;
    pl -> primeiro = novo;
}

void insere_fim (int e, t_lista *pl) {
    t_no *novo = constroi_no(e);
    if (lista_vazia(pl)) {
        pl -> primeiro = novo;
    }
    else {
        pl -> ultimo -> proximo = novo;
    }
    pl -> ultimo = novo;
}

int remove_inicio (t_lista *pl) {
    int copia_valor = pl -> primeiro -> info;
    t_no *copia_endereco = pl -> primeiro;
    pl -> primeiro = pl -> primeiro -> proximo;
    if (pl -> primeiro == NULL)
        pl -> ultimo = NULL;
    free(copia_endereco);
    return copia_valor;
}

int tamanho_lista (t_lista *pl) {
    int contador = 0;
    t_no *runner = pl -> primeiro;
    while (runner != NULL) {
        contador++;
        runner = runner -> proximo;
    }
    return contador;
}

void exibe_lista (t_lista *pl) {
    if (lista_vazia(pl))
        printf("Fila vazia!\n");
    else {
        t_no *runner = pl -> primeiro;
        while (runner != NULL) {
            if (runner -> info >= 100) {
                printf("[VIP %d] -> ", runner -> info);
            } else {
                printf("[%d] -> ", runner -> info);
            }
            runner = runner -> proximo;
        }
        printf("//\n");
    }
}

