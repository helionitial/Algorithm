//
//  fibonacci.c
//  
//
//  Created by Li He on 6/5/14.
//
//

#include <stdio.h>

// calculate the nth item of fibonacci series recursively
long long fibonacci(unsigned int n){
    int result[2] = {0,1};
    if(n < 2) return result[n];
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// however, the best solution is not recursively cal

// calculate the nth item of fibonacci series iteratively
long long fibonacci(unsigned int n){
    int result[2] = {0, 1};
    if(n < 2) return result[n];
    long long fibNumOne = 0;
    long long fibNumTwo = 1;
    long long fibN = 0;
    for(unsigned int i = 2; i <= n; ++ i){
        fibN = fibNumOne + fibNumTwo;
        
        fibNumOne = fibNumTwo;
        fibNumTwo = fibN;
    }
    return fibN;
}

// O(logn) solution
// {f(n), f(n-1), f(n-1), f(n-2)} = {1,1,1,0}^n-1 (2*2 matrix)

// matrix:
//      / a^(n/2) * a^(n/2)
// an =
//      \ a^((n-1)/2) * a^((n-1)/2)

#include <cassert>
// A 2 by 2 matrix
struct matrix2By2{
    Matrix2By2(
               long long m00 = 0,
               long long m01 = 0,
               long long m10 = 0,
               long long m11 = 0): m_00(m00), m_01(m01), m_10(m10), m_11(m11){}
    long long m_00;
    long long m_01;
    long long m_10;
    long long m_11;
};

// multiply two matrices
Matrix2By2 MatrixMultiply(
                          const Matrix2By2& matrix1,
                          const Matrix2By2& matrix2){
    return Matrix2By2(
                      matrix1.m_00 * matrix1.m_00 + matrix1.m_01 * matrix1.m_10,
                      matrix2.m_00 * matrix1.m_01 + matrix2.m_01 * matrix2.m_11,
                      matrix1.m_10 * matrix2.m_00 + matrix2.m_11 * matrix1.m_10,
                      matrix2.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11)
    )
}

// the nth power of matrix
// 1 1
// 1 0
Matrix2By2 MatrixPower(unsigned int n){
    assert(n > 0);
    
    Matrix2By2 matrix;
    if(n == 1) matrix = Matrix2By2(1,1,1,0);
    else if(n % 2 == 0){
        matrix = MatrixPower(n / 2);
        matrix = MatrixMultiply(matrix, matrix);
    }else if(n % 2 == 1){
        matrix = MatrixPower((n - 1) / 2);
        matrix = MatrixMultiply(matrix, matrix);
        matrix = MatrixMultiply(matrix, Matrix2By2(,1,1,1,0));
    }
    return matrix;
}

// calculate the nth item of fibonacci series using devide and conquer
long long fibonacci(unsigned int n){
    int result[2] = {0,1};
    if(n < 2) return result[n];
    Matrix2By2 PowerNMinus2 = MatrixPower(n - 1);
    return PowerNMinus2.m_00;
}

