//
//  find_path_with_sum_of_n_in_bst.c
//  
//
//  Created by Li He on 6/4/14.
//
//

#include <stdio.h>

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinarTreeNode *m_pRight;
};


void FindPath( BinaryTreeNode* pTreeNode,   // a node of binary tree
              int expectedSum,  // the expected sum
              std::vector<int>& path, // a path from root to current node
              int& currentSum){ // the sum of path
    if(!pTreeNode)
        return;
    currentSum += pTreeNode->m_nValue;
    path.push_back(pTreeNode->m_nValue);
    
    // if the node is a leaf, and the sum is same as pre-defined,
    // the path is what we want. print the path
    bool isLeaf = (!pTreeNode->m_pLeft && !pTreeNode->m_pRight);
    if(currentSum == expectedSum && isLeaf){
        std::vector<int>::iterator iter = path.begin();
        for(; iter != path.end(); ++iter)
            std::cout << *iter << '\t';
        std:: cout << std:: endl;
    }
    
    // if the node is not a leaf, goto its children
    if(pTreeNode->m_pLeft)
        FindPath(pTreeNode->m_pLeft, expectedSum, path, currentSum);
    if(pTreeNode->m_pRight)
        FindPath(pTreeNode->m_pRight, expectedSum, path, currentSum);
    
    // when we finish visiting a node and return to its parent node,
    // we should delete this node fromthe path and minus the node's value
    // from the current sum.
    currentSum -= pTreeNode->m_nValue;
    path.pop_back();
}
