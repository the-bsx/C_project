#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 20
#define MAX_CONTACT_LENGTH 15
#define MAX_ADDRESS_LENGTH 100
#define MAX_EMAIL_LENGTH 50
#define MAX_PARENTS_NAME_LENGTH 100

// Structure to represent a bank account
typedef struct {
    int account_number;
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    float balance;
    char contact_number[MAX_CONTACT_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char dob[11]; // Date of Birth (YYYY-MM-DD)
    char email[MAX_EMAIL_LENGTH];
    char parents_name[MAX_PARENTS_NAME_LENGTH];
} Account;

// Global variables
Account accounts[MAX_USERS];
int num_accounts = 0;

// Function prototypes
void createAccount();
void login();
void deposit();
void transfer();

// Function to display a decorative line of stars
void printStarsLine() {
    printf("*************************************************************\n");
}

// Function to display a decorative line of stars with centered text
void printCenteredStarsLine(char *text) {
    int text_length = strlen(text);
    int num_stars = (60 - text_length) / 2;
    printf("*************************************************************\n");
    printf("%*s%s%*s\n", num_stars, "", text, num_stars, "");
    printf("*************************************************************\n");
}

// Function to create a new bank account
void createAccount() {
    system("cls");
    printCenteredStarsLine("Create New Account");

    Account new_account;
    printf("Enter account number: ");
    scanf("%d", &new_account.account_number);
    printf("Enter first name: ");
    scanf("%s", new_account.first_name);
    printf("Enter last name: ");
    scanf("%s", new_account.last_name);
    printf("Enter password: ");
    scanf("%s", new_account.password);
    printf("Enter contact number: ");
    scanf("%s", new_account.contact_number);
    printf("Enter address: ");
    scanf(" %[^\n]", new_account.address);
    printf("Enter date of birth (YYYY-MM-DD): ");
    scanf("%s", new_account.dob);
    printf("Enter email: ");
    scanf("%s", new_account.email);
    printf("Enter parents' name: ");
    scanf(" %[^\n]", new_account.parents_name);
    new_account.balance = 0.0;
    accounts[num_accounts++] = new_account;
    printf("\nAccount created successfully.\n");
    printStarsLine();
    printf("Press Enter to continue...\n");
    getchar();
    getchar();
    system("cls");
}
// Function to login and view account details
void login() {
    system("cls");
    printCenteredStarsLine("Login");
    int account_number,i;
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your account number: ");
    scanf("%d", &account_number);
    for ( i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter your password: ");
            scanf("%s", password);
            if (strcmp(accounts[i].password, password) == 0) {
                printf("\nWelcome, %s %s!\n", accounts[i].first_name, accounts[i].last_name);
                printf("Account Number: %d\n", accounts[i].account_number);
                printf("First Name: %s\n", accounts[i].first_name);
                printf("Last Name: %s\n", accounts[i].last_name);
                printf("Contact Number: %s\n", accounts[i].contact_number);
                printf("Address: %s\n", accounts[i].address);
                printf("Date of Birth: %s\n", accounts[i].dob);
                printf("Email: %s\n", accounts[i].email);
                printf("Parents' Name: %s\n", accounts[i].parents_name);
                printf("Balance: $%.2f\n", accounts[i].balance);
                printStarsLine();
                printf("Press Enter to continue...\n");
                getchar();
                getchar();
                system("cls");
                return;
            } else {
                printf("Incorrect password.\n");
                printStarsLine();
                printf("Press Enter to continue...\n");
                getchar();
                getchar();
                system("cls");
                return;
            }
        }
    }
    printf("Account not found.\n");
    printStarsLine();
    printf("Press Enter to continue...\n");
    getchar();
    getchar();
    system("cls");
}


// Function to deposit money into an account
void deposit() {
    system("cls");
    printCenteredStarsLine("Deposit");
    int account_number,i;
    float amount;
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your account number: ");
    scanf("%d", &account_number);
    for ( i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter your password: ");
            scanf("%s", password);
            if (strcmp(accounts[i].password, password) == 0) {
                printf("Enter amount to deposit: $");
                scanf("%f", &amount);
                accounts[i].balance += amount;
                printf("Amount deposited successfully.\n");
                printf("New balance: $%.2f\n", accounts[i].balance);
                printStarsLine();
                printf("Press Enter to continue...\n");
                getchar();
                getchar();
                system("cls");
                return;
            } else {
                printf("Incorrect password.\n");
                printStarsLine();
                printf("Press Enter to continue...\n");
                getchar();
                getchar();
                system("cls");
                return;
            }
        }
    }
    printf("Account not found.\n");
    printStarsLine();
    printf("Press Enter to continue...\n");
    getchar();
    getchar();
    system("cls");
}

// Function to transfer money to another user
void transfer() {
    system("cls");
    printCenteredStarsLine("Transfer Money");
    int from_account, to_account,i,j;
    float amount;
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your account number: ");
    scanf("%d", &from_account);
    for ( i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == from_account) {
            printf("Enter your password: ");
            scanf("%s", password);
            if (strcmp(accounts[i].password, password) == 0) {
                printf("Enter recipient's account number: ");
                scanf("%d", &to_account);
                for ( j = 0; j < num_accounts; j++) {
                    if (accounts[j].account_number == to_account) {
                        printf("Enter amount to transfer: $");
                        scanf("%f", &amount);
                        if (accounts[i].balance >= amount) {
                            accounts[i].balance -= amount;
                            accounts[j].balance += amount;
                            printf("Amount transferred successfully.\n");
                            printf("New balance: $%.2f\n", accounts[i].balance);
                            printStarsLine();
                            printf("Press Enter to continue...\n");
                            getchar();
                            getchar();
                            system("cls");
                            return;
                        } else {
                            printf("Insufficient balance.\n");
                            printStarsLine();
                            printf("Press Enter to continue...\n");
                            getchar();
                            getchar();
                            system("cls");
                            return;
                        }
                    }
                }
                printf("Recipient's account not found.\n");
                printStarsLine();
                printf("Press Enter to continue...\n");
                getchar();
                getchar();
                system("cls");
                return;
            } else {
                printf("Incorrect password.\n");
                printStarsLine();
                printf("Press Enter to continue...\n");
                getchar();
                getchar();
                system("cls");
                return;
            }
        }
    }
    printf("Account not found.\n");
    printStarsLine();
    printf("Press Enter to continue...\n");
    getchar();
    getchar();
    system("cls");
}

// Main function
int main() {
    int choice;
    do {
        system("cls");
        printCenteredStarsLine("Bank System Menu");
        printf("1. Create Account\n");
        printf("2. Login and View Account Details\n");
        printf("3. Deposit\n");
        printf("4. Transfer Money\n");
        printf("5. Exit\n");
        printStarsLine();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                login();
                break;
            case 3:
                deposit();
                break;
            case 4:
                transfer();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                printf("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
        }
    } while (1);
    return 0;
}

