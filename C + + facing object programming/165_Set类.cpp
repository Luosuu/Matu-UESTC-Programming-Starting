#include <iostream>
#include <cstring>
using namespace std;
class Set{
private:
    int n;
    int * pS; //集合元素
public:
    Set(){n = 0;pS =nullptr;}
    Set(Set &s){
        n = s.n;
        if (n !=0)
        {
            pS= new  int[n+1];
            for (int i =1;i<=n;i++) //集合的下标从1开始，集合中不能有重复元素
                pS[i] = s.pS[i];
        }
    }
    ~Set(){
        if (pS)
        {
            delete []pS;
            pS = nullptr;
            n =0;
        }
    }
    void ShowElement()const{ //输出集合的元素
        cout<<"{";
        for(int i =1;i<n;i++)
            cout <<pS[i]<<",";
        if (IsEmpty())
            cout<<"}"<<endl;
        else cout<<pS[n]<<"}"<<endl;
    }
    bool IsEmpty()const{return n==0;} //判断集合是否为空
    int size(){return n;};//大小
    bool IsElement(int e)const {//判断是否为元素
        for (int i =1;i<=n;i++)
            if (pS[i] ==e)
                return true;
        return  false;
    }
    bool operator <=(const Set &s)const;//this <= s判断当前集合是否包于集合s
    bool operator ==(const Set &s)const; //判断集合是否相等
    Set & operator +=(int e);    // 向集合中增减元素e
    Set & operator -=(int e);

    //删除集合中的元素e

    Set operator |(const Set &s)const;  //集合并
    Set operator &(const Set &s)const;//集合交
    Set operator -(const Set &s)const; //集合差
};
//#include <CSet.h>
#define nullptr 0
bool Set::operator<=(const Set &s) const {
    for(int i =1;i<=n;i++)
    {
        if(!s.IsElement(this->pS[i]))
            return false;
    }
    return true;
};

bool Set::operator==(const Set &s) const {
    if(this->n!=s.n) return false;
    for(int i=1;i<=s.n;i++)
    {
        if(!this->IsElement(s.pS[i])) return false;
    }
    return true;
}

Set& Set::operator+=(int e) {
    if(!this->IsElement(e))
    {
        Set set;
        set.n = this->n + 1;
        set.pS = new int[set.n+1];
        for(int i = 1;i<this->n+1;i++)
        {
            set.pS[i] = this->pS[i];
        };
        set.pS[set.n] = e; //现在的脚标有问题

        delete []this->pS;
        this->pS = nullptr;
        this->n++;
        this->pS = new int[set.n+1];
        for(int i=1;i<set.n+1;i++)//应该从i=1开始赋值
        {
            this->pS[i] = set.pS[i];
        }
    }

    return *this;
}
Set& Set::operator-=(int e) {
    Set set(*this);
    if(set.IsElement(e)) {
        delete []pS;
        pS = nullptr;
        pS = new int[n];
        for (int i = 1, j = 1; i <= n + 1; ++i)
        {
            if (set.pS[i] != e)
            {
                pS[j++] = set.pS[i];//
            }
        }
        --n;

    }
    return *this;
}

Set Set::operator|(const Set &s) const {
    Set set;
    for(int i = 1;i<=n;++i){
        set+=this->pS[i];
    }
    for(int i = 1;i<=s.n;++i){
        set+=s.pS[i];
    }
    return set;
}
Set Set::operator&(const Set &s) const {
    Set set;
    set.n = n;
    set.pS = new int[n+1];
    for(int i =1;i<=n;++i)
    {
        set.pS[i]=pS[i];
    }
    for(int i = 1;i<=n;i++)
    {
        if(!s.IsElement(this->pS[i])) {
            set-=this->pS[i];
        }
    }
    return set;
}

Set Set::operator-(const Set &s) const {
    Set set;
    set.n = n;
    set.pS = new int[n+1];
    for(int i = 1;i<=n;++i)
    {
        set.pS[i] = this->pS[i];
    }
    for(int i = 1;i<=s.n;++i)
    {
        if(this->IsElement(s.pS[i]))
        {
            set-=s.pS[i];
        }
    }
    return set;
}


int main(){
    int type = 5;

    Set s1, s2, s3, s4;
    s1 += 2;
    s1 += 3; s1 += 5; s1 += 5;
    s2 += 3; s2 += 5; s2 += 6;
    s3 += 2; s3 += 3; s3 += 5; s3 += 7;
   // cin >> type;
    switch (type){
        case 1:
            s1.ShowElement();
            break;
        case 2:
            s2.ShowElement();
            s2 -= 6;
            s2 -= 7;
            s2.ShowElement();
            break;
        case 3:
            cout << ((s1 <= s3) ? "true" : "false");
            cout << ((s4 <= s4) ? "true" : "false");
            cout << ((s1 <= s2) ? "true" : "false") << endl;
            break;
        case 4:
            s3 -= 7;
            cout << ((s1 == s3) ? "true" : "false");
            cout << ((s4 == s4) ? "true" : "false");
            cout << ((s1 == s2) ? "true" : "false") << endl;
            break;
        case 5:
            (s1 | s2).ShowElement();
            break;
        case 6:
            (s1 &s2).ShowElement();
            break;
        case 7:
            s2 += 6;
            (s1 - s2).ShowElement();
            break;
    }
}

