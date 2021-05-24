//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

class List{
    public:
  int val;
  List *next = NULL;
  List(int val){
      this->val = val;
  }
};
List *head=NULL;
void insert_node(int position, int value) {
    List *nn = new List(value);
    if(!head){
        head = nn;
        return;
    }
    
    if(position == 1){cout<<"Here\n";
        nn->next = head;
        head = nn;
        return;
    }
    
    List *tmp = head;
    for(int i=1; i<position-1; i++){
        tmp=tmp->next;
    }
    
    if(tmp->next){
        nn->next = tmp->next->next;
        tmp->next = nn;
    }else{
        tmp->next = nn;
    }
}

void delete_node(int position) {
    if(position == 1){
        List *tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    
    List *tmp=head;
    for(int i=1; i<position-1; i++){
        tmp = tmp->next;
    }
    
    if(tmp->next->next){
        // not last node;
        List *tmp2 = tmp->next;
        tmp->next = tmp->next->next;
        delete tmp2;
    }else{
        List *tmp2 = tmp->next;
        tmp->next = NULL;
        delete tmp2;
    }
}


void print_ll() {
    // Output each element followed by a space
    List *tmp=head;
    while(tmp){
        cout<<tmp->val<<(tmp->next != NULL)?" ":"";
        tmp = tmp->next;
    }
}

int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE 
	    freopen("/home/rahul/Desktop/Algorithm/input.txt", "r", stdin);  
	    freopen("/home/rahul/Desktop/Algorithm/output.txt", "w", stdout); 
    #endif 
    insert_node(1,5);
    insert_node(1,9);
    insert_node(1,7);
    print_ll();
	return 0;
}
