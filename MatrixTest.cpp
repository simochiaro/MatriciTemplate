//
// Created by Simone Chiarini on 15/03/2019.
//

#include <gtest/gtest.h>
#include "../Matrix.h"

TEST(Matrix,Matrix){
    Matrix<int>* m=new Matrix<int>(2,3);
    Matrix<int>* prod=new Matrix<int>(3,1);
    ASSERT_EQ(m->numCol+prod->numRow,6);
}

TEST(Matrix1,setValue){
    Matrix<int>* m=new Matrix<int>(2,3);
    m->setValue(5,1,1);

    ASSERT_EQ(m->buffer[4],5);
    ASSERT_THROW(m->setValue(5,8,6),std::invalid_argument);
    ASSERT_THROW(m->setValue(5,-4,6),std::invalid_argument);
    ASSERT_THROW(m->setValue(5,8,-1),std::invalid_argument);
}

TEST(Matrix2,getValue){
    Matrix<int>* m=new Matrix<int>(2,3);
    m->setValue(5,1,1);
    int s=m->getValue(1,1);
    ASSERT_EQ(s,5);
    ASSERT_THROW(m->getValue(8,6),std::invalid_argument);
    ASSERT_THROW(m->getValue(8,-1),std::invalid_argument);
    ASSERT_THROW(m->getValue(-2,6),std::invalid_argument);
}

TEST(Matrix3,selectRow) {
    Matrix<int> *m = new Matrix<int>(2, 3);
    m->setValue(4, 1, 1);
    m->setValue(3, 1, 0);
    m->setValue(5, 1, 2);

    int *row = m->selectRow(1);

    ASSERT_EQ(row[0], 3);
    ASSERT_EQ(row[1], 4);
    ASSERT_EQ(row[2], 5);
    ASSERT_THROW(m->selectRow(5), std::invalid_argument);
    ASSERT_THROW(m->selectRow(-5), std::invalid_argument);
}

TEST(Matrix4,selectCol){
    Matrix<int>* m=new Matrix<int>(2,3);
    m->setValue(4,0,1);
    m->setValue(5,1,1);

    int* row=m->selectCol(1);

    ASSERT_EQ(row[0],4);
    ASSERT_EQ(row[1],5);

    ASSERT_THROW(m->selectCol(5),std::invalid_argument);
    ASSERT_THROW(m->selectRow(-5), std::invalid_argument);

}

TEST(Matrix5,trasposta){
    Matrix<int>* m=new Matrix<int>(2,3);
    m->setValue(4,0,0);
    m->setValue(5,0,1);
    m->setValue(3,0,2);
    m->setValue(1,1,0);
    m->setValue(1,1,1);
    m->setValue(9,1,2);

    Matrix<int>* t=m->trasposta();

    ASSERT_EQ(t->buffer[1],1);
    ASSERT_EQ(t->buffer[3],5);
}

TEST(Matrix6, Product){

    int* s =new int[6];
    s[0]=0;
    s[1]=1;
    s[2]=2;
    s[3]=3;
    s[4]=4;
    s[5]=5;

    Matrix<int>* m=new Matrix<int>(2,3,s);
    Matrix<int>* t=new Matrix<int>(3,2,s);

    Matrix<int>* w=m->operator*(t);

    ASSERT_EQ(w->buffer[0],10);
    ASSERT_EQ(w->buffer[1],13);

    Matrix<int>* x=new Matrix<int>(2,6);
    ASSERT_THROW(m->operator* (x),std::invalid_argument);


}

TEST(Matrix7, sumMatrix){

    int* s =new int[6];
    s[0]=0;
    s[1]=1;
    s[2]=2;
    s[3]=3;
    s[4]=4;
    s[5]=5;

    Matrix<int>* m=new Matrix<int>(2,3,s);
    Matrix<int>* t=new Matrix<int>(2,3,s);



    Matrix<int>* g= m->operator+ (t);

    ASSERT_EQ(g->buffer[3],6);
    ASSERT_EQ(g->buffer[2],4);


    Matrix<int>* w=new Matrix<int>(2,4);
    ASSERT_THROW(m->operator+ (w),std::invalid_argument);

}

TEST(Matrix8, scalarProduct){

    int* s =new int[6];
    s[0]=0;
    s[1]=1;
    s[2]=2;
    s[3]=3;
    s[4]=4;
    s[5]=5;
    Matrix<int>* m=new Matrix<int>(2,3,s);

    Matrix<int>* t=m->operator*(7);



    ASSERT_EQ(t->buffer[3],21);
    ASSERT_EQ(t->buffer[2],14);




}

TEST(Matrix9, printMatrix){

    int* s =new int[6];
    s[0]=0;
    s[1]=1;
    s[2]=2;
    s[3]=3;
    s[4]=4;
    s[5]=5;

    Matrix<int>* m=new Matrix<int>(2,3,s);

    std::string w=m->printMatrix();



    ASSERT_EQ(w[0],0);
    ASSERT_EQ(w[1],1);
    ASSERT_EQ(w[2],2);
    ASSERT_EQ(w[3],3);
    ASSERT_EQ(w[4],4);
    ASSERT_EQ(w[5],5);





}
