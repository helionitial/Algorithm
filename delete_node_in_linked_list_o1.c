//
//  delete_node_in_linked_list_o1.c
//  
//
//  Created by Li He on 6/10/14.
//
//

#include <stdio.h>

// delete a node in a list
// input: pListHead - the head of list
// pToBeDeleted - the node to be deleted
void DeleteNode(ListNode* pListHead, ListNode* pToBeDeleted){
    if(!pListHead || !pToBeDeleted) return;
    
    // if pToBeDeleted is not the last node in the list
    if(pToBeDeleted->m_pNext != NULL){
        // copy data from the node next to pToBeDeleted
        ListNode* pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nKey = pNext->m_nKey;
        pToBeDeleted->m_pNext = pNext->m_pNext;
        
        // delete the node next to the pToBeDeleted
        delete pNext;
        pNext = NULL;
    }
    else{
        // if pToBeDeleted is the last node in the list
        ListNode* pNode = pListHead;
        while(pNode->m_pNext != pToBeDeleted){
            pNode = pNode->m_pNext;
        }
        // delete pToBeDeleted
        pNode->m_pNext = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}