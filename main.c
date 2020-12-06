#include "myBank.h"
#include <ctype.h>
#include <stdio.h>

bool resumeProgram = true;

int main(){
    while (resumeProgram){
        char input;
        printf("\nPlease choose a transaction type:\n");
        printf(" O-Open Account\n");
        printf(" B-Balance Inquiry\n");
        printf(" D-Deposit\n");
        printf(" W-Withdrawal\n");
        printf(" C-Close Account\n");
        printf(" I-Interest\n");
        printf(" P-Print\n");
        printf(" E-Exit\n");
        scanf(" %c", &input);
        switch (input){

            case 'O':{
                double amount;
                printf("Please enter amount for deposit: ");
                if (!isValidAmount(amount, scanf("%lf", &amount)))
                break;

            openAccount(amount);
            break;  
            }
             case 'B':
        {
            int account_number;
            printf("Please enter account number: ");
            scanf("%d", &account_number);
            account_number = getBankAccountAndCheck(account_number);
            if (account_number == -1)
                break;

            checkBalance(account_number);
            break;
        }
        case 'D':
        {
            int account_number;
            printf("Enter account number: ");
            scanf("%d", &account_number);

           if (isalpha(account_number))
           {
               printf("Invalid account number \n");
            break;
           }
            
            
            account_number = getBankAccountAndCheck(account_number);
            if (account_number == -1)
                break;
            double amount;
            printf("Enter amount to deposit: \n");
            if (!isValidAmount(amount, scanf("%lf", &amount)))
                break;

            deposit(account_number, amount);
            break;
        }
        case 'W':
        {
            int account_number;
            printf("Enter account number:\n");
            scanf("%d", &account_number);
            account_number = getBankAccountAndCheck(account_number);
            if (account_number == -1)
                break;
            double amount;
            printf("Enter amount to withdraw: \n");
            if (!isValidAmount(amount, scanf("%lf", &amount)))
                break;

            withdraw(account_number, amount);
            break;
        }
        case 'C':
        {
            int account_number;
            printf("Enter account number:\n");
            scanf("%d", &account_number);
            account_number = getBankAccountAndCheck(account_number);
            if (account_number == -1)
                break;

            closeAccount(account_number);
            break;
        }
        case 'I':
        {
            int interest_rate;
            printf("Enter interest rate: \n");
            if (!isValidAmount(interest_rate, scanf("%d", &interest_rate)))
                break;

            addInterest(interest_rate);
            break;
        }
        case 'P':
            printAccounts();
            break;
        case 'E':
            closeBank();
            resumeProgram = false;
            break;
        default:
            printf("Invalid transaction type\n");
            break;
        }
    }
    if (!resumeProgram)
        return 0;
}
