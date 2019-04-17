#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "input N : ";
    cin >> n;

    for (int i=1; i<10; i++)
    {
        cout << n << " * " << i << " = " << n*i << endl;
    }
}