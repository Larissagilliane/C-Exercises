#include "matrizes.h"
 #include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(int argc, char * argv[])
{

	int linhas, colunas;
    
      std::cout << "Digite as linhas \n ";
      cin >> linhas;
      std::cout << "Digite as colunas \n ";
      cin >> colunas;
  
      std::vector< std::vector<int> > matriz;
		 
		    for(int i = 0 ; i < linhas ; i ++)
			{
				vector<int> tamanho;
				for (int j = 0; j < colunas ; j ++)
				{
					tamanho.push_back(i * j);
				} 
				matriz.push_back(tamanho);
			}
			
			for (int i = 0; i < linhas; i++) 
			{
			    for (size_t j = 0; j < matriz[i].capacity(); j++)
			    {
			    	cout << "Digite o valor da linha "  << i << " e da coluna " << j << endl;
			      	cin >> matriz [i][j];
			    }
		    }
		    
		    if (linhas==colunas)
		    {
		    	cout << "Simétrica" <<  endl;
		   		diagonal( matriz, linhas, colunas);
		    }
		    else 
		    {
		    	cout << "Matriz não quadrática" <<  endl;
		    }


			cout << "E essa é sua matriz : "<< endl;
			print(matriz,linhas,colunas);

			cout << "E essa é sua matriz transposta: " << endl;
			transpose(matriz,linhas,colunas); 

		
    return 0;

}


