#include<iostream>
using namespace std;
const char init[50]="DEH##FJ##G#CK###A#B##";
int i=0;
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
public:
    BinaryTree();
    ~BinaryTree();
    void creatBinTree(BTNode<T> *&t);
    void Creat();
    void Traverse();
    void DestroyBT(BTNode<T> *&head,BTNode<T> *&parent);
    void ProTraverse(BTNode<T> *p);
    void InTraverse(BTNode<T> *p);
    void PostTraverse(BTNode<T> *p);
};
template<class T>
BinaryTree<T>::BinaryTree()
{
    root=new BTNode<T>;
    root->rchild=root->rchild=NULL;
}
template<class T>
BinaryTree<T>::~BinaryTree()
{
    BTNode<T> *parent=NULL;
    DestroyBT(root,parent);
}
template<class T>
void BinaryTree<T>::DestroyBT(BTNode<T> *&head,BTNode<T> *&parent)
{
    if(!parent)
        return;
    if(head->lchild==parent)
    {
        if(parent->rchild==NULL&&parent->lchild==NULL)
        {
            delete parent;
            head->lchild=NULL;
        }
        DestroyBT(head->lchild,parent->lchild);
        DestroyBT(head->lchild,parent->rchild);
    }
    if(head->rchild==parent)
    {
        if(parent->rchild==NULL&&parent->lchild==NULL)
        {
            delete parent;
            head->rchild=NULL;
        }
        DestroyBT(head->rchild,parent->lchild);
        DestroyBT(head->rchild,parent->rchild);
    }
}
template<class T>
void BinaryTree<T>::creatBinTree(BTNode<T> *&t)
{
    T c=init[i++];
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
int main()
{
    BinaryTree<char> test;
    test.Creat();
    test.Traverse();
    return 0;
}










