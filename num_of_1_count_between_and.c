//
//  num_of_1_count_between_and.c
//  
//
//  Created by Li He on 6/6/14.
//
//

#include <stdio.h>

// method 1: O(n)

// find the number of 1 in the integers between 1 and n
// input: n - an integer
// output: the number of 1 in the integers between 1 and n

int num_of_1_count_between_and(unsigned int n){
    int number = 0;
    for(unsigned int i = 1; i <= n; ++i){
        number += NumberOf1(i);
    }
    return number;
}

// find the number of 1 in an integer with radix 10
// input: n - an integer
// output: the number of 1 in n with radix

int NumberOf1(unsigned int n){
    int number = 0;
    while(n){
        if(n % 10 == 1) number ++;
        n = n / 10;
    }
    
    return number;
}


// method 2: analysis:

#include "string.h"
#include "stdlib.h"

int NumberOf1(const char* strN);
int PowerBase10(unsigned int n);

int num_of_1_count_between_and(int n){
    if(n <= 0) return 0;
    
    // convert the integer into a string
    char str[50];
    sprintf(strN, "%d", n);
    return NumberOf1(strN);
}

int NumberOf1(const char* strN){
    if(!strN || *strN < '0' ||*strN > '9' || *strN == '\0') return 0;
    
    int firstDigit = *strN - '0';
    unsigned int length = static_cast<unsigned int>(strlen(strN));
    
    // the integer contains only one digit
    if(length == 1 && firstDigit == 0) return 0;
    if(length == 1 && firstDigit >0) return 1;
    
    // suppose the integer is 21345
    // 10000-19999
    int numFirstDigit = 0;
    // 01346-21345
    int numOtherDigits = firstDigit * (length - 1) * PowerBase10(length - 2);
    
    int numRecursive = NumberOf1(strN + 1);
    
    // if the first digit is greater than 1,
    // number of 1 due to the first digit is 10^4
    if(firstDigit > 1)
        numFirstDigit = PowerBase10(length - 1);
    
    // if the first digits equals to 1, suppose in integer 12345
    else if(firstDigit == 1)
        numFirstDigit = atoi(strN + 1) + 1;
    
    return numFirstDigit + numOtherDigits + numRecursive;
}

int PowerBase10(unsigned int n){
    int result = 1;
    for(unsigned i = 0; i < n; ++i) result *= 10;
    return result;
}