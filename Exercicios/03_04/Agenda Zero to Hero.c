#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contato
{
    char nome[128];
    char telefone[16];
} contato;

void novoContato(contato *c, int *capacidade);
void exibirContatos(contato *c, int capacidade);
void salvarContatos(contato *c, int capacidade);
void lerContatos(contato *c, int *capacidade);

void main()
{
    int capacidade = 1;
    contato *c;
    c = (contato *)malloc(capacidade * sizeof(contato));
    if (c == NULL)
    {
        printf("Erro ao alocar memória.");
        return;
    }

    lerContatos(c, &capacidade);

    int op;

    do
    {
        printf("O que deseja fazer?\nNovo Contato (1)\nExibir Contato (2)\nSalvar Contatos (3)\nSair (0)\nOpção: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            novoContato(c, &capacidade);
            break;
        case 2:
            exibirContatos(c, capacidade);
            break;
        case 3:
            salvarContatos(c, capacidade);
            break;
        case 0:
            printf("Saindo...");
            break;
        }
    } while (op != 0);

    free(c);
}

void novoContato(contato *c, int *capacidade)
{
    if (*capacidade < 100)
    {
        if (*capacidade <= 1)
        {
            printf("Digite o nome do contato: ");
            scanf("%s", c->nome);
            printf("Digite o telefone do contato (somente dígitos, ex: DDDXXXXXXXXX): ");
            scanf("%s", c->telefone);
            (*capacidade)++;
        }
        else
        {
            c = (contato *)realloc(c, sizeof(contato) * (*capacidade));
            printf("Digite o nome do contato: ");
            scanf("%s", c[*capacidade-1].nome);
            printf("Digite o telefone do contato (somente dígitos, ex: DDDXXXXXXXXX): ");
            scanf("%s", c[*capacidade-1].telefone);
            (*capacidade)++;
        }
    }
    else
    {
        printf("Limite de contatos atingido!");
    }
}

void exibirContatos(contato *c, int capacidade)
{
    int op;
    printf("Qual contato deseja exibir? (1-%d): ", capacidade-1);
    scanf("%d", &op);
    if (op <= 0 || op > capacidade)
    {
        printf("Contato inválido!");
    }
    else
    {
        printf("Nome: %s\n", c[op - 1].nome);
        printf("Telefone: (%.3s) %.5s-%.4s\n", c[op - 1].telefone, c[op - 1].telefone + 3, c[op - 1].telefone + 8);
    }
}

void salvarContatos(contato *c, int capacidade)
{
    FILE *file = fopen("contatos.csv", "w");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        return;
    }
    for (int i = 0; i < capacidade; i++)
    {
        fprintf(file, "%s,%s\n", c[i].nome, c[i].telefone);
    }
    fclose(file);
}

void lerContatos(contato *c, int *capacidade)
{
    FILE *file = fopen("contatos.csv", "r");
    if (file == NULL)
    {
        printf("Nenhum contato salvo encontrado.\n");
        return;
    }
    else
    {
        char linha[144];
        while (fgets(linha, sizeof(linha), file))
        {
            if (*capacidade >= 100)
            {
                printf("Limite de contatos atingido.");
                break;
            }
            printf("Capacidade: %d\n", *capacidade);

            if (*capacidade <= 1)
            {
                sscanf(linha, "%127[^,],%15s", c->nome, c->telefone);
            }
            else
            {
                c = (contato *)realloc(c, sizeof(contato) * (*capacidade + 1));
                sscanf(linha, "%127[^,],%15s", c[*capacidade].nome, c[*capacidade].telefone);
                (*capacidade)++;
            }
        }
    }
    fclose(file);
}