#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define ROWS 50
#define COLUMNS 2
#define BANK_STATUS 0
#define BANK_BALANCE 1
#define BANK_STATUS_CLOSED 0
#define BANK_STATUS_OPEN 1

void openAccount(double amount);
void checkBalance(int account_number);
void deposit(int account_number, double amount);
void withdraw(int account_number, double amount);
void closeAccount(int account_number);
void addInterest(int interest_rate);
void printAccounts();
void closeBank();
int getBankAccountAndCheck(int account_number);
bool isValidAmount(double amount, int scanfVal);
bool isValidInterest(int amount, int scanfVal);
