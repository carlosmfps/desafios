#include <bits/stdc++.h>
using namespace std;


struct produto{
    string nome;
    float preco;

};


int main ()
{
    vector<produto> mercado;
    vector<produto>::iterator ptr;
    int i,j,p,idas,m,pquant;
    float total;
    string pname;
    
    cin >> idas;

    for(i=0 ; i<idas ; i++){
        cin >> m;
        for(j=0 ; j<m;j++){
        mercado.push_back(produto());
        cin >> mercado[j].nome >> mercado[j].preco;        
        }
        cin >> p;
        total=0;
        for(j=0;j<p;j++){
            cin >> pname >>pquant;
            for(ptr = mercado.begin(); ptr < mercado.end();ptr++){
                if((*ptr).nome.compare(pname)==0){
                    total+=(*ptr).preco*pquant;
                }
            }

        }
        printf("R$ %.2f\n",total);
        for(j=0 ; j<m;j++){
            mercado.pop_back();
        }

    }
    return 0;
}