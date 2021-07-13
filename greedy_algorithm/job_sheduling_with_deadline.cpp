//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : This is a standered problem of computer science. Here we try to maximize the profit by executing tasks within deadline. 
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * Comparator function that sorts jobs according to their profits in non-increasing order. 
 * @param p1 first job
 * @param p2 second job
 * @return true if profit of p1 is  greater than profit of p2
 */
bool comp(pair<int,int>p1,pair<int,int>p2){
    return  p1.first>p2.first;
}

/**
 * This function finds maximim deadline,
 * @param jobs vector
 * @return maximum deadline. 
 */
int maxDeadline(vector<pair<int,int>>&jobs){
    int deadline=0;
    for(auto job:jobs)
        if(job.second>deadline)
            deadline=job.second;
    return deadline;
}
/**
 * This is job sheduling function. 
 * @param jobs array of jobs. 
 * @return maximum profits that can be bearned by executing the tasks. 
 */
int shedule(vector<pair<int,int>>&jobs){
    // pair<profit,deadline>
    // Step1:
    // Sort jobs in non-decreasing order according to their profits
    sort(jobs.begin(),jobs.end());

    // Step2:
    // find position
    int size=jobs.size(),deadline=maxDeadline(jobs);
    int pos=min(size,deadline);
    int jobselected[pos+1];

    // fill all values to -1
    memset(jobselected,-1,sizeof jobselected);

    // step3:
    // assign the jobs
    int i=1;
    for(auto job:jobs){
        int deadline=job.first;
        if(jobselected[deadline]==-1){
            jobselected[deadline]=i;
        }
        i++;
    }
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
    
	return 0;
}