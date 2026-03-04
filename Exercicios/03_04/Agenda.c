#include <stdio.h>
#include <stdlib.h>

typedef struct Contato
{
    char nome[128];
    char telefone[32];
} contato;

int novoContato(contato *c, int *capacidade, int modo);
void exibirContatos(contato *c, int capacidade);
void salvarContatos(contato *c, int capacidade);

void main()
{
    int capacidade = 0;

    contato *c;
    c = (contato *)malloc(sizeof(contato));

    if (c == NULL)
    {
        printf("\nErro ao alocar memória.\n");
        return;
    }

    FILE *file = fopen("contatos.csv", "r");
    if (file == NULL)
    {
        printf("\nNão há contatos salvos.\n");
    }
    else
    {
        char linha[160];
        while (fgets(linha, sizeof(linha), file))
        {
            if (capacidade == 0)
            {
                sscanf(linha, "%[^,],%s", c->nome, c->telefone);
                (capacidade)++;
            }
            else
            {
                c = (contato *)realloc(c, sizeof(contato) * (capacidade + 1));
                sscanf(linha, "%[^,],%s", c[capacidade].nome, c[capacidade].telefone);
                (capacidade)++;
            }
        }
    }

    int op;

    do
    {
        printf("\nO que deseja fazer?\nNovo Contato (1)\nExibir Contato (2)\nSalvar Contatos (3)\nSair (0)\nOpção: ");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            printf("Saindo...\n");
            break;
        case 1:
            switch (novoContato(c, &capacidade, 0))
            {
            case 0:
                break;
            case 1:
                c = (contato *)realloc(c, (capacidade + 1) * sizeof(contato));
                novoContato(c, &capacidade, 1);
                break;
            }
            printf("\nContato adicionado com sucesso.\n");
            break;
        case 2:
            exibirContatos(c, capacidade);
            break;
        case 3:
            printf("\nSalvando contatos...\n");
            salvarContatos(c, capacidade);
            break;
        }
    } while (op != 0);

    free(c);
    fclose(file);
}

int novoContato(contato *c, int *capacidade, int modo)
{
    if (*capacidade < 100)
    {
        switch (modo)
        {
        case 0:
            if (*capacidade == 0)
            {
                printf("\nDigite o nome do contato: ");
                scanf("%s", c->nome);
                printf("Digite o telefone do contato (Padrão: DDDXXXXXXXXX): ");
                scanf("%s", c->telefone);
                (*capacidade)++;
                return 0;
            }
            else
            {
                return 1;
            }
        case 1:
            printf("\nDigite o nome do contato: ");
            scanf("%s", c[*capacidade].nome);
            printf("Digite o telefone do contato (Padrão: DDDXXXXXXXXX): ");
            scanf("%s", c[*capacidade].telefone);
            (*capacidade)++;
            return 0;
        }
    }
    else
    {
        printf("Limite de contatos atingido.\n");
    }
}

void exibirContatos(contato *c, int capacidade)
{
    if (capacidade <= 0)
    {
        printf("\nNenhum contato para exibir.\n");
    }
    else
    {
        printf("\nQual contato deseja exibir? (1-%d): ", capacidade);
        int op;
        scanf("%d", &op);
        op--;
        if (op < 0 || op >= capacidade)
        {
            printf("Contato inválido.\n");
        }
        else
        {
            printf("\nNome: %s\n", c[op].nome);
            printf("Telefone: (%.3s) %.5s-%.4s\n", c[op].telefone, c[op].telefone + 3, c[op].telefone + 8);
        }
    }
}

void salvarContatos(contato *c, int capacidade)
{
    FILE *file = fopen("contatos.csv", "w");
    if (file == NULL)
    {
        printf("\nErro ao abrir o arquivo.\n");
    }
    for (int i = 0; i < capacidade; i++)
    {
        fprintf(file, "%s,%s\n", c[i].nome, c[i].telefone);
    }
    fclose(file);
}
