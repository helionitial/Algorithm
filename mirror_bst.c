//
//  mirror_bst.c
//  
//
//  Created by Li He on 6/4/14.
//
//

#include <stdio.h>

struct BSTreeNode{
    int m_nValue;
    BSTreeNode* m_pLeft;
    BSTreeNode* m_pRight;
};


// mirror a BST(swap the left right child of each node) recursively
// the head of BST in initial call

void MirrorRecursively(BSTreeNode* pNode){
    if(!pNode) return;
    
    // swap the right and left child sub tree
    BSTreeNode* pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp;
    
    // mirror left child sub-tree if not null
    if(pNode->m_pLeft)
        MirrorRecursively(pNode->m_pLeft);
    
    // mirror right child sub tree if not null
    if(pNode->m_pRight)
        MirrorRecursively(pNode->m_pRight);
}

// non-recursive version

void MirrorIteratively(BSTreeNode* pTreeHead){
    if(!pTreeHead)
        return;
    
    std::stack<BSTreeNode* > stackTreeNode;
    stackTreeNode.push(pTreeHead);

    while(stackTreeNode.size()){
        BSTreeNode* pNode = stackTreeNode.top();
        stackTreeNode.pop();
        
        // swap the right and left child sub-tree
        BSTreeNode* pTemp = pNode->m_pLeft;
        pNode->m_pLeft = pNode->m_pRight;
        pNode->m_pRight = pTemp;
        
        // push left child sub-tree into stack if not null
        if(pNode->m_pLeft)
            stackTreeNode.push(pNode->m_pLeft);
        
        // push right child sub-tree into stack if not null
        if(pNode->m_pRight)
            stackTreeNode.push(pNode->m_pRight);
    }
}