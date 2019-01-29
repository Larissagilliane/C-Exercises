#include "palindromo.h"
#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

void trocar (char &a, char &b)
{
	char c;
	c=a;
	a=b;
	b=c;
}

bool palindromo (std::string palavra) 
{
    std::string copia;  
    copia = palavra; 
    int spaces=0; 
    bool flag;

    std::string aux;  
    aux = palavra;  
    std::size_t cont3;
    std::size_t i=0;

    // excluir espaços de palavra para testar
    for(cont3=0 ; cont3 < palavra.length() ; cont3++)
    {
        if (aux[cont3] ==' ')
        {
            spaces++;
            aux.erase (aux.begin()+cont3);
            palavra.erase (palavra.begin()+cont3);
        }
    }
    //faz a troca
   	for (std::size_t cont=0; cont < palavra.length()/2 ; cont ++) 
   	{ 
      trocar(aux[cont], aux[palavra.length()-1-cont]);   		
   	}

    //recoloca os espaços do palindromo
    if( aux == palavra && spaces<10)
    {   
      for(cont3=0 ; cont3 < copia.length(); cont3++)
      {
        if (copia[cont3] ==' ')
        {
            aux.insert(cont3," "); 
            palavra.insert(cont3," "); 
        }
    }
		    flag = true; 
    } 
    else 
    {
       		flag = false;
    }

    int j= 0;
    if (flag == true)
    {
            std::string str3, str1, str2;  
            str3 = "";              
            std::size_t found = palavra.find_last_of(" ");
            str2 = palavra.substr(found+1);
            str1 = palavra.substr(0,found);

        do{
            if (str2.length() >= 2)
            {
                found = str1.find(str2);
                if (found != std::string::npos )
                {
                     for(i = 0; i < str2.size(); i++)
                     {
                         str2[i] = toupper(str2[i]);
                     }

                    str1.replace(found, str2.size(), str2);
                    str2.clear();
                }
                else
                {
                    str3 = str2 + " " + str3;
                } 
            }
            else
            {
                str3 = str2 + " " + str3;
            }
                std::size_t found = str1.find_last_of(" ");
                str2 = str1.substr(found+1);
                str1 = str1.substr(0, found);
                
                j++;

        }while (j<spaces);

            str3 = str2 +" "+ str3;
            cout << str3 << endl; 

            return true;
    }
    else
    {
        return false;
    }

}