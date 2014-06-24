//
//  final_class.cc
//  
//
//  Created by Li He on 6/10/14.
//
//

#include <stdio.h>

// without using final keyword

class FinalClass1{
public:
    static FinalClass1* GetInstance(){
        return new FinalClass1;
    }
    static void DeleteInstance(FinalClass1* pInstance){
        delete pInstance;
        pInstance = 0;
    }
private:
    FinalClass1(){}
    ~FinalClass1(){}
};

// better:
template<typename T>
class MakeFinal{
    friend T;
private:
    MakeFinal(){}
    ~MakeFinal(){}
};
class FinalClass2: virtual public MakeFinal<FinalClass2>{
public:
    FinalClass2(){}
    ~FinalClass2(){}
}

// 38/74, very good sample
