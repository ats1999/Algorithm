//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Linked list implemention using class. 
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * Repersention of linked list.
 */
class List{
    public:
    int data;
    List *next;
    public:
        List(int n){
            this->data=n;
            this->next=NULL;
        }

        /**
         * This function creates a new node and append it to the end of the list.
         * @param n data to append.
         */
        void addNode(List *&head,int n){
            List *nn = new List(n);

            // if list is empty
            if(head==NULL){
                head=nn;
                return;
            }

            List *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=nn;
        }

        /**
         * This function print the list. 
         * @param head head pointer of the list. 
         */
        void printList(List *head){
            // if list is empty
            if(head==NULL){
                cout<<"List is empty\n";
                return ;
            }

            List *temp=head;
            while(temp->next){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<temp->data;
        }
};

// driver code
int main(){
	cout<<"Started\n";
	// I/O
	IOS;
    #ifndef ONLINE_JUDGE 
	    // For getting input from input.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin); 
	    // Printing the Output to output.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    List *head=NULL;
    head->addNode(head,506);
    head->addNode(head,45);
    head->addNode(head,202);
    head->printList(head);
	return 0;
}