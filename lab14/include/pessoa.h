#ifndef __PESSOA_H__
#define __PESSOA_H__

class Pessoa 
{
  private:
    string* nome;
  public:
    Pessoa (const string& str) : nome(new string(str)) {}
    
    ~Pessoa () {delete nome;}
    
    Pessoa (Pessoa&& x) : nome(x.nome) {x.nome=nullnome;}
    
    Pessoa& operator= (Pessoa&& x) 
    {
      delete nome; 
      nome = x.nome;
      x.nome=nullnome;
      return *this;
    }
    
    const string& content() const {return *nome;}
   
    Pessoa operator+(const Pessoa& rhs) 
    {
      return Pessoa(content()+rhs.content());
    }
};

#endif /* __PESSOA_H__ */