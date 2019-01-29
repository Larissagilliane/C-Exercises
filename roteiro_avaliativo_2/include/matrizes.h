#ifndef __MATRIZES_H__
#define __MATRIZES_H__

using namespace std;

class Matriz 
{
  private:
    std::vector<string> matriz;

  public:
    friend std::ostream& operator<< (ostream &Saida, const Matriz& m)
    {
        for (size_t i = 0; i < m.matriz.size(); i++) 
        {
              Saida << m.matriz[i] << endl;       
        }
        return Saida;      
    }

    friend std::istream& operator>> (istream & Entrada,  Matriz& m )
    {
                 std::string aux_string; 
                 m.linhas=0;
              
                 size_t found;
                 std::string str3, str1, str2;
              
                 int contador=0;
                 vector<string> repetidas;
                 while (getline(Entrada, aux_string)) 
                 {    
                    str3 = aux_string;           
                    found = str3.find_first_of(" ");
                    while (found != std::string::npos)
                    {
                        str2 = str3.substr(0,found);
                        cout << str2 << " str2 " << endl;
                        str1 = str3.substr(found+1);
                        cout << str1 << " str1 " << endl;
                        found = str1.find(str2);
                        if (found != std::string::npos)
                        {
                          repetidas.push_back(str2);
                        }
                      contador++;
                    }          
                m.matriz = repetidas; 
                
                 quantidade de linhas
                }   
                //cout << "linhas e cont  " << m.linhas << " " << contador << endl;
                return Entrada;  
    }
};

#endif /* __MATRIZES_H__ */