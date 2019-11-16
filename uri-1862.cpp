#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int num,i,j;
    char aux;
    int people[1000][1000];

    cin >> num;

    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            cin >> aux;       
            if(aux == 'S'){
                people[i][j]=1;
            }
            else(people[i][j]=0);
        }
    }
    for(i=0;i<num;i++){
            for(j=0;j<num;j++){
                cout << people[i][j];
            }
        }
    cout<< "a";
    return 0;
}