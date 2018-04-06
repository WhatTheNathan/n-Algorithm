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

// 使用了O(n)空间的方法
//ListNode* EntryNodeOfLoop(ListNode* first) {
//    ListNode* currentNode = first;
//    map<ListNode*,int> mapp;
//    while(currentNode) {
//        if(mapp[currentNode] == 2) {
//            return currentNode;
//        }
//        mapp[currentNode]++;
//        currentNode = currentNode->next;
//    }
//    return nullptr;
//}

ListNode* MeetingNode(ListNode* first) {
    if(!first) {
        return nullptr;
    }
    ListNode* slow = first->next;
    if(!slow){
        return nullptr;
    }
    ListNode* fast = slow->next;
    while(slow && fast) {
        if(slow == fast) {
            return slow;
        }
        slow = slow->next;
        fast = fast->next;
        if(fast)
            fast = fast->next;
    }
    return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* head) {
    ListNode* meetingNode = MeetingNode(head);
    if(!meetingNode)
        return nullptr;

    int nodeOfLoop = 1;
    ListNode* node = meetingNode;
    while(node->next != meetingNode) {
        node = node->next;
        nodeOfLoop++;
    }

    ListNode* prePointer = head;
    for(int i = 0; i < nodeOfLoop; i++) {
        prePointer = prePointer->next;
    }

    ListNode* afterPointer = head;
    while(true) {
        if(prePointer == afterPointer) {
            return prePointer;
        }
        prePointer = prePointer->next;
        afterPointer = afterPointer->next;
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
    node_3->next = node_4;
    node_4->next = node_5;
    node_5->next = node_6;

    node_6->next = node_3;

    cout<<EntryNodeOfLoop(node_1)->value<<endl;
}