#include "algos.h"

vector<int> generateVector(int length,int min,int max)
{
    vector<int> vectorOfIntegers(length);
    for(int i=0;i<length;i++)
    {
        int randomInteger=min+rand()%(max+1-min);
        vectorOfIntegers.at(i)=randomInteger;
    }
    return vectorOfIntegers;
}

vector<int> manualVector(int length)
{
    vector<int> vectorOfIntegers(length);
    for(int i=0;i<length;++i)
    {
        int input;
        cin>>input;
        vectorOfIntegers.at(i)=(input);
    }
    return vectorOfIntegers;
}


void printVector(vector<int> L)
{
    for(int i=0;i<L.size();i++)
    {
        cout<<L.at(i)<<" ";
    }
    cout<<endl;
}
