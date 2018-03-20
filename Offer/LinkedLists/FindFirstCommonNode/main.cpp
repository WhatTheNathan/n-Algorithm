#include <iostream>

/*
 * Description:
 * 输入两个链表，找出它们的第一个公共结点
 */

using namespace::std;


struct ListNode {
    int value;
    ListNode* next;
    ListNode(int x) : value(x), next(nullptr) {}
};

int getLength(ListNode* node) {
    if(!node)
        return 0;
    int length = 0;
    while(node) {
        length++;
        node = node->next;
    }
    return length;
}

ListNode* firstCommonNode(ListNode* root_1, ListNode* root_2) {
    if(!root_1 || !root_2)
        return nullptr;
    int length_1 = getLength(root_1);
    int length_2 = getLength(root_2);

    int lengthDiff = abs(length_1 - length_2);

    ListNode* pR_1 = root_1;
    ListNode* pR_2 = root_2;

    // 默认length_1小于length_2
    // 若大于，则手动更改指针指向
    if(length_1 <= length_2) {
        pR_1 = root_2;
        pR_2 = root_1;
    }

    while(lengthDiff > 0 && pR_1) {
        pR_1 = pR_1->next;
        lengthDiff--;
    }

    while(pR_1 && pR_2) {
        if(pR_1 == pR_2)
            return pR_1;
        pR_1 = pR_1->next;
        pR_2 = pR_2->next;
    }

}

int main(){
    ListNode* node_1 = new ListNode(1);
    ListNode* node_2 = new ListNode(2);
    ListNode* node_3 = new ListNode(3);
    ListNode* node_4 = new ListNode(4);
    ListNode* node_5 = new ListNode(5);
    ListNode* node_6 = new ListNode(6);
    ListNode* node_7 = new ListNode(7);

    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_6;

    node_4->next = node_5;
    node_5->next = node_6;

//    node_6->next = node_7;

    cout<<firstCommonNode(node_4,node_1)->value<<endl;
}