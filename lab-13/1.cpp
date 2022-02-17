#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
vector<int> find(std::string & t, std::string & p) {
    vector<int> ans;
    unsigned long t_size = t.length();
    unsigned long p_size = p.length();
    if (t_size < p_size){
        swap(t_size, p_size);
        swap(t, p);
    }
    for (int i = 0; i <= t_size - p_size; ++i) {
        string temp;
        for (int j = i; j <= i + p_size - 1; ++j)
            temp.push_back(t[j]);
        if (temp == p)
            ans.push_back(i);
    }
    return ans;
}
int main() {
    freopen("search1.in", "r", stdin);
    freopen("search1.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    string t, p;
    cin >> p >> t;
    vector<int> ans = find(t, p);
    cout << ans.size() << std::endl;
    for (auto &i:ans) {
        cout << i + 1 << " ";
    }
    return 0;
}
