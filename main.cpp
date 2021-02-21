#include "algos.h"

/*
     vectorGenerator function is a generalized
     function for manually/randomly genrating
     a vector of integers
*/
vector<int> vectorGenerator(string input)
{
            vector<int> resultantVector;
            if(input=="N")
            {
                int vectorLength=0,minValue=0,maxValue=0;
                cout<<"Vector Length : ";
                cin>>vectorLength;
                cout<<"Minimum Value : ";
                cin>>minValue;
                cout<<"Maximum Value : ";
                cin>>maxValue;
                resultantVector=generateVector(vectorLength,minValue,maxValue);
            }
            else if(input=="Y")
            {
                cout<<"Enter the length of vector to generate: ";
                int length=0;
                cin>>length;
                resultantVector=manualVector(length);
            }
            return resultantVector;
}

//beginning of main function
int main()
{
    cout<<"Welcome! This program implements and tests three sorting algorithms on vector of integers."<<endl;
    string command="";
    while(command!="quit")
    {
        cout<<"Enter command (csort, Summarize, CheckDuplicate, Permutation, quit): ";
        cin>>command;
        if(command=="quit")
        {
            cout<<"Program is terminated"<<endl;
            break;
        }
        else if(command=="csort")
        {
            string input;
            vector<int> resultantVector;
            cout<<"Do you want to enter the vector manually (Y/N): ";
            cin>>input;

            resultantVector=vectorGenerator(input);
            resultantVector=csort(resultantVector);
            //resultantVector=radixSort(resultantVector);   //Testing the radix sort function for sorting vector of integers
            printVector(resultantVector);
        }

        else if(command=="Summarize")
        {
            string input;
            vector<int> resultantVector;
            cout<<"Do you want to enter the vector manually (Y/N): ";
            cin>>input;
            resultantVector=vectorGenerator(input);
            unordered_map<int,int> countMap;
            printVector(resultantVector);
            countMap=summarize(resultantVector);
            for(auto it:countMap)
            {
                int val=it.first;
                int frequency =it.second;
                cout<<val<<": "<<"appeared "<<frequency<<" times"<<endl;
            }
        }
        else if (command=="CheckDuplicate")
        {
            string input;
            bool result = false;
            vector<int> resultantVector;
            cout<<"Do you want to enter the vector manually (Y/N): ";
            cin>>input;
            resultantVector=vectorGenerator(input);
            cout<<"Want to check duplicate with sorting or without sorting (Y/N): ";
            string in;
            cin>>in;
            if(in=="Y")
            {
                resultantVector=csort(resultantVector);
                for(int i=1;i<resultantVector.size();i++)
                {
                    if(resultantVector.at(i)==resultantVector.at(i-1))
                        result=true;
                }
            }
            else
            {
                bool result=containDuplicate(resultantVector);

            }
            printVector(resultantVector);
            if(result==true)
                cout<<"Contains Duplicates!"<<endl;
            else
                cout<<"No Duplicates!"<<endl;
        }
        else if (command=="Permutation")
        {
            vector<int> list1;
            vector<int> list2;
            string input;
            cout<<"Do you want to enter the vector manually (Y/N): ";
            cin>>input;
            list1=vectorGenerator(input);
            cout<<"Do you want to enter the vector manually (Y/N): ";
            cin>>input;
            list2=vectorGenerator(input);
            cout<<"Want to check permutation with sorting or without sorting (Y/N): ";
            string in;
            cin>>in;
            bool result=true;
            if(in=="Y")
            {
                list1=csort(list1);
                list2=csort(list2);
                if(list1.size()!=list2.size())
                    result=false;
                else
                {
                    for(int i=0;i<list1.size();i++)
                    {
                        if(list1.at(i)!=list2.at(i))
                            result=false;
                    }
                }
            }
            else
            {
                result=isPermutation(list1,list2);
            }
            cout<<"List 1: ";printVector(list1);
            cout<<"List 2: ";printVector(list2);
            if(result==true)
                cout<<"Is a permutation"<<endl;
            else
                cout<<"Not a permutation"<<endl;
        }
    }
}
