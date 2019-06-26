#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* input(vector<int> v) {
    ListNode *res;
    ListNode *head=NULL;
    for(auto x:v) {
        ListNode *temp=new ListNode(x);
        if(head==NULL) head=temp;
        else res->next=temp;
        res=temp;
    }
    return head;
}
void output(ListNode *l) {
    while(l!=NULL) {
        cout<<l->val;
        if(l->next!=NULL) cout<<"->";
        l=l->next;
    }
    cout<<"\n";
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *res;
    ListNode *head=NULL;
    int val=0;
    while(l1!=NULL||l2!=NULL) {
        if(l1!=NULL) val+=l1->val;
        if(l2!=NULL) val+=l2->val;
        ListNode *temp=new ListNode(val%10);
        val/=10;
        if(head==NULL) head=temp;
        else res->next=temp;
        res=temp;
        if(l1!=NULL) l1=l1->next;
        if(l2!=NULL) l2=l2->next;
    }
    while(val!=0) {
        ListNode *temp=new ListNode(val%10);
        val/=10;
        if(head==NULL) head=temp;
        else res->next=temp;
        res=temp;
    }
    return head;
}

int main() {
    vector<int> v1{1,8};
    vector<int> v2{0};
    output(input(v1));
    output(input(v2));
    output(addTwoNumbers(input(v1),input(v2)));
    return 0;
}