#include<iostream>
using namespace std;
template<class T>
class SeqList
{
public:
    SeqList(int mSize);
    ~SeqList(){delete []elements;}
    bool IsEmpty()const;
    bool IsFull()const;
    int Length();
    bool Find(int i,T& x)const;
    int Search(T x);
    bool Insert(int i,T x);
    bool Delete(int i);
    bool DeleteX(const T &x);
    bool Update(int i,T x);
    void Output(ostream &out)const;
    void Reverse();
private:
    int maxLength;
    T *elements;
    int n;
};
template<class T>
SeqList<T>::SeqList(int mSize)
{
    maxLength=mSize;
    elements=new T[maxLength];
    n=0;
}
template<class T>
bool SeqList<T>::IsEmpty()const
{
    return n==0;
}
template<class T>
bool SeqList<T>::IsFull()const
{
    return n==maxLength;
}
template<class T>
int SeqList<T>::Length()
{
    return n;
}
template<class T>
bool SeqList<T>::Find(int i,T& x)const
{
    if(i<0||i>n-1)
    {
        cout<<"Out of Bound"<<endl;
        return false;
    }
    x=elements[i];
    return true;
}
template<class T>
int SeqList<T>::Search(T x)
{
    for(int j=0;j<n;j++)
        if(x==elements[j])
        return j;
    return -1;
}
template<class T>
bool SeqList<T>::Insert(int i,T x)
{
    if(i<-1||i>n-1)
    {
        cout<<"Out of Bound"<<endl;
        return false;
    }
    if(n==maxLength)
    {
        cout<<"Full of List"<<endl;
        return false;
    }
    for(int j=n-1;j>i;j--)
        elements[j+1]=elements[j];
    elements[i+1]=x;
    n++;
    return true;
}
template<class T>
bool SeqList<T>::Delete(int i)
{
    if(i<0||i>n-1)
    {
        cout<<"Out of Bound"<<endl;
        return false;
    }
    if(n==0)
    {
        cout<<"Empty List"<<endl;
        return false;
    }
    for(int j=i;j<n-1;j++)
        elements[j]=elements[j+1];
    n--;
    return true;
}
template<class T>
bool SeqList<T>::Update(int i,T x)
{
    if(i<0||i>n-1)
    {
        cout<<"Out of Bound"<<endl;
        return false;
    }
    elements[i]=x;
    return true;
}
template<class T>
void SeqList<T>::Output(ostream &out)const
{
    for(int i=0;i<n;i++)
        out<<elements[i]<<" ";
    out<<endl;
}
template<class T>
void SeqList<T>::Reverse()
{
    T temp;
    for(int i=0,j=Length()-1;i<j;i++,j--)
    {
        temp=elements[i];
        elements[i]=elements[j];
        elements[j]=temp;
    }
}
template<class T>
bool SeqList<T>::DeleteX(const T &x)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(x==elements[i])
        {
            flag=1;
            Delete(i);
            i--;
        }
    }
    if(!flag)
        return false;
    return true;
}
int main()
{
    int n;
    cin>>n;
    SeqList<int> test1(n);
    int delete_ei;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        test1.Insert(i-1,value);
    }
    cin>>delete_ei;
    test1.Reverse();
    test1.Output(cout);
    test1.DeleteX(delete_ei);
    test1.Output(cout);
    cin>>n;
    SeqList<char> test2(n);
    for(int i=0;i<n;i++)
    {
        char value;
        cin>>value;
        test2.Insert(i-1,value);
    }
    char delete_ec;
    cin>>delete_ec;
    test2.Reverse();
    test2.Output(cout);
    test2.DeleteX(delete_ec);
    test2.Output(cout);
    cin>>n;
    SeqList<double> test3(n);
    for(int i=0;i<n;i++)
    {
        double value;
        cin>>value;
        test3.Insert(i-1,value);
    }
    double delete_ed;
    cin>>delete_ed;
    test3.Reverse();
    test3.Output(cout);
    test3.DeleteX(delete_ed);
    test3.Output(cout);
    return 0;
}

















