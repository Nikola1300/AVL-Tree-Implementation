#include "avl_type.h"
#include <iostream>


AVL_Tree::AVL_Tree(){
    root = nullptr;
}

void AVL_Tree::insert(int x){
    root = insert(root, x);
}

int AVL_Tree::height(Node* node){
    return node ? node->height : -1;
}

int AVL_Tree::balance_factor(Node* node){
    return node ? height(node->left) - height(node->right) : 0;
}

Node* AVL_Tree::insert(Node* root, int key){

    if(!root){
        root = new Node(key);
        return root;
    }

    if(root->val > key){
        root->left = insert(root->left,key);
    }
    else{
        root->right = insert(root->right,key);
    }

    root->height = 1  + std::max(height(root->left), height(root->right));

    int balance = balance_factor(root);

    if(balance > 1 && key < root->left->val){//left heavy
        return rotate_right(root);
    }
    if(balance < -1 && key > root->right->val){//right heavy
        return rotate_left(root);
    }
    if(balance > 1 && key > root->left->val){
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }
    if(balance < -1 && key < root->right->val){
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }


    return root;

}


Node* AVL_Tree::rotate_right(Node* root){

   Node* y = root->left;
   Node* temp = y->right;

   y->right = root;
   root->left = temp;

   root->height = 1 + std::max(height(root->left), height(root->right));
   y->height = 1 + std::max(height(y->left), height(y->right));
   


   return y;

}

Node* AVL_Tree::rotate_left(Node* root){

    Node* y = root->right;
    Node* temp = y->left;

    root->right = temp;
    y->left = root;

    root->height = 1+ std::max(height(root->left), height(root->right));

    y->height = 1 + std::max(height(y->left), height(y->right));


    return y;


}


void AVL_Tree::print_tree(){

    pre_order(root);
  
}


void AVL_Tree::pre_order(Node* root){
    if(!root){
        return;
    }

    std::cout << root->val<< "\n";

    pre_order(root->left);
    pre_order(root->right);
}