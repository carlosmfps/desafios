#include <bits/stdc++.h>
using namespace std;
int ar[5][5];
int ganhador=0;

void aux(int i,int j,char origin){
    if(ganhador==0){
        if(i!=4 && j !=4){
            ar[i][j]=1;
            switch(origin)
            {
                case 'c':
                    if(j!=0 && ar[i][j-1]==0){
                        aux(i,j-1,'d');
                    }//esquerda
                    if(i!=4 && ar[i+1][j]==0){
                        aux(i+1,j,'c');
                    }//baixo
                    if(j!=4 && ar[i][j+1]==0){
                        aux(i,j+1,'e');
                    }//direita
                    break;
                case 'e':
                    if(i!=0 && ar[i-1][j]==0){
                        aux(i-1,j,'b');
                    }//cima
                    if(i!=4 && ar[i+1][j]==0){
                        aux(i+1,j,'c');
                    }//baixo
                    if(j!=4 && ar[i][j+1]==0){
                        aux(i,j+1,'e');
                    }//direita
                    break;
                case 'd':
                    if(i!=0 && ar[i-1][j]==0){
                        aux(i-1,j,'b');
                    }//cima
                    if(i!=4 && ar[i+1][j]==0){
                        aux(i+1,j,'c');
                    }//baixo
                    if(j!=0 && ar[i][j-1]==0){
                        aux(i,j-1,'d');
                    }//esquerda
                    break;
                case 'b':
                    if(i!=0 && ar[i-1][j]==0){
                        aux(i-1,j,'b');
                    }//cima
                    if(j!=4 && ar[i][j+1]==0){
                        aux(i,j+1,'e');
                    }//direita
                    if(j!=0 && ar[i][j-1]==0){
                        aux(i,j-1,'d');
                    }//esquerda
                    break;
            }
        }
        else{
            ganhador=1;
        }
    }
}


int main ()
{
    int testes;
    int i,j,x;
    cin >> testes;
    for(x=0;x<testes;x++){
        for(i=0;i<5;i++){
            for(j=0;j<5;j++){
                cin>> ar[i][j];
            }
        }
        aux(0,0,'e');
        if(ganhador==1){
            printf("COPS\n");
        }
        else{
            printf("ROBBERS\n");
        }

        for(i=0;i<5;i++){
            for(j=0;j<5;j++){
                ar[i][j]=0;
            }
        }
        ganhador=0;
    }
    
    
    return 0;
}