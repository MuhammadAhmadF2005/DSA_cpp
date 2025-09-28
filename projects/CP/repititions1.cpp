#include <iostream>
using namespace std;
int main()
{
    string dna;
    cin >> dna;

    int maxlength = 1;
    int currentlength = 1;

    for (int i = 1; i < dna.length(); i++)
    {
        currentlength = 1;
        while (dna[i] == dna[i - 1] && i < dna.length())
        {
            currentlength++;
            i++;
        }
        maxlength = max(maxlength, currentlength);
    }

    cout << maxlength << endl;

    return 0;
}