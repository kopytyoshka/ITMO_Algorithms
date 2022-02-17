#include <fstream>
#include <vector>
 
using namespace std;
 
int bin_right(vector<int> & arr, int x) {
    int l = 0;
    int r = arr.size();
 
    while (l < r) {
        int mid = (l + r) / 2;
        if (x < arr[mid]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return arr[l - 1] == x ? l : -1;
}
 
int bin_left(vector<int> & arr, int x) {
    int l = 0;
    int r = arr.size();
 
    while (l < r) {
        int mid = (l + r) / 2;
        if (x <= arr[mid]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return arr[l] == x ? l + 1 : -1;
}
 
int main() {
    ifstream fin("binsearch.in");
    ofstream fout("binsearch.out");
 
    int n, m;
    fin >> n;
    vector<int> arr(n);
 
    for (int i = 0; i < n; ++i) {
        fin >> arr[i];
    }
 
    fin >> m;
 
    for (int i = 0; i < m; ++i) {
        int x = 0;
        fin >> x;
        int leftest = bin_left(arr, x);
        int rightest = bin_right(arr, x);
        fout << leftest << " " << rightest << endl;
    }
}
