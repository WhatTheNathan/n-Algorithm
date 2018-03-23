#include <iostream>

/*
 * Description:
 * 定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点
 */

using namespace::std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* ReverseList(ListNode* head) {
    ListNode* pNode = head;
    ListNode* pReserved = nullptr;

    while(pNode) {
        ListNode* pPrvious = pReserved;
        pReserved = pNode;
        pNode = pNode->next;
        pReserved->next = pPrvious;
    }
    return pReserved;
}


int main(){
    ListNode* node_1 = new ListNode(1);
    ListNode* node_2 = new ListNode(2);
    ListNode* node_3 = new ListNode(3);
    ListNode* node_4 = new ListNode(4);
    ListNode* node_5 = new ListNode(5);
    ListNode* node_6 = new ListNode(6);
//    node_1->next = node_2;
//    node_2->next = node_3;
//    node_3->next = node_4;
//    node_4->next = node_5;
//    node_5->next = node_6;

    cout<<ReverseList(node_1)->val<<endl;
}