#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n,k,i,x,y,z,input;
    float med;
    vector<int> vetor;
    vector<float> medias;
    while(cin>>n){
        cin>>k;
        for(i=0;i<n;i++){
            cin >> input;
            vetor.push_back(input);
        }
        
        for(x= 0; x < n; x++)
            for(y = x+1; y < n; y++)
                for(z = y+1; z < n; z++){
                    med =(vetor[x] + vetor[y] + vetor[z]) / 3.0;
                    medias.push_back(med);
                }

        sort(medias.begin(), medias.end(), greater<float>()); 
        printf("%.1f\n", medias[k-1]);
        
        for(i=0;i<n;i++){
            vetor.pop_back();
        }
    }
    
    
    return 0;
}