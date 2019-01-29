#ifndef __MATRIZES_H__
#define __MATRIZES_H__

#include <iostream>
#include <vector>

using namespace std;

void print(std::vector< std::vector<int> > matriz , int linhas, int colunas)
{
	for (int i = 0; i < linhas; i++) 
	{
		for (size_t j = 0; j < matriz[i].capacity(); j++)
		{
			cout << matriz [i][j] << " ";      	
		}
		  cout << endl;
	}
}

template < typename T >
void transpose(T matriz, int linhas, int colunas)
{
 	T aux;
	
	for(int i = 0 ; i < colunas; i ++)
	{
		vector<int> tamanho;
		for (int j = 0; j < linhas ; j ++)
		{
			tamanho.push_back(j * i);
		} 
			aux.push_back(tamanho);
	} 	

 	for(int cont1=0; cont1<linhas; cont1++)
 	{
 	  for(int cont2=0; cont2<colunas; cont2++) 
   	  {
    	aux[cont2][cont1] = matriz[cont1][cont2];
      }
    }
    matriz=aux;
    print(matriz,colunas,linhas);
    
  
}

template < typename T >
T diagonal(T matriz, int linhas, int colunas) 
{
    T simetrica;

	simetrica.reserve(linhas);
  	for (int i = 0; i < linhas; i++)
  	{
  		simetrica[i].reserve(i+1); 
  	} 
  	
  	for (int cont=0; cont<linhas;cont++)
  	{
  	    for(int j = 0; j < cont+1; j++)     	
  	    {     		
  	        simetrica[cont][j] = matriz[cont][j];     	
  	    }
  	} 
  	
  	for (int i = 0; i < linhas; i++) 
  	 {
    	for (size_t j = 0; j < simetrica[i].capacity(); j++)
    	{
     		 std::cout << simetrica[i][j] << " ";
    	}
   		 std::cout << std::endl;
 	 }
 	 
 	 return simetrica;
} 

#endif /* __MATRIZES_H__ */