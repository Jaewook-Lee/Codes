#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 20;
    unsigned int inputs[SIZE];
    int min_value, min_idx;

    /*for (int i=0; i<SIZE; i++)
    {
        cout << "Write down grade :\t";
        cin >> inputs[i];
        if (i == 0)
        {
            min_value = inputs[i];
            min_idx = i;
        }
        else
        {
            if (inputs[i] < min_value)
            {
                min_value = inputs[i];
                min_idx = i;
            }
        }
    }
    cout << "You are F, No. " << min_idx << endl;*/

    for (int i=0; i<SIZE; i++)
    {
        cout << "Write down grade :\t";
        cin >> inputs[i];
    }

    min_value = inputs[0];
    for (int i=1; i<SIZE; i++)
    {
        if (inputs[i] < min_value)
        {
            min_value = inputs[i];
            min_idx = i;
        }
    }
    cout << "You are F, No. " << min_idx << endl;
    return 0;
}