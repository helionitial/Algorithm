//
//  int_bin_1_count.c
//  
//
//  Created by Li He on 6/5/14.
//
//

#include <stdio.h>

//  solution 1: only work on positive
int NumberOf1_Solution1(int i)
{
    int count = 0;
    while(i)
    {
        if(i & 1)
            count ++;
        i = i >> 1;
    }
    return count;
}

// solution 2: ok with both positive and negative
int NumberOf1_Solution2(int i)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(i & flag)
            count ++;
        flag = flag << 1;
    }
    return count;
}

// solution 3
int NumerOf1_Solution3(int i){
    int count = 0;
    while(i){
        ++ count;
        i = (i - 1) & i;    // ?
    }
    return count;
}

