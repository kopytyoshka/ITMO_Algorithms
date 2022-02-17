#include <iostream>
#include <fstream>
 
using namespace std;
 
int N;
bool flag = true;
 
struct Binary_Tree
{
    int left;
    int key;
    int right;
};
 
void check(struct Binary_Tree tree[], int x, int l, int r)
{
    if(flag)
    {
        if (tree[x].key <= l || tree[x].key >= r)
            flag = false;
        if (tree[x].right != 0)
            check(tree, tree[x].right - 1, tree[x].key, r);
        if (tree[x].left != 0)
            check(tree, tree[x].left - 1, l, tree[x].key);
    }
}
 
int main()
{
    ifstream fin("check.in");
    ofstream fout("check.out");
 
    fin >> N;
    struct Binary_Tree tree[N];
 
    if (N == 0)
    {
        fout << "YES";
 
        fin.close();
        fout.close();
 
        return 0;
    }
 
    for (int i = 0; i < N; i++)
        fin >> tree[i].key >> tree[i].left >> tree[i].right;
 
    check(tree, 0, -1000000001, 1000000001);
 
    if (flag)
        fout << "YES" << endl;
    else
        fout << "NO" << endl;
 
    fin.close();
    fout.close();
 
    return 0;
}
