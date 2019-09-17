//
// Created by Simone Chiarini on 04/03/2019.
//

#include "FactoryMatrix.h"


Matrix<int>* FactoryMatrix::buildMatrixInt(int m,int n) {
    return new Matrix<int>(m,n);
}

Matrix<float>* FactoryMatrix::buildMatrixFloat(int m, int n) {
    return new Matrix<float>(m,n);
}

Matrix<char>* FactoryMatrix::buildMatrixChar(int m, int n) {
    return new Matrix<char>(m,n);
}
