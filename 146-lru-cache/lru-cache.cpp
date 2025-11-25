class LRUCache {
public:
    class Node{
    public:
        int _key;
        int _val;
    Node*next;
    Node*prev;
Node(int key , int val ){
    _key=key;
    _val=val;
    }
};
        Node*head=new Node(-1,-1);
        Node*tail=new Node(-1,-1);
    int cap;
    unordered_map<int , Node*> mp;
public:
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

void addNode(Node*newNode){
    Node*temp=head->next;
    newNode->next=temp;
    newNode->prev=head;

head->next=newNode;
temp->prev=newNode;
}

void deleteNode(Node*delnode){

    Node*delprev=delnode->prev;
    Node*delnext=delnode->next;

delprev->next=delnext;
delnext->prev=delprev;
}
    
    int get(int key) {
        // if the key exixts 
    if(mp.find(key) != mp.end()){
            Node*resnode=mp[key];
            int res=resnode->_val;
    // remove old mapping
        mp.erase(key);
    deleteNode(resnode);
    addNode(resnode);
    mp[key]=head->next;
    return res;
    }
    return -1;
    }
    
    void put(int key, int value) {
        // if key already exists
    if(mp.find(key)!=mp.end()){
        Node*existnode=mp[key];
        mp.erase(key);
        deleteNode(existnode);
    }
    if(mp.size()==cap){
        mp.erase(tail->prev->_key);
        deleteNode(tail->prev);
    }
    addNode(new Node(key , value));
        mp[key]=head->next;
}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */