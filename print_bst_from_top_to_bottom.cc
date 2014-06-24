//
//  print_bst_from_top_to_bottom.cc
//  
//
//  Created by Li He on 6/4/14.
//
//

#include <deque>
#include <iostream>

struct BTreeNode{
    int m_nValue;
    BTreeNode* m_pLeft;
    BTreeNode* m_pRight;
};

// print a binary tree from top level to bottom level
// input: pTreeRoot - the root of binary tree

void PrintFromTopToBottom(BTreeNode* pTreeRoot){
    if(!pTreeRoot) return;
    
    // get a empty queue
    deque<BTreeNode* > dequeTreeNode;
    
    // insert the root at the tail of queue
    dequeTreeNode.push_back(pTreeRoot);
    while (dequeTreeNode.size()) {
        // get a node from the head of queue
        BTreeNode* pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();
        
        // print the node
        cout << pNode->m_nValue << ' ';
        
        // print its left child sub-tree if it has
        if(pNode->m_pLeft)
            dequeTreeNode.push_back(pNode->m_pLeft);
        
        // print its right child sub-tree if it has
        if(pNode->m_pRight)
            dequeTreeNode.push_back(pNode->m_pRight);
        
    }
}
