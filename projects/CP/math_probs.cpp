#include <bits/stdc++.h>
#define ll long long
#define vi vector<ll>
#define vll vector<long long>
using namespace std;
int main()
{
    // prog to find out the 10,001st prime number
    ll n = 10001;
    vll primes = {2};
    for (ll i = 3; i <= n; i += 2)
    {
        bool isprime = true;
        for (ll j = 0; j < primes.size(); j++)
        {
            if (i % primes[j] == 0)
            {
                isprime = false;
                break;
            }
        }

        if (isprime)
        {
            primes.push_back(i);
        }

        cout << primes[n - 1];
    }

    return 0;
}