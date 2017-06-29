#include<iostream>
#include<list>
#include<iterator>
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
public:
    BinaryTree();
    ~BinaryTree();
    void creatBinTree(BTNode<T> *&t);
    void Creat();
    void DestroyBT(BTNode<T> *&head,BTNode<T> *&parent);
    void LevelTraverse();
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
void BinaryTree<T>::Creat()
{
    creatBinTree(root);
}
template<class T>
void BinaryTree<T>::LevelTraverse()
{
    list<BTNode<T> *> temp(0);
    BTNode<T> *p=root;
    cout<<"LevelOrder:";
    if(p)
        temp.push_back(p);
    while(!temp.empty())
    {
        p=temp.front();
        temp.pop_front();
        if(p->lchild)
            temp.push_back(p->lchild);
        if(p->rchild)
            temp.push_back(p->rchild);
        cout<<" "<<p->element;
    }
    cout<<endl;
}
int main()
{
    BinaryTree<char> test;
    test.Creat();
    test.LevelTraverse();
    return 0;
}
