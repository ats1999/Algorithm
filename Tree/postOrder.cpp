//============================================================================
// Name        : postOrder.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Tree traversal by pre order traversal algorithm.
//============================================================================
#include<bits/stdc++.h>
using namespace std;
/**
* This class repersent tree.
* @member data: an integer - data of the node
* @left   pointer: a Node - repersent left link of tree
* @right   pointer: a Node - repersent left link of tree
* @Node() constructor: initialize tree with given values.
*/
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
/**
* This function print the pre order traversal of tree.
* @param root: a Node - pointer to head of tree.
*/
void postOrder(Node *root) {
    // traverse left
    if(root->left!=NULL)
        preOrder(root->left);
        
    // traverse right
    if(root->right!=NULL)
        preOrder(root->right);
        
    // visit node
    cout<<root->data<<" ";
}
// driver code
int main(){

	return 0;
}

