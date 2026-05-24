#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void exibir_menu () {
    printf("\n==================================\n");
    printf("   SISTEMA DE FILA DE ATENDIMENTO   \n");
    printf("==================================\n");
    printf("1. Emitir nova senha\n");
    printf("2. Chamar proximo\n");
    printf("3. Ver fila atual\n");
    printf("4. Quantas pessoas estao na fila?\n");
    printf("5. Emitir senha VIP\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main () {
    t_lista fila;
    inicia_lista(&fila);

    int opcao;
    int senha_comum = 1;
    int senha_vip =100;

    do {
        exibir_menu();
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                insere_fim(senha_comum, &fila);
                printf(">>> Senha comum gerada: %d\n", senha_comum);
                senha_comum++;
                break;
                
            case 2:
                if (!lista_vazia(&fila)) {
                    int atendido = remove_inicio(&fila);
                    if (atendido >= 100) {
                        printf(">>> ATENDIMENTO CHAMADO: Senha VIP %d\n", atendido);
                    } else {
                        printf(">>> ATENDIMENTO CHAMADO: Senha Comum %d\n", atendido);
                    }
                } else {
                    printf(">>> A fila esta vazia. Ninguem aguardando atendimento.\n");
                }
                break;
                
            case 3:
                printf(">>> Status da Fila: ");
                exibe_lista(&fila);
                break;
                
            case 4:
                printf(">>> Pessoas aguardando atendimento: %d\n", tamanho_lista(&fila));
                break;
                
            case 5:
                insere_inicio(senha_vip, &fila);
                printf(">>> Senha VIP gerada: %d (Adicionada ao inicio da fila)\n", senha_vip);
                senha_vip++;
                break;
                
            case 0:
                printf(">>> Encerrando o sistema...\n");
                while(!lista_vazia(&fila)) {
                    remove_inicio(&fila);
                }
                break;
                
            default:
                printf(">>> Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);
}
