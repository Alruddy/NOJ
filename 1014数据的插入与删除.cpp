#include<iostream>
using namespace std;
const int maxLength=10000;
bool Sort(int *array,int &length);
bool Insert(int *array,int element,int &length);
bool Delete(int *array,int element,int &length);
void Output(int *array,int &length);
int main()
{
    int testArray[10001];
    int delete_element,insert_element;
    int length=0;
    while(true)
    {
        int x;
        cin>>x;
        if(x==-1)
            break;
        testArray[length]=x;
        length++;
    }
    Sort(testArray,length);
    cin>>insert_element>>delete_element;
    Output(testArray,length);
    Insert(testArray,insert_element,length);
    Output(testArray,length);
    Delete(testArray,delete_element,length);
    Output(testArray,length);
    return 0;
}
bool Sort(int *array,int &length)
{
    if(length==0)
        return false;
    int k;
    for(int i=0;i<length;i++)
    {
        k=i;
        for(int j=k+1;j<length;j++)
        {
            if(array[k]>array[j])
                k=j;
        }
        if(k!=i)
        {
            int temp=array[k];
            array[k]=array[i];
            array[i]=temp;
        }
    }
    return true;
}
bool Insert(int *array,int element,int &length)
{
    if(length==maxLength)
        return false;
    int i;
    if(length)
    {
        for(i=0;array[i]<element;i++);
        for(int j=length-1;j>=i;j--)
            array[j+1]=array[j];
        array[i]=element;
        length++;
    }
    else
    {
        array[length]=element;
        length++;
    }
    return true;
}
bool Delete(int *array,int element,int &length)
{
    if(length==0)
        return false;
    for(int k=length;k>0;k--)
    {
        for(int i=0;i<length;i++)
        {
            if(array[i]==element)
            {
                for(int j=i;j<length;j++)
                    array[j]=array[j+1];
                length--;
            }
        }
    }
    return true;
}
void Output(int *array,int &length)
{
    if(length)
    {
        int i;
        for(i=0;i<length-1;i++)
        {
            cout<<array[i]<<",";
        }
        cout<<array[i]<<endl;
    }
    else
        cout<<"No elements."<<endl;
}









