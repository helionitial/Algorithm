//
//  exception_safe_operator_assig.cc
//  
//
//  Created by Li He on 6/8/14.
//
//

#include <stdio.h>

class CMyString{
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString(void);
    CMyString& operator = (const CMyString& str);
private:
    char* m_pData;
};


// normal version
CMyString& CMyString::operator = (const CMyString& str){
    if(this == &str) return *this;
    
    delete []m_pData;
    m_pData = NULL;
    
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
    
    return *this;
}

// safer
CMyString& CMyString::operator = (const CMyString& str){
    if(this != &str){
        CMyString strTemp(str);
        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }
    return *this;
}