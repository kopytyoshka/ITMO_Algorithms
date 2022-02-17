#include <vector>
#include <fstream>
 
using namespace std;
 
struct stack {
    vector<char> arr;
    int size = 0;
    explicit stack(int n) {
        arr.resize(n);
    }
    char top() {
        return arr[size];
    }
    bool empty() {
        return size == 0;
    }
    void push(char val) {
        arr[++size] = val;
    }
    char pop() {
        return arr[size--];
    }
};
 
char inverse(char bracket) {
    if (bracket == '[')
        return ']';
    if (bracket == '(')
        return ')';
}
 
bool check_brackets(string line) {
    stack arr(line.size());
 
    for (auto & bracket : line) {
        if (bracket == '(' || bracket == '[')
            arr.push(bracket);
        else if (bracket == inverse(arr.top()) && !arr.empty())
            arr.pop();
        else
            return false;
    }
 
    return arr.empty();
}
 
int main() {
    ifstream fin("brackets.in");
    ofstream fout("brackets.out");
 
    string line;
    while (fin >> line)
    {
        if (check_brackets(line) == true) {
            fout << "YES" << endl;
        } else {
            fout << "NO" << endl;
        }
    }
 
    return 0;
}
