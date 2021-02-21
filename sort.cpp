#include "algos.h"

/*
    The below version of count sort 
    implements the concept of map to keep 
    track of each numbers frequency and 
    place the numbers in the correct order.
*/
vector<int> csort(vector<int> L)
{
    map<int,int> countMap;
    for(auto i=L.begin();i!=L.end();++i)
    {
        countMap[*i]++;
    }
    int i=0;
    for(auto it:countMap)
    {
        int val=it.first;
        int frequency =it.second;
        for(int j=0;j<frequency;j++)
            L[i++]=val;
    }
    return L;
}
/*
    getMax helper function is used in 
    Radix Sort to find out the number in the
    vector with the largest value.
*/
int getMax(vector<int> L, int n)
{
    int maximum=L.at(0);
    for(int i=1;i<n;i++)
    {
        if(L.at(i)>maximum)
            maximum=L.at(i);
    }
    return maximum;
}

void countingSort(vector<int> &L, int size,int place)
{
    const int maximum=10;
    int output[size];
    int count[maximum];
    for(int i=0;i<maximum;++i)
        count[i]=0;
    for(int i=0;i<size;i++)
        count[(L.at(i)/place)%10]++;
    for(int i=1;i<maximum;i++)
        count[i]+=count[i-1];
    for(int i=size-1;i>=0;i--)
    {
        output[count[(L.at(i)/place)%10]-1]=L.at(i);
        count[(L.at(i)/place)%10]--;
    }
    for(int i=0;i<size;i++)
    {
        L.at(i)=output[i];
    }
}

/*
    The radix sort has been implemented as a sorting 
    function which can be alternatively used in place
    of csort.
*/
vector<int> radixSort(vector<int> L)
{
    int maximum=getMax(L,L.size());
    for(int i=1;maximum/i>0;i*=10)
        countingSort(L,L.size(),i);
    return L;
}
