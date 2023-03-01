/******************************************************************************

Bank Account

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "banco.h"


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
            int choice1 = 0;
            int flag = 0;
            int i = 0;
            while(flag == 0){
                system("clear");
                printf("Enter an account number: \n");
                scanf("%i",&accNum);
                
                
                for(; i < numOfAccounts; i++){
                    if(accounts[i].accountNum == accNum){
                        printf("You are logged-in!\n");
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    printf("There is no such account number!\n");
                    system("sleep 2");
                }
                printf("Welcome %s to your account\n\nChoose the operation you want to perform:\n1. Deposit\n2. Withdraw\n3. Check Balance\n", accounts[i].accountHolder);
                scanf("%i", &choice1);
                
                switch(choice1){
                    case 1:
                    int depositAmount = 0;
                    printf("How much money do you want to deposit?\n");
                    scanf("%i", &depositAmount);
                    deposit(&accounts[i], depositAmount);
                    break;
                    
                    case 2:
                    int withdrawAmount = 0;
                    printf("How much money do you want to withdraw?\n");
                    scanf("%i", &withdrawAmount);
                    withdraw(&accounts[i], withdrawAmount);
                    break;
                    
                    case 3:
                    printf("Balance of %s: %.2f \n", accounts[i].accountHolder, accounts[i].accountBalance);
                    break;
                }
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










