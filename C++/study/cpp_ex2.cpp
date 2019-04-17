#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number :\t";
    cin >> n;

    for (int i=2; i<=n; i+=2)
    {
        cout << i << " ";
    }
    cout << endl;
}