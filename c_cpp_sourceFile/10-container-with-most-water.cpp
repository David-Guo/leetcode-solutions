#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int> & height) {
    size_t i, j, max = 0;
    size_t area;
    for (i = 0; i < height.size() - 1; i++)
        for (j = i + 1; j < height.size(); j++) {

}

int main () {
    int input[5] = {1, 2, 3, 4, 5};
    vector<int> v;
    for (int i = 0; i < 5; i++)
        v.push_back(input[i]);
    cout << maxArea(v) << endl;
}
