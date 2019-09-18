//
// Created by Simone Chiarini on 25/02/2019.
//

#ifndef LABORATORIOPROGMATRICITEMPLATE_MATRIX_H
#define LABORATORIOPROGMATRICITEMPLATE_MATRIX_H


#include <iostream>
#include<stdexcept>
#include<limits>

template<class T> class Matrix {
public:
    T* buffer;
    int numCol,numRow;

    Matrix (int m,int n):numRow(m),numCol(n){
        buffer =new T[m*n];
        for(int i=0;i<m*n;i++)
            buffer[i]=0;

    }

    Matrix (int m,int n, T s[]):numRow(m),numCol(n){

        buffer =new T[m*n];

        initMatrix(s);
    };

    ~Matrix(){
        delete[] buffer;
    };


    void setValue(T t,int m,int n){

        if ((m<0 || m >= numRow) || (n<0 || n >= numCol)) {
            throw std::invalid_argument("Out of index");  //Esempio di gestione di eccezioni nel main
        }

        buffer[m*numCol+n]=t;
    }

private:
    void initMatrix(T s[]){
        for(int i=0;i<numRow;i++){
            for (int j=0;j<numCol;j++){
                buffer[i*numCol+j]=s[i*numCol+j];
            }

        }
    }
public:
    T getValue(int m,int n){
        if((m<=0 || m >= numRow) || (n<0 || n >= numCol)){
            throw std::invalid_argument("Out of index");

        }
        return buffer[m*numCol+n];
    }

    T* selectRow(int m){
        if(m<0 || m>=numRow){
            throw std::invalid_argument("Out of index");

        }
        T* row=new T[numCol];
        for(int i=0;i<numCol;i++){
            row[i]=buffer[m*numCol+i];
        }
        return row;
    }

    T* selectCol(int n){
        if(n<0 || n>=numCol){
            throw std::invalid_argument("Out of index");
        }
        T* col=new T[numRow];
        for(int i=0;i<numRow;i++){
            col[i]=buffer[i*numCol+n];
        }
        return col;
    }

    Matrix<T> trasposta(){
        Matrix<T>* trasp=new Matrix<T>(this->numCol,this->numRow);
        for(int i=0;i<this->numCol;i++){
            for(int j=0;j<this->numRow;j++){
                trasp->buffer[i*numCol+j]=this->buffer[j*numCol+i];
            }
        }
        return *trasp;
    }

     Matrix<T> operator *(Matrix<T>* matrix){
        if(numCol!=matrix->numRow){
            throw std::invalid_argument("Matrix dimension not right to do product");
        }
        T sum=0;
        Matrix<T>* prod=new Matrix<T>(numRow,matrix->numCol);
        for(int i=0;i<this->numRow;i++){
            for(int j=0;j<matrix->numCol;j++){
                sum=0;
                for(int k=0;k<this->numCol;k++){
                   sum+=(this->buffer[(i*numCol)+k])*(matrix->buffer[(k*(matrix->numCol))+j]);
                }
                prod->buffer[i*numCol+j]=sum;
            }
        }
        return *prod;

    }

    Matrix<T> operator + (Matrix<T>* m1){
        if(m1->numCol!=this->numCol || m1->numRow!= this->numRow)
            throw std::invalid_argument("Impossible to do sumMatrix");
        Matrix<T>* sum=new Matrix(numCol,numRow);
        for(int i=0;i<numRow;i++){
            for(int j=0;j<numCol;j++)
                sum->buffer[i*numCol+j]=this->buffer[i*numCol+j]+m1->buffer[i*numCol+j];
        }
        return *sum;
    }

    Matrix<T> operator* (T scalar){
        Matrix<T>* s=new Matrix(numCol,numRow);
        for(int i=0;i<numRow;i++){
            for(int j=0;j<numCol;j++)
                s->buffer[i*numCol+j]=(this->buffer[i*numCol+j])*scalar;
        }
        return *s;
    }

    std::string printMatrix(){
        std::string s;
        for(int i=0;i<numRow;i++){
            for (int j=0;j<numCol;j++){
                s+=buffer[i*numCol+j];
            }
        }
        return s;
    }

};


#endif //LABORATORIOPROGMATRICITEMPLATE_MATRIX_H
