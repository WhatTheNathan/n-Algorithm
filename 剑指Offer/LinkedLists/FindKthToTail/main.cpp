#include <iostream>

/*
 * Description:
 * 输入一个链表，输出该链表中倒数第k个结点。
 * 例如一个链表有6个结点，从头结点开始依次1,2,3,4,5,6
 */

using namespace::std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* FindKthToTail(ListNode* head, int k) {
    if(!head || k == 0)
        return nullptr;

    ListNode* p = head;
    ListNode* pp = head;

    for(auto i = 0; i < k - 1; i++) {
        if(!p->next) {
            return nullptr;
        }
        p = p->next;
    }
    while(p->next) {
        p = p->next;
        pp = pp->next;
    }
    return pp;
}


int main(){
    ListNode* node_1 = new ListNode(1);
    ListNode* node_2 = new ListNode(2);
    ListNode* node_3 = new ListNode(3);
    ListNode* node_4 = new ListNode(4);
    ListNode* node_5 = new ListNode(5);
    ListNode* node_6 = new ListNode(6);
    node_1->next = node_2;
//    node_2->next = node_3;
//    node_3->next = node_4;
//    node_4->next = node_5;
//    node_5->next = node_6;

    cout<<FindKthToTail(node_1,0)->val<<endl;
}