#include <iostream>

using namespace std;

// This function calculates the new balance after adding the deposit amount.
double calculateDeposit(double balance, double amount){
   balance += amount;
   return balance;
}

// This function calculates the new balance after a withdrawal from the bank account.
double calculateWithdrawal(double balance, double amount){
   balance -= amount;
   return balance;
}

// This function returns the new annual interest rate.
double changeInterestRate(double annualInterestRate){
   cout << "Enter new annual interest rate: ";
   cin >> annualInterestRate;
   return annualInterestRate;
}

// This function calculates the monthly compound interest.
double calculateInterest(double balance, double annualInterestRate, int monthsNum){
   for(int i = 0; i < monthsNum; i++){
      balance *= 1 + annualInterestRate / 1200;
   }
   return balance;
}

// This program offers options for the user to manage a bank account.
int main() 
{
   int choice = 0, monthsNum;
   double balance, annualInterestRate, amount;
   // Get the initial balance and annual interest rate from the user.
   cout << "Enter your balance: ";
   cin >> balance;
   cout << "Enter your annual interest rate: ";
   cin >> annualInterestRate; 
   cout << endl;
   // Keep showing the menu until the user chooses to close the account.
   while(choice != 5){
      cout << "1. Make a deposit" << endl;
      cout << "2. Make a withdrawal" << endl;
      cout << "3. Change interest rate" << endl;
      cout << "4. Wait" << endl;
      cout << "5. Close account" << endl;
      cout << endl;
      cout << "Enter your choice: ";
      cin >> choice;
      // Check the user's choice and perform the selected operation.
      if(choice == 1){
         cout << "Enter deposit amount: ";
         cin >> amount;
         balance = calculateDeposit(balance, amount);
      }else if(choice == 2){
         cout << "Enter withdrawal amount: ";
         cin >> amount;
         balance = calculateWithdrawal(balance, amount);
      }else if(choice == 3){
         annualInterestRate = changeInterestRate(annualInterestRate);
      }else if(choice == 4){
         cout << "Enter how many months to wait: ";
         cin >> monthsNum;
         balance = calculateInterest(balance, annualInterestRate, monthsNum);
      }else if(choice < 1 || choice > 5){
         cout << "Invalid choice. Please try again." << endl;
      }
      if(choice >= 1 && choice <= 4){
         cout << "Current balance: " << balance << endl;
      }
      cout << endl;
   }
   return 0;
}