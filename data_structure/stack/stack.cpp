//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implemention of stack using array.
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define

// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * This function pushes an item in satck.
 * @param stack stack pointer
 * @param size size of stack
 * @param top top of the stack
 * @param item number to be pushed.
 * @return true if item is sucessfully pushed,false otherwise indecating full stack.
 */
bool push(int stack[],int *top,int size,int item){
    // if stack is full then return false
    // item can not be pushed. 
    if(*top==size)
        return false;
    
    // push the item 
    stack[*top]=item;
    *top++;
}
/**
 * This function pops an item in satck.
 * @param stack stack pointer
 * @param top top of the stack
 * @return true if item is sucessfully poped,false otherwise indecating empty stack.
 */
bool pop(int stack[],int *top){
    // empty stack
    // item can not be poped
    if(*top<0)
        return false;
    
    // pop the item
    *top--;
} 
/**
 * This function retrives the top item from satck.
 * @param stack stack pointer
 * @param size size of stack
 * @param top top of the stack
 * @return  item  if sucessfully retrived, Infinite value if stack is empty.
 */
int peep(int stack[],int *top,int size){
    // empty stack
    // item can not be retrived
    if(*top<0)
        return INT_MAX;
    
    // retrive the item
    return stack[*top];
}
/**
 * This check is stack is empty.
 * @param top top of the stack
 * @return true if stack is empty, false otherwise. 
 */
bool isEmpty(int *top){
    // if stack is empty
    if(*top<0)
        return true;
    return false;
}
/**
 * This function checks is stack is full. 
 * @param size size of stack
 * @param top top of the stack
 * @return true if stack is full, false otherwise. 
 */
bool isFull(int *top,int size){
    // stack is full
    if(*top==size)
        return true;
    return false;
}
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
    int size;
    cin>>size;
    int stack[size];
    int top=-1;
    
	return 0;
}