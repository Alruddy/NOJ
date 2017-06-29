#include<iostream>
using namespace std;
template<class T>
class BinaryTree;
template<class T>
class BTNode
{
private:
    T element;
    BTNode<T> *lchild,*rchild;
    friend class BinaryTree<T>;
public:
    BTNode()
    {
       lchild=rchild=NULL;
    }
    BTNode(T &a)
    {
        element=a;
        lchild=rchild=NULL;
    }
};
template<class T>
class BinaryTree
{
    BTNode<T> *root;
    int Height;
    int tempHeight;
    int Nodecount;
    int Lastnodecount;
    int Singleducount;
public:
    BinaryTree();
    ~BinaryTree();
    void creatBinTree(BTNode<T> *&t);
    void Creat();
    void Traverse();
    void DestroyBT(BTNode<T> *head,BTNode<T> *parent);
    void ProTraverse(BTNode<T> *p);
    void InTraverse(BTNode<T> *p);
    void PostTraverse(BTNode<T> *p);
    void TraverseforGet(BTNode<T> *p);
    void TraverseforGet();
    int getLastnodecount();
    int getNodecount();
    int getHeight();
    int getSingleducount();
};
template<class T>
BinaryTree<T>::BinaryTree()
{
    root=new BTNode<T>;
    root->rchild=root->rchild=NULL;
    Height=0;
    Nodecount=0;
    Lastnodecount=0;
    Singleducount=0;
    tempHeight=0;
}
template<class T>
BinaryTree<T>::~BinaryTree()
{
    BTNode<T> *head=new BTNode<T>;
    head->lchild=root;
    DestroyBT(head,root);
}
template<class T>
void BinaryTree<T>::DestroyBT(BTNode<T> *head,BTNode<T> *parent)
{
    if(!parent)
        return;
    if(head->lchild==parent)
    {
        DestroyBT(head->lchild,parent->lchild);
        DestroyBT(head->lchild,parent->rchild);
        if(parent->rchild==NULL&&parent->lchild==NULL)
        {
            cout<<parent->element<<endl;
            delete parent;
            head->lchild=NULL;
        }
    }
    else
    {
        DestroyBT(head->rchild,parent->lchild);
        DestroyBT(head->rchild,parent->rchild);
        if(parent->rchild==NULL&&parent->lchild==NULL)
        {
            cout<<parent->element<<endl;
            delete parent;
            head->rchild=NULL;
        }
    }
}
template<class T>
void BinaryTree<T>::creatBinTree(BTNode<T> *&t)
{
    T c;
    cin>>c;
    if(c=='#')
        t=NULL;
    else{
        t=new BTNode<T>(c);
        creatBinTree(t->lchild);
        creatBinTree(t->rchild);
    }
}
template<class T>
void BinaryTree<T>::ProTraverse(BTNode<T> *p)
{

    if(p==NULL)
        return;
    cout<<" "<<p->element;
    ProTraverse(p->lchild);
    ProTraverse(p->rchild);
}
template<class T>
void BinaryTree<T>::Creat()
{
    creatBinTree(root);
}
template<class T>
void BinaryTree<T>::Traverse()
{
    cout<<"PreOrder:";
    ProTraverse(root);
    cout<<endl;
    cout<<"InOrder:";
    InTraverse(root);
    cout<<endl;
    cout<<"PostOrder:";
    PostTraverse(root);
    cout<<endl;
}
template<class T>
void BinaryTree<T>::InTraverse(BTNode<T> *p)
{
    if(p==NULL)
        return;
    InTraverse(p->lchild);
    cout<<" "<<p->element;
    InTraverse(p->rchild);
}
template<class T>
void BinaryTree<T>::PostTraverse(BTNode<T> *p)
{
    if(p==NULL)
        return;
    PostTraverse(p->lchild);
    PostTraverse(p->rchild);
    cout<<" "<<p->element;
}
template<class T>
void BinaryTree<T>::TraverseforGet()
{
    Nodecount=0;
    Lastnodecount=0;
    Singleducount=0;
    tempHeight=Height=0;
    TraverseforGet(root);
}
template<class T>
void BinaryTree<T>::TraverseforGet(BTNode<T> *p)
{
    if(!p)
    {
        Height=tempHeight>Height?tempHeight:Height;
        return;
    }
    Nodecount++;
    tempHeight++;
    if(p->lchild==NULL&&p->rchild==NULL)
        Lastnodecount++;
    if(p->lchild==NULL&&p->rchild!=NULL||p->lchild!=NULL&&p->rchild==NULL)
        Singleducount++;
    TraverseforGet(p->lchild);
    TraverseforGet(p->rchild);
    tempHeight--;
}
template<class T>
int BinaryTree<T>::getNodecount()
{
    return Nodecount;
}
template<class T>
int BinaryTree<T>::getLastnodecount()
{
    return Lastnodecount;
}
template<class T>
int BinaryTree<T>::getHeight()
{
    return Height;
}
template<class T>
int BinaryTree<T>::getSingleducount()
{
    return Singleducount;
}
int main()
{
    BinaryTree<char> test;
    test.Creat();
    test.Traverse();
    test.TraverseforGet();
    cout<<test.getHeight()<<endl;
    cout<<test.getNodecount()<<" "<<test.getLastnodecount()<<" "<<test.getSingleducount();
    cout<<endl;
    return 0;
}
