#include <stdio.h>
#include "hash.h"

int main(int argc, char **argv)
{
    THEA *th = THEA_Criar(7);
    THEA_Ins(th, 12, 0);
    THEA_Ins(th, 5, 0);
    THEA_Ins(th, 6, 0);
    THEA_Remover(th, 5);
    int pos = THEA_Buscar(th, 6);
    
}