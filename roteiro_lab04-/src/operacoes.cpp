#include "operacoes.h"

void swap ( int* a, int* b, int linhas)  // ok 
{ 
	int cont1 =0;
	int *auxiliar;
	auxiliar = new int[linhas]; 

 	for(cont1=0; cont1<linhas; cont1++) //auxiliar recebe a
 	{
    	auxiliar[cont1] = a[cont1];
    }

 	for(cont1=0; cont1<linhas; cont1++)//a recebe b
 	{
    	a[cont1] = b[cont1];
    }

 	for(cont1=0; cont1<linhas; cont1++)//b recebe a
 	{
    	b[cont1] = auxiliar[cont1];
    }
    delete []auxiliar;   
}

void add ( int* a, int* b, int linhas)  //ok
{ 
	int x;
	for (x=0;x<linhas;x++) 
	{
	a[x] = a[x] + b[x];
	}
}

void sub ( int* a, int* b, int linhas) //ok
{ 
	int x;
	for (x=0;x<linhas;x++) 
	{
	a[x] = a[x] - b[x];
	}
}


void mult( int* a, int b, int* auxiliar, int linhas)  // ok
{ 
	int i ;
	for(i=0; i<linhas; i++)
	{	   
    auxiliar[i] = a[i] * b;
	}

}

