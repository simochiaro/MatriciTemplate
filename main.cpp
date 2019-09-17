#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    int* s=new int[9];
    for(int i=0;i<9;i++)
        s[i]=i;
    Matrix<int>* matrix= new Matrix<int>(3,3);
    matrix->initMatrix(s);
    try
    {
        matrix->getValue(2,6); //cause an exception to throw
    }

    catch (invalid_argument& e)
    {
        cerr << e.what() << endl;
        return -1;
    }

    try
    {
        matrix->setValue(1,6,7); //cause an exception to throw
    }

    catch (invalid_argument& e)
    {
        cerr << e.what() << endl;
        return -1;
    }
    return 0;
}



