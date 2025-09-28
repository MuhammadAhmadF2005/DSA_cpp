#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n, a, b;
        int k = log2(n);
        int ans = k * a + (k - 1) * b;
        cout << ans << endl;
    }
}
