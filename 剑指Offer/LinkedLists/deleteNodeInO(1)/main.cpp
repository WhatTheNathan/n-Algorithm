#include <iostream>

/*
 * Description:
 * 给定单向链表的头指针和一个结点指针,定义一个函数在O(1)时间删除该结点
 */

using namespace::std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* head, ListNode* node) {
    if(!head && !node)
        return;

    /* 所删除的结点不是尾结点 */
    if(node->next != nullptr) {
        ListNode* pNext = node->next;
        node->val = pNext->val;
        node->next = pNext->next;

        delete pNext;
        pNext = nullptr;
    }

    /* 链表只有一个结点 */
    else if(head == node) {
        delete node;
        node = nullptr;
        head = nullptr;
    }

    /* 删除的是尾结点 */
    else {
        ListNode* temp = head;
        while(temp->next != node) {
            temp = temp->next;
        }
        temp->next = nullptr;
        delete node;
        node = nullptr;
    }
}

int main(){

}