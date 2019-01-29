#ifndef __MATRIZES_H__
#define __MATRIZES_H__

using namespace std;

template <typename T> 
class Matriz 
{
  private:
    char carc = ' ';
  protected:
  	T linhas, colunas;
    std::vector< std::vector<T> > matriz;

  public:
    virtual void print (std::ostream & Saida, const Matriz &m, const char &carc) const
    {
        for (int i = 0; i < m.linhas; i++) 
        {
          for (int j = 0; j < m.colunas; j++)
          {
              Saida << m.matriz[i][j] << carc;       
          }
          Saida << endl;
        }      
    }
    friend std::ostream& operator<< (ostream &Saida, const Matriz& m)
    {
        m.print(Saida, m, m.carc);
       return Saida;
    }

    void read(std::istream& Entrada,  Matriz& m , const char &carc) const
    {
          std::string aux_string; 
          m.linhas=0;
          m.colunas=0; 

          std::string elemento , elemento2;
          size_t found;
        
          vector<T> numeros;
          while (getline(Entrada, aux_string)) 
          {   
              elemento = aux_string;
              found = elemento.find_first_of(carc);
              while (found != std::string::npos)
              {
                elemento2 = elemento.substr(0,found);
                elemento = elemento.substr(found + 1);
                numeros.push_back(std::stoi(elemento2));
                        
                found = elemento.find_first_of(carc);
              }
              numeros.push_back(std::stoi(elemento));
                  
              if(m.matriz.size() == 0)
              {
                  m.colunas=numeros.size();
              }
                  
              m.matriz.push_back(numeros);
              numeros.clear();

            m.linhas++;   
         }      
    }
    friend std::istream& operator>> (istream& Entrada,  Matriz& m )
    {
       m.read(Entrada, m, m.carc);
       return Entrada;      
    }
};


// ____________________________________________________________________________________________________



template <typename T> 
class DataFrame: public Matriz <T>
{
   private:
    char carc = ';';
    std::vector <string> linha_1;
   public:
    friend std::ostream& operator<< (std::ostream& Saida, const DataFrame& d)
    {
            for(size_t i = 0; i < d.linha_1.size(); i++) 
            {
                if(i == d.linha_1.size() - 1)
                {
                  Saida << d.linha_1[i];
                }
                else 
                { 
                  Saida << d.linha_1[i] << d.carc; 
                }
            }
          Saida << endl;
          d.Matriz<T>::print(Saida, d, d.carc);
          return Saida;      
    }

    friend std::istream& operator>> (std::istream& Entrada, DataFrame& d)
    {
          string aux, aux2;
          std::getline (Entrada, aux);

          std::istringstream inputStream(aux);
          while(inputStream.good())
          {
            getline(inputStream, aux2, d.carc);
            d.linha_1.push_back(aux2);
          }

        d.Matriz<T>::read(Entrada, d, d.carc);
        return Entrada;
    }
};

#endif /* __MATRIZES_H__ */