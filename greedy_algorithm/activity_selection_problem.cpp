//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : This is a standered problem of computer science. 
// T.C         : O(nlog(n))- time taken to sort the activity if we use merge sort
// A.S         : O() - according to sorting algorthim used
//============================================================================
#include<bits/stdc++.h>
using namespace std;

// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
/**
 * Comparator function that helps in sorting the array according to finish time. 
 * @param p1 firts pair of start time and finish time
 * @param p2 second pair of start time and finish time
 * @return true if sorting required false otherwise.
 */
bool comp(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;
}

/**
 * This is activity selection problem. 
 * @param activity vector of finish time and start time. 
 * @return number of sortest activity. 
 */
int activity(vector<pair<int,int>>&activities){
    // sort the activity according to their finish time. 
    sort(activities.begin(),activities.end(),comp);
    
    int numOfActivity=0,startTime,finishTime;
    for(auto activity:activities){
        // initially select the first activity in optimal set
        if(!numOfActivity){
            startTime=activity.first;
            finishTime=activity.second;
            numOfActivity++;
        }else{
            // if start time of current activity is greater then finish time of selected activity
            // then include this activity in the optimal set
            if(finishTime<activity.first){
                startTime=activity.first;
                finishTime=activity.second;
                numOfActivity++;
            }
        }
    }
    return numOfActivity;
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
    
    vector<pair<int,int>>activityTask;
    activityTask.push_back(make_pair(1,4));
    activityTask.push_back(make_pair(3,5));
    activityTask.push_back(make_pair(0,6));
    activityTask.push_back(make_pair(5,7));
    activityTask.push_back(make_pair(3,8));
    activityTask.push_back(make_pair(5,9));
    activityTask.push_back(make_pair(6,10));
    activityTask.push_back(make_pair(8,11));
    activityTask.push_back(make_pair(8,12));
    activityTask.push_back(make_pair(2,13));
    activityTask.push_back(make_pair(12,14));
    cout<<activity(activityTask);
	return 0;
}