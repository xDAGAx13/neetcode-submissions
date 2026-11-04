class Solution {
public:
    Node* copyRandomList(Node* head) {
      if(head==nullptr)return nullptr;
      unordered_map<Node*, Node*> map;
      Node* copy = new Node(head->val);
      Node* old = head->next;
      Node* newList = copy;
      map[head] = copy;
      while(old!=nullptr){
        Node* temp = new Node(old->val);
        //old addresses map the new addresses
        map[old] = temp;
        newList->next = temp;

        //traverse
        old = old->next;
        newList = newList->next;
      }

      old = head;
      newList = copy;
      while(old!=nullptr){
        if(old->random!=nullptr)newList->random = map[old->random];
        else newList->random = nullptr;

        old=old->next;
        newList = newList->next;
      }
      return copy;
    }
};
