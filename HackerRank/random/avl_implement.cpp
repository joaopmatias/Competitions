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

int getbalance(node * root){
    if(root == nullptr) return 0;
    else return height(root -> left) - height(root -> right);
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
    x -> parent = root -> parent;
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
    z -> parent = root -> parent;
    root->parent = z;
    if(root ->right != nullptr) root -> right -> parent = root;
    return z;
}

node * insertin(node * root, int value){
    node * noob = newnode(value);
    if(root == nullptr) return noob;
    node *t = root, *u = root;
    while(u != nullptr){
        t = u;
        if(value < u -> value) u = u -> left;
        else u = u-> right;
    }
    if(value < t -> value) t -> left = noob;
    else t-> right = noob;
    noob -> parent = t;
    u = t;
    t = t -> parent;
    while(t != nullptr){
        u = t;
        if(getbalance(u) > 1){
            if(value < u -> value) u = rotateR(u);
            else{//left right
                u -> left = rotateL(u -> left);
                u = rotateR(u);
            }
        }
        if(getbalance(u) < -1){
            if(value >= u -> value) u = rotateL(u);
            else{//right left
                u -> right = rotateR(u -> right);
                u = rotateL(u);
            }
        }
        else u -> height = max(height(u->right), height(u-> left)) + 1;
        t = t -> parent;
    }
    return u;
}

//YOU ARE HERE

//give smallest term too
node * erasin(node * root, int value){

    return root;
}


int main(){




}