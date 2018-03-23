#include <iostream>

/*
 * Description:
 * 输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按照递增排序的
 */

using namespace::std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* MergeList(ListNode* lNode, ListNode* rNode) {
    if(!lNode)
        return rNode;
    else if(!rNode)
        return lNode;

    ListNode* pMergedHead = nullptr;
    if(lNode->val <= rNode->val) {
        pMergedHead = lNode;
        pMergedHead->next = MergeList(lNode->next,rNode);
    } else {
        pMergedHead = rNode;
        pMergedHead->next = MergeList(lNode,rNode->next);
    }
    return pMergedHead;
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

    node_1->next = node_3;
    node_3->next = node_5;
    node_5->next = node_7;

    node_2->next = node_4;
    node_4->next = node_6;
    node_6->next = node_8;

    MergeList(node_1,node_2);
    cout<<node_1->next->val<<endl;
}