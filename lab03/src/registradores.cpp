#include <iostream>
#include "registradores.h"

using namespace std;

void ler_registradores(int r[]) 
{
	for (int i = 0; i < 10; i++) cin >> r[i];

}

void estado_registradores(int r[], char sep , bool indices)
{
	int i;
	switch (indices)
	{
		case 1: 
			for ( i=0; i < 10; i++)
			{
				cout << '[' << i << ']' << sep;
			}
			cout << endl;
			for (i =0; i < 10; i++)
			{
				cout << r[i] << sep ;
			}
			cout << endl;
			break;
		case 0 :
			for (i =0; i < 10; i++)			
			{
				cout << r[i] << sep ;
			}
			cout << endl;
			break;	
	}
}


void estado_registradores(int r[], int (*v)(int*))
{
	cout << v(r) << endl;
}
