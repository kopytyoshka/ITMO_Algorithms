#include <fstream>
#include <vector>
 
using namespace std;
 
struct queue {
    vector <int> a;
    int head = 0;
    int tail = 0;
    explicit queue(int n) {
        a.resize(n);
    }
    int pop() {
        int x = a[head];
        head = head + 1;
        return x;
        ;
    }
    void push(int val) {
        a[tail] = val;
        tail = tail + 1;
    }
};
 
int main() {
    ifstream fin("queue.in");
    ofstream fout("queue.out");
    long n;
    fin >> n;
    char com;
    long mean;
    queue a(n);
    for (int i = 0; i < n; i++) {
        fin >> com;
        if (com == '+') {
            fin >> mean;
            a.push(mean);
        }
        else {
            if (a.head != a.tail) {
                fout << a.pop() << endl;
            }
        }
    }
    fin.close();
    fout.close();
    return 0;
}
