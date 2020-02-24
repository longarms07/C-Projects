#include <iostream>
#include <cassert>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

class check{
    private:
        list<int> transactions;
        int totalAmount;
    public:
        check(){
            transactions = {};
            totalAmount = 0;
        }

        check(int initTransaction){
            transactions = {initTransaction,};
            totalAmount = initTransaction;
        }

        void add_item(int amount){
            transactions.push_back(amount);
            totalAmount+=amount;
        }

        int total(){
            return totalAmount;
        }

        list<int> getTransactions(){
            return transactions;
        }
};

int main(){
    cout << "Welcome to your digital checkbook!\n";
    check checkbook = check();
    while(true){
        cout << "Type in 'PAY' to make a transaction, 'TOTAL' to view your current total spent, or 'QUIT' to close this program.\n";
        string input;
        cin >> input;
        transform(input.begin(), input.end(), input.begin(), ::toupper); //performs toupper on each char in the string
        if(input == "PAY"){
            cout << "Type in how much you will be paying.\n";
            int payment = 0;
            cin >> payment;
            if(!cin){
                cin.clear();
                cout << "Error! You did not type in a number.\n";
                cin >> input;
            }
            else
                checkbook.add_item(payment);
        }
        else if (input == "TOTAL")
        {
            cout << "Total amount spent: " << checkbook.total() << '\n';
        }
        else if(input == "QUIT"){
            exit(0);
        }
        else{
            cout << "Input " << input << " not recognized. Please try again.\n";
        }
    }

}