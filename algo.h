#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<stack>
#include<climits>

using namespace std;


void Fcfs(vector<string> process,vector<int> arrayOfArrival, vector<int> arrayOfBurst);

void SJF(vector<string> &process,vector<int> &arrayOfArrival, vector<int> &arrayOfBurst);

void SRT(vector<string> &process,vector<int> &arrayOfArrival, vector<int> &arrayOfBurst);

void RR(vector<string> &process,vector<int> &arrayOfArrival, vector<int> &arrayOfBurst , int quantum);

void PQ(vector<string> &process,vector<int> &arrayOfArrival, vector<int> &arrayOfBurst , vector<int> &priority);