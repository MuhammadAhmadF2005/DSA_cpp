#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a[n];
    long long count = 0;
    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            count += (a[i - 1] - a[i]);
            a[i] = a[i - 1];
        }
    }

    cout << count << endl;

    return 0;
}