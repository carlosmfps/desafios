#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    while(x!=0){

        for(int i=1;i<=sqrt(x);i++){
            if(i>1){
                cout << ' ';
            }
            cout << i*i;
        }
        cout << '\n';
        cin >> x;
    }

    return 0;
}
