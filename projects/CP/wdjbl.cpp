#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a[n];
    long long count = 0;

    // Read the array
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Calculate the minimum number of moves
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            count += (a[i - 1] - a[i]);
            a[i] = a[i - 1]; // Increase a[i] to make the array non-decreasing
        }
    }

    cout << count << endl;
    return 0;
}
