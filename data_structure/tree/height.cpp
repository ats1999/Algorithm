//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Find height of the tree.
// T.C         : O(N) Time taken to traverse all nodes. 
//               - For all node, we are finding height. 
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
// TREE
class Tree{
    //public:
    int data;
    Tree *left,*right;
    public:
        Tree(int valueOfNode){
            this->data=valueOfNode;
            this->left=NULL;
            this->right=NULL;
        }
        /**
         * This function add a node to the tree. 
         * @param {root} root of the tree. 
         */
        void addNode(Tree *&root,int data){
            // create a new node nn
            Tree *nn = new Tree(data);

            // if tree is empty
            if(root==NULL){
                root=nn;
                return;
            }
            Tree *temp=root;
            while ( temp ) {
                // make it right child
                if (temp->data<nn->data){
                    // if there is right chiled then make decision on the right child
                    if(temp->right)
                    temp = temp->right;

                    else {
                        // if there is no right child then this is the node where we have to insert
                        temp->right=nn;
                        break;
                    }
                }

                // make it left child
                else{
                    // if there is left chiled then make decision on the left child
                    if(temp->left)
                    temp = temp->left;

                    else {
                        // if there is no left child then this is the node where we have to insert
                        temp->left=nn;
                        break;
                    }
                }
            }
        }
        

        /**
         * Traverse the tree using inorder traversal. 
         * @param {root} root node of the tree. 
         */
        void inOrder(Tree *root){
            // empty tree
            if(!root)
                return;

            // go to the left of the tree
            if(root->left!=NULL)
                inOrder(root->left);

            // visit the node..
            cout<<root->data<<"->";

            // go to the right of the tree
            if(root->right!=NULL)
                inOrder(root->right);
        }

        /**
         * This function returns height of the tree.
         * @param {root} root of the tree.
         * @return {int} height of the tree. 
         */
        int getHeight(Tree *root){
            if(!root)
                return 0;

            // height of left subtree    
            int leftHeight = getHeight(root->left);

            // height of right subtree  
            int rightHeight = getHeight(root->right);
            
            // height of current node is maximum height of left subtree and right subtree. 
            return 1 + max(leftHeight,rightHeight);
        }
};
// driver code
int main(){
	cout<<"Started\n";
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    Tree *root=NULL;
    int n;
    cin>>n;
    int data;
    while(n--){
        cin>>data;
        root->addNode(root,data);
    }

    root->inOrder(root);
    cout<<"\nHeight is:";
    cout<<root->getHeight(root);
	return 0;
}