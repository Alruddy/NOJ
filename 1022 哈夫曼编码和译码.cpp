#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include<cstring>
#include<queue>
using namespace std;
template<class T>
struct BTNode
{
    T element;
    struct BTNode *lchild,*rchild;
    BTNode()
    {
        lchild=rchild=NULL;
    }
    BTNode(const T &x)
    {

        element=x;
        lchild=rchild=NULL;
    }
    BTNode(const T &x,BTNode<T> *l,BTNode<T> *r)
    {
        element=x;
        lchild=l;
        rchild=r;
    }
};
template<class T>
class BinaryTree
{
private:
    /**������������*/
    int temHeight;
protected:
    BTNode<T> *root;
    /**��������*/
    int Height;//�������߶�
    int NumofNode;//�������ڵ����
    int NumofLNode;//������Ҷ�ӽڵ����
    int NumofSNode;//��������Ҷ�ڵ�ĸ���
public:
    BinaryTree();
    ~BinaryTree();
    bool IsEmpty();
    void Clear();
    bool Root(T &x);
    void MakeTree(const T &x,BinaryTree<T> &l,BinaryTree<T> &r);
    void BreakTree(T &x,BinaryTree<T> &l,BinaryTree<T> &r);
    void ProTraverse(void (*Visit)(T &x));
    void InTraverse(void (*Visit)(T &x));
    void PostTraverse(void (*Visit)(T &x));
    void LevelTraverse(void (*Visit)(T &x));
    /**�������нӿ�*/
    int GetHeight();
    int GetNumofNode();
    int GetNumofLNode();
    int GetNumofSNode();
protected:
    void Clear(BTNode<T> *&t);
    void ProTraverse(void (*Visit)(T &x),BTNode<T> *t);
    void InTraverse(void (*Visit)(T &x),BTNode<T> *t);
    void PostTraverse(void (*Visit)(T &x),BTNode<T> *t);
    /**����˽�нӿ�*/
    void TraverseforGet(BTNode<T> *t);
};
/**���нӿ�*/
template<class T>
BinaryTree<T>::BinaryTree()
{
    root=NULL;
}
template<class T>
BinaryTree<T>::~BinaryTree()
{
  //  Clear();
}
template<class T>
bool BinaryTree<T>::IsEmpty()
{
    return root==NULL;
}
template<class T>
void BinaryTree<T>::Clear()
{
    Clear(root);
}
template<class T>
bool BinaryTree<T>::Root(T &x)
{
    if(root)
    {
        x=root->element;
        return true;
    }
    else
        return false;
}
template<class T>
void BinaryTree<T>::MakeTree(const T &x,BinaryTree<T> &l,BinaryTree<T> &r)
{
    if(root||&l==&r)
        return;
    root=new BTNode<T>(x,l.root,r.root);
    l.root=r.root=NULL;
}
template<class T>
void BinaryTree<T>::BreakTree(T &x,BinaryTree<T> &l,BinaryTree<T> &r)
{
    if(!root||&l==&r||l.root||r.root)//Ҫ���ٵĲ����ڣ���������������ĵ�ַ��ͬ�����������Ѿ�����
        return;
    l.root=root->lchild;
    r.root=root->rchild;
    x=root->element;
    delete root;
    root=NULL;
}
template<class T>
void BinaryTree<T>::ProTraverse(void (*Visit)(T &x))
{
    ProTraverse(Visit,root);
    cout<<endl;
}
template<class T>
void BinaryTree<T>::InTraverse(void (*Visit)(T &x))
{
    InTraverse(Visit,root);
    cout<<endl;
}
template<class T>
void BinaryTree<T>::PostTraverse(void (*Visit)(T &x))
{
    PostTraverse(Visit,root);
    cout<<endl;
}
template<class T>
void BinaryTree<T>::LevelTraverse(void (*Visit)(T &x))
{
    if(!root)
        return ;
    queue<BTNode<T>*> qu;
    BTNode<T> *t=root;
    qu.push(root);
    while(!qu.empty())
    {
        Visit(t->element);
        if(t->lchild)
            qu.push(t->lchild);
        if(t->rchild)
            qu.push(t->rchild);
        qu.pop();
        t=qu.front();
    }
    cout<<endl;
}
/**�����ӿ�*/
template<class T>
int BinaryTree<T>::GetHeight()
{
    Height=temHeight=0;
    TraverseforGet(root);
    return Height;
}
template<class T>
int BinaryTree<T>::GetNumofNode()
{
    NumofNode=0;
    TraverseforGet(root);
    return NumofNode;
}
template<class T>
int BinaryTree<T>::GetNumofLNode()
{
    NumofLNode=0;
    TraverseforGet(root);
    return NumofLNode;
}
template<class T>
int BinaryTree<T>::GetNumofSNode()
{
    NumofSNode=0;
    TraverseforGet(root);
    return NumofSNode;
}
/**˽�нӿ�*/
template<class T>
void BinaryTree<T>::Clear(BTNode<T> *&t)
{
    if(!t)
        return ;
    Clear(t->lchild);
    Clear(t->rchild);
    delete t;
    t=NULL;
}
template<class T>
void BinaryTree<T>::ProTraverse(void (*Visit)(T &x),BTNode<T> *t)
{
    if(!t)
        return ;
    Visit(t->element);
    ProTraverse(Visit,t->lchild);
    ProTraverse(Visit,t->rchild);
}
template<class T>
void BinaryTree<T>::InTraverse(void (*Visit)(T &x),BTNode<T> *t)
{
    if(!t)
        return ;
    InTraverse(Visit,t->lchild);
    Visit(t->element);
    InTraverse(Visit,t->rchild);
}
template<class T>
void BinaryTree<T>::PostTraverse(void (*Visit)(T &x),BTNode<T> *t)
{
    if(!t)
        return;
    PostTraverse(Visit,t->lchild);
    PostTraverse(Visit,t->rchild);
    Visit(t->element);
}
template<class T>
void BinaryTree<T>::TraverseforGet(BTNode<T> *t)
{
    if(!t)
    {
        Height=Height>temHeight?Height:temHeight;
        return;
    }
    if(t->lchild==NULL&&t->rchild==NULL)
        NumofLNode++;
    if((t->lchild==NULL&&t->rchild!=NULL)||(t->lchild!=NULL&&t->rchild==NULL))
        NumofSNode++;
    temHeight++;
    NumofNode++;
    TraverseforGet(t->lchild);
    TraverseforGet(t->rchild);
    temHeight--;
}
template<class T>
class PrioQueue
{
private:
    T *q;
    int maxSize;
    int n;

public:
    PrioQueue(int mSize);
    ~PrioQueue();
    bool IsEmpty();
    bool IsFull();
    void Append(const T &x);
    void Serve(T &x);
private:
    void AdjustDown(int r,int j);
    void AdjustUp(int j);
};
template<class T>
PrioQueue<T>::PrioQueue(int mSize)
{
    maxSize=mSize;
    q=new T[maxSize];
    n=0;
}
template<class T>
PrioQueue<T>::~PrioQueue()
{
    delete []q;
}
template<class T>
bool PrioQueue<T>::IsEmpty()
{
    return n==0;
}
template<class T>
bool PrioQueue<T>::IsFull()
{
    return n==maxSize;
}
template<class T>
void PrioQueue<T>::Append(const T &x)
{
    if(IsFull())
        return ;
    q[n]=x;
    n++;
    AdjustUp(n-1);
}
template<class T>
void PrioQueue<T>::Serve(T &x)
{
    if(IsEmpty())
        return;
    x=q[0];
    q[0]=q[n-1];
    n--;
    AdjustDown(0,n-1);
}
/**˽�нӿ�*/
template<class T>
void PrioQueue<T>::AdjustDown(int r,int j)
{
    T temp=q[r];
    int child=r*2+1;
    while(child<=j)
    {
        if(child<j&&q[child]>q[child+1])
            child=child+1;
        if(temp<=q[child])
            break;
        q[(child-1)/2]=q[child];
        child=child*2+1;
    }
    q[(child-1)/2]=temp;
}
template<class T>
void PrioQueue<T>::AdjustUp(int j)
{
    T temp=q[j];
    int parent=j;
    while(parent>0&&q[(parent-1)/2]>temp)/**�����*/
    {
        q[parent]=q[(parent-1)/2];
        parent=(parent-1)/2;
    }
    q[parent]=temp;
}
template<class T>
class HfmTree:public BinaryTree<T>
{
private:
    T weight;
public:
    operator T()const
    {
        return weight;
    }
    T getW()
    {
        return weight;
    }
    void putW(T w)
    {
        weight=w;
    }
    void SetNull()
    {
        this->root=NULL;
    }
    void ProtraverseForCode(int *w,string *str,int n);
    void protravese(BTNode<T> *t,int *w,string *str,string st,int n);
    template<class U>
    friend void DeCodeString(HfmTree<U> &h,char *&chset,int *weight,int n);
};
template<class T>
void HfmTree<T>::protravese(BTNode<T> *t,int *w,string *str,string st,int n)
{
    if(!t)
        return ;
    if(t->lchild==NULL&&t->rchild==NULL)
    {
        for(int i=0;i<n;i++)
            if(t->element==w[i])
            {
                str[i]=st;
            }
    }
    st=st+"0";
    protravese(t->lchild,w,str,st,n);
    int len=st.size();
    st.erase(len-1);
    st=st+"1";
    protravese(t->rchild,w,str,st,n);
    len=st.size();
    st.erase(len-1);
}
template<class T>
void HfmTree<T>::ProtraverseForCode(int *w,string *str,int n)
{
    string st="";
    protravese(this->root,w,str,st,n);
}
void Menu()
{
    cout<<"B��������\t"<<"T��������\t"<<"E�������ɱ���\t"<<endl;
    cout<<"C��������\t"<<"D��������\t"<<"P������ӡ    \t"<<endl;
    cout<<"X�����˳�\t"<<endl;
}
template<class T>
void Visit(T &x)
{
    cout<<x<<" ";
}
int Input(char *&chset,int *&weight);
template<class T>
HfmTree<T> CreathfmTree(T *w,int n);
template<class T>
void CreateHfmCode(HfmTree<T> &h,char *&chset,int *&weight,string *&code,int n);
void CodeString(string *&code,char *&chset,int n);
template<class T>
void DeCodeString(HfmTree<T> &h,char *&chset,int *weight,int n);
void Print();
int main()
{
    int *w;
    char *s;
    char choice;
    string *code;
    HfmTree<int> h;
    int n;

    n=Input(s,w);
    h=CreathfmTree(w,n);

    CreateHfmCode(h,s,w,code,n);


    CodeString(code,s,n);
    DeCodeString(h,s,w,n);
    h.Clear();
    return 0;
}
/** \brief
 *          �����ַ�����Ȩֵ
 * \param   �ַ���ָ��
 * \param   Ȩֵ��ָ��
 * \return  �ַ�����Ȩֵ���ĳ���
 *
 */
int Input(char *&chset,int *&weight)
{

    char s[]="ACIMNPTU";
    int n=8;
    /**�õ��ַ������ȣ����ַ���CHSET*/
    chset=new char[9];
    weight=new int[n];
    for(int i=0;i<n;i++)
    {
        chset[i]=s[i];
        cin>>weight[i];
    }
    for(int i=0;i<n;i++)
        cout<<chset[i];
        cout<<endl;
    chset[8]='\0';
    return n;
}
/** \brief
 *        ����Ȩֵ������������
 * \param   Ȩֵ�׵�ַָ��
 * \param   Ȩֵ������
 * \return  ���ɵĹ�������
 *
 */
template<class T>
HfmTree<T> CreathfmTree(T *w,int n)
{
    PrioQueue<HfmTree<T> > qu(n);
    HfmTree<T> x,y,z;
    for(int i=0;i<n;i++)
    {
        z.MakeTree(w[i],x,y);
        z.putW(w[i]);
        qu.Append(z);
        z.SetNull();
    }
    for(int i=1;i<n;i++)
    {
        qu.Serve(x);
        qu.Serve(y);
        z.MakeTree(x.getW()+y.getW(),x,y);
        z.putW(x.getW()+y.getW());
        qu.Append(z);
        z.SetNull();
    }
    qu.Serve(z);
    return z;
}
/** \brief
 *          ���ݹ����������ɹ���������,�ڿ���̨��ӡ�����������ļ�D://code.txt��
 * \param   ��������
 * \param   �ַ���
 * \param   Ȩֵ��
 * \param   ���뼯
 * \param   �ַ�����Ȩֵ������
 * \return  NULL
 *
 */
template<class T>
void CreateHfmCode(HfmTree<T> &h,char *&chset,int *&weight,string *&code,int n)
{
    code=new string[n];
    for(int i=0;i<n;i++)
        code[i]="";
    h.ProtraverseForCode(weight,code,n);
    for(int i=0;i<n;i++)
        cout<<chset[i]<<": "<<code[i]<<endl;
}
/** \brief
 *      ���ɱ��룬��д�����ַ����ַ���ɵ������ַ��������ù�����������б���
 *      ���ַ����ͱ��봮�ֱ𴢴���D://textfile.txt��D://codefile.txt��
 * \param ���봮��
 * \param �ַ���
 * \param �ַ����ͱ��봮������
 * \return NULL
 *
 */
void CodeString(string *&code,char *&chset,int n)
{
    /*string text;
    getchar();
    getline(cin,text);
    ofstream out("D://textfile.txt");
    ofstream out1("D://codefile.txt");
    if(!out||!out1)
        return;
    out<<text;
    out.close();*/
    string text;
    cin>>text;
    for(int i=0;i<int(text.size());i++)
    {
        for(int j=0;j<n;j++)
            if(chset[j]==text[i])
            {
                cout<<code[j];
            }
    }
    //out1.close();
}
/** \brief
 *          ���ݹ��������Ա����ļ��������룬��������ļ�����D://result.txt��
 * \param   ��������
 * \param   �ַ���
 * \param   Ȩֵ��
 * \param   �ַ�����Ȩֵ������
 * \return  NULL
 *
 */
template<class T>
void DeCodeString(HfmTree<T> &h,char *&chset,int *weight,int n)
{
    string s;
    cin>>s;
    char c;
    BTNode<T> *t=h.root;
    int i=0;
    while(s[i++]!='\0')
    {
        if(c=='0')
            t=t->lchild;
        if(c=='1')
            t=t->rchild;
        if(t->lchild==NULL&&t->rchild==NULL)
        {
            for(int i=0;i<n;i++)
            {
                if(weight[i]==t->element)
                {
                    cout<<chset[i];
                    t=h.root;
                }

            }
        }
        if(!t)
            break;
    }
}
/** \brief
 *          ��ӡ�ļ����� "D://textfile.txt" "D://codefile.txt" "D://result.txt"
 * \param   NULL
 * \param
 * \return  NULL
 *
 */
void Print()
{
    ifstream in("D://textfile.txt");
    char c;
    cout<<"******"<<"D://textfile.txt"<<"******"<<endl;
    if(!in)
        return;
    while(in.get(c))
    {
        cout<<c;
    }
    cout<<endl<<endl;
    in.close();

    in.open("D://codefile.txt");
    cout<<"******"<<"D://codefile.txt"<<"******"<<endl;
    if(!in)
        return;
    while(in.get(c))
    {
        cout<<c;
    }
    cout<<endl<<endl;
    in.close();

    in.open("D://result.txt");
    cout<<"******"<<"D://result.txt"<<"******"<<endl;
    if(!in)
        return;
    while(in.get(c))
    {
        cout<<c;
    }
    cout<<endl<<endl;
    in.close();
}
