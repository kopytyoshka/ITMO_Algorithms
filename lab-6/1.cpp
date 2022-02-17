#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> HashSheet[1000001];
 
int HashFunction(int number){
    int hash = abs((number % 1000001));
    return hash;
}
 
bool SetExists(int number){
    int hash = HashFunction(number);
    if (!(find(HashSheet[hash].begin(), HashSheet[hash].end(), number) == HashSheet[hash].end()))
        return true;
    else
        return false;
}
 
void SetInsert(int number){
    if(!SetExists(number))
    {
        int hash = HashFunction(number);
        HashSheet[hash].push_back(number);
    }
}
 
void SetDelete(int number){
    if (SetExists(number))
    {
        int hash = HashFunction(number);
        HashSheet[hash].erase(remove(HashSheet[hash].begin(), HashSheet[hash].end(), number), HashSheet[hash].end());
    }
}
 
 
int main() {
    string what_to_do;
    int n;
 
    ifstream fin("set.in");
    ofstream fout("set.out");
 
    while(fin >> what_to_do)
    {
        fin >> n;
 
        if (what_to_do == "insert")
            SetInsert(n);
 
        if (what_to_do == "delete")
            SetDelete(n);
 
        if (what_to_do == "exists")
        {
            if(SetExists(n))
                fout << "true" << endl;
            else
                fout << "false" << endl;
        }
    }
    fin.close();
    fout.close();
 
    return 0;
}
