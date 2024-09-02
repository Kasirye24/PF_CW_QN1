#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

struct Account
{
    string username;
    string password;
    double balance = 0.0;
};

void renderSecondOption(Account &account)
{
    string loggedInOption;
    while (true)
    {
        cout << "d -> Deposit Money" << endl;
        cout << "w -> Withdraw Money" << endl;
        cout << "r -> Request Balance" << endl;
        cout << "q -> Quit" << endl;
        cout << "Enter: ";
        cin >> loggedInOption;

        if (loggedInOption == "d")
        {
            double depositAmount;
            cout << "Amount to deposit: ";
            cin >> depositAmount;
            account.balance += depositAmount;
        }
        else if (loggedInOption == "w")
        {
            double withdrawAmount;
            cout << "Enter amount to withdraw: ";
            cin >> withdrawAmount;
            if (withdrawAmount > account.balance)
            {
                cout << "Insufficient balance!" << endl;
            }
            else
            {
                account.balance -= withdrawAmount;
            }
        }
        else if (loggedInOption == "r")
        {
            cout << "Your bank balance is: $" << account.balance << endl;
        }
        else if (loggedInOption == "q")
        {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Wrong option, please select a correct option!" << endl;
        }
    }
}

void renderFirstOption()
{
    Account account;
    bool loggedIn = false;
    while (true)
    {
        string optionTwo;
        string username;
        string password;
        string option;
        cout << "Hi! Welcome to the ATM Machine!." << endl
             << endl;
        cout << "Please select an option from the menu below: " << endl
             << endl;
        cout << "l -> Login." << endl;
        cout << "c -> Create New Account." << endl;
        cout << "q -> Quit." << endl;
        cout << "Enter: ";
        cin >> option;
        if (option == "l")
        {
            if (!loggedIn)
            {

                cout << "Please enter your user id: ";
                cin >> username;
                cout << "Please enter your password: ";
                cin >> password;
                if (account.username == username && account.password == password)
                {
                    cout << "Access Granted!" << endl
                         << endl;
                    loggedIn = true;
                    renderSecondOption(account);
                }
                else
                {
                    cout << "*** LOGIN FAILED! ***" << endl;
                }
            }
            else
            {
                cout << "You are already logged in!" << endl;
                renderSecondOption(account);
            }
        }
        else if (option == "c")
        {
            cout << "Login" << endl;
            cout << "Please enter your user id: ";
            cin >> username;
            account.username = username;
            cout << "Please enter your password: ";
            cin >> password;
            account.password = password;
            cout << "Thank You! Your account has been created! ";
        }
        else if (option == "q")
        {
            cout << "Exiting the program. Goodbye!" << endl;
            exit(0);
        }
        else
        {
            cout << "Wrong option, please select a correct option!" << endl;
        }
    }
}

int main()
{
    renderFirstOption();

    return 0;
}
