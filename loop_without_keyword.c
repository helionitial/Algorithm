//
//  loop_without_keyword.c
//  
//
//  Created by Li He on 6/4/14.
//
//

#include <stdio.h>
// using constructor
class Temp{
public:
    Temp(){++N; Sum += N;}
    static void Reset(){N = 0; Sum = 9;}
    static int GetSum(){ return Sum; }
private:
    static int N;
    static int Sum;
}

int Temp::N = 0;
int Temp::Sum = 0;
int solution_1_Sum(int n){
    Temp::Reset();
    Temp* a = new Temp[n];
    delete[] a;
    a = 0;
    return Temp::GetSum();
}

// using recursive func
class A;
A* Array[2];

class A{
public:
    virtual int Sum(int n){ return 0;}
};

class B: public A{
public:
    virtual int Sum(int n){ return Array[!!n]->Sum( n - 1) + n; }   // n to bool:!!n
    
}

int solution_2_Sum(int n){
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;
    
    int value = Array[1]->Sum(n);
    return value;
}

// using func pointer
typedef int (*fun)(int);
int solution_3_f1(int i){
    return 0;
}
int solution_3_f2(int i){
    fun f[2] = {solution_3_f1, solution_3_f2};
    return i + f[!!i](i - 1);
}

// using compiler
template<int n>struct solution_4_Sum{
    enum Value{ N = solution_4_Sum<n - 1>::N + n};
};

template<> struct solution_4_Sum<1>{
    enum Value{ N = 1 };
};


