//
//  LCS.c
//
// Most classic Dynamical programming problem.
//
//  Created by Li He on 6/5/14.
//
//

#include <stdio.h>
#include "string.h"

template<typename T>
void prtM(vector<vector<T>>& arr, string msg = ""){
    cout << msg << " " << endl;
    for(auto i: arr){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template<typename T>
void prt(vector<T>& arr, string msg = ""){
    cout << msg << " ";
    for(auto i: arr){
        cout << i << " ";
    }
    cout << endl;
}

void prt_LCS(vector< vector<char> >& S, string& X, int i, int j){
    if(i == 0 || j == 0) return;
    if('s' == S[i][j]){
        prt_LCS(S, X, i - 1, j - 1);
        cout << X[i];
    }else if('j' == S[i][j]){
        prt_LCS(S, X, i, j - 1);
    }else{
        prt_LCS(S, X, i - 1, j);
    }
}

void calc_LCS(String& X, string& Y){
    vector< vector<int> > C;
    vector< vector<char> > S;
    for(int i = 0; i < X.size(); i++){
        C.push_back(vector<int>(Y.size()));
        S.push_back(vector<int>(Y.size()));
    }
    
    for(int i = 0; i < X.size(); i++) C[i][0] = 0;
    for(int j = 0; j < Y.size(); j++) C[0][j] = 0;
    
    for(int i = 1; i < X.size(); i++)
        for(int j = 1; j < Y.size(); j++){
            if(X[i] == Y[j]){
                C[i][j] = C[i - 1][j - 1] + 1;
                S[i][j] = 's';  // same
            }else if(C[i][j - 1] > C[i - 1][j]){
                C[i][j] = C[i][j - 1];
                S[i][j] = 'j';
            }else{
                C[i][j] = C[i - 1][j];
                S[i][j] = 'i';
            }
        }

    prtM(C);
    prtM(S);
    prt_LCS(S, X, X.size() - 1, Y.size() - 1);
    cout << endl;
}


// LCCS?
// longest consecutive common substring?

