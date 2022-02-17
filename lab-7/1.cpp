#include <iostream>
#include <fstream>
 
using namespace std;
 
struct Node
{
    int key;
    int right;
    int left;
    int difference;
};
 
int TreeGo(Node *array, int pointer, int heightCounter)
{
    int leftHeight = 0;
    int rightHeight = 0;
 
    if (array[pointer].left != 0)
    {
        leftHeight = TreeGo(array, array[pointer].left, heightCounter);
    }
 
    leftHeight++;
 
    if (array[pointer].right != 0)
    {
        rightHeight = TreeGo(array, array[pointer].right, heightCounter);
    }
 
    rightHeight++;
 
    if(leftHeight > rightHeight)
        heightCounter = leftHeight;
 
    else if(leftHeight < rightHeight)
        heightCounter = rightHeight;
 
    else if (leftHeight == rightHeight && leftHeight != 0)
        heightCounter = leftHeight;
 
    array[pointer].difference = rightHeight - leftHeight;
 
    return heightCounter;
}
 
int main()
{
    int amount;
    int counter1 = 1;
 
    ifstream fin("balance.in");
    ofstream fout("balance.out");
 
    fin >> amount;
 
    if(amount == 0 || amount == 1)
    {
        fout << "0";
        return 0;
    }
 
    Node *array = new Node [amount + 1];
 
    for(int i = 1; i < amount + 1; i++)
    {
        fin >> array[i].key;
        fin >> array[i].left;
        fin >> array[i].right;
 
        if (array[i].left == 1 || array[i].right == 1)
            counter1 = i;
    }
 
    TreeGo(array, counter1, 1);
 
    for(int j = 1; j <= amount; j++)
    {
        fout << array[j].difference << endl;
    }
 
    return 0;
}
