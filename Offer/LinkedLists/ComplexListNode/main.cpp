#include <iostream>

/*
 * Description:
 * 实现函数ComplexListNode* Clone(ComplexListNode* pHead)
 * 复制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个结点外，还有一个m_pSibling指向链表中
 * 的任意结点或者NULL
 */

using namespace::std;


struct ListNode {
    int m_nValue;
    ListNode* m_pNext;
    ListNode* m_pSibling;
    ListNode(int x) : m_nValue(x), m_pNext(nullptr), m_pSibling(nullptr) {}
};

void CloneNodes(ListNode* pHead) {
    ListNode* pNode = pHead;
    while(pNode) {
        ListNode* pCloned = new ListNode(pNode->m_nValue);
        pCloned->m_pNext = pNode->m_pNext;

        pNode->m_pNext = pCloned;
        pNode = pCloned->m_pNext;
    }
}

void ConnectSiblingNodes(ListNode* pHead) {
    ListNode* pNode = pHead;
    while(pNode) {
        ListNode* pCloned = pNode->m_pNext;
        if(pNode->m_pSibling) {
            pCloned->m_pSibling = pNode->m_pSibling;
        }
        pNode = pCloned->m_pNext;
    }
}

ListNode* ReconnectNodes(ListNode* pHead) {
    ListNode* clonedHead = nullptr;
    ListNode* clonedNode = nullptr;
    ListNode* pNode = pHead;

    if(pNode) {
        clonedHead = pNode->m_pNext;
        clonedNode = pNode->m_pNext;
        pNode->m_pNext = clonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    while(pNode) {
        clonedNode->m_pNext = pNode->m_pNext;
        clonedNode = clonedNode->m_pNext;
        pNode->m_pNext = clonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
}

ListNode* Clone(ListNode* pHead) {
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}


int main(){
    ListNode* node_1 = new ListNode(1);
    ListNode* node_2 = new ListNode(2);
    ListNode* node_3 = new ListNode(3);
    ListNode* node_4 = new ListNode(4);
    ListNode* node_5 = new ListNode(5);
    ListNode* node_6 = new ListNode(6);
    ListNode* node_7 = new ListNode(7);
    ListNode* node_8 = new ListNode(8);

//    node_1->m_pNext = node_2;
//    node_1->m_pSibling = node_3;
    node_2->m_pNext = node_3;
    node_2->m_pSibling = node_5;
    node_3->m_pNext = node_4;
    node_4->m_pNext = node_5;
    node_4->m_pSibling = node_2;

    cout<<Clone(node_1)->m_nValue<<endl;
}