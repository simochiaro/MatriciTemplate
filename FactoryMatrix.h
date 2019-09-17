//
// Created by Simone Chiarini on 04/03/2019.
//

#ifndef LABORATORIOPROGMATRICITEMPLATE_FACTORYMATRIX_H
#define LABORATORIOPROGMATRICITEMPLATE_FACTORYMATRIX_H


#include "Matrix.h"

class FactoryMatrix {
public:
    Matrix<int>* buildMatrixInt(int m,int n);
    Matrix<float>* buildMatrixFloat(int m,int n);
    Matrix<char>* buildMatrixChar(int m,int n);

};


#endif //LABORATORIOPROGMATRICITEMPLATE_FACTORYMATRIX_H
