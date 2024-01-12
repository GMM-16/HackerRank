/*
Abstract base classes in C++ can only be used as base classes. Thus, they are allowed to have virtual member functions without definitions.
A cache is a component that stores data so future requests for that data can be served faster. The data stored in a cache might be the results of an earlier computation, or the duplicates of data stored elsewhere. A cache hit occurs when the requested data can be found in a cache, while a cache miss occurs when it cannot. Cache hits are served by reading data from the cache which is faster than recomputing a result or reading from a slower data store. Thus, the more requests that can be served from the cache, the faster the system performs.
One of the popular cache replacement policies is: "least recently used" (LRU). It discards the least recently used items first.
Given an abstract base class Cache with member variables and functions:
mp - Map the key to the node in the linked list
cp - Capacity
tail - Double linked list tail pointer
head - Double linked list head pointer
set() - Set/insert the value of the key, if present, otherwise add the key as the most recently used key. If the cache has reached its capacity, it should replace the least recently used key with a new key.
get() - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
You have to write a class LRUCache which extends the class Cache and uses the member functions and variables to implement an LRU cache.

Input Format
First line of input will contain the N number of lines containing get or set commands followed by the capacity M of the cache.
The following N lines can either contain get or set commands.
An input line starting with get will be followed by a key to be found in the cache. An input line starting with set will be followed by the key and value respectively to be inserted/replaced in the cache.

Constraints
1 <= N <= 500000
1 <= M <= 1000
1 <= key <= 20
1 <= value <= 2000

Output Format
The code provided in the editor will use your derived class LRUCache to output the value whenever a get command is encountered.
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache
{
    private:
        void update_usage(int k)           
        {            
            auto node = mp[k];            
            if(node == head || node == tail) return;                   
            node->prev->next = node->next;                        
            node->next->prev = node->prev;
            node->prev = nullptr; 
            node->next = head; 
            head->prev = node; 
            head = node;  
        }
    public:
        void set(int k, int v) override     
        {            
            if(mp.find(k) != mp.end())
            {                
                mp[k]->value = v;
                update_usage(k);
            } 
            else
            {
                Node* new_node = new Node(k, v);                    
                if(head == nullptr)
                {                    
                    head = new_node;
                    tail = new_node;
                    mp[k] = new_node;
                    return;
                }
                if(mp.size() >= cp)
                {                
                    mp.erase(tail->key);  
                    auto new_tail = tail->prev;                         
                    tail->prev->next = nullptr;
                    tail = new_tail;
                }
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
                mp[k] = new_node;        
            }            
        }
        int get(int k) override 
        {            
            if(mp.find(k) != mp.end())
            {                
                update_usage(k);
                return mp[k]->value;
            }
            else
            {
                return -1;
            }
        }
        LRUCache(int capacity)
        {
            cp = capacity;
        }     
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
