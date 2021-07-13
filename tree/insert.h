//============================================================================
// Name        : insert.h
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : insert a new node into tree.
//============================================================================

/**
* This function creates a new node and return it.
*/
Tree* newNode(int data){
 	Tree* newNode=new Tree(data);
 	return newNode;
}

/**
* This function insert a node into tree.
* @param root: a Tree - root node of tree.
* @param data: a integer - data to be inserted
* @return newely inserted node . 
*/

Tree* insert(Tree* root,int key){
	// if tree is empty
	if(root==NULL)
		return newNode(key);

	// root has greater value than key
	if(root->data>key)
		root->left=insert(root->left,key);
	else
	// root has less value than key
	root->right=insert(root->right,key);
}

