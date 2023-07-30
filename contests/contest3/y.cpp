#include <iostream>
#include <vector>

using namespace std;

void solve() {
    
    int count = 0;
    vector<vector<char>> a(3, vector<char>(3));


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    }

    bool ans = false;
    if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] != '.') {
        cout << a[0][0] << endl;
        ans = true;
    }

    if (!ans && a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[1][1] != '.') {
        cout << a[1][1] << endl;
        ans = true;
    }

    for (int i = 0; i < 3; i++) {
        if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] != '.') {
            cout << a[i][0] << endl;
            ans = true;
            break;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] != '.') {
            cout << a[0][i] << endl;
            ans = true;
            break;
        }
    }

    if (!ans)
        cout << "DRAW" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t) {
        solve();
        t--;
    }
    return 0;
}
