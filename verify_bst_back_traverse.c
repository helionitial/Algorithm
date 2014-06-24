//
//  verify_bst_back_traverse.c
//  
//
//  Created by Li He on 6/4/14.
//
//

#include <stdio.h>

using namespace std;

// verify whether a sequence of integers are the post order traversal
// of a binary search tree
// input: sequence - the sequence of integers
//        length - the length of sequence
// return: return true if the sequence is traversal result of a BST,
//         other wise, return false

bool verifySequenceOfBST(int sequence[], int length){
    if(sequence == NULL || length <= 0)
        return false;
    
    // root of a BST is at the end of post order traversal sq
    int root = sequence[length - 1];
    // the nodes in left sub tree are less than the root
    int i = 0;
    for(; i < length - 1; ++ i){
        if(sequence[i] > root)
            break;
    }
    
    // the nodes in the right sub-tree are greater than the root
    int j = 0;
    for(; j < length - 1; ++ j){
        if(sequence[j] < root) return false;
    }
    
    // verify whether the left sub-tree is a BST
    bool left = true;
    if(i > 0)
        left = verifySequenceOfBST(sequence, i);
    
    // verify whether the right sub-tree is a BST
    bool right = true;
    if(i < length - 1)
        right = verifySequenceOfBST(sequence + i, length - i - 1);
    
    return (left && right);
}