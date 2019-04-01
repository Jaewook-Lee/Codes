#include <iostream>
using namespace std;

int numberOfZero(int array[], int n);

int main(void)
{
    int t;
    int n;

    cin >> t;

    for(int i=0; i<t; i++)
    {
        cin >> n;

        int num_array[n];
        for(int j=0; j<n; j++)
        {
            cin >> num_array[j];
        }
        cout << numberOfZero(num_array, n) << endl;
    }
}

int numberOfZero(int array[], int n)
{
    double mul = 1;
    int count = 0;

    for (int i=0; i<n; i++)
    {
        mul *= array[i];
    }

    while (mul % 10 == 0)
    {
        count++;
        mul /= 10;
    }

    return count;
}