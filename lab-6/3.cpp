#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <list>
 
using namespace std;
 
class HashMapEntry{
public:
    HashMapEntry(string key_in, string value_in){
        key = std::move(key_in);
        value = std::move(value_in);
    }
    string key;
    string value;
    HashMapEntry *next = nullptr;
    HashMapEntry *prev = nullptr;
};
 
vector<list<HashMapEntry*>> HashTable(100001);
HashMapEntry *head;
 
int HashFunction(string s)
{
    const int p = 31;
    int hash = 0, p_pow = 1;
    for (char i : s)
    {
        hash += (i - 'a' + 1) * p_pow;
        p_pow *= p;
    }
    return abs(hash)%100001;
}
 
void MapPut(const string& key, const string& value){
 
    int hash = HashFunction(key);
 
    for (auto it = HashTable[hash].begin(); it != HashTable[hash].end(); ++it)
    {
        if((*it)->key == key)
        {
            (*it)->value = value;
            return;
        }
    }
 
    auto *entry = new HashMapEntry(key, value);
    HashTable[hash].push_back(entry);
 
    if(head == nullptr)
        head = entry;
    else
    {
        head->next = entry;
        entry->prev = head;
        head = entry;
    }
}
 
string MapGet(const string& key){
    int hash = HashFunction(key);
 
    for(const HashMapEntry *element : HashTable[hash])
    {
        if(element->key == key)
            return element->value;
    }
    return "none";
}
 
void MapDelete(const string& key){
    int hash = HashFunction(key);
 
    for (auto it = HashTable[hash].begin(); it != HashTable[hash].end(); ++it)
    {
        if((*it)->key == key)
        {
            HashMapEntry *next, *prev;
            HashTable[hash].erase(it);
 
            next = (*it)->next;
            prev = (*it)->prev;
 
            if(prev != nullptr)
                prev->next = next;
            if(next != nullptr)
                next->prev = prev;
            else
                head = prev;
 
            delete *it;
            return;
        }
    }
 
}
 
string MapGetPrev(const string& key){
    int hash = HashFunction(key);
 
    for (auto it = HashTable[hash].begin(); it != HashTable[hash].end(); ++it)
    {
        if((*it)->key == key)
        {
            if((*it)->prev == nullptr)
                return  "none";
 
            return (*it)->prev->value;
        }
    }
    return "none";
}
 
string MapGetNext(const string& key){
    int hash = HashFunction(key);
 
    for (auto it = HashTable[hash].begin(); it != HashTable[hash].end(); ++it)
    {
        if((*it)->key == key)
        {
            if((*it)->next == nullptr)
                return  "none";
 
            return (*it)->next->value;
        }
    }
    return "none";
}
 
 
int main() {
    string what_to_do;
    string key, value;
 
    ifstream fin("linkedmap.in");
    ofstream fout("linkedmap.out");
 
    while(fin >> what_to_do)
    {
        fin >> key;
 
        if(what_to_do == "put")
        {
            fin >> value;
            MapPut(key, value);
        }
 
        if(what_to_do == "get")
            fout << MapGet(key) << endl;
 
        if(what_to_do == "delete")
            MapDelete(key);
 
        if(what_to_do == "next")
            fout << MapGetNext(key) << endl;
 
        if(what_to_do == "prev")
            fout << MapGetPrev(key) << endl;
    }
 
    fin.close();
    fout.close();
 
    return 0;
}
