#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N))
        return 0;

    vector<long long> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    long long ans = 0;
    map<long long, int> freq;

    for (int i = 0; i < N; i++)
    {

        for (int k = 1; k <= 31; k++)
        {
            long long target = 1LL << k;
            long long complement = target - A[i];

            if (freq.count(complement))
            {
                ans += freq[complement];
            }
        }
        freq[A[i]]++;
    }

    cout << ans << endl;

    return 0;
}