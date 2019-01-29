#include "matrizes.h"
 #include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char * argv[])
{

	int linhas;
    int colunas;

    		cout << "Digite o número de linhas:    " << endl;
		    cin >> linhas;

		    cout << "Digite o número de colunas:    " << endl;
		    cin >> colunas;

		    int **matriz;
		    matriz = new int*[linhas]; //alocação
		 
		    for(int i = 0;i < linhas; ++i)
		        matriz[i] = new int[colunas]; //alocação
		 
		    for(int cont1 = 0 ; cont1 < linhas ; cont1 ++)
			{
				for (int cont2 = 0; cont2 < colunas ; cont2 ++)
				{
					cout << "Digite o valor da linha "  << cont2 << " e da coluna " << cont1 << endl;
					cin >> matriz[cont1][cont2];
					cout << endl;
				} 
			}

			cout << "É essa é sua matriz : " << endl;
			print(matriz,linhas,colunas);

			cout << "É essa é sua matriz transposta: " << endl;
			transpose(matriz,linhas,colunas)  ;  


	diagonal( matriz, linhas, colunas);

			    for(int i = 0; i < colunas; ++i)
		        delete []matriz[i];
		 
		    delete []matriz; 
		 

    return 0;

}


