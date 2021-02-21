#include "algos.h"

/*
    This .cpp file consists of general functions
    which perform summarise, checks duplicates and checks
    permutations of two arrays/vectors.
*/

unordered_map<int,int> summarize(vector<int> &L)
{
    unordered_map<int,int> countMap;
    for(auto i=L.begin();i!=L.end();++i)
    {
        countMap[*i]++;
    }
    return countMap;
}

bool containDuplicate(vector<int> L)
{
    unordered_map<int,int> countMap;
    for(auto i=L.begin();i!=L.end();++i)
    {
        countMap[*i]++;
    }
    for(auto it:countMap)
    {
        int val=it.first;
        int frequency =it.second;
        if(frequency>=2)
            return true;
    }
    return false;
}

bool isPermutation(vector<int> list1, vector<int>list2)
{

    unordered_map<int,int> countMapList1;
    unordered_map<int,int> countMapList2;
    if(countMapList1.size()!=countMapList2.size())
        return false;
    for(auto i=list1.begin();i!=list1.end();++i)
    {
        countMapList1[*i]++;
    }

    for(auto i=list2.begin();i!=list2.end();++i)
    {
        countMapList2[*i]++;
    }
    for(auto it:countMapList1)
    {
        int val=it.first;
        countMapList2[val];
        if(countMapList1[val]!=countMapList2[val])
            return false;
    }
    return true;
}
