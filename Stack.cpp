#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node{
    Node* pNext;
    int data;
    Node(int pdata):pNext(nullptr),data(pdata){}
    ~Node(){
        if(pNext !=nullptr)
        {
            delete pNext;
            pNext=nullptr;
        }
    }
};

class MyStackusingLinkList
{
    private:
    Node* pHead;
    int _nPosition;
    public:
    MyStackusingLinkList() :pHead(nullptr),_nPosition(0)
    {}
    void pop()
    {
        if(pHead !=nullptr)
        {
            Node* temp= pHead;
            pHead=pHead->pNext;
            temp->pNext=nullptr;
            delete temp;
            temp=nullptr;
            _nPosition--;

        }
    }
    int top()
    {
        return pHead->data;
    }
    void push(int data)
    {
        Node* pNode=new Node(data);
        pNode->pNext=pHead;
        pHead=pNode;
        _nPosition++;
    }
    int getSize()
    {
        return _nPosition;
    }
};

class myStackUsingQueue
{
    private:
    queue<int> mq;
    public:
    void push(int a)
    {
        queue<int> q1;
        q1.push(a);

        while(!mq.empty())
        {
            q1.push(mq.front());
            mq.pop();
        }
        mq=std::move(q1);
    }

    int top()
    {
       return mq.front();
    }

    void pop()
    {
        mq.pop();
    }
    int getSize()
    {
        return mq.size();
    } 
};

int main()
{
    /*
    MyStackusingLinkList pStack;
    pStack.push(10);
    pStack.push(20);
    pStack.push(30);

while(pStack.getSize()>0)
{
    cout<<pStack.top()<<endl;
    pStack.pop();
}
*/



    myStackUsingQueue pStack;
    pStack.push(10);
    pStack.push(20);
    pStack.push(30);

while(pStack.getSize()>0)
{
    cout<<pStack.top()<<endl;
    pStack.pop();
}
    return 0;
    
}
