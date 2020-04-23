//============================================================================
// Name        : post_order.h
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : post order traversal of the tree. 
//============================================================================


/**
* This function print the pre order traversal of tree.
* @param root: a Node - pointer to head of tree.
*/
void post_order(Tree *root) {
	if(!root)
		return;
    // traverse left
    if(root->left!=NULL)
        post_order(root->left);
        
    // traverse right
    if(root->right!=NULL)
        post_order(root->right);
        
    // visit node
    cout<<root->data<<" ";
}
