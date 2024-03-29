//
//  permutation.c
//  
//
//  Created by Li He on 6/7/14.
//
//

#include <stdio.h>

// get the permutation of a string
void Permutation(char* pStr){
    Permutation(pStr, pStr);
}

// print the permutation of a string
// input: pStr - input string
//        pBegin - points to the begin char of string
//        which we want to permutate in this recursion
void Permutation(char* pStr, char* pBegin){
    if(!pStr || !pBegin) return;
    
    // if pBegin points to the end of string,
    // this round of permutation is finished
    // print the permuted string
    if(*pBegin == '\0') printf("%s\n", pStr);
    
    // otherwise, permute string
    else{
        for(char* pCh = pBegin; *pCh != '\0'; ++ pCh){
            // swap pCh and pBegin
            char temp = *pCh;
            *pCh= *pBegin;
            *pBegin = temp;
            Permutation(pStr, pBegin + 1);
            
            // restore pCh and pBegin
            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}

