
#include <bits/stdc++.h>
using namespace std;

#define infinito numeric_limits<int>::max()
int visitados[400];

void dfs(vector<vector<int> > grafo,int tamanho,int origem,int aux)
{
    int achou,i,retorno=0;

    for(i=0;i<tamanho;i++){
        if(grafo[origem][i]==1 && visitados[i]==0){
            visitados[i]=aux;
            dfs(grafo,tamanho,i,aux);      
        }
    }    
}



int main()
{
    int num_cidades = 0;
    int origem,destino,custo,numper;
    int i,j,k;
    int num_ruas,numrota,cid,alvo;
    
    cin >> num_cidades >> num_ruas >> numper;
    vector<vector<int> > grafo(num_cidades,vector<int>(num_cidades));

    for(j=0; j<num_cidades; j++)            //Inicializa o grafos(ainda sem valores das ruas)
    {
        for(k=0; k<num_cidades; k++)
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

    for(j=0; j<num_ruas; j++)                   //coloca os valores das ruas no grafo
    {
        cin >> origem >> destino;
        grafo[origem-1][destino-1]=1;
        grafo[destino-1][origem-1]=1;        
    }        
    /*for(i=0;i<num_cidades;i++){
        for(j=0;j<num_cidades;j++){
            cout << grafo[i][j];
        }
        cout<< '\n';
    }*/
    

    for(j=0;j<num_cidades;j++){
            visitados[j]=0;
        }

    for(i=0;i<numper;i++){        
        
        cin>> origem>>destino;
        if(visitados[origem-1]==visitados[destino-1] && visitados[origem-1]==0){
            dfs(grafo,num_cidades,origem-1,i+1);
        }
        if(visitados[origem-1]==visitados[destino-1] && visitados[origem-1]!=0){
            
            cout << "Lets que lets\n";

        }
        else{
            cout << "Deu ruim\n";
        }
        
    }
    

    return 0;
}
