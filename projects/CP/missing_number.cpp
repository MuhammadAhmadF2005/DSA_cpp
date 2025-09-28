#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;

    int sum1 = (n * (n + 1)) / 2;
    int sum2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int num;
        cin >> num;
        sum2 += num;
    }
    int missing_num = sum1 - sum2;
    cout << missing_num << endl;
    return 0;
}