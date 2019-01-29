#include "palindromo.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc, char * argv[])
{
	std::string palavra;

  	getline(std::cin,palavra);

	palindromo(palavra);
	

    return 0;
}
