#include "myBank.h"


double accounts[ROWS][COLUMNS] = {{0, 0}};

const int FIRST_ACCOUNT_NUMBER = 901;
const int LAST_ACCOUNT_NUMBER = 950;


void openAccount(double amount){

     for (int i = 0; i < ROWS; i++)
    {
        if (accounts[i][BANK_STATUS] == BANK_STATUS_CLOSED)
        {
            accounts[i][BANK_BALANCE] = floor(100 * amount) / 100;
            accounts[i][BANK_STATUS] = BANK_STATUS_OPEN;
            printf("New account number is: %d\n", FIRST_ACCOUNT_NUMBER + i);
            return;
        }
    }
    printf("All of the bank accounts are open\n");
}



void checkBalance(int account_number)
{
    printf("The balance of account number %d is: %0.2lf\n",account_number+FIRST_ACCOUNT_NUMBER, accounts[account_number][BANK_BALANCE]);
}



void deposit(int account_number, double amount)
{
    accounts[account_number][BANK_BALANCE] += floor(100 * amount) / 100;
    printf("New balance of your account is: %f\n", accounts[account_number][BANK_BALANCE]);
}



void withdraw(int account_number, double amount)
{
    if (accounts[account_number][BANK_BALANCE] >= amount)
    {
        accounts[account_number][BANK_BALANCE] -= floor(100 * amount) / 100;
        printf("New balance of your account is: %f\n", accounts[account_number][BANK_BALANCE]);
    }
    else
    {
        printf("You don't have enough money\n");
    }
}



void closeAccount(int account_number)
{
    accounts[account_number][BANK_STATUS] = BANK_STATUS_CLOSED;
    accounts[account_number][BANK_BALANCE] = 0;
    printf("The account is closed\n");
}



void addInterest(int interest_rate)
{
    for (int i = 0; i < ROWS; i++)
    {
        if (accounts[i][BANK_STATUS] == BANK_STATUS_OPEN)
        {
            double percentage = (interest_rate / 100.0) + 1;
            accounts[i][BANK_BALANCE] = floor(100 * accounts[i][BANK_BALANCE] * percentage) / 100;
        }
    }
}



void printAccounts()
{
    for (int i = 0; i < ROWS; i++)
    {
        if (accounts[i][BANK_STATUS] == BANK_STATUS_OPEN)
        {
            printf("Account number: %d, Balance is: %lf\n", FIRST_ACCOUNT_NUMBER + i, accounts[i][BANK_BALANCE]);
        }
    }
}



void closeBank()
{
    for (int i = 0; i < ROWS; i++)
    {
        accounts[i][BANK_STATUS] = BANK_STATUS_CLOSED;
        accounts[i][BANK_BALANCE] = 0;
    }
}



int getBankAccountAndCheck(int account_number)
{
    
    if (account_number < FIRST_ACCOUNT_NUMBER || account_number > LAST_ACCOUNT_NUMBER)
    {
        printf("Failed to read the account number\n");
        //printf("Account number must be between %d and %d\n", FIRST_ACCOUNT_NUMBER, LAST_ACCOUNT_NUMBER);
        return -1;
    }
    if (accounts[account_number - FIRST_ACCOUNT_NUMBER][BANK_STATUS] == BANK_STATUS_CLOSED)
    {
        printf("This account is closed\n");
        return -1;
    }

    else
    {
        return account_number - FIRST_ACCOUNT_NUMBER;
    }
}



bool isValidAmount(double amount, int scanfVal)
{
    if (scanfVal != 1)
    {
        printf("Failed to read the amount\n");
        return false;
    }
    
    if (amount < 0 )
    {
        printf("Cannot deposit a negative amount\n");
        return false;
    }
    else
        return true;
}