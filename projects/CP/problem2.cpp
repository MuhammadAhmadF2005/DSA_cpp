#include <iostream>
using namespace std;

long long factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

long long combination(int n, int k)
{
    if (k > n)
        return 0;
    return factorial(n) / (factorial(k) * factorial(n - k));
}

long long power(int base, int exp)
{
    long long result = 1;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}

long long calculateTerm(int n, int r, int x, int y)
{

    long long comb = combination(n, r - 1);
    long long x_power = power(x, n - (r - 1));
    long long y_power = power(y, r - 1);
    return comb * x_power * y_power;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, r, x, y;

        cin >> n;
        cin >> r;
        cin >> x >> y;

        long long result = calculateTerm(n, r, x, y);
        cout << result << endl;
    }

    return 0;
}