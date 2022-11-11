#include "hash.h"
#include <stdio.h>

THEA *THEA_Criar(int tamanho)
{
    THEA *nova = (THEA *)malloc(sizeof(THEA));
    nova->tamanho = tamanho;
    nova->tabela = (EL *)malloc(sizeof(EL) * tamanho);
    nova->nOcupados = 0;
    for (int i = 0; i < tamanho; i++)
    {
        nova->tabela[i].estado = LIVRE;
    }
    return nova;
}

int THEa_Ins(THEA *TH, int chave, int valor)
{
    int count = 0;
    int h = THEA_Field(TH, chave);

    if (h < 0)
    {
        h = THEA_Hash(TH, chave, count);
        int h_ini = h;

        while (TH->tabela[h] == OCUPADO)
        {

            count++;
            h = THEA_Hash(TH, chave, count);
            if (h == h_ini)
            {
                return -1;
            }
            TH->nOcupados++;
        }
    }
    TH->tabela[h].estado = OCUPADO;
    TH->tabela[h].chave = chave;
    TH->tabela[h].valor = valor;

    return h;
}

int THEA_Busca(THEA *TH, int chave)
{
    int count = 0;
    int h = THEA_Hash(TH, chave, count);
    int h_ini = h;

    while (TH->tabela[h] != LIVRE)
    {
        if ((TH->tabela[h].estado == OCUPADO) && (TH->tabela[h].chave == chave))
        {
            return h;
        }

        count++;
        h = THEA_Hash(TH, chave, count);
        if (h == h_ini)
            return -1;
    }
    return -1;
}

int THEA_Remover(THEA *TH, int chave)
{
    int h = THEA_Busca(TH, chave);
    if (h < 0)
        return -1;
    TH->tabela[h].estado = REMOVIDO;
    return h;
}

void THEA_Imprimir(THEA *TH)
{
    for (int i = 0; i < TH->tamanho; i++)
    {
        printf(" ");
    }
}