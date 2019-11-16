#include <bits/stdc++.h>
using namespace std;
int visitados[26];


void dfs(vector<vector<int> > grafo,int tamanho,int origem,int aux)
{
    int i;

    for(i=0;i<tamanho;i++){
        if(grafo[origem][i]==1 && visitados[i]==0){
            visitados[i]=aux;
            dfs(grafo,tamanho,i,aux);      
        }
    }    
}

void embers(int teste, map<char,int> dic, map<int,char> dic2){
    int qvertice, qaresta;
    char entrada, saida;
    int familia=1;
    int i,j,k;
    int entrada2,saida2;
    cin >> qvertice >> qaresta;    
    vector<vector<int> > grafo(qvertice,vector<int>(qvertice));

    for(i=0;i<26;i++){
        visitados[i]=0;
    }

    for(j=0; j<qvertice; j++)         
    {
        for(k=0; k<qvertice; k++)
        {
            if(j==k)
            {
                grafo[j][k]=1;
            }
            else
            {
                grafo[j][k]=0;
                grafo[k][j]=0;
            }
        }
    }

    for(i=0;i<qaresta;i++){
        cin >>entrada;
        cin>> saida;
        entrada2 = dic[entrada];
        saida2 = dic[saida];
        grafo[entrada2][saida2]=1;
        grafo[saida2][entrada2]=1;
    }

    for(i=0;i<qvertice;i++){
        if(visitados[i]==0){
            visitados[i]=familia;
            dfs(grafo,qvertice,i,familia);
            familia++;
        }
    }

    cout<< "Case #"<< teste << ":\n";
    for(i=1;i<familia;i++){

        for(j=0;j<qvertice;j++){
            if(visitados[j]==i){
                cout <<dic2[j]<< ',';
            }

        }
        cout << '\n';
    }
    cout << familia-1<<" connected components\n\n"; 



}


int main()
{
    int origem,destino,num_teste;
    int i,j,k;
    map<char,int> dic;
    map<int,char> dic2;
    dic.insert(pair<char,int>('a',0));
    dic.insert(pair<char,int>('b',1));
    dic.insert(pair<char,int>('c',2));
    dic.insert(pair<char,int>('d',3));
    dic.insert(pair<char,int>('e',4));
    dic.insert(pair<char,int>('f',5));
    dic.insert(pair<char,int>('g',6));
    dic.insert(pair<char,int>('h',7));
    dic.insert(pair<char,int>('i',8));
    dic.insert(pair<char,int>('j',9));
    dic.insert(pair<char,int>('k',10));
    dic.insert(pair<char,int>('l',11));
    dic.insert(pair<char,int>('m',12));
    dic.insert(pair<char,int>('n',13));
    dic.insert(pair<char,int>('o',14));
    dic.insert(pair<char,int>('p',15));
    dic.insert(pair<char,int>('q',16));
    dic.insert(pair<char,int>('r',17));
    dic.insert(pair<char,int>('s',18));
    dic.insert(pair<char,int>('t',19));
    dic.insert(pair<char,int>('u',20));
    dic.insert(pair<char,int>('v',21));
    dic.insert(pair<char,int>('w',22));
    dic.insert(pair<char,int>('x',23));
    dic.insert(pair<char,int>('y',24));
    dic.insert(pair<char,int>('z',25));
    dic2.insert(pair<int,char>(0,'a'));    
    dic2.insert(pair<int,char>(1,'b'));
    dic2.insert(pair<int,char>(2,'c'));    
    dic2.insert(pair<int,char>(3,'d'));
    dic2.insert(pair<int,char>(4,'e'));    
    dic2.insert(pair<int,char>(5,'f'));
    dic2.insert(pair<int,char>(6,'g'));    
    dic2.insert(pair<int,char>(7,'h'));
    dic2.insert(pair<int,char>(8,'i'));    
    dic2.insert(pair<int,char>(9,'j'));
    dic2.insert(pair<int,char>(10,'k'));    
    dic2.insert(pair<int,char>(11,'l'));
    dic2.insert(pair<int,char>(12,'m'));    
    dic2.insert(pair<int,char>(13,'n'));
    dic2.insert(pair<int,char>(14,'o'));    
    dic2.insert(pair<int,char>(15,'p'));
    dic2.insert(pair<int,char>(16,'q'));
    dic2.insert(pair<int,char>(17,'r'));    
    dic2.insert(pair<int,char>(18,'s'));
    dic2.insert(pair<int,char>(19,'t'));    
    dic2.insert(pair<int,char>(20,'u'));
    dic2.insert(pair<int,char>(21,'v'));
    dic2.insert(pair<int,char>(22,'w'));    
    dic2.insert(pair<int,char>(23,'x'));
    dic2.insert(pair<int,char>(24,'y'));    
    dic2.insert(pair<int,char>(25,'z'));
    
    cin >> num_teste;
    for(i=1;i<=num_teste;i++){
        embers(i,dic,dic2);
    }

    
    

    return 0;
}
