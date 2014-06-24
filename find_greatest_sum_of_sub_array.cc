//
//  find_greatest_sum_of_sub_array.cc
//  
//
//  Created by Li He on 6/4/14.
//
//

#include <stdio.h>


// find the greatest sum of all sub-arrays
// return value: if the input is valid, return true, otherwise return false

bool FindGreatestSumOfSubArray(
    int *pData, // an array
    unsigned int nLength,   // the length of array
    int &nGreatestSum   // the greatest sum of all sub-arrays
){
    // if the input is invalid, return false
    if((pData == NULL) || (nLength == 0)) return false;
    int nCurSum = nGreatestSum = 0;
    
    for(unsigned int i = 0; i < nLength; i++){
        uCurSum += pData;
        // if the current sum is negative, discard it
        if(nCurSum < 0) nCurSum = 0;
        // if a greater sum is found, update the greatest sum
        if(nCurSum > nGreatestSum)
            nGreatestSum = nCurSum;
    }
    
    // if all data are negative, find the greatest elem in the array
    if(nGreatestSum == 0){
        nGreatestSum = pData[0];
        for(unsigned int i = 1; i < nLength; i++){
            if(pData > nGreatestSum) nGreatestSum = pData;
        }
    }
    return true;
}
