#pragma once


struct Node{
    int val;
    Node* left;
    Node* right;
    int height;

    Node(){val=0;left=nullptr;right=nullptr;height=0;};
    Node(int x){
        val = x;
        left = nullptr;
        right = nullptr;
        height =0;
    }
};

class AVL_Tree{

    private: 
        Node* root;
        void pre_order(Node* root);

        int height(Node* root);
        int balance_factor(Node* root);

        Node* insert(Node* root, int key);
        Node* rotate_right(Node* root);
        Node* rotate_left(Node* root);

    public:
        AVL_Tree();
        void insert(int key);
        void print_tree();



};