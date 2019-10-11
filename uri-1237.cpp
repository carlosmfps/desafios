#include <bits/stdc++.h>
using namespace std; 
  

int F_LCS(string X, string Y) 
{ 
    int T_LCS[X.length()+1][Y.length()+1]; 
    int result = 0;  
    for (int i=0; i<=X.length(); i++) 
    { 
        for (int j=0; j<=Y.length(); j++) 
        { 
            if (i == 0 || j == 0) 
                T_LCS[i][j] = 0; 
  
            else if (X[i-1] == Y[j-1]) 
            { 
                T_LCS[i][j] = T_LCS[i-1][j-1] + 1; 
                result = max(result, T_LCS[i][j]); 
            } 
            else T_LCS[i][j] = 0; 
        } 
    } 
    return result; 
}

int main() 
{ 
    string X,Y;
    while(getline(cin,X)){
    getline(cin,Y);
  
    cout  << F_LCS(X, Y)<< '\n';
    }
    return 0; 
} 