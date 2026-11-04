class Solution {
public:
    void reorderList(ListNode* head) {
      if(head==nullptr)return;
      ListNode* slow = head;
      ListNode* fast = head;
      while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
      }

      //slow.next = middle
      ListNode* second = slow->next;
      slow->next=nullptr;
      ListNode* prev = nullptr;
      while(second!=nullptr){
        ListNode*temp = second->next;
        second->next=prev;
        prev=second;
        second = temp;
      }

      ListNode* first = head;
      second = prev;
      while(second!=nullptr){
        ListNode* list1 = first->next;
        ListNode* list2 = second->next;

        first->next = second;
        second->next = list1;

        first = list1;
        second = list2;
      }
  }
};