//
//  find_least_k_num.cc
//  
//
//  Created by Li He on 6/4/14.
//
//

#include <stdio.h>

// O(n + nlogk)

#include <set>
#include <vector>
#include <iostream>

using namespace std;

typedef multiset<int, greater<int>> IntHeap;

// find k least numbers in a vector

void FindKLeastNumbers(
    const vector<int>& data,    // vector of data
    IntHeap& leastNumbers,  // ke least numbers, output
    unsigned int k
                       ){
    leastNumbers.clear();
    
    if(k == 0 || data.size() < k) return;
    
    vector<int>::const_iterator iter = data.begin();
    for(; iter != data.end(); ++iter){
        // if less than k numbers was inserted into leastNumbers
        if((leastNumbers.size()) < k)
            leastNumbers.insert(*iter);
        
        // leastNumbers contains k numbers and it's full now
        else{
            // first number in leastNumbers is the greatest one
            IntHeap::iterator iterFirst = leastNumbers.begin();
            // if is less than the previous greatest number
            if(*iter < *(leastNumbers.begin())){
                // replace the previous greatest number
                leastNumbers.erase(iterFirst);
                leastNumbers.insert(*iter);
            }
        }
    }
}