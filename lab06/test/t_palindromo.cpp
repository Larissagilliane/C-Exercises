#include "palindromo.h"
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

int main (int argc, char * argv[]) 
{

    std::string palavra;

    cout << "Testando a verificacao de palindromos.." << endl;
    palavra = "lab";
    assert(palindromo(palavra) == false);
    palavra = "ana";
    assert(palindromo(palavra) == true);
    palavra = "reviver";
    assert(palindromo(palavra) == true);
    palavra = "paralelepipedo";
    assert(palindromo(palavra) == false);
 	
 	char a, b;
  	a='a';
  	b='b';
  	trocar(a,b);
  	assert(a=='b' && b=='a');

    return 0;

}
