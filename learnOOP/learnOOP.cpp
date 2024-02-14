#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    multiset<int> set;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        set.insert(num);
    }

    for (int i = 0; i < m; i++) {
        set.insert(80);
    }

    int min = *set.begin();
    for (auto it = set.begin(); it != set.end(); ++it) {
        if (*it < min) {
            min = *it;
        }
    }

    cout << min;

    return 0;
}