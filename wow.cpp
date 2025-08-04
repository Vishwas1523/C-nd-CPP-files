#include <iostream>
using namespace std;

class BankAccount
{
private:
    long long balance;

public:
    BankAccount()
    {
        balance = 10000000;
        cout << "Your initial balance is: " << balance << endl;
    }
    void deposit(long long amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited successfully." << endl;
            cout << "New balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }
    void withdraw(long long amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful." << endl;
            cout << "New balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }
    long long getBalance()
    {
        return balance;
    }
};

int main()
{
    BankAccount myAccount;

    int choice;
    long long amount;

    cout << "\nWhat do you want to do:\n";
    cout << "1) Deposit\n";
    cout << "2) Withdraw\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter amount to deposit: ";
        cin >> amount;
        myAccount.deposit(amount);
        break;
    case 2:
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        myAccount.withdraw(amount);
        break;
    default:
        cout << "Invalid option selected!" << endl;
        break;
    }

    return 0;
}