#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include "matrizes.h"

using namespace std;

int main(int argc, char * argv[])
{
	Matriz m1;

	std::string aux, aux2;
	size_t found;
	if ( std::strcmp(argv[1],"--file")==0)
	{
		aux = argv[2];
	    found = aux.find_first_of(".");
	    aux2 = aux.substr(0,found);
		aux = aux.substr(found + 1);

		string nome = aux2 + ".in";
		string nome2 = aux2 +".out";

		std::ifstream arquivo(nome, std::ifstream::in);
		std::istream* arquivo_2 = &(arquivo);
		*arquivo_2 >> m1;

		std::ofstream arquivo_saida(nome2, std::ofstream::out);	
		std::ostream* arquivo_saida_2 = &(arquivo_saida);
		*arquivo_saida_2 << m1 << std::endl;
	}
	else if ( std::strcmp(argv[1], "--std") == 0 ) //ok
	{	
		std::ifstream arquivo(argv[2], std::ifstream::in);
		std::istream* arquivo_2 = &(arquivo);
		*arquivo_2 >> m1;

		std::ofstream arquivo_saida(argv[3], std::ofstream::out);	
		std::ostream* arquivo_saida_2 = &(arquivo_saida);
		*arquivo_saida_2 << m1 << std::endl;
	}
}
