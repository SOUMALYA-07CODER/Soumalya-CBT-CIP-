#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct 
{
    int accountNumber;
    char accountType[10]; 
    char accountHolderName[50];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount();
void deposit();
void withdraw();
void checkBalance();
void calculateInterest();
void displayMenu();

int main() 
{
    int choice;
    
    while (1) 
	{
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
		{
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                calculateInterest();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() 
{
    printf("\n=== Bank Account Management System ===\n");
    printf("1. Create a new account\n");
    printf("2. Deposit funds\n");
    printf("3. Withdraw funds\n");
    printf("4. Check balance\n");
    printf("5. Calculate interest\n");
    printf("6. Exit\n");
}

void createAccount() 
{
    if (accountCount >= MAX_ACCOUNTS)
	{
        printf("Account limit reached. Cannot create more accounts.\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1;
    
    printf("Enter account holder name: ");
    scanf("%s", newAccount.accountHolderName);
    
    printf("Enter account type (Savings/Current): ");
    scanf("%s", newAccount.accountType);
    
    newAccount.balance = 0.0; 
    
    accounts[accountCount] = newAccount;
    accountCount++;
    
    printf("Account created successfully! Your account number is %d.\n", newAccount.accountNumber);
}

void deposit() 
{
    int accNumber;
    double amount;
    
    printf("Enter account number: ");
    scanf("%d", &accNumber);
    
    if (accNumber < 1 || accNumber > accountCount) 
	{
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    
    if (amount <= 0) 
	{
    	
        printf("Invalid amount. Deposit amount must be positive.\n");
        return;
    }
    
    accounts[accNumber - 1].balance += amount;
    printf("Amount deposited successfully. New balance: %.2lf\n", accounts[accNumber - 1].balance);
}

void withdraw() 
{
    int accNumber;
    double amount;
    
    printf("Enter account number: ");
    scanf("%d", &accNumber);
    
    if (accNumber < 1 || accNumber > accountCount) 
	{
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);
    
    if (amount <= 0) 
	{
        printf("Invalid amount. Withdrawal amount must be positive.\n");
        return;
    }
    
    if (accounts[accNumber - 1].balance < amount) 
	{
        printf("Insufficient balance.\n");
        return;
    }
    
    accounts[accNumber - 1].balance -= amount;
    printf("Amount withdrawn successfully. New balance: %.2lf\n", accounts[accNumber - 1].balance);
}

void checkBalance() 
{
    int accNumber;
    
    printf("Enter account number: ");
    scanf("%d", &accNumber);
    
    if (accNumber < 1 || accNumber > accountCount) 
	{
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Account holder: %s\n", accounts[accNumber - 1].accountHolderName);
    printf("Account type: %s\n", accounts[accNumber - 1].accountType);
    printf("Current balance: %.2lf\n", accounts[accNumber - 1].balance);
}

void calculateInterest() 
{
    int accNumber;
    double interestRate, interest;
    
    printf("Enter account number: ");
    scanf("%d", &accNumber);
    
    if (accNumber < 1 || accNumber > accountCount) 
	{
        printf("Invalid account number.\n");
        return;
    }
    
    if (strcmp(accounts[accNumber - 1].accountType, "Savings") == 0) 
	{
        interestRate = 0.04; // 4% interest for Savings
    } else if (strcmp(accounts[accNumber - 1].accountType, "Current") == 0) 
	{
        interestRate = 0.02; // 2% interest for Current
    } else {
        printf("Invalid account type.\n");
        return;
    }
    
    interest = accounts[accNumber - 1].balance * interestRate;
    printf("Calculated interest for account number %d is: %.2lf\n", accNumber, interest);
}
