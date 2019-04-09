#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a number -> ";
    int num;
    cin >> num;

    if (num >= 0)
    {
        cout << "Unsigned!" << endl;

        switch (num)
        {
            case 1:
                cout << "Number 1" << endl;
                break;

            case 2:
                cout << "Number 2" << endl;
                break;

            default:
                cout << "Maybe more than 2?" << endl;
                break;
        }
    }
    else
        cout << "Signed!" << endl;
    
}