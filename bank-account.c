/******************************************************************************

Bank Account

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

struct bank_account {
    int accountNum;
    double accountBalance;
    char *accountHolder;
    char *accountType;
};

void deposit(struct bank_account *account, double toDeposit);

void withdraw(struct bank_account *account, double toWithdraw);

struct bank_account createAccount(char *accountHolder, char *accountType);

int main()
{
    srand(time(NULL));
    struct bank_account accounts[10];
    int i = 0;
    int numOfAccounts = 0; //this variable will increase everytime you create a new account
    while(true){
        
        int choice = 0;
        printf("Welcome to the Deez Bank\n1. Create an account\n2. Saved accounts\n3. Log in \n4. Exit\n");
        scanf("%i", &choice);
        
        switch(choice){
            case 1:
            int nameSize, typeSize;
                char name[100];
                int type;
                char accType[20];
                system("clear");
                printf("Enter a name: ");
                scanf("%s", name);
                printf("Choose your account type: \n1. Saving account\n2. Checking account\n");
                scanf("%i", &type);
                    if(type == 1)
                        strcpy(accType, "Saving account");
                    else if(type == 2)
                        strcpy(accType, "Checking account");
                    else
                        printf("Please enter a valid number");
                        
                accounts[i] = createAccount(name, accType);
                i++;
                numOfAccounts++;
                system("clear");
                break;
            case 2:
                system("clear");
                printf("You got all of this accounts for the moment (%i saved): \n\n", numOfAccounts);
                for(int j = 0; j < numOfAccounts; j++){
                    printf(" Account Number: %i\n Account Holder: %s\n Account Type: %s\n\n",accounts[j].accountNum, accounts[j].accountHolder, accounts[j].accountType);
                }
                break;
            case 3:
            
                break;
            case 4:
                return 0;
            default:
                system("clear");
                printf("Enter a number from 1 to 4\n\n");
                break;
        }
    }
    
    
    return 0;
}

void deposit(struct bank_account *account, double toDeposit){
    account->accountBalance += toDeposit;
}

void withdraw(struct bank_account *account, double toWithdraw){
    if(account->accountBalance >= 0)
        account->accountBalance -= toWithdraw;
    else
        printf("Insufficent funds");
}

struct bank_account createAccount(char *accountHolder, char *accountType){
        struct bank_account newAccount;
        newAccount.accountNum = rand()%100+100;
        newAccount.accountBalance = 0;
        newAccount.accountHolder = accountHolder;
        newAccount.accountType = accountType;
        
        return newAccount;
}







