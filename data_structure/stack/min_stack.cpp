//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Return the minimum element of the stack in O(1) time.
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
/**
 * This function takes the instance of stack and  a integer number and pushes it into the stack.
 * @param {Stack} - stack in which we have to push the items.
 * @param {m} - input number which we have to  push.
 */
void pushStack(stack<pair<int,int>>&Stack,int m){
	// if stack is empty then current element would be the minimum element
	if(Stack.empty()){
		auto p = make_pair(m,m);
		Stack.push(p);
		return;
	}
	
	// if stack is not empty then minmum element would be minimum of top of the stack and the current element
	auto p = make_pair(m,min(m,Stack.top().second));
	Stack.push(p);
}
/**
 * This function takes the instance of stack and  pop the top element.
 * @param {Stack} - stack in which we have to push the items.
 */
void popStack(stack<pair<int,int>>&Stack){
	if(Stack.empty()){
		cout<<"Stack is empty\n";
		return;
	}
	
	auto p = Stack.top();
	cout<<p.first<<" is poped\n";
	Stack.pop();
}

/**
 * This function takes the instance of stack and  returns the minimum element of the stack.
 * @param {Stack} - stack in which we have to push the items.
 * @param {m} - input number which we have to  push.
 */
int minStack(stack<pair<int,int>>&Stack){
	if(Stack.empty())
		return -1;
	
	return Stack.top().second;
}
// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);
    #endif
	cout<<"Started\n";
	int n;
	cin>>n;
	stack<pair<int,int>>Stack;
	while(n--){
		int num,type;
		cin>>type;
		if(type == 1){
			cin>>num;
			pushStack(Stack,num);
		}
		else
		if(type == 2)
			popStack(Stack);
		else cout<<minStack(Stack)<<endl;
	}
	
	cout<<"\nDone:)\n";
	return 0;
}

