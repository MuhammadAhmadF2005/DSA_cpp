#include <iostream>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (ll k = 1; k <= n; k++)
    {
        ll total = (k * k * (k * k - 1)) / 2;

        ll attack_ways = 4 * (k - 1) * (k - 2);

        ll ans = total - attack_ways;

        cout << ans << endl;
    }

    return 0;
}