//
//  tree_deep.c
//  
//
//  Created by Li He on 6/7/14.
//
//

#include <stdio.h>


struct SBinaryTreeNode{
    int m_nValue;
    SBinaryTreeNode* m_pLeft;
    SBinaryTreeNode* m_pRight;
};

// get depth of a binary tree
// input: pTreeNode - the head of a binary tree
// output: the depth of a binary tree

int TreeDepth(SBinaryTreeNode* pTreeNode){
    // the depth of a empty tree is 0
    if(!pTreeNode) return 0;
    
    // the depth of left sub-tree
    int nLeft = TreeDepth(pTreeNode->m_pLeft);
    // the depth of right sub-tree
    int nRight = TreeDepth(pTreeNode->m_pRight);
    
    return (nLeft > nRight)?(nLeft + 1):(nRight + 1);
}

