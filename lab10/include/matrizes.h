#ifndef __MATRIZES_H__
#define __MATRIZES_H__

using namespace std;

template <typename T> class Matriz;
template <typename T> std::ostream& operator<< (ostream &Saida, const Matriz<T>& m);
template <typename T> std::istream& operator>> (std::istream & Entrada,  Matriz<T>& m );

template <typename T>
class Matriz 
{
  private:
  	T linhas, colunas;
    std::vector< std::vector<T> > matriz;

  public:
    friend std::ostream& operator<< <>(ostream &Saida, const Matriz& m);
    friend std::istream& operator>> <>(istream & Entrada,  Matriz& m );
};

template <typename T>
std::ostream& operator<<(ostream &Saida, const Matriz<T>& m)

{
    for (int i = 0; i < m.linhas; i++) 
    {
      for (int j = 0; j < m.colunas; j++)
      {
          Saida << m.matriz[i][j] << " ";       
      }
      Saida << endl;
  	}
     return Saida;
}

template <typename T>
std::istream& operator>> (std::istream & Entrada, Matriz<T>& m) 
{
    
    std::string aux_string; 
    m.linhas=0;
    m.colunas=0; 

    std::string elemento , elemento2;
	size_t found;
	
	vector<int> numeros;
    while (getline(Entrada, aux_string)) 
    {   
	    elemento = aux_string;
	    found = elemento.find_first_of(" ");
	    while (found != std::string::npos)
	    {
	        elemento2 = elemento.substr(0,found);
		    elemento = elemento.substr(found + 1);
		    numeros.push_back(std::stoi(elemento2));
		            
		    found = elemento.find_first_of(" ");
	    }
	    numeros.push_back(std::stoi(elemento));
	        
	    if(m.matriz.size() == 0)
	    {
	        m.colunas=numeros.size();
	    }
	        
	    m.matriz.push_back(numeros);
	    numeros.clear();

    m.linhas++; //quantidade de linhas
      
   }    
   
   return Entrada;

}
#endif /* __MATRIZES_H__ */