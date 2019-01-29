#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <sstream>
#include "matrizes.h"

using namespace std;

int main(int argc, char * argv[])
{
	Matriz<int> m1;
	DataFrame<int> m2;

    std::ifstream arquivo(argv[2], std::ifstream::in);
	std::istream* arquivo_2 = &(arquivo);

	std::ofstream arquivo_saida("saida.out");	
	std::ostream* arquivo_saida_2 = &(arquivo_saida);

	if (std::strcmp(argv[1],"--matriz")==0)
	{
		*arquivo_2 >> m1;

		*arquivo_saida_2 << m1 << std::endl;
	}
	else if (std::strcmp(argv[1], "--dataframe")==0)
	{	
		*arquivo_2 >> m2;

		*arquivo_saida_2 << m2 << std::endl;
	}
}
