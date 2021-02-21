/*
  This header file consists of all the necessary header files
  required to run the entire program.
*/


#include<iostream>
#include <bits/stdc++.h>
using namespace std;

//List of all the required functions
vector<int> generateVector(int,int,int);
vector<int> manualVector(int);
void printVector(vector<int>);

vector<int> csort(vector<int>);
unordered_map<int,int> summarize(vector<int> &L);
bool containDuplicate(vector<int>);
bool isPermutation(vector<int>,vector<int>);

//extra credit function
vector<int> radixSort(vector<int>);
