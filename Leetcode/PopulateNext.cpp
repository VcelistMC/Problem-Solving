#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    vector<Node*> nodes;
   
    int calculateHeight(Node* node){
        int height = 0;
        while(node != 0){
            height++;
            node = node -> left;
        }
        return height;
    }

    void currentLvlTraverse(Node* node, int d){
        if(node == 0)
            return;
        if(d == 1)
            nodes.push_back(node);
        else{
            currentLvlTraverse(node->left, d-1);
            currentLvlTraverse(node-> right, d-1);
        }
    }

    void levelOrderTraverse(Node* root, int d){
        for(int i = 1; i <= d; i++)
            currentLvlTraverse(root, i);
    }
    Node* connect(Node* root) {
        int treeHeight = calculateHeight(root);
        nodes.clear();
        levelOrderTraverse(root, treeHeight);
        int level = 0;
        for(int i = 0; i < nodes.size(); i++){
            if(i == pow(2, level+1) - 2){
                nodes[i]->next = 0;
                level++;
            }
            else{
                nodes[i] -> next = nodes[i+1];
            }
        }
    }
};