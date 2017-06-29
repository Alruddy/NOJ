#include<iostream>
using namespace std;
class Polynome;
class Term
{
private:
    int coef;
    int exp;
    Term *link;
public:
    Term(int c,int e);
    Term(int c,int e,Term* next);
    Term* InsertAfter(int c,int e);
    friend ostream& operator<<(ostream &out,Term &item);
    friend class Polynome;
};
class Polynome
{
public:
    Term* thisList;
    Polynome();
    Polynome(const Polynome &);
    ~Polynome();
    void Output(ostream &out);
    void AddTerm(istream &in);
    void PolyAdd(Polynome &);
    friend ostream &operator<<(ostream& ,Polynome& );
    friend istream &operator>>(istream& ,Polynome& );
    friend Polynome &operator+(Polynome& ,Polynome &);
};
Term::Term(int c,int e):coef(c),exp(e)
{
    link=0;
}
Term::Term(int c,int e,Term* next):coef(c),exp(e)
{
    link=next;
}
Term* Term::InsertAfter(int c,int e)
{
    link=new Term(c,e);
    return link;
}
ostream& operator<<(ostream &out,Term &item)
{
    if(item.coef)
    {
        if(!item.exp||item.coef!=1&&item.coef!=-1)
            out<<item.coef;
        switch(item.exp)
        {
        case 0:
            break;
        case 1:
            if(item.coef==-1)
                out<<"-X";
            else
                out<<"X";
            break;
        default:
            if(item.coef==-1)
                out<<"-X^"<<item.exp;
            else
                out<<"X^"<<item.exp;
            break;
        }
    }
    return out;
}
Polynome::Polynome()
{
    thisList=new Term(0,-1);
    thisList->link=NULL;
}
Polynome::Polynome(const Polynome& r)
{
    thisList=new Term(0,-1);
    thisList->link=NULL;
    Term *p=r.thisList->link;
    Term *q=thisList;
    while(p)
    {
        q=q->InsertAfter(p->coef,p->exp);
        p=p->link;
    }
    q->link=NULL;
}
Polynome::~Polynome()
{
    Term *p,*q;
    p=thisList->link;
    while(p!=NULL)
    {
        q=p;
        p=p->link;
        delete q;
    }
    delete thisList;
}
void Polynome::Output(ostream &out)
{
    Term *q=thisList->link;
    while(q&&!q->coef)
    {
        q=q->link;
    }
    if(!q)
    {
        cout<<"0"<<endl;
        return ;
    }
    int first=1;
    Term *p=q;
    while(p)
    {
        if(!first&&p->coef>0)
        {
            out<<"+";
        }
        first=0;
        out<<*p;
        p=p->link;
    }
    cout<<endl;
}
void Polynome::AddTerm(istream &in)
{
    Term *p=thisList;
    int c,e;
    do
    {
        in>>c>>e;
        if(e<0)
            break;
        p=p->InsertAfter(c,e);
    }while(1);
    p->link=NULL;
}
void Polynome::PolyAdd(Polynome &pol)
{
    Term *p1=thisList;
    Term *p=p1->link;
    Term *q=pol.thisList->link;
    while(q)
    {
        if(!p||p->exp<q->exp)
        {
            p1=p1->InsertAfter(q->coef,q->exp);
            p1->link=p;
            q=q->link;
            continue;
        }
        if(p->exp>q->exp)
        {
            p1=p;
            p=p1->link;
            continue;
        }
        if(p->exp==q->exp)
        {
            p->coef+=q->coef;
            if(p->coef==0)
            {
                if(p->exp)
                {
                    p1->link=p->link;
                    delete p;
                    p=p1->link;
                }
                else
                {
                    p1=p;
                    p=p1->link;
                }
            }
            else
            {
                p1=p;
                p=p1->link;
            }
            q=q->link;
            continue;
        }
    }
}
ostream &operator<<(ostream& out,Polynome& r)
{
    r.Output(out);
    return out;
}
istream &operator>>(istream& in,Polynome& r)
{
    r.AddTerm(in);
    return in;
}
Polynome &operator+(Polynome& a,Polynome &b)
{
    a.PolyAdd(b);
    return a;
}
int main()
{
    Polynome operat1,operat2;
    cin>>operat1;
    cin>>operat2;
    cout<<operat1;
    cout<<operat2;
    cout<<operat1+operat2;
    return 0;
}









