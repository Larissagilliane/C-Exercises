#include <iostream> // cont , endl
#include <vector>  // vector
#include <algorithm> // copy
#include <iterator> // ostream_iterator
#include <utility> //swap
//#include "quick_sort.h"
#include "insertion_sort.h"

using namespace std;

int main(int argc, char * argv[])
{
	std::vector< int > A;
    int value;
	while (cin >> value)
    {
        A.push_back(value);
    }

    // CHAMADAS DAS FUNÇÕES
    insertion_sort(A.begin(),A.end(), compare);
    //quick_sort(A.begin(),A.end()-1, compare );

    copy( A.begin(), A.end(), std::ostream_iterator<int>(std::cout, "\n") );

    return EXIT_SUCCESS;
}