//
//  is_possible_pop_order.c
//  
//
//  Created by Li He on 6/6/14.
//
//

#include <stdio.h>

// give a push order of a stack, determine whether an array is possible to
// be its corresponding pop order
// input: pPush - an array of integers, the push order
//        pPop - an array of integers, the pop order
//        nLength - the length of pPush and pPop
// output: if pPop is possible to be the pop order of pPush, return true.
// otherwise return false.

bool is_possible_pop_order(const int* pPush, const int* pPop, int nLength){
    bool bPossible = false;
    
    if(pPush && pPop && nLength > 0){
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;
        
        // ancillary stack
        std::stack<int> stackData;
        
        // check every integers in pPop
        while(pNextPop - pPop < nLength){
            // while the top of the ancillary stack is not the integer
            // to be poped, try to push some integers into the stack
            while(stackData.empty() || stackData.top() != *pNextPop){
                if(!pNextPush) break;
                
                stackData.push(*pNextPush);
                
                if(pNextPush - pPush < nLength - 1)
                    pNextPush ++;
                else
                    pNextPush = NULL;
            }
            if(stackData.top() != *pNextPop) break;
            
            stackData.pop();
            pNextPop ++;
        }
        if(stackData.empty() && pNextPop - pPop == nLength)
            bPossible = true;
    }
    return bPossible;
}

int good_order(int push[], int pop[], int size){
    int* tmp = (int*)malloc(size * sizeof(int));
    int top = 0, cur_push = 0, cur_pop = 0;
    tmp[top] = push[cur_push ++];
    
    for(; cur_pop < size; cur_pop ++){
        while(cur_push < size && tmp[top] != pop[cur_pop])
            tmp[++ top] = push[cur_push ++];
        if(tmp[top] == pop[cur_pop])
            top --;
        else{
            free(tmp);
            tmp = NULL;
            return 0;
        }
    }
    free(tmp);
    return 1;
}

