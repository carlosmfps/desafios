#include <bits/stdc++.h>
using namespace std;


int dist(string a,string b){
    int dist=0;
    int i;

    for(i=0;i<a.length();i++){
        if(a[i]!=b[i]){
            dist++;
        }
    }

    return dist;
}


int main ()
{
    
    int num;
    string a,b,c,d,e,f;
    int i,saida=-1,saida2,vetor[5];
    cin >> a >> num >> b >> c >> d >> e >> f;
    vetor[0]=dist(a,b);
    vetor[1]=dist(a,c);
    vetor[2]=dist(a,d);
    vetor[3]=dist(a,e);
    vetor[4]=dist(a,f);

    saida2=a.length()+1;
    for(i=0;i<5;i++){
         if(vetor[i]>=0 && vetor[i]<=num && vetor[i]<=saida2){
            saida=i+1;
            saida2=vetor[i];
        }
    }
    if(saida!=-1){
        printf("%d\n%d\n",saida,saida2);
    }
    else{
        printf("-1\n");
    }

    return 0;
}