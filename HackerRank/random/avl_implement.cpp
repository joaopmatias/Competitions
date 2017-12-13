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


node * balanceup(node * up){
    //make sure argument is not nullptr
    //assumes that the children of up are balanced
    //and parents are off by at most 2
    node * u, * t;
    u = up;
    t = up;
    while(t != nullptr){
        u = t;
        if(getbalance(u) > 1){
            if(getbalance(u -> left) >= 0) u = rotateR(u);
            else{//left right
                u -> left = rotateL(u -> left);
                u = rotateR(u);
            }
        }
        else if(getbalance(u) < -1){
            if(getbalance(u -> right) <= 0) u = rotateL(u);
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
    u = balanceup(t); 
    return u;
}


node * extremeleft(node * root){
    node * t = root;
    while(t -> left != nullptr) t = t -> left; 
    return t;
}


int erasin(node * root, int value){
    node * u, * v = root, * replace, * fixbalance, *t;
    if(root == nullptr) return 0;
    while(v != nullptr) {
        u = v;
        if(value < v -> value) v -> left;
        else if(value > v -> value) v -> right;
        else v = nullptr;
    }
    if(value != u -> value) return 0; 
    if(u -> right == nullptr){
        replace = u -> left;
        fixbalance = replace
    }
    else if(u -> right -> left == nullptr){
        replace = u -> right;
        replace -> left = u -> left;
        fixbalance = replace;
    }
    else {
        replace = extremeleft(u -> right);
        fixbalance  = replace -> parent;
        fixbalance -> left = nullptr;
        replace -> left = u -> left;
        replace -> right = u -> right;
    }
    if(replace -> right != nullptr) replace -> right -> parent = replace;
    if(replace -> left != nullptr) replace -> left -> parent = replace;
    replace -> parent = u -> parent;
    if(replace -> parent != nullptr){
        if(value < replace -> parent -> value) replace -> parent -> left = replace;
        if(value > replace -> parent -> value) replace -> parent -> right = replace;
    }
    //above is just the beginning
    t = balanceup(fixbalance);
    root = t;
    return 1;
}


int main(){




}