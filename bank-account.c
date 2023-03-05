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
    int accNum = 0;
    while(true){
        
        int choice = 0;
        printf("Welcome to the Deez Bank\n1. Create an account\n2. Saved accounts\n3. Log in \n4. Exit\n");
        scanf("%i", &choice);
        
        switch(choice){
            case 1:
                char *name = (char*)malloc(sizeof(char)*100);
                int type;
                char *accType = (char*)malloc(sizeof(char)*20);
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
                printf("%i", i);
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
                system("clear");
                int accountIndex = -1;
                printf("Please enter your Account number: \n");
                scanf("%i", &accNum);
                
                for(int j = 0; j < numOfAccounts; j++){
                    if(accounts[j].accountNum == accNum){
                        accountIndex = j;
                        printf("You are logged-in!\n\n");
                    }
                }
                if(accountIndex == -1){
                    printf("There is no such account number!\n");
                    break;
                }
                
                printf("Welcome %s to your account\n", accounts[accountIndex].accountHolder);
                int choice1 = 0;
                while(true){
                    printf("Choose the operation you want to perform:\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Log-out\n");
                    scanf("%i", &choice1);
                    switch(choice1){
                        case 1:
                            int depositAmount = 0;
                            printf("Enter the amount you want to deposit: ");
                            scanf("%d", &depositAmount);
                            deposit(&accounts[accountIndex], depositAmount);
                        break;
                        
                        case 2:
                            int withdrawAmount;
                            printf("Enter the amount you want to withdraw: ");
                            scanf("%d", &withdrawAmount);
                            withdraw(&accounts[accountIndex], withdrawAmount);
                        break;
                        
                        case 3:
                            printf("Your current balance is: %.2lf \n", accounts[accountIndex].accountBalance);
                        break;
                        
                        case 4:
                        break;
                            
                        default:
                            printf("Please enter a valid number\n");
                        break;
                    }
                    if(choice1 == 4)
                        break;
                }
                break;
            case 4:
                return 0;
            default:
                system("clear");
                printf("Enter a number from 1 to 4\n\n");
                break;
        }
    }
    for(int j = 0; j < numOfAccounts; j++){
        free(accounts[j].accountHolder);
        free(accounts[j].accountType);
    }
    
    return 0;
}

void deposit(struct bank_account *account, double toDeposit){
    account->accountBalance += toDeposit;
}

void withdraw(struct bank_account *account, double toWithdraw){
    if(toWithdraw <= account->accountBalance) {
        account->accountBalance -= toWithdraw;
    } else {
        printf("Insufficient funds\n");
    }
}

struct bank_account createAccount(char *accountHolder, char *accountType){
        struct bank_account newAccount;
        newAccount.accountNum = rand()%100+100;
        newAccount.accountBalance = 0;
        newAccount.accountHolder = accountHolder;
        newAccount.accountType = accountType;
        
        return newAccount;
}