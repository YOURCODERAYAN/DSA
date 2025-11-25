struct Node{

        int key , value , cnt;
    Node*next;
    Node*prev;
    Node(int _key , int _value){
            key=_key;
            value=_value;
    cnt=1;
    }
    };
struct List{

    int size;
    Node*head;
    Node*tail;
List(){
    head=new Node(0,0);
    tail=new Node(0,0);
head->next=tail;
tail->prev=head;
    size=0;
}
void addfront(Node*node){
        Node*temp=head->next;
    node->next=temp;
    node->prev=head;
    head->next=node;
    temp->prev=node;
    size++;
}
void removeNode(Node*delnode){
    Node*prevNode=delnode->prev;
    Node*nextNode=delnode->next;
prevNode->next=nextNode;
nextNode->prev=prevNode;
    size--;
}
};
class LFUCache {
    private:
        map<int , Node*> keynode;
        map<int , List*> freqlistmap;
    int maxsizecache;
    int curr_size;
    int min_freq;

public:
    LFUCache(int capacity) {
        maxsizecache=capacity;
        min_freq=0;
    curr_size=0;
    }

void updatefreqlist(Node*node){
        keynode.erase(node->key);
    freqlistmap[node->cnt]->removeNode(node);
if(node->cnt==min_freq && freqlistmap[node->cnt]->size==0){
            min_freq++;
        } 
    List*nextH=new List();
    if(freqlistmap.find(node->cnt+1)!=freqlistmap.end()){
            nextH=freqlistmap[node->cnt+1];
    } 
        node->cnt+=1;
    nextH->addfront(node);
        freqlistmap[node->cnt]=nextH;
        keynode[node->key]=node;
    };
    
    int get(int key) {
        if(keynode.find(key)!=keynode.end()){
            Node*node=keynode[key];
            int val=node->value;
        updatefreqlist(node);
        return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxsizecache==0){
            return;
        }
    if(keynode.find(key)!=keynode.end()){
        Node*node=keynode[key];
    node->value=value;
    updatefreqlist(node);
    }
    else{

        if(curr_size==maxsizecache){
            List*list=freqlistmap[min_freq];
        keynode.erase(list->tail->prev->key);
        // update the freqlist map
        freqlistmap[min_freq]->removeNode(list->tail->prev);
            curr_size--;
        }
        curr_size++;
        min_freq=1;
            List*Listfreq=new List();
    if(freqlistmap.find(min_freq)!=freqlistmap.end()){
            Listfreq=freqlistmap[min_freq];
        }
    Node*node=new Node(key , value);
        Listfreq->addfront(node);
    keynode[key]=node;
    freqlistmap[min_freq]=Listfreq;
    }
}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */