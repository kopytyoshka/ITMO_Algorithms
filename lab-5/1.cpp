#include <fstream>
 
struct Node {
    int key;
    std::size_t height = 1;
    Node* parent = nullptr;
};
 
Node *node;
 
int main() {
    std::ifstream fin("height.in");
    std::ofstream fout("height.out");
 
    std::size_t N;
    fin >> N;
    node = new Node[N];
 
    std::size_t left_son;
    std::size_t right_son;
    std::size_t tree_height = 0;
 
    for (int i = 0; i < N; ++i) {
        fin >> node->key >> left_son >> right_son;
 
        if (left_son != 0) {
            node[left_son - 1].parent = &node[i];
        }
        if (right_son != 0) {
            node[right_son - 1].parent = &node[i];
        }
 
        if (node[i].parent != nullptr) {
            node[i].height = node[i].parent->height + 1;
        }
        if (node[i].height > tree_height) {
            tree_height = node[i].height;
        }
    }
 
    fout << tree_height;
 
    fin.close();
    fout.close();
 
    return 0;
}
