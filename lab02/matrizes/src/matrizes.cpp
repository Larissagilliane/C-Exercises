#include "matrizes.h"
#include <iostream>

using namespace std;

void print(int ** matriz, int linhas, int colunas)
{
	for(int cont1 = 0 ; cont1 < linhas ; cont1 ++)
	{
		for (int cont2 = 0 ; cont2 < colunas ; cont2 ++)
		{
			cout << matriz[cont1][cont2] << "   ";
		}
		cout << endl;
	}
}


void transpose(int ** & matriz, int linhas, int colunas)
{
	int **auxiliar;
  	auxiliar = new int*[colunas];

  	for(int i = 0;i < colunas; ++i)
        auxiliar[i] = new int[linhas]; //alocação

 	for(int cont1=0; cont1<linhas; cont1++)
 	{
 	  for(int cont2=0; cont2<colunas; cont2++) 
   	  {
    	auxiliar[cont2][cont1] = matriz[cont1][cont2];
  		
      }
    }

    print(auxiliar,colunas,linhas);

    for(int i = 0;i < linhas; ++i)
        delete []matriz[i];
 
    delete []matriz;     

    matriz=auxiliar;
}


int ** diagonal(int **matriz, int linhas, int colunas) // MUITAS DÚVIDAS
{
	int **simetrica;
	int i, j;
  	simetrica = new int*[linhas];

  	for(i = 0;i < linhas; ++i)
        simetrica[i] = new int[i+1]; 

    for (i=0; i<linhas;i++)
    	for(j = 0; j < i+1; j++)
    	{
    		simetrica[i][j] = matriz[i][j];
    	}

	cout << "Alocação com sucesso da matriz SIMÉTRICA " << endl;

	for(i = 0 ; i < linhas ; i ++)
	{
		for (j = 0 ; j < i+1 ; j ++)
		{
			cout << simetrica[i][j] << "    ";
		}
		cout << endl;
	}


	return simetrica;

}