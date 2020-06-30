//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implemention of Binary tree. 
// T.C         : O()
// A.S         : O()
//============================================================================

#include<iostream>
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
                //cout<<"Adding "<<data<<" to the root"<<endl;
                root=nn;
                return;
            }
            
            Tree *temp=root;
            while ( temp->right!=NULL && temp->left!=NULL) {
                // make it right child
                if (temp->data<nn->data){
                    temp = temp->right;
                }
                // make it left child
                else{
                    temp = temp->left;
                }
            }
            if(temp->right==NULL)
                temp->right=nn;
            else temp->left=nn;
        }
        
        /**
         * This function add a node to the tree using recursion. 
         * @param {root} root of the tree. 
         */
        void addNodeRecr(Tree *&root,int data){
            // if tree is empty
            if(root == NULL){
                Tree *nn = new Tree(data);
                root=nn;
                return;
            }

            // if value of parent is less than node value which have to insert then insert it to the right of the tree
            if(root->data<data){
                addNode(root->right,data);
            }
            // insert to the left of the tree
            else{
                addNode(root->left,data);
            }
        }

        /**
         * Traverse the tree using inorder traversal. 
         * @param {root} root node of the tree. 
         */
        void inOrder(Tree *root){
               
            // go to the left of the tree
            if(root->left!=NULL)
                inOrder(root->left);

            // visit the node..
            cout<<root->data<<"->";

            // go to the right of the tree
            if(root->right!=NULL)
                inOrder(root->right);
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

    int n,data;
    cin>>n;
    while(n--){
        cin>>data;
        //cout<<"Going to add "<<data<<endl;
        root->addNodeRecr(root,data);
        //cout<<"\n=========================\n";
    }
    cout<<"Nodes are added\n";
    
    //root->test(root);
    cout<<"\nTraversing\n";
    root->inOrder(root);
    cout<<"\n Done\n";
	return 0;
}
