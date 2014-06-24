//
//  find_two_num_with_sum.c
//  
//
//  Created by Li He on 6/4/14.
//
//

#include <stdio.h>

// find two numbers with a sum in a sorted array
// output: true is found such two numbers, otherwise false

bool find_two_num_with_sum(int data[], unsigned int length,
                           int sum, int& num1, int& num2){
    bool found = false;
    if(length < 1)
        return found;
    
    int ahead = length - 1;
    int behind = 0;
    
    while (ahead > behind) {
        long long curSum = data[ahead] + data[behind];
        // if the sum of two numbers is equal to the inut
        // we have found them
        if(curSum == sum){
            num1 = data[behind];
            num2 = data[ahead];
            found = true;
            break;
        }
        // if the sum of two numbers is greater than the input
        // decrease the greater number
        else if(curSum > sum)
            ahead --;
        
        // if the sum of two numbers is less than the input
        // increase the less number
        else behind ++;
    }
    return found;
}