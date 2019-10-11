#include <bits/stdc++.h>
using namespace std;

int menor(int a, int b, int c){
    int m;
    if(a<b && a<c){
        m=a;
    }
    else if(b<a && b<c){
        m=b;
    }
    else{
        m=c;
    }
    return m;
}
int dist(string a,string b){
   
    int i,j,c;
    int** p = new int*[a.length()];
    for(i=0;i<a.length();i++){
        p[i]= new int[b.length()];
    }

    for(i=0;i<a.length();i++){
        p[i][0]=i;
    }
    for(i=0;i<b.length();i++){
        p[0][i]=i;
    }
    for(i=1;i<a.length();i++){
        for(j=1;j<b.length();j++){
            if(a[i]==b[j]){
                c=0;
            }
            else{
                c=2;
            }
            p[i][j] = menor(p[i-1][j]+1,p[i][j+1]+1,p[i-1][j-1]+c);
        }
    }
    return p[a.length()-1][b.length()-1];
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

    for(i=0;i<5;i++){
        if(vetor[i]>=0 && vetor[i]<=num){
            saida=i+1;
            saida2=vetor[i];
        }
    }
    if(saida!=-1){
        printf("%d\n%d",saida,saida2);
    }
    else{
        printf("-1\n");
    }

    return 0;
}