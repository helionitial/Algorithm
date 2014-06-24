//
//  find_kth_to_tail_in_linked_list.c
//  
//
//  Created by Li He on 6/4/14.
//
//

#include <stdio.h>

struct ListNode{
    int m_nKey;
    ListNode* m_pNext;
};

// find the kth node from the tail of a list
// input: pListHead - the head of list
//                  - the distance to the tail
// output: the kth node from the tail of a list

// method 1:
// not recommended, 2 times traversa

ListNode* find_kth_to_tail_in_linked_list(ListNode* pListHead,
                                          unsigned int k){
    if(pListHead == NULL) return NULL;
    
    // count the nodes number in the lsit
    ListNode *pCur = pListHead;
    unsigned int nNum = 0;
    while(pCur->m_pNext != NULL){
        pCur = pCur->m_pNext;
        nNum ++;
    }
    
    // if the number of nodes in the list is less than k
    // do nothing
    if (nNum < k) {
        return NULL;
    }
    
    // the kth node from the tail of a list
    // is the (n - k)th node from the head
    pCur = pListHead;for(unsigned int i = 0; i < nNum - k; ++ i)
        pCur = pCur->m_pNext;
    
    return pCur;
}

// method 2:
// use a pair of pointer

listNode* find_kth_to_tail_in_linked_list(ListNode* pListHead,
                                          unsigned int k){
    if(pListHead == NULL) return NULL;
    
    ListNode* pAhead = pListHead;
    ListNode* pBehind = NULL;
    
    for(unsigned int i = 0; i < k; ++ i){
        if(pAhead->m_pNext != NULL)
            pAhead = pAhead->m_pNext;
        else{
            // if the number of nodes in the list is less than k
            return NULL;
        }
    }
    pBehind = pListHead;
    
    // the distance between pAhead and pBehind is k
    // when pAhead arrives at the tail, p
    // behind is at the kth node from the tail
    
    whil(pAhead->m_pNext != NULL){
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    
    return pBehind;
}
