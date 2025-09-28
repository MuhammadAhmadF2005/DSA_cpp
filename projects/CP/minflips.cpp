#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int pos = 0;
        int neg = 0;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            if (arr[i] == 1)
            {
                pos++;
            }
            else if (arr[i] == -1)
            {
                neg++;
            }
        }
        if (n % 2 != 0)
        {
            cout << "-1" << endl;
        }
        else
            (abs(pos > neg));

        cout << (pos - neg) / 2 << endl;
    }
}
