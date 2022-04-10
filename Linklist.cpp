// Type your code here, or load an example.
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node* pNext;
    Node(int pData):pNext(nullptr),data(pData){}
    ~Node(){
        cout<<"~Called"<<endl;
        if(pNext !=nullptr)
        {
            delete pNext;
            pNext=nullptr;
        }
    }

};
Node* getList(){
    Node* pNode= new Node(0);
    pNode->pNext=new Node(1);
    pNode->pNext->pNext=new Node(2);
    pNode->pNext->pNext->pNext=new Node(3);
    pNode->pNext->pNext->pNext->pNext=new Node(4);
    pNode->pNext->pNext->pNext->pNext->pNext=new Node(5);

    cout<<"getList"<<"Pointing to= "<<pNode<<endl<<"Address of pNode ="<<&pNode<<endl;
    return std::move(pNode);
}

Node* getLoopList(){
    Node* pNode= new Node(0);
    pNode->pNext=new Node(1);
    pNode->pNext->pNext=new Node(2);
    pNode->pNext->pNext->pNext=new Node(3);
    pNode->pNext->pNext->pNext->pNext=new Node(4);
    pNode->pNext->pNext->pNext->pNext->pNext=new Node(5);
    pNode->pNext->pNext->pNext->pNext->pNext->pNext=new Node(6);
     pNode->pNext->pNext->pNext->pNext->pNext->pNext->pNext=pNode->pNext->pNext->pNext->pNext;

    cout<<"getList"<<"Pointing to= "<<pNode<<endl<<"Address of pNode ="<<&pNode<<endl;
    return std::move(pNode);
}

Node* getList1(){
    Node* pNode= new Node(0);
    cout<<"getList"<<"Pointing to= "<<pNode<<endl<<"Address of pNode ="<<&pNode<<endl;
    return std::move(pNode);
}

void middleNode(Node*& pHead)
{
    cout<<"middleNode "<<"Pointing to= "<<pHead<<endl<<"Address of pHead ="<<&pHead<<endl;
    if(pHead==nullptr)
        return;
    Node* pFastNode=pHead;
    Node* pSlowNode=pHead;
    int indexer=0;
    while(pFastNode != nullptr && pFastNode->pNext !=nullptr)
    {
        pSlowNode=pSlowNode->pNext;
        pFastNode=pFastNode->pNext->pNext;
        indexer++;
    }
    cout<<"Middle of the List = "<<indexer<<" Value ="<<pSlowNode->data<<endl;
}

void reverseList(Node*& pHead)
{
    cout<<"reverseList "<<"Pointing to= "<<pHead<<endl<<"Address of pHead ="<<&pHead<<endl;
    if(pHead==nullptr)
        return;
    Node* pNext=pHead;
    Node* pCurr=pHead;
    Node* pPrev=nullptr;
    while(pNext!=nullptr)
    {
        pNext=pCurr->pNext;
        pCurr->pNext=pPrev;
        pPrev=pCurr;
        pCurr=pNext;
    }
    pHead=pPrev;
}

bool detectLoop(Node*& pHead)
{
    cout<<"detectLoop "<<" Pointing to= "<<pHead<<endl<<"Address of pHead ="<<&pHead<<endl;
    Node* pFast=pHead;
    Node* pSlow=pHead;
    while (pFast !=nullptr && pFast->pNext !=nullptr)
    {
        pFast=pFast->pNext->pNext;
        pSlow=pSlow->pNext;
        cout<<"pSlow is at = "<<pSlow->data<<" pFast is at = "<<pFast->data<<endl; 
        if(pFast==pSlow)
        {       
         return true;
        }
    }
return false;
}

void removeLoop(Node*& pHead)
{
    if(pHead==nullptr)
    return;
    Node* pFast=pHead;
    Node* pSlow=pHead;
    bool bIsLoop=false;
    while (pFast !=nullptr && pFast->pNext !=nullptr)
    {
        pSlow=pSlow->pNext;
        pFast=pFast->pNext->pNext;
        if(pSlow==pFast)
        {
            bIsLoop=true;
            break;
        }
    }

    if(false==bIsLoop)
    return;
pSlow=pHead;
if(pSlow==pFast) {
     while(pSlow != pFast->pNext){pFast=pFast->pNext;}
}
     else{
         while (pSlow->pNext != pFast->pNext)
         {
             pSlow=pSlow->pNext;
             pFast=pFast->pNext;
         }
     }
     pFast->pNext=nullptr;
}



void printList(Node*& pHead)
{
    cout<<"printList "<<"Pointing to= "<<pHead<<endl<<"Address of pHead ="<<&pHead<<endl;
    if(pHead==nullptr)
        return;
    Node* temp=pHead;
    while(temp != nullptr)
    {
        cout<<temp->data<<endl;
        temp=temp->pNext;
    }
}
int main()
{
     //Node* pHead=getList1();
    //cout<<"Main "<<"Pointing to= "<<pHead<<endl<<"Address of pHead ="<<&pHead<<endl;
    //middleNode(pHead);
    //printList(pHead);
    //reverseList(pHead);
    //printList(pHead);
    //delete pHead;

    Node* pHeadLoop=getLoopList();
    cout<< "Loop= "<<(bool)detectLoop(pHeadLoop)<<endl;
    removeLoop(pHeadLoop);
    printList(pHeadLoop);
    delete pHeadLoop;
    return 0;
}
