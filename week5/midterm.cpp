#include <iostream>
#include <iomanip>
#include <cctype>
#include <chrono>
#include <string>
#include <vector>
#include <random>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

using namespace std;

struct Transaction {
    string type;  // "deposit", "withdrawal", "transfer"
    double amount;
    chrono::system_clock::time_point date; //automatically creates a datetime entry for the transaction
};

struct Account {
    string accountNumber;
    string holderName;
    double balance;
    Transaction history[100];
    int transactionCount;
};

void accountInfo(const Account& account);
void transactionHistory(const vector<Account>& accounts);
string generateAccountNumber();
void manageMenu(vector<Account>& accounts);
void createAccount(vector<Account>& accounts);
void deleteAccount(vector<Account>& accounts);
void transactionMenu(vector<Account>& accounts);
string toLower(string search);
void addTransaction(Account& account, string type, double amount);

vector<Account> accounts; // allows a single variable to store an indeterminate number of struct entries

int main(){
    #if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
    #endif

    string choice;
    bool looping = true;

    do {

        cout << "[[[[CRYSTAL LOGIC BANKING]]]]" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Please select an option to continue. Options are not case-sensitive:" << endl;
        cout << "Option 1: Account Manager. To select this option, press 1 or type 'Manager'." << endl;
        cout << "Option 2: Make Transaction. To select this option, press 2 or type 'Transactions'." << endl;
        cout << "Option 3: View Transaction History. To select this option, press 3 or type 'View'." << endl;
        cout << "Option 4: Exit. To select this option, press 4, 0, 'Q', or type 'exit'." << endl;

        getline(cin, choice);

        for (int i = 0; i < choice.length(); i++) {
            if (isalpha(choice[i]))
            choice[i] = tolower(choice[i]);
        }
        if (choice == "1" || choice =="manager"){
            char cont;

            manageMenu(accounts);

            cout << "Would you like to make another selection? y/n: ";
            cin >> cont;
            cin.ignore(1000, '\n');

            if (tolower(cont) == 'y') {
                continue;
            } else {
                break;
            }
        } else if (choice == "2" || choice == "transactions") {
            char cont;

            transactionMenu(accounts);

            cout << "Would you like to make another selection? y/n: ";
            cin >> cont;
            cin.ignore(1000, '\n');

            if (tolower(cont) == 'y') {
                continue;
            } else {
                break;
            }
        } else if (choice == "3" || choice =="view") {
            char cont;

            transactionHistory(accounts);

            cout << "Would you like to make another selection? y/n: ";
            cin >> cont;
            cin.ignore(1000, '\n');

            if (tolower(cont) == 'y') {
                continue;
            } else {
                break;
            }
        } else if (choice == "4" || choice =="q" || choice == "0" || choice == "o" || choice == "exit") {
            cout << "Thank you for using Crystal Logic Banking. Have a nice day!" << endl;
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
            continue;
        }
    } while (looping == true);

}

string generateAccountNumber() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> digitDist(0, 9);

    string id = "";

    for (int i = 0; i < 12; i++) {
        id += char('0' + digitDist(gen));
    }

    while (id == "000000000000") {
        id = "";
        for (int i = 0; i < 12; i++) {
            id += char('0' + digitDist(gen));
        }
    }

    return id;
}

void accountInfo(const Account& account) {
    cout << "Account Number: " << account.accountNumber << endl;
    cout << "Account Holder: " << account.holderName << endl;
    cout << "Current Balance: " << account.balance << endl;
    cout << "Recent Transactions: " << endl;

    if (account.transactionCount == 0) {
        cout << "No recent transactions." << endl;
    } else {
        int results = 0;
        for (int i = account.transactionCount - 1; i >= 0 && results < 5; i--) {
            cout << "Type: " << account.history[i].type
                << ", Amount: " << account.history[i].amount << endl;
            results++;
        }
    }

    cout << "Transaction Count: " << account.transactionCount << endl;
}

void transactionHistory(const vector<Account>& accounts) {
    string searchName;
    string nameSearch;

    cout << "Please enter the name of the account holder: ";
    getline(cin, searchName);

    nameSearch = toLower(searchName);
    bool found = false;

    for (int i = 0; i < accounts.size(); i++) {
        if (toLower(accounts[i].holderName) == nameSearch) {
            found = true;

            cout << "Account found for " << accounts[i].holderName<< ". Displaying " << accounts[i].transactionCount << " transactions." << endl;

            if (accounts[i].transactionCount == 0) {
                cout << "No transactions found." << endl;
            } else {
                for (int x = accounts[i].transactionCount - 1; x >= 0; x--) {
                    cout << "Type: " << accounts[i].history[x].type << ", Amount: " << accounts[i].history[x].amount << endl;
                }
            }

            break;
        }
    }

    if (!found) {
        cout << "No account found under that name." << endl;
    }
}

void manageMenu(vector<Account>& accounts) {
    string subchoice;
    bool accCont = true;

    do{
        cout << "Thank you for choosing our account manager! Would you like to create, delete, or view an account?" << endl;
        cout << "To create an account, press 1 or type 'create'." << endl;
        cout << "To view account details, such as balance, account number, and recent transactions, press 2 or type 'account'." << endl;
        cout << "To delete an account, type 00 or 'delete account'. This may only be done if account balance is empty." << endl;
        cout << "To return to the main menu, please press 7." << endl;

        getline(cin, subchoice);

        for (int i = 0; i < subchoice.length(); i++) {
            if (isalpha(subchoice[i]))
            subchoice[i] = tolower(subchoice[i]);
        }

        if (subchoice == "1" || subchoice =="create"){ 
            createAccount(accounts);
        } else if (subchoice == "2" || subchoice == "account") {
            string searchName;
            string nameSearch;
            cout << "Please enter the name of the account holder: ";
            getline(cin, searchName);

            nameSearch = toLower(searchName);
            bool found = false;

            for (int i = 0; i < accounts.size(); i++) {
                if (toLower(accounts[i].holderName) == nameSearch) {
                    accountInfo(accounts[i]);
                    found = true;
                    break;
                }
            }

            if (!found) {
            cout << "No account found under that name." << endl;
            }    
        } else if (subchoice == "00" || subchoice == "delete account") {
            deleteAccount(accounts);
        } else if (subchoice == "7") {
            cout << "Returning to main menu." << endl;
            break;
        } else {
            cout << "Invalid option. Please try again.";
            continue;
        }
    } while (accCont == true);
}

void createAccount(vector<Account>& accounts) { //new accounts will have no transaction history, so that field will be left empty
    Account newAccount;

    cout << "Please enter the name of the account holder: ";
    getline(cin, newAccount.holderName);

    newAccount.accountNumber = generateAccountNumber(); //account numbers should not be manually entered

    cout << "Please enter account balance: " << endl;
    cin >> newAccount.balance;
    cin.ignore(1000, '\n');

    newAccount.transactionCount = 0;

    accounts.push_back(newAccount); //adds the new account to the vector

    cout << "New account successfully created for " << newAccount.holderName << "." << endl;
    cout << "Account number: " << newAccount.accountNumber << endl;
    cout << "Starting balance: $" << newAccount.balance << endl; 
}

void deleteAccount(vector<Account>& accounts) {
    string deleting;
    string deleteSearch;
    bool found = false;
    int foundIndex = -1;

    cout << "Please enter the name of the account holder: ";
    getline(cin, deleting);

    deleteSearch = toLower(deleting);

    for (int i = 0; i < accounts.size(); i++) {
        if (toLower(accounts[i].holderName) == deleteSearch) {
            found = true;
            foundIndex = i;
            break;
        }
    }

    if (!found) {
        cout << "No account found under that name." << endl;
        return;
    }

    if (accounts[foundIndex].balance != 0) {
        cout << "Cannot delete active accounts. Please move or withdraw all funds and try again." << endl;
        return;
    }

    string confirmNumber;
    cout << "Account found for " << accounts[foundIndex].holderName << "." << endl;
    cout << "To confirm deletion, please enter the account number: ";
    getline(cin, confirmNumber);

    if (confirmNumber == accounts[foundIndex].accountNumber) {
        cout << "Account " << accounts[foundIndex].accountNumber << " deleted successfully." << endl;
        accounts.erase(accounts.begin() + foundIndex);
    } else {
        cout << "Account number did not match. Deletion cancelled." << endl;
    }
}

void transactionMenu(vector<Account>& accounts) {
    string searchName;
    string searchNumber;
    string nameSearch;
    bool found = false;
    int foundIndex = -1;

    cout << "Please enter the name of the account holder: ";
    getline(cin, searchName);

    cout << "Please enter the account number: ";
    getline(cin, searchNumber);

    nameSearch = toLower(searchName);

    for (int i = 0; i < accounts.size(); i++) {
        if (toLower(accounts[i].holderName) == nameSearch &&
            accounts[i].accountNumber == searchNumber) {
            found = true;
            foundIndex = i;
            break;
        }
    }

    if (!found) {
        cout << "No account found with that holder name and account number." << endl;
        return;
    }

    string transChoice;

    cout << "Account found for " << accounts[foundIndex].holderName << "." << endl;
    cout << "Please select a transaction type:" << endl;
    cout << "Press 1 or type 'deposit' to make a deposit." << endl;
    cout << "Press 2 or type 'withdraw' to make a withdrawal." << endl;
    cout << "Press 3 or type 'transfer' to transfer funds." << endl;
    cout << "Press 7 to return to the main menu." << endl;

    getline(cin, transChoice);

    for (int i = 0; i < transChoice.length(); i++) {
        if (isalpha(transChoice[i])) {
            transChoice[i] = tolower(transChoice[i]);
        }
    }

    if (transChoice == "1" || transChoice == "deposit") {
        double amount;

        cout << "Enter deposit amount: ";
        cin >> amount;
        cin.ignore(1000, '\n');

        if (amount <= 0) {
            cout << "Invalid amount." << endl;
            return;
        }

        accounts[foundIndex].balance += amount;
        addTransaction(accounts[foundIndex], "deposit", amount);

        cout << "Deposit successful." << endl;
        cout << "New balance: $" << accounts[foundIndex].balance << endl;

    } else if (transChoice == "2" || transChoice == "withdraw") {
        double amount;

        cout << "Enter withdrawal amount: ";
        cin >> amount;
        cin.ignore(1000, '\n');

        if (amount <= 0) {
            cout << "Invalid amount." << endl;
            return;
        }

        if (amount > accounts[foundIndex].balance) {
            cout << "Insufficient funds." << endl;
            return;
        }

        accounts[foundIndex].balance -= amount;
        addTransaction(accounts[foundIndex], "withdrawal", amount);

        cout << "Withdrawal successful." << endl;
        cout << "New balance: $" << accounts[foundIndex].balance << endl;

    } else if (transChoice == "3" || transChoice == "transfer") {
        string recipientName;
        string recipientNumber;
        string recipientSearch;
        bool recipientFound = false;
        int recipientIndex = -1;
        double amount;

        cout << "Please enter the recipient account holder name: ";
        getline(cin, recipientName);

        cout << "Please enter the recipient account number: ";
        getline(cin, recipientNumber);

        recipientSearch = toLower(recipientName);

        for (int i = 0; i < accounts.size(); i++) {
            if (toLower(accounts[i].holderName) == recipientSearch &&
                accounts[i].accountNumber == recipientNumber) {
                recipientFound = true;
                recipientIndex = i;
                break;
            }
        }

        if (!recipientFound) {
            cout << "Recipient account not found." << endl;
            return;
        }

        if (recipientIndex == foundIndex) {
            cout << "Cannot transfer to the same account." << endl;
            return;
        }

        cout << "Enter transfer amount: ";
        cin >> amount;
        cin.ignore(1000, '\n');

        if (amount <= 0) {
            cout << "Invalid amount." << endl;
            return;
        }

        if (amount > accounts[foundIndex].balance) {
            cout << "Insufficient funds." << endl;
            return;
        }

        accounts[foundIndex].balance -= amount;
        accounts[recipientIndex].balance += amount;

        addTransaction(accounts[foundIndex], "transfer", amount);
        addTransaction(accounts[recipientIndex], "deposit", amount);

        cout << "Transfer successful." << endl;
        cout << "New balance: $" << accounts[foundIndex].balance << endl;

    } else if (transChoice == "7") {
        cout << "Returning to main menu." << endl;
        return;

    } else {
        cout << "Invalid transaction option." << endl;
        return;
    }
}

string toLower(string search) {
    for (int i = 0; i < search.length(); i++) {
        if (isalpha(search[i])) {
            search[i] = tolower(search[i]);
        }
    }
        return search;
}

void addTransaction(Account& account, string type, double amount) {
    if (account.transactionCount >= 100) {
        for (int i = 1; i < 100; i++) {
            account.history[i - 1] = account.history[i];
        }
        account.transactionCount = 99;
    }

    account.history[account.transactionCount].type = type;
    account.history[account.transactionCount].amount = amount;
    account.history[account.transactionCount].date = chrono::system_clock::now();
    account.transactionCount++;
}