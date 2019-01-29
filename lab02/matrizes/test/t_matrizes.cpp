#include "matrizes.h"
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

int main (int argc, char * argv[]) 
{
	
	int **matriz = new int*[2]; //alocação 
		    for(int i = 0;i < 2; ++i)
		        matriz[i] = new int[2]; //alocação

	matriz[0][0] = 1;
	matriz[0][1] = 2;

	matriz[1][0] =3;
	matriz [1][1]=4;

	transpose(matriz,2,2);
	assert(matriz[0][1] == 3);
	assert(matriz[0][0] == 1);
	assert(matriz[1][0] == 2);
	assert(matriz[1][1] == 4);

	cout << "Testes passados com sucesso " << endl;

	return 0;
}