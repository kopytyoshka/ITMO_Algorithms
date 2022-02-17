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
};
vector<list<HashMapEntry>> HashTable(100001);
 
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
 
void MapPut(string key, string value){
 
    int hash = HashFunction(key);
    for (auto it = HashTable[hash].begin(); it != HashTable[hash].end(); ++it)
    {
        if(it->key == key)
        {
            it->value = value;
            return;
        }
    }
 
    HashMapEntry entry(std::move(key), std::move(value));
    HashTable[hash].push_back(entry);
}
 
string MapGet(string key){
    int hash = HashFunction(key);
    for(const HashMapEntry& element : HashTable[hash])
    {
        if(element.key == key)
            return element.value;
    }
    return "none";
}
 
void MapDelete(string key){
    int hash = HashFunction(key);
    for (auto it = HashTable[hash].begin(); it != HashTable[hash].end(); ++it)
    {
        if(it->key == key)
        {
             HashTable[hash].erase(it);
             return;
        }
    }
}
 
 
int main() {
    string what_to_do;
    string key, value;
 
    ifstream fin("map.in");
    ofstream fout("map.out");
 
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
    }
 
    fin.close();
    fout.close();
 
    return 0;
}
