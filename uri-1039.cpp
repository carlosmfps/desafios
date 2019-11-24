#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int r1,x1,y1,r2,x2,y2;
    while(cin >> r1){
        cin >> x1 >> y1 >> r2 >> x2 >> y2;
        float dist = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
        if(r1 >= dist+r2){
            cout << "RICO\n";
        }
        else{
            cout << "MORTO\n";
        }
    }
    
    return 0;
}