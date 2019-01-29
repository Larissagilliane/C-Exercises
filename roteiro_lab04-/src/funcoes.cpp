#include <iostream>
#include "funcoes.h"

using namespace std;

void print(int ** matriz, int linhas, int colunas)
{
	for(int cont1 = 0 ; cont1 < linhas ; cont1 ++)
	{
		for (int cont2 = 0 ; cont2 < colunas ; cont2 ++)
		{
			cout << matriz[cont1][cont2] << "      ";
		}
		cout << endl;
	}
}

void criando_identidade(int linhas, int colunas, int ** matrizaux)
{
	int i=0;
	int j=0;

    for(i = 0;i < linhas; ++i)
        matrizaux[i] = new int[colunas]; //alocação

	for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            if(i == j)
            {
                matrizaux[i][j] = 1;
            }
            else
            {
                matrizaux[i][j] = 0; 
            }
        }
    }
}

