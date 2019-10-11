
#include <bits/stdc++.h>
using namespace std;

#define infinito numeric_limits<int>::max()


bool tds_visitados(bool visitados[],int num_cidades)
{
    int i;

    for(i=0; i<num_cidades; i++)
    {
        if(!visitados[i])
        {
            return false;
        }

    }
    return true;
}

int dijkstra(vector<vector<int> > grafo,int num_cidades,int inicio,int dest)
{
    int i,j,k;
    int menor_dist_atual = 0;
    int menor_nodo_atual = 0;

    int dist_min[num_cidades];
    int preced[num_cidades];
    bool visitados[num_cidades];


    for(i=0; i<num_cidades; i++)      //inicializa tds os vetores auxiliares;
    {
        dist_min[i] = infinito;
        preced[i] = -1;
        visitados[i] = false;
    }


    visitados[inicio] = true;                   //Coloca os valores da raiz nos vetores
    preced[inicio] = inicio;
    dist_min[inicio] = 0;

    for (i=0; i<num_cidades; i++)
    {
        if(grafo[inicio][i] != -1)              //Inicializa os vetores com nodos conectados com a raiz
        {
            dist_min[i] = grafo[inicio][i];
            preced[i] = inicio;
        }
    }

    while(!tds_visitados(visitados,num_cidades))//Enquanto tds os nodos n forem visitados o la�o de visita deve continuar
    {

        menor_dist_atual = infinito;

        for(i=0 ; i<num_cidades ; i++)
        {
            if((visitados[i] == false) && (dist_min[i] <= menor_dist_atual)) //Encontra o proximo nodo a ser visitado, ou seja, o de menor custo quanto a raiz
            {
                menor_dist_atual =  dist_min[i];
                menor_nodo_atual =  i;

            }
        }
        visitados[menor_nodo_atual] = true;                                    //Marca que o nodo atual foi visitado

        for(i=0 ; i<num_cidades ; i++)                                         //La�o que testa as custos dos nodos conectados ao nodo atual e atualiza os dados
        {
            if(visitados[i] == false)                                          //Apenas nodos que n foram visitados ainda devem ser testados
            {

                if(grafo[menor_nodo_atual][i] != -1)                           //Apenas conex�es existentes podem ser testadas
                {

                    if((grafo[menor_nodo_atual][i] + dist_min[menor_nodo_atual]) < dist_min[i]) //Teste para saber se o caminho atrav�s do novo nodo � menor que o antigo
                    {

                        dist_min[i] = grafo[menor_nodo_atual][i] + dist_min[menor_nodo_atual];
                        preced[i] = menor_nodo_atual;
                    }

                }
            }

        }

    }
    return dist_min[dest];
}



int main()
{
    int num_cidades = 0;
    int origem,destino,custo;
    int i,j,k;
    int num_ruas,numrota,cid;
    
    cin >> num_cidades >> num_ruas >> numrota >> cid;
    while(num_cidades !=0  || num_ruas !=0 || numrota!=0 || cid!=0){
        vector<vector<int> > grafo(num_cidades,vector<int>(num_cidades));

        for(j=0; j<num_cidades; j++)            //Inicializa o grafos(ainda sem valores das ruas)
        {
            for(k=0; k<num_cidades; k++)
            {
                if(j==k)
                {
                    grafo[j][k]=0;
                }
                else
                {
                    grafo[j][k]=-1;
                    grafo[k][j]=-1;
                }
            }
        }

        for(j=0; j<num_ruas; j++)                   //coloca os valores das ruas no grafo
        {
            cin >> origem >> destino >> custo;
            if(destino<numrota && origem<numrota){
                if(origem < destino && destino-origem == 1){
                    grafo[origem][destino] = custo;
                }
                else if(destino < origem && origem-destino == 1){
                    grafo[destino][origem] = custo;
                }
            }
            else if(origem<numrota){
                grafo[destino][origem] = custo;
            }
            else if(destino<numrota){
                grafo[origem][destino] = custo;
            }
            else{
                grafo[origem][destino] = custo;
                grafo[destino][origem] = custo;
            }
        }        

        cout << dijkstra(grafo,num_cidades,cid,numrota-1)<<'\n';
        cin >> num_cidades >> num_ruas >> numrota >> cid;
    }

    return 0;
}
