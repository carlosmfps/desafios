/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
*/
#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};



bool auxy(Node* root, int* aux){
    
    bool middle = false;
    

    if(root->left == NULL){
        if(*aux<root->data){
            middle = true;
            *aux = root->data;
        }
        else return false;
        if(root->right == NULL){
            return middle;
        }
    }
    else{
        bool left = auxy(root->left, aux);
        if(*aux<root->data){
            *aux = root->data;
            middle = true;
        }
        else{
            return false;
        }
        if(root->right == NULL){
            return left && middle;
        }
        else{
            return left && middle && auxy(root->right, aux);
        }

    }
}

void auxx(Node* root, int* aux){
    if(root.left==NULL){
        *aux = root->data;
    }
    else{
        auxx(root->left,*aux);s
    }
}

bool checkBST(Node* root) {
    int aux=0;
    auxx(root, &aux );
    return auxy(root, &aux);
};