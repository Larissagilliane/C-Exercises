#include "funcoes.h"
#include "operacoes.h"
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char * argv[])
{
    int cont3 = 0;
    int cont4 = 0;
    int colunas;
    int linhas;
    char op[4];
    int a, b;
    int **matriz;
    int **matrizaux;

    cin >> linhas >> colunas; // lê as linhas e colunas

	    int *vetor1;
	  	vetor1 = new int[linhas];

	    int *vetor2;
	  	vetor2 = new int[linhas];    

	  	int *vetor1aux;
	  	vetor1aux = new int[linhas];

	    int *vetor2aux;
	  	vetor2aux = new int[linhas]; 

	  	int *vetor_auxiliar;
	  	vetor_auxiliar = new int[linhas];  

	  	int *vetor_auxiliar_2;
	  	vetor_auxiliar_2 = new int[linhas]; 


    matriz = new int*[linhas]; //alocação
    matrizaux = new int*[linhas]; //alocação

    for(int i = 0;i < linhas; ++i)
        matriz[i] = new int[colunas]; //alocação

    for(int i = 0;i < linhas; ++i)
        matrizaux[i] = new int[colunas]; //alocação

    criando_identidade(linhas,colunas, matrizaux);
         
    for(int cont1 = 0 ; cont1 < linhas ; cont1 ++)
    {
        for (int cont2 = 0; cont2 < colunas ; cont2 ++)
        {
             cin >> matriz[cont1][cont2];
         } 
    }    

    print(matriz,linhas,colunas); //imprime matriz original
    cout << endl;

    while (cin >> op >> a  >> b )  //Para as operações
    {
	   if (strcmp (op,"swap") ==0)
       {
        	for (cont3 = 0; cont3 < linhas ; cont3 ++) 
            {
                vetor1[cont3] = matriz[a][cont3];
                vetor2[cont3] = matriz[b][cont3];
                vetor1aux[cont3] = matrizaux[a][cont3];
                vetor2aux[cont3] = matrizaux[b][cont3];
            } 

            swap( vetor1, vetor2, linhas); 
            swap( vetor1aux, vetor2aux, linhas); 

           for (cont4 = 0; cont4 < linhas ; cont4 ++)
            {
            	matriz[a][cont4]=vetor1[cont4];
                matriz[b][cont4]=vetor2[cont4];
                matrizaux[a][cont4]=vetor1aux[cont4];
                matrizaux[b][cont4]=vetor2aux[cont4];
            } 
            
        }
        else if (strcmp (op,"add") ==0)
        {
        	for (cont3 = 0; cont3 < linhas ; cont3 ++) //MATRIZ 1
           	{
	            vetor1[cont3] = matriz[a][cont3];
	            vetor1aux[cont3] = matrizaux[a][cont3];
            } 
            if (b != -1)
            {
 				for (cont3 = 0; cont3 < linhas ; cont3 ++) 
            	{
	                vetor2[cont3] = matriz[b][cont3];
	                vetor2aux[cont3] = matrizaux[b][cont3];
            	}

	            add( vetor1, vetor2, linhas);
	            add( vetor1aux, vetor2aux, linhas);


	            for (cont4 = 0; cont4 < linhas ; cont4 ++)
            	{
	            	matriz[a][cont4]=vetor1[cont4];
	                matrizaux[a][cont4]=vetor1aux[cont4];
            	} 
            }
            else 
           {

	            add( vetor1, vetor_auxiliar_2, linhas);
	            add( vetor1aux, vetor_auxiliar, linhas); 

	            for (cont4 = 0; cont4 < linhas ; cont4 ++)
            	{
	            	matriz[a][cont4]=vetor1[cont4];
	                matrizaux[a][cont4]=vetor1aux[cont4];
            	}
           }
        }  
        else if (strcmp (op,"sub") ==0)
        {
        	for (cont3 = 0; cont3 < linhas ; cont3 ++) //MATRIZ 1
           	{
	            vetor1[cont3] = matriz[a][cont3];
	            vetor1aux[cont3] = matrizaux[a][cont3];
            } 
           if (b != -1)
           {
           	  	for (cont3 = 0; cont3 < linhas ; cont3 ++) 
            	{
	                vetor2[cont3] = matriz[b][cont3];
	                vetor2aux[cont3] = matrizaux[b][cont3];
            	} 

	            sub( vetor1, vetor2, linhas);
	            sub( vetor1aux, vetor2aux, linhas);

	            for (cont4 = 0; cont4 < linhas ; cont4 ++)
            	{
	            	matriz[a][cont4]=vetor1[cont4];
	                matrizaux[a][cont4]=vetor1aux[cont4];
            	} 
           }
           else 
           {
	            sub( vetor1, vetor_auxiliar_2, linhas);
	            sub( vetor1aux, vetor_auxiliar, linhas);

	            for (cont4 = 0; cont4 < linhas ; cont4 ++)
            	{
	            	matriz[a][cont4]=vetor1[cont4];
	                matrizaux[a][cont4]=vetor1aux[cont4];
            	}
           }
        } 
        else if (strcmp (op,"mult") ==0)
        {
        	for (cont3 = 0; cont3 < linhas ; cont3 ++) //MATRIZ 1
           	{
	            vetor1[cont3] = matriz[a][cont3];
	            vetor1aux[cont3] = matrizaux[a][cont3];
            }
            mult(vetor1,b,vetor_auxiliar_2,linhas);
            mult(vetor1aux,b,vetor_auxiliar,linhas);

        }
        else
	    {
	    break;
	    }
    }

    print(matrizaux, linhas, colunas);
    cout << endl;

    print(matriz, linhas, colunas);

    for(int cont = 0; cont < colunas; ++cont)
            delete []matriz[cont];
         
            delete []matriz; 

    for(int cont = 0; cont < colunas; ++cont)
            delete []matrizaux[cont];
         
            delete []matrizaux; 


    delete []vetor1; 

   	delete []vetor2; 

   	delete []vetor1aux; 

   	delete []vetor2aux; 

   	delete []vetor_auxiliar; 

   	delete []vetor_auxiliar_2; 

    return 0;
}

