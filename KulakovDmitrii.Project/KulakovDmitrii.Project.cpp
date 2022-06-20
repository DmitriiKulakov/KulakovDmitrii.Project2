//Name: Kulakov Dmitrii
//Project#2

#include <iostream>
#include <cstring>
using namespace std;

const int MAX_CUSTOMERS = 100;
const int MAX_ACCOUNTS = 5;
const int MIN_BALANCE = 1000;

int numberOfCustomers(int);

struct account //structure for accounts
{
    int number;
    char type;
    double balance;
};

struct customer //structure for accounts
{
    char name[40];
    char address[50];
    char ID[10];
    int numOfAccounts;
    account accounts[MAX_ACCOUNTS];
};

void withdrawAmount(customer data[], int s, char name[], char id[], double amount) //This function is not working correctly
{
    int num, Amount=amount;
    for (int i = 0; i < s; i++)
    {
        if (!strcmp(data[i].ID, id)&&!strcmp(data[i].name,name))
        {            
            
                cout << "From what account do you want to withdraw money(enter the number): "<<endl;

                for (int j = 0;j < data[i].numOfAccounts;j++)
                {
                    cout << data[i].accounts[j].number << endl; //displays accounts numbers
                }

                cout << "Enter your choice: ";
                cin >> num; 

                for (int j = 0;j < data[i].numOfAccounts;j++) //loop to check accounts
                {
                    if (data[i].accounts[j].number==num)   
                    { 
                        if (data[i].accounts[j].balance < Amount) //if balance smaller than amount
                        {
                                    cout << "Don't have enough money, you have: " << data[i].accounts[j].balance << endl
                                        << " Please enter again the amount: ";
                                    cin >> Amount;
                        }
                        else if (data[i].accounts[j].type == 'm' && data[i].accounts[j].balance - Amount < 1000) //if subtraction from the balance the amount and it is smaller than 1000 you need to enter again the amount
                        {
                                    cout << "You cannot do this due to type of your account should have minimum 1000, you have " << data[i].accounts[j].balance << endl
                                        << " Please enter again the amount: ";
                                    cin >> Amount;
                        }
                        data[i].accounts[j].balance = data[i].accounts[j].balance - Amount; //subtraction from the account balance
                    }
                }
        }
    }
}

int search(customer data[], int s, char id[]) //function to find customer
{
    for (int i = 0; i < s; i++)
    {
        if (!strcmp(data[i].ID, id)) //returns true if same id
        {
            return i;
        }
    }
    return -1;
}

void deleteCustomer(customer data[], int& s, char id[]) //function to delete customer(working correctly)
{
    int pos = search(data, s, id); //call the function search
    if (pos == -1)
    {
        cout << "Customer with ID: " << id << " is not in the database";
    }
    else
    {
        s--;
        for (int i = pos; i < s; i++) //for loop to change the data from the forward places to behind
        {
            strcpy_s(data[i].name, data[i + 1].name); //copies name
            strcpy_s(data[i].ID, data[i + 1].ID); //copies ID
            strcpy_s(data[i].address, data[i + 1].address); //copies address
            for (int j = 0;j < data[i + 1].numOfAccounts;j++) //for loop to change the data in accounts
            {
                data[i].accounts[j] = data[i + 1].accounts[j]; //copies all in structure accounts
            }
        }
        cout << "Customer with ID: " << id << " is deleted"<<endl;
    }
}

void openNewAccount(customer data[], int s, char name[], char id[]) //opens a new account
{
    int j = 1;

    for (int i = 0; i < s; i++)
    {
        if (!strcmp(data[i].ID, id) && !strcmp(data[i].name, name)) //checks the id and the name
        {
            if (data[i].numOfAccounts < 5) //check if places for accountes are available
            {
                for (int g = data[i].numOfAccounts-1;g < data[i].numOfAccounts;g++) 
                {
                    do{
                    
                        cout << "Enter the account number for the " << j << " account: ";
                    
                        cin >> data[i].accounts[g].number; 
                    
                        cout << "Enter the balance for the " << j << " account: ";
                    
                        cin >> data[i].accounts[g].balance;
                     
                        cout << "Enter the type for the " << j << " account(checking, savings, money market- enter first letter of type): ";
                        cin >> data[i].accounts[g].type;

                        if (data[i].accounts[g].type == 'm' && data[i].accounts[g].balance < MIN_BALANCE) //check the balance and account type
                        {
                            cout << "You can't choose this type of account due to amount(minimum balance is 1000)" << endl;
                        }
                    } while (data[i].accounts[g].type != 'c' && data[i].accounts[g].type != 's' && data[i].accounts[g].type != 'm' || (data[i].accounts[g].type == 'm' && data[i].accounts[g].balance < MIN_BALANCE)); //check if user entered wrong letter
                    j++;
                }
            }
          
        }

    }
}

void openAccounts(customer data[],int s,char name[],char id[]) //opens several accounts
{
    int j = 1;

    for (int i = 0; i < s; i++)
    {
        if (!strcmp(data[i].ID, id)&&!strcmp(data[i].name, name)) //checks the id and the name
        {
            for (int g = 0;g < data[i].numOfAccounts;g++)
            {
                do {

                
                
                    cout << "Enter the account number for the " << j << " account: ";
                
                    cin >> data[i].accounts[g].number;

                
                    cout << "Enter the balance for the " << j << " account: ";
                
                    cin >> data[i].accounts[g].balance;
                
                    cout << "Enter the type for the " << j << " account(checking, savings, money market- enter first letter of type): ";
                    cin >> data[i].accounts[g].type;
                    
                    if (data[i].accounts[g].type == 'm'&& data[i].accounts[g].balance< MIN_BALANCE)
                    {
                        cout << "You can't choose this type of account due to amount(minimum balance is 1000)"<<endl;
                    }
                } while (data[i].accounts[g].type != 'c' && data[i].accounts[g].type != 's' && data[i].accounts[g].type != 'm' || (data[i].accounts[g].type == 'm' && data[i].accounts[g].balance < MIN_BALANCE));
                j++;
            }
        }

    }
}

void customerDetails(customer data[], int s, char id[]) //print customer details
{
    for (int i = 0; i < s; i++)
    {
        if (!strcmp(data[i].ID, id))
        {
            cout << data[i].name << endl;
            cout << data[i].ID << endl;
            cout << data[i].address << endl;
            cout << data[i].numOfAccounts << endl;
            for (int j = 0;j < data[i].numOfAccounts;j++)
            {
                cout << data[i].accounts[j].number << endl;
                cout << data[i].accounts[j].balance << endl;
                cout << data[i].accounts[j].type << endl;
            }
        }
        
    }
}

void accountHolderDetailes(customer data[], int s, int num) //prints details about customer of this account
{
    for (int i = 0; i < s; i++)
    {
        for (int j = 0;j < data[i].numOfAccounts;i++)
        {
            if (data[i].accounts[j].number==num)
            {
                cout << data[i].name << endl;
                cout << data[i].ID << endl;
                cout << data[i].address << endl;
                cout << data[i].numOfAccounts << endl;
            }
        }
    }
}

int numberOfCustomers(int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        j++;
    }
    return j;
}

int findCustomer(customer data[], int s, char id[]) //searching customer by id
{
    for (int i = 0; i < s; i++)
    {
        if (!strcmp(data[i].ID, id))
        {
            return 1;
        }
    }
    return 0;
}

void readCustomer(customer& data, customer Data[], int s) //Function is not finished due to don't have check on ID
{
    cin.ignore();
    cout << "Enter the name: ";
    cin.getline(data.name, 40);
    
    cout << "Enter the address: ";
    cin.getline(data.address, 50);
    
    cout << "Enter the ID: ";
    cin >> data.ID; 
    
    do {
        cout << "Enter the how many accounts do you want to create(max 5 accounts): ";
        cin >> data.numOfAccounts;
    } while (data.numOfAccounts > 5 || data.numOfAccounts < 0); //check how much accounts customer want to creat

    openAccounts(Data, s, data.name, data.ID);
}

int main()
{
    int counter = 1;
    customer customers[MAX_CUSTOMERS];
    account accounts[MAX_ACCOUNTS];
    char name[100], id[100];
    int accountNumber;
    int size = 0;
    double amount;
    int choice;
    do {
        do {
            cout << "MENU" << endl
                << "1) Read a customer" << endl
                << "2) Return the number of customers" << endl
                << "3) Find a customer" << endl
                << "4) Print Account holder details" << endl
                << "5) Print Customer details" << endl
                << "6) Open a new account" << endl
                << "7) Delete customer" << endl
                << "8) Withdraw amount" << endl
                << "9) Exit" << endl;
            cout << "Enter the choice: ";
            cin >> choice;
        } while (choice < 1 && choice>12);

        switch (choice)
        {
        case 1:
            if (size < MAX_CUSTOMERS) 
            {
                readCustomer(customers[size++],customers, size); //is not finished due to don't have check on what id user entered
            }
            else
            {
                cout << "Memory is full" << endl;
            }
            break;
        case 2:
            cout <<"Number of accounts is "<<numberOfCustomers(size)<<endl;
            break;
        case 3:
            cout << "Please enter ID: ";
            cin >> id;
            
            if (findCustomer(customers, size, id) == 1)
            {
                cout << "Customer found" << endl;
            }
            else
            {
                cout << "Customer not found" << endl;
            }
            break;
        case 4:
            cout << "Enter the account number: ";
            cin >> accountNumber;
            accountHolderDetailes(customers, size, accountNumber);
            break;
        case 5:
            cout << "Enter the ID: ";
            cin >> id;
            customerDetails(customers, size, id);
            break;
        case 6:
            cout << "Enter the name: ";
            cin >> name;
            cout << "Enter the ID: ";
            cin >> id;
            openNewAccount(customers, size, name, id); //is not finished due to don't have check on what number of account user entered
            break;
        case 7:
            cout << "Enter the ID : ";
            cin >> id;
            deleteCustomer(customers, size, id); 
            break;
        case 8:
            cout << "Enter the name: ";
            cin >> name;
            cout << "Enter the ID: ";
            cin >> id;
            cout << "Enter the amount: ";
            cin >> amount;
            withdrawAmount(customers, size, name, id, amount); //is not finished 
            break;
        default:
            cout << "Good bye!"<<endl;
        }
    } while (choice != 12);

    for (int i = 0; i < size; i++) //check what is in the structure
    {
        cout<<"Name:" << customers[i].name << endl;
        cout <<"ID:" << customers[i].ID << endl;
        cout <<"Address:" << customers[i].address << endl;
        cout <<"number Of Accounts" << customers[i].numOfAccounts << endl;
        for (int j = 0;j < customers[i].numOfAccounts;j++)
        {
            cout <<"Account "<<counter<< ": number" << customers[i].accounts[j].number << endl;
            cout << "Account " << counter << ": balance" << customers[i].accounts[j].balance<<endl;
            cout << "Account " << counter << ": type" << customers[i].accounts[j].type<<endl;
        }
    }
    
    return 0;
}