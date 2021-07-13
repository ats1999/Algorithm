//============================================================================
// Name        : height.h
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find height of given tree. 
//============================================================================


/**
* This function finds height of a given tree. 
* @param root: a Node - root of the tree.
* @return height of the tree
*/
int height(Tree* root) {
	if(!root)
		return;
    int left=0,right=0;
    
    // count left
    if(root->left!=NULL){
        left=1;
        left+=height(root->left);
    }
    
    //count right
    if(root->right!=NULL){
        right=1;
        right+=height(root->right);
    }
    
    //return height
    return max(left,right);
}
