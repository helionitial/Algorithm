//
//  reorder_odd_even.c
//  
//
//  Created by Li He on 6/8/14.
//
//

#include <stdio.h>

void Reorder(int* pData, unsigned int length, bool (*func)(int));
bool isEven(int n);

// devide an array of integers into two parts, odd in the first part,
// and even in the second part
// input: pData - an array of integers
// length - the length of array

void reorder_odd_even(int* pData, unsigned int length){
    if(pData == NULL || length == 0) return;
    
    Reorder(pData, length, isEven);
}

// devide an array of integers into  two parts, the integers which satisfy func in
// the first part, otherwise in the second part
// input: pData - an array of integers
// length - the length of array
// func - a function
void Reorder(int* pData, unsigned int length, bool (*func)(int)){
    if(pData == NULL || length == 0) return;
    
    int *pBegin = pData;
    int* pEnd = pData + length - 1;
    
    while(pBegin < pEnd){
        // if *pBegin does not satisfy func, move forward
        if(!func(*pBegin)){
            pBegin ++;
            continue;
        }
        // if *pEnd does not satisfy func, move backward
        if(func(*pEnd)){
            pEnd --;
            continue;
        }
        
        // if *pBegin satisfy func while *pEnd does not,
        // swap these integers
        int temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp
    }
}

// determine whether an integer is even or not
// input: an integer
// otherwise return false
bool isEven(int n){
    return (n & 1) == 0;
}