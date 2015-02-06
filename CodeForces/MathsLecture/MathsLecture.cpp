#include <iostream>
#include <cmath>

int main(int, char**) {
    using namespace std;
    int n, k, m;

    cin >> n;
    cin >> k;
    cin >> m;

    cout << n << " " << k << " " << m << endl;

    // A number of range  10**(n - 1) to 10**n
    // whose suffix mod k = 0
    // outputed mod m

    // naive
    int count;
    for (int i = pow(10, n - 1); i < pow(10, n); ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if ((i / pow(10, j)) % k == 0) {
                ++count;
            }
        }
    }
    return count % k;


}
