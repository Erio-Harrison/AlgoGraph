#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> solutions;
vector<int> solution;
vector<int> state;

void dfs(int current, int n) {
    if (current == n) {
        solutions.push_back(solution);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!state[i]) {
            solution[current] = i;
            state[i] = 1;
            dfs(current + 1, n);
            state[i] = 0;
        }
    }
}

void solveNumbers(int n) {
    solution = vector<int>(n, 0);
    state = vector<int>(n, 0);
    dfs(0, n);
}
int main() {
    int n;
    cout << "Enter the number of numbers: ";
    cin >> n;
    solveNumbers(n);
    for (vector<int> solution: solutions) {
        for (int i: solution) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}