#include <iostream>
#include <map>

/*
 * Description:
 * 一个链表中包含环，如何找出环的入口结点？
 */

using namespace::std;


struct ListNode {
    int value;
    ListNode* next;
    ListNode(int x) : value(x), next(nullptr) {}
};


// 注意调整Head的指向
void deleteDuplication(ListNode** head) {
    if(!head || !*head) {
        return;
    }
    ListNode* currentNode = *head;
    ListNode* preNode = nullptr;

    while(currentNode) {
        bool isNeedDelete = false;
        ListNode* nextNode = currentNode->next;
        if(nextNode && nextNode->value == currentNode->value) {
            isNeedDelete = true;
        }
        if(isNeedDelete) {
            ListNode* node2delete = currentNode;
            int value = currentNode->value;
            while(node2delete && node2delete->value == value) {
                nextNode = node2delete->next;
                delete node2delete;
                node2delete = nextNode;
            }
            if(preNode)
                preNode->next = nextNode;
            else {
                *head = nextNode;
            }
            currentNode = nextNode;
        } else {
            preNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}


int main(){
    ListNode* node_1 = new ListNode(1);
    ListNode* node_2 = new ListNode(1);
    ListNode* node_3 = new ListNode(3);
    ListNode* node_4 = new ListNode(3);
    ListNode* node_5 = new ListNode(3);
    ListNode* node_6 = new ListNode(3);
    ListNode* node_7 = new ListNode(5);

    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_4;
    node_4->next = node_5;
    node_5->next = node_6;
    node_6->next = node_7;

    deleteDuplication(&node_1);
    cout<<node_1->value<<endl;
//    cout<<EntryNodeOfLoop(node_1)->value<<endl;
}