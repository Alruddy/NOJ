#include<iostream>
#include<list>
using namespace std;
struct BTNode
{
    char element;
    struct BTNode *lchild,*rchild;
};
typedef struct BTNode BTNode;
void Creat(BTNode **T)
{
    char c;
    cin>>c;
    if(c=='#')
        *T=NULL;
    else
    {
        *T=new BTNode;
        (*T)->element=c;
        Creat(&(*T)->lchild);
        Creat(&(*T)->rchild);
    }
}
void CopyBT(BTNode **dst ,BTNode **scr)
{
    if(!*scr)
    {
        *dst=NULL;
        return ;
    }
    *dst=new BTNode;
    (*dst)->element=(*scr)->element;
    CopyBT(&(*dst)->lchild ,&(*scr)->lchild);
    CopyBT(&(*dst)->rchild ,&(*scr)->rchild);
}
void PreTraverse(BTNode *p)
{
    if(!p)
        return;
    cout<<" "<<p->element;
    PreTraverse(p->lchild);
    PreTraverse(p->rchild);
}
void LevelTraverse(BTNode *p)
{
    list<BTNode *> temp;
    BTNode *q;
    q=p;
    if(q)
        temp.push_back(q);
    while(!temp.empty())
    {
        q=temp.front();
        cout<<" "<<q->element;
        temp.pop_front();
        if(q->lchild)
            temp.push_back(q->lchild);
        if(q->rchild)
            temp.push_back(q->rchild);
    }
}
void Exchangechild(BTNode **r)
{
    BTNode *temp;
    temp=(*r)->lchild;
    (*r)->lchild=(*r)->rchild;
    (*r)->rchild=temp;
}
void Exchange(BTNode **r)
{
    if(!*r)
        return;
    Exchange(&(*r)->lchild);
    Exchange(&(*r)->rchild);
    Exchangechild(&(*r));
}
int main()
{
    BTNode *a,*b,*c,*d;
    char ch;
    Creat(&a);
    Creat(&b);
    cin>>ch;
    CopyBT(&c,&a);
    CopyBT(&d,&b);

    BTNode *root=new BTNode;
    root->element=ch;
    root->lchild=c;
    root->rchild=d;

    cout<<"PreOrder:";
    PreTraverse(root);
    cout<<endl<<"LevelOrder:";
    LevelTraverse(root);
    cout<<endl;

    Exchange(&root);
    cout<<"PreOrder:";
    PreTraverse(root);
    cout<<endl<<"LevelOrder:";
    LevelTraverse(root);
    cout<<endl;
    return 0;
}
