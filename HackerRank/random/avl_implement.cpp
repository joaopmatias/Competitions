#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int value;
    int size;
    int height;
    node * parent;
    node * left;
    node * right;
}

int height(node * root){
    if(root == nullptr) return 0;
    else return root -> height;
}

node * newnode(int value){
    node * ans;
    ans -> value = value;
    ans -> height = 1;
    ans -> parent = nullptr;
    ans -> left = nullptr;
    ans -> right = nullptr;
    return ans;
}

node * rotateR(node * root){
    node * x = root -> left;
    root -> left = x -> right;
    x -> right = root;
    root -> height = max(height(root->right), height(root->left)) + 1;
    x -> height = max(height(x->right), height(x->left)) + 1;
    root-> parent = x;
    if(root -> left != nullptr) root -> left -> parent = root;
    return x;
}

node * rotateL(node * root){
    node * z = root -> right;
    root -> right = z -> left;
    z -> left = root;
    root -> height = max(height(root->right), height(root->left)) + 1;
    z -> height = max(height(z->right), height(z->left)) + 1;
    root->parent = z;
    if(root ->right != nullptr) root -> right -> parent = root;
    return z;
}
//YOU ARE HERE
node * insertin(node * root, int value){
    node * noob = newnode(value);
    if(root == nullptr) return noob;
    node *t = root;
    while(t)


}



int main(){




}