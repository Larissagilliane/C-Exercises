#include "registradores.h"
#include "mips.h"
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char * argv[])
{
    char op[6]; //Lê a operação
    int a, b, c;
    int r[10]; // Vetor
    int (*p)(int,int)= NULL;
    int (*funcoes[5]) (int*);
    int teste = 0 ;

    ler_registradores(r);
    estado_registradores(r, '\t', true);
	 
    while (cin >> op )  //Para as operações
    {
	if (strcmp (op,"add") ==0)
        {
	    cin >> a >> b >> c;
            p = &add;
        }else if (strcmp (op,"sub") ==0)
        {
	    cin >> a >> b >> c;
            p = &sub;
        }else if (strcmp (op,"and") ==0)
        {
	    cin >> a >> b >> c;
            p = &e;
        }else if (strcmp (op,"or") ==0)
        {
	    cin >> a >> b >> c;
            p = &ou;
        }else if (strcmp (op,"slt") ==0)
        {
	    cin >> a >> b >> c;
            p = &slt;
        }
	else
	{
	    goto func;
	}
        apply(r,a,b,c,p);
    }

	
    while (cin >> op)	// Para as funções
    {
    func: 
       if (strcmp (op,"min") ==0)
        {
	    teste ++;
            funcoes[teste] = &min; 
	    
        }
        else if (strcmp (op,"max") ==0)
        {
	    teste ++;
            funcoes[teste] = &max; 
        }
        else if (strcmp (op,"ones") ==0)
        {
	    teste ++;
 	    funcoes[teste] = &ones; 
        }
        else if (strcmp (op,"zeros") ==0)
        {
	    teste ++; 
            funcoes[teste] = &zeros; 
        }
	else 
        {
            break;
        }
	estado_registradores( r, funcoes[teste]);
    }

    if (teste == 0)
    {
	estado_registradores(r);
    }
    return 0;
}

