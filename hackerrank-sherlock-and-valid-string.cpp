#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    
    int len = s.length();
    vector<int > letras(26);
    int i;
    
    int prin=0,aux;
    int sec=0;
    bool subst=true;
    for(i=0;i<26;i++){
        letras[i]=0;
    }
    for(i=0;i<len;i++){
        letras[s[i]-'a']+=1;
    }
    
    
    for(i=0;i<26;i++){
        if(letras[i]==0){
        }
        else if(prin==0){
            prin = letras[i];
        }
        else if(letras[i]==prin){
            subst = false;
        }
        else if(letras[i]!=prin && sec == 0){
            sec = letras[i];
        }
        else if(letras[i]==sec){
            if(subst){
                subst = false;
                aux = prin;
                prin = sec;
                sec = aux;
            }
            else{
                return "NO";
            }
        }
        else{

         return "NO";
        }

        //cout << "prin = " << prin << "\nsec = " << sec << "\n";
    }

    if(sec <=1 || sec-1 == prin){
        return "YES";
    }
    else{
        return "NO";
    }

}

int main()
{
    

    string s;
    getline(cin, s);

    string result = isValid(s);

    cout << result << "\n";

    return 0;
}
