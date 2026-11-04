class LRUCache {
public:

    class Node{
        public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v){
          key = k;
          val = v;
          prev=next=nullptr;
        }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int, Node*> map;
    int capacity;

    void removeNode(Node* node){
      Node* prevNode = node->prev;
      Node* nextNode = node->next;
      prevNode->next = nextNode;
      nextNode->prev = prevNode;
    }

    void addToTail(Node* node){
      node->prev = tail->prev;
      node->next = tail;
      tail->prev->next = node;
      tail->prev = node;
    }

    void moveToTail(Node* node){
      removeNode(node);
      addToTail(node);
    }

    Node* pop(){
      Node* lru = head->next;
      removeNode(lru);
      return lru;
    }

    LRUCache(int capacity) {
      this->capacity = capacity;
      head->next = tail;
      tail->prev = head;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()){
          moveToTail(map[key]);
          return map[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
      if(map.find(key)!=map.end()){
        Node* node = map[key];
        node->val = value;
        moveToTail(node);
      }else{
        Node* newNode = new Node(key, value);
        map[key] = newNode;
        addToTail(newNode);

        if(map.size()>capacity){
          Node* lru = pop();
          map.erase(lru->key);
          delete lru;
        }
      }
    }
};