#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <vector>
//#include "pessoa.h"
using namespace std;

class Pessoa
{
  private:
    string nome;
    float peso;
    float altura;
    
  public:
  
   Pessoa(std::string n_="", float p_=0.f, float a_=0.f ) //construtor básico
            : nome{ n_ }
            , peso{ p_ }
            , altura{ a_ }
            { /* empty */ }
    
    //métodos de suporte tradicionais      
    ~Pessoa() = default; 
    Pessoa( const Pessoa & ) = default;
    Pessoa& operator=( const Pessoa & ) = default;
    Pessoa( Pessoa && ) = default;
    Pessoa& operator=( Pessoa && ) = default;
    
    friend std::ostream & operator<< ( std::ostream& os_, const Pessoa & p_ )
    {
        os_ << "<" << std::setw(30) << p_.nome << " , " << p_.peso << " , " << p_.altura << ">";
        return os_;        
    }
    
    float get_altura( void ) const
    { return altura; }
    
    float get_peso( void ) const
    { return peso; }
 
};

bool compareByPeso( const Pessoa & a, const Pessoa &b )
{
    return ( a.get_peso() < b.get_peso() );
}


int main () 
{
    std::vector< Pessoa >  pessoas {
        Pessoa{ "Maria da Silva", 60.f, 1.7f },
        Pessoa{ "Joao da Silva", 80.f, 1.9f },
        Pessoa{ "Joana de Andrade", 58.f, 1.65f }
    };

    std::cout << "Lista de pessoas:\n";
    std::copy( pessoas.begin(), pessoas.end(), std::ostream_iterator<Pessoa>(std::cout,"\n") );


    {//ordena pelo peso

    std::sort( pessoas.begin(), pessoas.end(), compareByPeso );
    std::cout << "\nLista de pessoas: (ordenadas por peso)\n";
    std::copy( pessoas.begin(), pessoas.end(), std::ostream_iterator<Pessoa>(std::cout,"\n") );
    std::cout << "\n";
    }

return EXIT_SUCCESS;
}