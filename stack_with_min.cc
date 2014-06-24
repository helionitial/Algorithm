//
//  stack_with_min.cc
//  
//
//  Created by Li He on 6/4/14.
//
//

#include <stdio.h>
#include <deque>
#include <assert.h>

template<typename T>
class CStackWithMin{
public:
    CStackWithMin(void){};
    virtual ~CStakcWithMin(void){}
    T& top(void);
    const T& top(void) const;
    
    void push(const T& value);
    void pop(void);
    
    const T& min(void) const;
    
private:
    deque<T> m_data;    // the elements of stack
    deque<size_t> m_minIndex;   // the indices of minimum elements
};

// get the last elem of mutable stack
template<typename T>
T& CStackWithMin<T>::top(){
    return m_data.back();
}

// get the last elem of non-mutable stack
template<typename T>
const T& CStackWithMin<T>::top() const{
    return m_data.back();
}

// insert an elem at the end of stack
template<typename T>
void CStackWithMin<T>::push(const T& value){
    
    // append the data into the end of m_data
    m_data.push_back(value);
    
    //set the index of minimum elem  in m_data at the end of m_minIndex
    if(m_minIndex.size() == 0)
        m_minIndex.push_back(0);
    else{
        if(value < m_data[m_minIndex.back()])
            m_minIndex.push_back(m_data.size() - 1);
        else
            m_minIndex.push_back(m_minIndex.back());
    }
}

// erase the elem at the end of stack
template<typename T>
void CStackWithMin<T>::pop(){
    // pop m_data
    m_data.pop_back();
    // pop m_minIndex
    m_minIndex.pop_back();
}

// get the minimum elem of stack
template<typename T>
const T& CStackWithMin<T>::min() const{
    assert(m_data.size() > 0);
    assert(m_minIndex.size() > 0);
    return m_data[m_minIndex.back()];
}