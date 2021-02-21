#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> generateVector(int,int,int);
vector<int> manualVector(int);
void printVector(vector<int>);

vector<int> csort(vector<int>);
unordered_map<int,int> summarize(vector<int> &L);
bool containDuplicate(vector<int>);
bool isPermutation(vector<int>,vector<int>);

//extra credit function
vector<int> radixSort(vector<int>);
