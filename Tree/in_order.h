//============================================================================
// Name        : in_order.h
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : In order traversal of tree. 
//============================================================================

/**
* This function print the pre order traversal of tree.
* @param root: a Node - pointer to head of tree.
*/
void in_order(Tree *root) {
	if(root==NULL)
		return ;
    // traverse left
    if(root->left!=NULL)
        in_order(root->left);
        
    // visit node
    cout<<root->data<<" ";
        
    // traverse right
    if(root->right!=NULL)
        in_order(root->right);
        
}
