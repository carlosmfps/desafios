#include <bits/stdc++.h>
using namespace std;

struct vaga{
    int entrada;
    int saida;
};

int main ()
{
    vector<vaga> vagas;
    vector<vaga>::iterator ptr;
    int i,j,k;
    int numcar,numvag,entrada, saida,curvag;
    int set=1;

    cin >>numcar >> numvag;
    while(numcar != 0 && numvag != 0){
        cout<< "mais um\n";
        for(i=0;i<numcar;i++){
            if(set==0){            
            cin >>entrada >>saida;
            continue;
            }
            cin >>entrada >>saida;
            curvag=vagas.size();
            cout << curvag<<"\n";
            set=0;
            if(curvag==0){
                vagas.push_back(vaga());
                vagas.back().entrada=entrada;
                vagas.back().saida=saida;
                curvag++;
                set=1;
            }
            else if(curvag<=numvag){
                    for(ptr=vagas.end()-1;ptr>=vagas.begin();ptr--){
                        cout<<(*ptr).saida;
                        if(entrada >= (*ptr).saida){
                            vagas.pop_back();
                            cout<<"saiu\n";
                            curvag--;
                            continue;
                        }
                        else if(saida>(*ptr).saida){
                            cout<<"tranco\n";
                            break;
                        }
                        else{
                            if(curvag==numvag){
                                cout<<"talotadocarai\n";
                                break;
                            }
                            vagas.push_back(vaga());
                            vagas.back().entrada = entrada;
                            vagas.back().saida = saida;
                            set=1;
                            curvag++;
                            cout <<"entro\n";
                            break;
                    }
                        
                }                       
            }
            if(curvag==0){
                vagas.push_back(vaga());
                vagas.back().entrada=entrada;
                vagas.back().saida=saida;
                set=1;
                cout<<"tavazio";
            }                    
        }
        if(set==0){
            printf("Nao\n");
        }
        else{
            printf("Sim\n");
        }
        while(!vagas.empty()){
            vagas.pop_back();
            cout<<"esvaziando\n";
        }
        cin >> numcar >> numvag;
        set=1;

    }
    
    
    return 0;
}