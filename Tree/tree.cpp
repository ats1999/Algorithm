//============================================================================
// Name        : tree.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Represention of tree data structure.
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
* This function creates a new node and return it.
*/
Node* newNode(int data){
 	Node* newNode=new Node(data);
 	return newNode;
}

/**
* This function insert a node into tree.
*/
Node* insert(Node* root,int data){
	// if tree is empty
	if(root==NULL)
		return newNode(data);

	// tree is not empty
	if(root->data>data)
		root->left=insert(root->left,data);
	
	root->right=insert(root->right,data);
}
	// driver code
int main(){
	Node *root=NULL;
	root=newNode(5);
	cout<<root->data;
	return 0;
}

