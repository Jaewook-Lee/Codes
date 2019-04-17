#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool card;
    int cash;
    string answer;
    string cardInput;

    cout << "Do you have credit card?\t";
    cin >> cardInput;

    if (cardInput == "yes")
        card = true;
    else
        card = false;

    cout << "How many cahses do you have?\t";
    cin >> cash;

    if (card || cash >= 4000)
        answer = "Cafeteria";
    else if (cash >= 3000)
        answer = "Convenience store";
    else
        answer = "Bakery";

    cout << answer << endl;

    return 0;
}