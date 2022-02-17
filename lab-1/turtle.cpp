#include <fstream>
#include <iostream>
 
using namespace std;
 
int main()
{
    int h, w;
    ifstream fin("turtle.in");
    ofstream fout("turtle.out");
    fin >> h >> w;
    int arr[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++){
            fin >> arr[i][j];
        }
    }
    for (int i = h - 1; i >= 0; i--){
        for (int j = 0; j < w; j++){
            int goleft = 0; int godown = 0;
            if (j != 0) goleft = arr[i][j-1];
            if (i != h - 1) godown = arr[i+1][j];
            if (goleft > godown) arr[i][j] += goleft;
            else arr[i][j] += godown;
        }
    }
    fout << arr[0][w-1];
    fin.close();
    fout.close();
 
    return 0;
}
