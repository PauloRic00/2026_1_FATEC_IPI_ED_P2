# Sistema de Fila de Atendimento — P2 Estrutura de Dados (Fatec Ipiranga)

Este repositório contém a implementação do projeto desenvolvido para a avaliação **P2** da disciplina de **Estrutura de Dados** na **Fatec Ipiranga**.

O objetivo do projeto é simular um **Sistema de Fila de Atendimento** interativo via terminal, utilizando uma **Lista Encadeada Simplesmente Encadeada** com ponteiros para o início e para o fim da estrutura.

---

## Funcionalidades do Sistema

1. **Emitir Nova Senha Comum:** Insere um novo cliente no **final da fila** (conceito FIFO - *First In, First Out*).
2. **Emitir Senha VIP:** Insere um cliente prioritário diretamente no **início da fila**, furando a fila padrão.
3. **Chamar Próximo:** Remove e atende a pessoa que está no **início da fila**.
4. **Ver Fila Atual:** Exibe o estado visual de toda a fila com a indicação dos tipos de senha (`[1] -> [VIP 100] -> //`).
5. **Quantas pessoas estão na fila?:** Percorre a estrutura e exibe a quantidade total de senhas aguardando.
6. **Encerrar Sistema:** Limpa todos os nós alocados dinamicamente na memória antes de finalizar o programa.

---

## Arquitetura e Estrutura dos Arquivos

O projeto segue o princípio de **Modularização** e **Tipo Abstrato de Dados (TAD)** em linguagem C:

| Arquivo | Descrição |
| :--- | :--- |
| `no.h` | Definição da estrutura do nó (`t_no`) e protótipo de criação de nós. |
| `no.c` | Alocação dinâmica de memória (`malloc`) e inicialização do nó. |
| `lista.h` | Definição da estrutura do cabeçalho da lista (`t_lista`) e protótipos das operações. |
| `lista.c` | Implementação das operações da lista (inserções, remoções, busca, exibição). |
| `main.c` | Interface de menu interativo via terminal que integra as operações da lista. |

---

## Aprendizado Progressivo de Conceitos

Através do desenvolvimento deste código, foi possível consolidar uma evolução clara de conceitos fundamentais da ciência da computação e linguagem C:

### 1. Alocação Dinâmica e Gerenciamento de Memória
* **Uso do `malloc`:** Compreensão de como requisitar memória em tempo de execução para os nós da estrutura (`constroi_no`), evitando o desperdício de memória estática.
* **Liberação com `free`:** Manipulação segura do ponteiro e desalocação manual da memória na função `remove_inicio` e na limpeza final da lista ao encerrar o sistema, prevenindo vazamentos de memória (*memory leaks*).

### 2. Ponteiros e Manipulação de Endereços
* **Passagem por Referência:** Uso de ponteiros (`t_lista *pl`) para alterar o estado original da estrutura dentro de funções sem a necessidade de copiar a estrutura inteira.
* **Encadeamento:** Conexão lógica entre elementos da memória onde cada nó armazena seu dado (`info`) e o endereço do próximo nó (`proximo`).

### 3. Modificações na Estrutura de Fila (Otimização)
* **Ponteiro para o Úlitmo Elemento (`ultimo`):** Adição de um ponteiro direto para o final da fila. Isso permitiu otimizar a inserção de senhas comuns (`insere_fim`) para tempo constante $O(1)$, evitando ter que percorrer toda a lista para adicionar no fim.
* **Flexibilidade da Lista Encadeada:** Diferente de uma fila rígida (FIFO pura), a lista encadeada permitiu criar regras de prioridade com o uso da `insere_inicio` para senhas **VIP**.

### 4. Percorrimento (*Traversing*) e Manipulação
* **Variável Ponteiro Auxiliar (`runner`):** Técnica para percorrer a lista elemento por elemento sem perder o endereço do início (`primeiro`), aplicada tanto no cálculo de tamanho quanto na exibição e formatada dos elementos na tela.

---

## Como Executar o Projeto

1. Compile todos os arquivos `.c` usando o `gcc`:
   ```bash
   gcc main.c lista.c no.c -o sistema_fila
   ```

2. Execute o binário gerado:
     ```bash
     .\sistema_fila.exe
     ```
