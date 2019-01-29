#ifndef __MATRIZES_H__
#define __MATRIZES_H__

#include <iostream>

void print(int **matriz, int linhas, int colunas);

void transpose(int ** & matriz, int linhas, int colunas);

int ** diagonal(int **matriz, int linhas, int colunas);

#endif /* __MATRIZES_H__ */