//============================================================================
// Name        : pre_order.h
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
//============================================================================


/**
* This function print the pre order traversal of tree.
* @param root: a Node - pointer to head of tree.
*/
void pre_order(Tree *root) {
	if(!root)
		return;
	// visit node
    cout<<root->data<<" ";
    
    // traverse left
    if(root->left!=NULL)
        pre_order(root->left);
        
    // traverse right
    if(root->right!=NULL)
        pre_order(root->right);
}
