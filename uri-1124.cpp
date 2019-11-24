#include <bits/stdc++.h>
using namespace std;

int main(){
    int L,C,r1,r2;

    cin >> L >> C >> r1 >> r2;
    while(L!=0 || C!=0 || r1!=0 || r2!=0){
        if(min(L,C)< max(r1,r2)*2){
            cout << "N\n";
        }else{
            r1 = r1 + r2;
	        L = L - r1; 
	        C = C - r1;
            if(r1 * r1 > ((L * L) + (C * C))) cout << "N\n";
	        else cout << "S\n";
        }
        cin >> L >> C >> r1 >> r2;         
    }

    return 0;
}