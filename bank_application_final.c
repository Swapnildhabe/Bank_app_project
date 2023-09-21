#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a bank account
struct Account {
    int accountNum;
    char name[50];
    double balance;
};

// Function to create a new account
struct Account createAccount(int accountNum, const char *name, double initialBalance) {
    struct Account account;
    account.accountNum = accountNum;
    strcpy(account.name, name);
    account.balance = initialBalance;
    return account;
}

// Function to display account information
void displayAccount(struct Account account) {
    printf("Account Number: %d\n", account.accountNum);
    printf("Account Holder: %s\n", account.name);
    printf("Balance: %.2lf\n", account.balance);
}

int main() {
    // Assuming a fixed number of accounts for simplicity
    printf("****Welcome To \"PSV\" Nagpur Digital Bank****");
    const int maxAccounts = 10;
    struct Account accounts[maxAccounts];
    int numAccounts = 0;

    int choice;
    int dInAccountIndex = -1;

    do {
        printf("\nMenu:\n");
        printf("1. Create New Account\n");
        printf("2. Login\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Display Account Information\n");
        printf("6. Logout\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Create New Account
                if (numAccounts < maxAccounts) {
                    int accountNum;
                    char name[50];
                    double initialBalance;

                    accountNum = rand()%100 + 10;
                    printf("Your Account Number is : %d\n",accountNum);
                    // scanf("%d", &accountNum);

                    printf("Enter Account Holder's Name: ");
                    scanf("%s", name);
                    AMOUNT:
                    printf("Enter Initial Balance: ");
                    scanf("%lf", &initialBalance);
                    
                     // Here Check minimun 500Rs balacne.
                    if(initialBalance <=500 )
                    {
                        printf("minimum balance 500 required.\n");
                        printf("Enter amount again \n");
                        goto AMOUNT;
                    }

                    accounts[numAccounts] = createAccount(accountNum, name, initialBalance);
                    numAccounts++;
                    printf("Account created successfully!\n");
                } else {
                    printf("Maximum number of accounts reached.\n");
                }
                
                break;

            case 2: // Login
                if (dInAccountIndex == -1) {
                    int accountNum;
                    printf("Enter Account Number: ");
                    scanf("%d", &accountNum);

                    for (int i = 0; i < numAccounts; i++) {
                        if (accounts[i].accountNum == accountNum) {
                            dInAccountIndex = i;
                            printf("Logged in Succesfull!! Welcome -->> %s\n", accounts[i].name);
                            printf("Check The Menu Option ::\n\n");
                            printf("---------------------------------------------");
                            
                            break;
                        }
                    }

                    if (dInAccountIndex == -1) {
                        printf("Account not found.\n");
                    }
                } else {
                    printf("You are already logged in.\n");
                }
                break;

            case 3: // Deposit
                if (dInAccountIndex != -1) {
                    double amount;
                    printf("Enter the amount to deposit: ");
                    scanf("%lf", &amount);
                    accounts[dInAccountIndex].balance += amount;
                    printf("Deposit successful!\n");
                } else {
                    printf("Please login first.\n");
                }
                break;

            case 4: // Withdraw
                if (dInAccountIndex != -1) {
                    double amount;
                    printf("Enter the amount to withdraw: ");
                    scanf("%lf", &amount);
                    if (accounts[dInAccountIndex].balance >= amount) {
                        accounts[dInAccountIndex].balance -= amount;
                        printf("Withdrawal successful!\n");
                    } else {
                        printf("\nInsufficient balance!!!\n");
                       
                    }
                } else {
                    printf("Please login first.\n");
                }
                break;

            case 5: // Display Account Information
                if (dInAccountIndex != -1) {
                    displayAccount(accounts[dInAccountIndex]);
                } else {
                    printf("Please login first.\n");
                }
                break;

            case 6: // Logout
                dInAccountIndex = -1;
                printf("Logged out.\n");
                break;

            case 0: // Exit
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

