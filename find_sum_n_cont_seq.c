//
//  find_sum_n_cont_seq.c
//  
//
//  Created by Li He on 6/7/14.
//
//

#include <stdio.h>

// find continuous sequence, whose sum is n
void find_sum_n_cont_seq(int n) {
    if(n < 3) return;
    
    int small = 1;
    int big = 2;
    int middle = (1 + n) / 2;
    int sum = small + big;
    
    while(small < middle){
        // we are lucky and find the sequence
        if(sum == n)
            print_cont_seq(small, big);
        
        // if the current sum is greater than n
        // move small forward
        while(sum > n){
            sum -= small;
            small ++;
            
            // we are lucky and find the sequence
            if(sum == n)
                print_cont_seq(small, big);
        }
        // move big forward
        big ++;
        sum += big;
    }
}

// print continuous sequence between small and big

void print_cont_seq(int small, int big){
    for(int i = small, i <= big; i++)
        printf("%d", i);
    
    printf("\n");
}
