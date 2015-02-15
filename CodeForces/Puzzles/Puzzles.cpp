#include <algorithm>
#include <iostream>
#include <vector>

int main(int, char**) {
    using namespace std;

    int children, puzzles;
    cin >> children;
    cin >> puzzles;

    vector<int>& pieces = *( new vector<int>(puzzles) );

    for (int i = 0; i < puzzles; ++i) {
        cin >> pieces[i];
    }

    sort(pieces.begin(), pieces.end());

    for (std::vector<int>::const_iterator i = pieces.begin(); i != pieces.end(); ++i) {
        cout << *i << ' ';
    }
}
