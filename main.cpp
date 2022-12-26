#include <iostream>
using namespace std;
int bin_tree[200000][4];

int find_height(int i) {
    int height_left, height_right;
    if (bin_tree[i][1] == 0) height_left = 0;
    if (bin_tree[i][1] != 0) {
        find_height(bin_tree[i][1]-1);
        height_left = bin_tree[bin_tree[i][1]-1][3];
    }
    if (bin_tree[i][2] == 0) height_right = 0;
    if (bin_tree[i][2] != 0) {
        find_height(bin_tree[i][2]-1);
        height_right = bin_tree[bin_tree[i][2]-1][3];
    }
    bin_tree[i][3] += max(height_left, height_right);
    return 0;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> bin_tree[i][0] >> bin_tree[i][1] >> bin_tree[i][2]; bin_tree[i][3] = 1;
    }
    find_height(0);
    for (int i = 0; i < n; i++) {
        cout << (bin_tree[bin_tree[i][2]-1][3] - bin_tree[bin_tree[i][1]-1][3]) << "\n"; //diff_height
    }
    return 0;
}
