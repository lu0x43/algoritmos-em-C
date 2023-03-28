#pragma once

typedef enum ESTADO
{
    LIVRE,
    OCUPADO,
    REMOVIDO
} ESTADO;

typedef struct EL
{
    int chave;
    int valor;
    ESTADO estado;
} EL;

// THEA is table hash element array
typedef struct THEA
{
    size_t tamanho;
    size_t nOcupados; 
    EL *tabela;
} THEA;