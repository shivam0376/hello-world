// Type your code here, or load an example.
#include <iostream>
#include <string>
using namespace std;

void printArr(int arr[],int nSize)
{
    for(int i =0;i <nSize;i++)
    {
        cout<<arr[i]<<endl;
    }
}

void reverseArray()
{
    int arr[]={1,2,3,4,5};
    int nStart=0;
    int nEnd=4;
    cout<<"Before= "<<endl;
    printArr(arr,5);
    while(nStart<nEnd)
    {
        int temp=arr[nStart];
        arr[nStart]=arr[nEnd];
        arr[nEnd]=temp;
        nStart++;
        nEnd--;
    }
    cout<<"After= "<<endl;
    printArr(arr,5);
}


// Contiguous Subbarray

 void subarraySum()
    {
        int arr[]={1,2,3,7,5};
        int n=5; //Size of an array
        int s=12; //Sum to be found
        int nStartIndex=0;
        int nEndIndex=0;
        int nCurrSum=0;
        while(nStartIndex<n)
        {
            if(s==nCurrSum)
            {
                cout<<"Start Index ="<<nStartIndex+1<<" End Index= "<<nEndIndex<<endl;
                return;
            }
            if(s>nCurrSum)
            {
                nCurrSum+=arr[nEndIndex];
                nEndIndex++;
            }else{
                nCurrSum-=arr[nStartIndex];
                nStartIndex++;
            }
        }
       cout<<"Not Found "<<endl;
    }


int main()
{


//reverseArray();

//BubbleSort();
subarraySum();
    return 0;
}
