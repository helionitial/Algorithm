//
//  shared_ptr_needed.cc
//  
//
//  Created by Li He on 6/5/14.
//
//

#include <stdio.h>

// class without copy constructor/assignment operator
template<typename T>
class Array{
public:
    Array(unsigned arraySize): data(0), size(arraySize){
        if(size > 0) data = new T[size];
    }
    ~Array(){
        if(data) delete[] data;
    }
    
    void setValue(unsigned index, const T& value){
        if(index < size)
            data[index] = value;
    }
    T getValue(unsigned index) const{
        if(index < size) return data[index];
        else return T();
    }
private:
    T* data;
    unsigned size;
};

// problem sequence:
Array A(10);
Array B(A)
B = A;
// compiler generated copy constructor/assignment operator
// copy ptr of T
// delete A
// B operate on data pointed with same ptr
// program crash

// fix: deep copy user defined:
Array(const Array& copy): data(0), size(copy.size){
    if(size > 0){
        data = new T[size];
        for(int i = 0; i < size; i ++)
            setValue(i, copy.getValue(i));
    }
}

const Array& operator = (const Array& copy){
    if(data == copy.data)
        return *this;
    if(data != NULL){
        delete []data;
        data = NULL;
    }
    size = copy.size;
    if(size > 0){
        data = new T[size];
        for(int i = 0; i < size; ++ i)
            setValue(i, copy.getValue(i));
    }
}

// fix: shared_ptr simulation
public:
Array(unsigned arraySize): data(0), size(arraySize),
cout(new unsigned int){
    *cout = 1;
    if(size > 0) data = new T[size];
}
Array(const Array& copy): size(copy.size), data(copy.data), count(copy.count){
    ++(*count);
}
~Array(){
    Release();
}

const Array& operator = (const Array& copy){
    if(data == copy.data)
        return *this;
    Release();
    data = copy.data;
    size = copy.size;
    count = copy.count;
    ++(*count);
}
private:
void Release(){
    --(*count);
    if(*count == 0){
        if(data){
            delete []data;
            data = NULL;
        }
        delete count;
        count = 0;
    }
}
unsigned int* count;