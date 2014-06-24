//
//  reverse_linked_list.c
//  
//
//  Created by Li He on 6/5/14.
//
//

#include <stdio.h>

struct ListNode{
    int m_nKey;
    ListNode* m_pNext;
};

// reverse a list iteratively
// input: pHead - the head of the original list
// output: the head of the reversed head

ListNode* ReverseIteratively(ListNode* pHead){
    ListNode* pReversedHead = NULL;
    ListNode* pNode - pHead;
    ListNode* pPrev = NULL;
    while(pNode != NULL){
        // get the next node, and save it at pNext
        ListNode* pNext = pNode->m_pNext;
        // if the next node is null, the current is the end of original
        // list, and its the head of the reversed list.
        if(pNext == NULL) pReversedHead = pNode;
        
        // reverse the linkage between nodes
        pNode->m_pNext = pPrev;
        
        pPrev = pNode;
        pNode = pNext;
    }
    return pReversedHead;
}
