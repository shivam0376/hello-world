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
     pNode->pNext->pNext->pNext->pNext->pNext->pNext=pNode->pNext->pNext;

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
    Node* pHead=getList1();
    cout<<"Main "<<"Pointing to= "<<pHead<<endl<<"Address of pHead ="<<&pHead<<endl;
    middleNode(pHead);
    printList(pHead);
    reverseList(pHead);
    printList(pHead);
    delete pHead;
    return 0;
}
