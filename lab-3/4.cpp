#include<iostream>
#include<fstream>
 
using namespace std;
 
struct node{
    int key;
    int operation;
};
node *a;
 
int heap_size = 0;
 
int Left_i(int i) {
    return 2 * i;
}
 
int parent(int i) {
    return i / 2;
}
 
int Right_i(int i) {
    return 2 * i + 1;
}
 
void Min_Heapify(int i)
{
    int l = Left_i(i);
    int r = Right_i(i);
    int least;
    if (l <= heap_size && a[l].key < a[i].key)
        least = l;
    else
        least = i;
    if (r <= heap_size && a[r].key < a[least].key)
        least = r;
    if (least != i)
    {
        swap(a[i], a[least]);
        Min_Heapify(least);
    }
}
 
void decrease_key(int x, int i)
{
    bool flag = true;
 
    if (a[i].key < x)
        flag = false;
 
    if (flag)
    {
        a[i].key = x;
        while (i > 1 && a[parent(i)].key > a[i].key)
        {
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }
}
 
int formation_i(int i)
{
    int flag = false;
    for (int j = 1; j <= heap_size; j++)
        if (a[j].operation == i)
        {
            flag = j;
            break;
        }
    return flag;
}
 
void push(int x, int i)
{
    heap_size++;
    a[heap_size].key = 1000000000;
    a[heap_size].operation = i;
    decrease_key(x, heap_size);
}
 
int extract_min()
{
    int min = a[1].key;
    a[1] = a[heap_size];
    heap_size--;
    Min_Heapify(1);
    return min;
      
}
 
int main() {
 
    ifstream fin("priorityqueue.in");
    ofstream fout("priorityqueue.out");
 
    int n = 1, x, i;
    int m = 1000001;
    a = new node[m];
    string s;
 
    while (fin >> s) {
        if (s == "push")
        {
            fin >> x;
            push(x, n);
        }
        if (s == "extract-min")
        {
            if (heap_size == 0)
                fout << "*" << endl;
            else
                fout << extract_min() << endl;
        }
        if (s == "decrease-key")
        {
            fin >> i >> x;
            i = formation_i(i);
            if (i != false)
                decrease_key(x, i);
        }
        n++;
    }
 
    fin.close();
    fout.close();
 
    return 0;
}
