#include "mips.h"
#include <iostream>
#include <cassert>

using namespace std;

int main (int argc, char * argv[]) 
{

    int v[10]= {3 , 5 , 6 , 0 , 54, 1 , 5, 12, -90, 2};

    cout << "Testando add.." << endl;
    assert(add(2,3) == 5);

    cout << "Testando sub.." << endl;
    assert(sub(10,4) == 6);
 
    cout << "Testando slt.." << endl;
    assert(slt(2,3) == 1);
    assert(slt(4,3) == 0);
    assert(slt(3,3) == 0);

    cout << "Testando and.." << endl;
    assert(e(6,7) == 6);
    assert(e(9,5) == 1);

    cout << "Testando min.." << endl;
    assert(min(v) == 8);

    cout << "Testando max.." << endl;
    assert(max(v) == 4);

    cout << "Testando zeros.." << endl;
    assert(zeros(v) == 1);

    cout << "Testando ones.." << endl;
    assert(ones(v) == 1);

    cout << "Testando or.." << endl;
    assert(ou(4,8) == 12);
    assert(ou(9,5) == 13);

    return 0;
}
