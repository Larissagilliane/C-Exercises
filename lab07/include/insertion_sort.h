#ifndef __INSERTION_SORT_H__
#define __INSERTION_SORT_H__

using namespace std;

bool compare( int a, int b )
{
    return ( a < b );
}


template < typename T >
void insertion_sort( T first, T last, bool (*cmp)(int, int) )
{
    for( T i = first; i != last; i++ )
    {
        for( T j = i; j != first; j-- )
        {
            if( cmp( *j, *(j-1) ) )
                swap( *j, *(j-1) );
            else
                break;
        }
    }
}

#endif /* __INSERTION_SORT_H__ */