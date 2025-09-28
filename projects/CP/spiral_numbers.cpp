#include <iostream>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll r, c;
        cin >> r >> c;

        ll n = max(r, c);
        ll result;

        if (n % 2 == 0)
        {
            // Even layer
            if (r == n)
            {
                result = n * n - (c - 1);
            }
            else
            {
                result = (n - 1) * (n - 1) + r;
            }
        }
        else
        {
            // Odd layer
            if (c == n)
            {
                result = n * n - (r - 1);
            }
            else
            {
                result = (n - 1) * (n - 1) + c;
            }
        }

        cout << result << endl;
    }

    return 0;
}