#include <iostream>
//#include <ctime>
using namespace std;

void outputPyramid(int n, int k);

int main(void)
{
    int t;
    int n, k;

    cin >> t;

    for(int i=0; i<t; i++)
    {
        cin >> n >> k;
        //lock_t start = clock();
        outputPyramid(n, k);
        //cout << clock() - start <<endl;
    }

    return 0;
}

void outputPyramid(int n, int k)
{
    for(int i=0; i<n; i++)
    {       
        if(i + 1 == k)
        {
            int sum = i + 1;
            cout << sum;

            for(int j=0; j<i; j++)
            {
                sum = sum + n - (j + 1);
                cout << "*" << sum;
            }
            cout << "\n";

            break;
        }
        else
        {
            continue;
        }
        
    }
}