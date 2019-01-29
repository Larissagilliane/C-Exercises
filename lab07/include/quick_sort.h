#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

using namespace std ;

bool
compare( int a, int b )
{
    return ( a < b );
}

template<typename T>
T particao( T first, T last,  bool (*cmp)(int, int))
{
    T i  = first-1; // i "aponta" para fora do vetor inicialmente
    T hp = first;   // hp "aponta" para o inicio do vetor inicialmente

    //Percorre enquanto "hp" for menor que o final do vetor, ou seja, o valor a qual hp aponta seja menor que o pivot (ultimo elemento inicialmente)
    while ( hp < last ) 
        {
            if (cmp(*hp , *last)) 
            {
                ++i;
                swap(*i,*hp);  // troca os elementos 
            }
            ++hp;
        }
    swap(*(i+1),*last); // caso "hp" seja maior do que "last" ele , ele insere last antes do valor "hp"
    return ++i; //retorna a posicao onde o pivot esta
}


template<typename T>
void quick_sort( T first, T last, bool (*cmp)(int, int) )
{
    if (first < last)
    {
        T p = particao(first, last, cmp); 
        quick_sort (first, p-1, cmp);  // ordena na primeira metade
        quick_sort ( p+1, last, cmp);  //ordea na segunda metade
    }
  
}



#endif /* __QUICK_SORT_H__ */