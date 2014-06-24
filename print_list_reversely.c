//
//  print_list_reversely.c
//  
//
//  Created by Li He on 6/10/14.
//
//

#include <stdio.h>

// print a list from end to beginning
// input: pListHead - the head of list

void print_list_reversely(ListNode* pListHead){
    if(pListHead != NULL){
        print_list_reversely(pListHead->m_pNext);
    }
    printf("%d", pListHead->m_nKey);
}