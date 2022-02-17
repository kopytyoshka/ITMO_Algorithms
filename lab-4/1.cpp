#include <fstream>
#include <vector>
 
using namespace std;
 
struct stack {
    vector <int> a;
    int size = 0;
    explicit stack(int n) {
        a.resize(n);
    }
    int pop() {
        return a[size--];
    }
    void push(int val) {
        a[++size] = val;
    }
};
 
int main() {
    ifstream fin("stack.in");
    ofstream fout("stack.out");
    long n;
    fin >> n;
    char com;
    long mean;
    stack a(n);
    for (int i = 0; i < n; i++) {
        fin >> com;
        if (com == '+') {
            fin >> mean;
            a.push(mean);
        }
        else {
            fout << a.pop() << endl;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
