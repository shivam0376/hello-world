//Sorting Algo
void BubbleSort()
{
     int arr[]={1,2,6,4,5};
     int nSize=5;

    cout<<"BubbleSort "<<endl;
    cout<<"Before= "<<endl;
    printArr(arr,5);
    for(int i=0; i<nSize-1;i++)
    {
        bool isSwapped=false;
        for(int j=i+1;j<nSize-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                isSwapped=true;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }

        }
        if(isSwapped==false)
        {
            break;
        }
    }
    cout<<"After= "<<endl;
    printArr(arr,5);
}
