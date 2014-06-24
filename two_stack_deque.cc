//
//  two_stack_deque.cc
//  
//
//  Created by Li He on 6/5/14.
//
//

#include <stdio.h>
// class definition
template<typename T>
class CQueue{
public:
    CQueue(){}
    ~CQueue(){}
    void appendTail(const T& node);
    void deleteHead();
private:
    stack<T>m_stack1;
    stack<T>m_stack2;
};

// append a element at the tail of the queue
template<typename T>
void CQueue<T>::appendTail(const T& element){
    // push the new element into m_stack1
    m_stack1.push(element);
}

// delete the head from the queue
template<typename T>
void CQueue<T>::deleteHead(){
    // if m_stack2 is empty
    // and there are some elements in m_stack1, push them in m_stack2
    if(m_stack2.size() <= 0){
        while(m_stack1.size() > 0){
            T& data = m_stack1.top();
            m_stack1.pop();
            m_stack2.push(data);
        }
    }
    assert(m_stack2.size() > 0);
    m_stack2.pop();
}

