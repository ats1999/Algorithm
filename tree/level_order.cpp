//============================================================================
// Name        : level_order.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Print level order traversal of tree. 
//============================================================================
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
            rNight = NULL;
        }
};
/**
* This function finds height of a given tree. 
* @param root: a Node - root of the tree.
* @return height of the tree
*/
int height(Node* root) {
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
// driver code
int main(){

	return 0;
}
