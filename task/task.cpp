#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<int> symmetric_difference(set<int> set1, set<int> set2) {
    set<int> resultSet;

    set_difference(set1.begin(), set1.end(),
        set2.begin(), set2.end(),
        inserter(resultSet, resultSet.begin()));

    set_difference(set2.begin(), set2.end(),
        set1.begin(), set1.end(),
        inserter(resultSet, resultSet.begin()));

    return resultSet;
}

int main() {
    setlocale(LC_ALL, "ru");

    set<int> set1{ 0, 1, 2, 4 };
    set<int> set2{ 1, 2, 3, 5 };
    set<int> resultSet = symmetric_difference(set1, set2);

    cout << "set1: ";
    for (auto i = set1.cbegin(); i != set1.cend(); ++i) {
        cout << *i << " ";
    }
    cout << endl;

    cout << "set2: ";
    for (auto i = set2.cbegin(); i != set2.cend(); ++i) {
        cout << *i << " ";
    }
    cout << endl;

    cout << "resultSet: ";
    for (auto i = resultSet.cbegin(); i != resultSet.cend(); ++i) {
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}
