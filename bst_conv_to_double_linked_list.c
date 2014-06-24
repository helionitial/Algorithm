//
//  alg_0603.c
//
// linked list related algorithm
//
//  Created by Li He on 6/3/14.
//
//

#include <stdio.h>


//////////////////////////////////////////////////////////////////////////////////
// turn a binary search tree into a sorted double-link list.
// no new nodes, just change the pointer
// sample:
//          10
//          /\
//         6  14
//        / \ / \
//       4  8 12 16
//
// 4=6=8=10=12=14=16
//
//
// normally any problem with tree, you should use recursive method.

struct BSTreeNode{
    int m_nValue;
    BSTreeNode* m_pLeft;
    BSTreeNode* m_pRight;
};

// Method 1:
// Convert a sub binary-search tree into a sorted double-linked list
// input: pNode - the head of the sub tree
//        asRight - whether pNode is the right child of its parent
// output: if asRight is true, return the least node in the subtree
//         else return the greatest node in the sub-tree

BSTreeNode* ConvertNode(BSTreeNode* pNode, bool asRight){
    if(!pNode) return NULL;
    BSTreeNode* pLeft = NULL;
    BSTreeNode* pRight = NULL;
    
    // convert the left sub-tree
    if(pNode->m_pLeft)
        pLeft = ConvertNode(pNode->m_pLeft, false);
    
    // connect the greatest node in the left sib-tree to the current node
    if(pLeft){
        pLeft->m_pLeft = pNode;
        pNode->m_pLeft = pLeft;
    }
    
    // convert the right sub-tree
    if(pNode->m_pRight)
        pRight = ConvertNode(pNode->m_pRight, true);
    
    // connect the least node in the right sub-tree to the current node.
    if(pRight){
        pNode->m_pRight = pRight;
        pRight->m_pLeft = pNode;
    }
    
    BSTreeNode* pTemp = pNode;
    // if the current node is the right child of its parent,
    // return the least node in the tree whose root is the current node
    if(asRight){
        while(pTemp->m_pLeft)
            pTemp = pTemp->m_pLeft;
    }
    // if the current node is the left child of its parent,
    // return the greatest node in the tree whose root is the current nde
    else{
        while(pTemp->m_pRight){
            pTemp = pTemp->m_pRight;
        }
    }
    return pTemp;
}

// convert a binary search tree into a sorted double-linked list
// input: the head of tree
// output: the head of sorted double-linked list
BSTreeNode* Convert(BSTreeNode* pHeadOfTree){
    // as we want to return the head of the sorted double-linked list,
    // we set the second parameter to be true
    return ConvertNode(pHeadOfTree, true);
}






// Method 2
// Convert a binary search tree into a sorted double-linked list
// input: the head of tree
// output: the head of sorted double-linked list

void ConvertNode(BSTreeNode* pNode, BSTreeNode*& pLastNodeInList){
    if(pNode == NULL)
        return;
    BSTreeNode* pCurrent = pNode;
    
    // convert the left sub-tree
    if(pCurrent->m_pLeft != NULL)
        ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
    
    // put the current node into the double-linked list
    pCurrent->m_pLeft = pLastNodeInList;
    if(pLastNodeInList != NULL)
        pLastNodeInList->m_pRight = pCurrent;
    
    pLastNodeInList = pCurrent;
    
    // convert the right sub-tree
    if(pCurrent->m_pRight != NULL)
        ConvertNode(pCurrent->m_pRight, pLastNodeInList);
}

// convert a binary search tree into a sorted double-lined list
// input: pHeadOfTree - the head of tree
// output: the head of sorted double-linked list
BSTreeNode* Convert_Solution2(BSTreeNode* pHeadOfTree){
    BSTreeNode* pLastNodeInList = NULL;
    ConvertNode(pHeadOfList, pLastNodeInList);
    
    // get the head of the double-linked list
    BSTreeNode* pHeadOfList = pLastNodeInList;
    while(pHeadOfList && pHeadOfList->m_pLeft)
        pHeadOfList = pHeadOfList->m_pLeft;
    
    return pHeadOfList;
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
