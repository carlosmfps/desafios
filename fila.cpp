// cin with strings
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int nclient,nfunc;
    int client[10000],func[10000][2]={{0}};
    int i,j,k,a,tempo=0,full,menort,pos,ptime=0;

    cin >>nfunc >>nclient;

    /*
    for(i=0;i<nfunc;i++){
        cin >> func[i][0];
    }
    for(i=0;i<nclient;i++){
        cin >> client[i];
    }

    for(i=0;i<nclient;i++){
        menort=101;
        for(j=0;j<nfunc;j++){
            if(func[j][1]==0){
                pos=j;
                full=0;
                break;
            }
            if(func[j][1] < menort){
                menort=func[j][1];
                pos=j;
                full=1;
            }
        }
        if(full){
            tempo+=func[pos][1];
            for(j=0;j<nfunc;j++){
                func[j][1]=func[j][1]-menort;
            }
        }
        func[pos][1]=func[pos][0]*client[i];

    }
    menort=0;
    for(j=0;j<nfunc;j++){
        if(func[j][1]>menort){
            menort=func[j][1];
        }
    }
    tempo+=menort;
    cout << tempo << "\n";*/
    cout << "aaa";

  return 0;
}
