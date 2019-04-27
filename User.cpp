#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
#include "User.h"
using namespace std;

User::User()
{
  budget = 0.0;
}

//
// Function to validate date input by user 
bool User::validateDateInput()
{
  int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31}, dd, mm, yy, i;
  if(date.length() != 8)
  {
    cout << "Incompatible length of date input.\n";
    return false;
  }
  for(i=0; i<8; i++)
  {
    if(i == 2 || i == 5)
    {
      if(date[i] != '/')
      {
        cout << "Please use '/' as a seperator in date input.\n";
        return false;
      }
      continue;
    }
    if(! (date[i] >= '0' && date[i] <='9') )
    {
      cout << "Date input accepts numbers only\n";
      return false;
    }
  }
  dd = stoi(date.substr(0,2));
  mm = stoi(date.substr(3,2));
  yy = stoi(date.substr(6,2));
  if(yy < 0 || yy > 19)
  {
    cout << "Year entered is in the future!\n";
    return false;
  }
  if(mm < 0 || mm > 12)
  {
    cout << "Incompatible month value in date input!\n";
    return false;
  }
  if (((yy % 4 == 0) && (yy % 100 != 0)) || (yy % 400 == 0))
    month[2] = 29;
  if(dd < 0 || dd > month[mm])
  {
    cout << "Incompatible day of the month in date input\n";
    return false;
  }
  return true;
}

//
// Function to load values from username.txt into currentUser object
void User::readFromFile()
{
  int pos = 0;
  string word, line;
  double value;
  ifstream fin;
  fin.open((username+".txt").c_str());
  if(fin.fail())
  {
    cout << "Failed to open " << username << ".txt" << endl;
    return;
  }
  fin >> budget;
  fin.ignore();

  pos = 0;
  getline(fin, line);
  for(int i=0; i<line.length(); i++)
  {
    if(line[i] == ' ')
    {
      word = line.substr(pos, (i-pos) );
      accounts.date.push_back(word);
      pos = i+1;
    }
  }
  pos = 0;
  getline(fin, line);
  for(int i=0; i<line.length(); i++)
  {
    if(line[i] == ' ')
    {
      word = line.substr(pos, (i-pos) );
      accounts.type.push_back(word);
      pos = i+1;
    }
  }
  pos = 0;
  getline(fin, line);
  for(int i=0; i<line.length(); i++)
  {
    if(line[i] == ' ')
    {
      word = line.substr(pos, (i-pos) );
      accounts.value.push_back( stof(word) );
      pos = i+1;
    }
  }

  pos = 0;
  getline(fin, line);
  for(int i=0; i<line.length(); i++)
  {
    if(line[i] == ' ')
    {
      word = line.substr(pos, (i-pos) );
      expense.date.push_back(word);
      pos = i+1;
    }
  }
  pos = 0;
  getline(fin, line);
  for(int i=0; i<line.length(); i++)
  {
    if(line[i] == ' ')
    {
      word = line.substr(pos, (i-pos) );
      expense.type.push_back(word);
      pos = i+1;
    }
  }
  pos = 0;
  getline(fin, line);
  for(int i=0; i<line.length(); i++)
  {
    if(line[i] == ' ')
    {
      word = line.substr(pos, (i-pos) );
      expense.value.push_back( stof(word) );
      pos = i+1;
    }
  }

  pos = 0;
  getline(fin, line);
  for(int i=0; i<line.length(); i++)
  {
    if(line[i] == ' ')
    {
      word = line.substr(pos, (i-pos) );
      income.date.push_back(word);
      pos = i+1;
    }
  }
  pos = 0;
  getline(fin, line);
  for(int i=0; i<line.length(); i++)
  {
    if(line[i] == ' ')
    {
      word = line.substr(pos, (i-pos) );
      income.type.push_back(word);
      pos = i+1;
    }
  }
  pos = 0;
  getline(fin, line);
  for(int i=0; i<line.length(); i++)
  {
    if(line[i] == ' ')
    {
      word = line.substr(pos, (i-pos) );
      income.value.push_back( stof(word) );
      pos = i+1;
    }
  }
  fin.close();
}

//
//Function to write updated entries from currentUser object into username.txt
void User::writeToFile()
{
  ofstream fout;
  fout.open((username+".txt").c_str());
  fout << budget << "\n";
  for(int i=0; i<accounts.date.size(); i++){
    fout << accounts.date[i] << " ";
  }
  fout << endl;
  for(int i=0; i<accounts.type.size(); i++){
    fout << accounts.type[i] << " ";
  }
  fout << endl;
  for(int i=0; i<accounts.value.size(); i++){
    fout << accounts.value[i] << " ";
  }
  fout << endl;

  for(int i=0; i<expense.date.size(); i++){
    fout << expense.date[i] << " ";
  }
  fout << endl;
  for(int i=0; i<expense.type.size(); i++){
    fout << expense.type[i] << " ";
  }
  fout << endl;
  for(int i=0; i<expense.value.size(); i++){
    fout << expense.value[i] << " ";
  }
  fout << endl;

  for(int i=0; i<income.date.size(); i++){
    fout << income.date[i] << " ";
  }
  fout << endl;
  for(int i=0; i<income.type.size(); i++){
    fout << income.type[i] << " ";
  }
  fout << endl;
  for(int i=0; i<income.value.size(); i++){
    fout << income.value[i] << " ";
  }
  fout << endl;
}

//
// Function to save changes and exit application
char User::saveChanges()
{
  char yesNo;
  cout << "\nEnter 'Y' to save changes and any other key to discard all changes: ";
  cin >> yesNo;
  if(yesNo=='Y' || yesNo=='y')
    return 'y';
  else
    return 'n';
}

//
// Function to display status of all expenses made by user
void User::display_expense_status()
{
  if(expense.type.size()!=0){
    cout << "\nStatus of all expenses is as follows\n";
  }
  else{
    cout << "No expense record to display! Please create a new expense record first.";
  }
  for(int i=0; i<expense.type.size(); i++)
    cout << i+1 << ". " << expense.date[i] << " " << expense.type[i] << " HK$" << expense.value[i] << endl;
}

//Function to provide user with choice of action in the expense feature
//Input: none
//Output: Expense menu for the user to choose from
void User::expenseMenu()
{
  cout << "\nPlease enter the number next to your preferred option from the menu below. \n\n";
  cout << "*************************************************" << endl;
  cout << "0. Exit to Main Menu." << endl;
  cout << "1. Add an expense." << endl;
  cout << "2. Edit expense." << endl;
  cout << "3. Delete expense." << endl;
  cout << "*************************************************" << endl;
}

//
// Function to manage expense inputs
// Function will also alert in case expenses are 100% of budget
// Input: structure user1
// Output: updated structure user1
//         Conditional Alerts
void User::manageExpense()
{
  cout << "\nWelcome to the Manage Expense screen.\n" << endl;
  if(budget==0){
    cout << "Please set budget using option 4 on the Main Menu below.\n";
    return;
  }
  string newCategory;
  double newExpense;
  int userInput, userChoice, accountChoice;
  double sum=0;
  unsigned int i=0;
  if(accounts.type.size()==0){
    cout << "No Accounts found! Please create an account using option 5 on the previous menu.";
    return;
  }
  else{
    cout << "\nPlease select an account to make a transaction from.\n";
    display_accounts_status();
  }
  cin >> accountChoice;
  if(accountChoice > accounts.type.size())
  {
    cout << "Input integer does not link to any Account. Try again!\n";
    return;
  }
  do
  {
    expenseMenu();
    cin >> userInput;
    switch(userInput)
    {
      case 0 : break;
      case 1 :
        cout << "Please enter ONE WORD to categorise your expense : ";
        cin >> newCategory;
        cout << "Please enter the expense incurred : ";
        cin >> newExpense;
        if(newExpense<0){
          cout << "\nInvalid Expense Value. Try again!\n";
          break;
        }
        if(newExpense > accounts.value[accountChoice-1]){
          cout << "\nNot sufficient balance in account! Try again.\n";
        }
        else{
          expense.type.push_back(newCategory);
          expense.value.push_back(newExpense);
          expense.date.push_back(date);
          
          for(i=0; i<expense.type.size(); i++){
            sum+=expense.value[i];
          }
        
          if(budget-sum ==0){
            cout << "\nBudget limit reached!" << endl;
          }
          else if(budget-sum < 0){
            cout << "\nAlert! Budget has been exceeded by HK$" << sum-budget << endl; 
          }
          
          cout << "\nNew expense has been added!\n";
          accounts.value[accountChoice-1] -= newExpense;
          sum=0;
        }
        break;

      case 2:
        if(expense.type.size() == 0){
          cout << "No expense added! To add an expense choose option 1 from the previous menu.\n";
          }
        else{
          cout << "Please select the number corresponding to the expense you would like to edit.\n";
          for(i=0; i<expense.type.size(); i++){
            cout << i+1 << ". " << expense.type[i] << " HK$" << expense.value[i] << endl;
          }
          
          cin >> userChoice;
          if(userChoice > expense.type.size())
          {
            cout << "Input integer does not link to any expense incurred. Try again!\n";
            break;
          }
          accounts.value[accountChoice-1] += expense.value[userChoice-1];
          cout << "Please enter ONE WORD to update Expense Category : ";
          cin >> newCategory;
          cout << "Please enter updated expense : ";
          cin >> newExpense;
          if(newExpense<0){
            cout << "\nInvalid Expense Value. Try again!\n";
            break;
          }
          if(newExpense > accounts.value[accountChoice-1]){
            cout << "\nNot sufficient balance in account! Try again.\n";
          }
          else{
            sum=newExpense;
            if(expense.type.size() >0){
              for(i=1; i<expense.type.size(); i++){
                sum+=expense.value[i];
              }
            }
            if(budget-sum ==0){
              cout << "\nBudget limit reached!" << endl;
            }
            else if(budget-sum < 0){
              cout << "\nAlert! Budget has been exceeded by HK$" << abs(budget-newExpense) << endl; 
            }
            expense.type[userChoice-1] = newCategory;
            expense.value[userChoice-1] = newExpense;
          }
        }
        accounts.value[accountChoice-1] -= newExpense;
        break;

        case 3:
          if(expense.type.size() == 0){
          cout << "No expense to delete! To add an expense choose option 1 from the previous menu.\n";
          }
        else{
          cout << "Please select the number corresponding to the expense you would like to delete.\n";
          for(i =0; i<expense.type.size(); i++){
            cout << i+1 << ". " << expense.type[i] << " HK$" << expense.value[i] << endl;
          }
          cin >> userChoice;
          if(userChoice > expense.type.size())
          {
            cout << "Input integer does not link to any expense incurred. Try again!\n";
            break;
          }
          accounts.value[accountChoice-1] += expense.value[userChoice-1];
          expense.type.erase(expense.type.begin()+userChoice-1);
          expense.value.erase(expense.value.begin()+userChoice-1);
        }
        break;

    default: cout << "Invalid input. Please choose a number from the menu below. \n";
    }
    display_expense_status();
  } while (userInput!=0);
}

//
// Function to display status of all incomes of by user
void User::display_income_status()
{
  if(income.type.size()!=0){
    cout << "\nStatus of all Income Sources is as follows\n";
  }        
  else{
    cout << "No income record to display! Please create a new income record first.";
  }

  for(int i=0; i<income.type.size(); i++){
    cout << i+1 << ". " << income.date[i] << " " << income.type[i] << " HK$" << income.value[i] << endl;
  }
}

//Function to provide user with choice of action in the income feature
//Input: none
//Output: Income menu for the user to choose from
void User::incomeMenu()
{
  cout << "\nPlease enter the number next to your preferred option from the menu below. \n\n";
  cout << "*************************************************" << endl;
  cout << "0. Exit to Main Menu." << endl;
  cout << "1. New income." << endl;
  cout << "2. Edit income." << endl;
  cout << "3. Delete income." << endl;
  cout << "*************************************************" << endl;
}

//
// Function to manage income inputs
// Input: structure user1
// Output: updated structure user1
void User::manageIncome()
{
  cout << "Welcome to the Income screen.\n";
  double newIncome;
  string newSource;
  unsigned int i=0;
  int userInput, choice, accountChoice;
  bool append = false;
  if(accounts.type.size()==0){
    cout << "No Accounts found! Please create an account using option 5 on the previous menu.";
    return;
  }
  else{
    cout << "\nPlease select an account to make transaction to.\n";
    display_accounts_status();
  }
  cin >> accountChoice;
  if(accountChoice > accounts.type.size())
  {
    cout << "Input integer does not link to any Account. Try again!\n";
    return;
  }
  do
  {
    incomeMenu();
    cin >> userInput;
    switch(userInput)
    {
      case 0: break;
      case 1: 
        cout << "Please enter ONE WORD to categorise Income : " ;
        cin >> newSource;
        cout << "Please input Income amount : ";
        cin >> newIncome;
        if(newIncome<0){
          cout << "\nInvalid Income Value. Try again!\n";
          break;
        }
        income.type.push_back(newSource);
        income.value.push_back(newIncome);
        income.date.push_back(date);
        
        cout << "\nNew Income has been added!\n";
        accounts.value[accountChoice-1] += newIncome;
        break;

      case 2:
        if(income.type.size() == 0){
          cout << "No income added! Please add Income using option 1 on the previous menu.\n";
        }
        else{
          cout << "Please select the number corresponding to the income you would like to edit.\n";
          for(i=0; i<income.type.size(); i++){
            cout << i+1 << ". " << income.type[i] << " HK$" << income.value[i]<< endl;
          }
          cin >> choice;
          if(choice > income.type.size()){
            cout << "Input integer does not link to any income. Try again!\n";
            break;
          }
          accounts.value[accountChoice-1] -= income.value[choice-1];
          cout << "Please enter ONE WORD to update Income Source : ";
          cin >> newSource;
          cout << "Please enter updated Income Amount : ";
          cin >> newIncome;
          if(newIncome<0){
            cout << "\nInvalid Income Value. Try again!\n";
            break;
          }
          income.type[choice-1] = newSource;
          income.value[choice -1] = newIncome;
        }
        accounts.value[accountChoice-1] += newIncome;
        break;
        
      case 3 :
        if(income.type.size()== 0){
          cout << "No income added! Please add Income using option 1 on the previous menu.\n";
        }
        else {
          cout << "Please select the number corresponding to the income you would like to delete.\n";
          for(i=0; i<income.type.size(); i++){
            cout << i+1 << ". " << income.type[i] << " HK$" << income.value[i]<< endl;
          }
          cin >> choice;
          if(choice>income.type.size()){
            cout << "Input integer does not link to any Income. Try again!\n";
            break;
          }
          accounts.value[accountChoice-1] -= income.value[choice-1];
          income.type.erase(income.type.begin()+choice-1);
          income.value.erase(income.value.begin()+choice-1);
        }
        break;
        default: cout << "Invalid Input! Please choose a number from the Menu below. \n ";
    }
    display_income_status();
  } while (userInput!=0);
}

//
// Function to display Menu for View Records Feature
void User::viewRecordsMenu()
{
  cout << "\nPlease enter the number next to your preferred option from the menu below.\n\n";
  cout << "*************************************************" << endl;
  cout << "0. Exit to Main Menu." << endl;
  cout << "1. View Expense Records." << endl;
  cout << "2. View Income Records." << endl;
  cout << "3. View Current Accounts Status." << endl;
  cout << "*************************************************" << endl;
}

//
//Function to display filter options for View Records feature
void User::filterRecordsMenu()
{
  cout << "\nPlease enter the number next to your preferred option from the menu below.\n\n";
  cout << "*************************************************" << endl;
  cout << "0. Exit to Main Menu." << endl;
  cout << "1. Filter by Category." << endl;
  cout << "2. Filter by Date." << endl;
  cout << "*************************************************" << endl;
}

//
// Function to view records with filters
// Input: structure user1
// Output: user's choice of records
void User::viewRecords()
{
  int choice, filterchoice;
  string type, filterDate;
  char yesNo; 
  unsigned int i=0;
  do
  {
    viewRecordsMenu();
    cin >> choice;
    switch(choice)
    {
      case 0: return;
      case 1: 
        cout << "Would you like to filter expense records? (Y/N): ";
        cin >> yesNo;
        if(yesNo=='Y' || yesNo=='y'){
          filterRecordsMenu();
          cin >> filterchoice;
          switch(filterchoice){
            case 0 : break;
            case 1 : 
              cout << "\nRecorded Expense Categories are as follows\n";
              for(i=0; i<expense.type.size(); i++){
                cout << expense.type[i] << " " << endl;
              }
              cout << "\nPlease enter ONE WORD to filter records by: ";
              cin >> type;
              cout << type << endl;
              for(i=0; i<expense.type.size(); i++){
                if(expense.type[i]==type){
                  cout << expense.date[i] << " HK$" << expense.value[i] << endl;
                }
              }
              break;
            case 2 :
              cout << "\nRecorded Expense Dates are as follows\n";
              for(i=0; i<expense.date.size(); i++){
                cout << expense.date[i] << " " << endl;
              }
              cout << "\nPlease enter date to filter records by :";
              cin >> filterDate;
              cout << filterDate << endl;
              for(i=0; i<expense.date.size(); i++){
                if(expense.date[i]==filterDate){
                  cout << expense.type[i] << " HK$" << expense.value[i] << endl;
                }
              }
              break;
            default : cout << "Invalid Input! Please try again!";
          }
        }
        else if (yesNo=='N' || yesNo=='n') {
          display_expense_status();
        }
        else {
          cout << "Invalid input. Please try again!" << endl;
        }
        break;
      case 2: 
        cout << "Would you like to filter income records? (Y/N)";
        cin >> yesNo;
        if(yesNo=='Y'|| yesNo=='y'){
          filterRecordsMenu();
          cin >> filterchoice;
          switch(filterchoice){
            case 0 : break;
            case 1 : 
              cout << "\nRecorded Income Categories are as follows\n";
              for(i=0; i<income.type.size(); i++){
                cout << income.type[i] << " " << endl;
              }
              cout << "\nPlease enter ONE WORD to filter records by :";
              cin >> type;
              cout << type << endl;
              for(i=0; i<income.type.size(); i++){
                if(income.type[i]==type){
                  cout << income.date[i] << " HK$" << income.value[i] << endl;
                }
              }
              break;
            case 2 :
              cout << "\nRecorded Income Dates are as follows\n";
              for(i=0; i<income.date.size(); i++){
                cout << income.date[i] << " " << endl;
              }
              cout << "\nPlease enter date to filter records by :";
              cin >> filterDate;
              cout << filterDate << endl;
              for(i=0; i<income.date.size(); i++){
                if(income.date[i]==filterDate){
                  cout << income.type[i] << " HK$" << income.value[i] << endl;;
                }
              }
              break;
            default : cout << "Invalid Input! Please try again!";
          }
        }
        else if (yesNo=='N' || yesNo=='n') {
          display_income_status();
        }
        else {
          cout << "Invalid input. Please try again!" << endl;
        }
        break;
      case 3: 
        display_accounts_status();
        break;
      default: 
        cout << "Invalid Input! Please try again!";     
    }
  } while (true);
}

//Function to print Budget Menu on the screen
//Input: none
//Output: Displays the Menu for user to choose from
void BudgetMenu(){
  cout << "\nPlease enter the number next to your preferred option from the menu below.\n\n";
  cout << "*************************************************" << endl;
  cout << "0. Exit to Main Menu." << endl;
  cout << "1. Create a New Budget." << endl;
  cout << "2. Check Remaining Budget." << endl;
  cout << "*************************************************" << endl;
}

//
// Function to set and edit budget
// Input: structure user1
// Output: updated structure user1 with monthly budget
void User::manageBudget()
{
  cout << "Welcome to the Manage Budget screen.\n" << endl;
  int userInput;
  unsigned int i=0;
  double sum=0;
  do{
    BudgetMenu();
    cin >> userInput;
    switch (userInput)
    {
      case 0: break;
      case 1:
        cout << "Please enter new Budget Amount : ";
        cin >> budget;
        cout << "\nBudget limit has been set to : HK$" << budget << endl;
        break;
      
      case 2: 
        for(i=0; i<expense.type.size(); i++){
          sum+=expense.value[i];
        }
        cout << "Total amount spent : HK$" << sum << endl;
        cout << "Budget left : HK$" << budget-sum << endl;
        if(budget > 0)
          cout << "% of Budget used : " <<fixed<<setprecision(2) << sum/budget*100  << "%" << endl; 
        else
          cout << "Please set a budget!" << endl;
        
        sum=0;
        break;
    
      default: cout << "Invalid Input! Please choose a number from the Menu below.\n";
    }
  } while(userInput!=0);
}

//
//Function to print menu on accounts screen
//Input: none
//Output: Displays the Menu for user to choose from
void User::accountsMenu()
{
  cout << "\nPlease enter the number next to your preferred option from the menu below.\n\n";
  cout << "*************************************************" << endl;
  cout << "0. Exit to Main Menu." << endl;
  cout << "1. Create a New Account." << endl;
  cout << "2. Delete an Existing Account." << endl;
  cout << "3. Edit an Existing Account." << endl;
  cout << "4. View all Existing Accounts." << endl;
  cout << "*************************************************" << endl;
}

void User::display_accounts_status()
{
  if(accounts.type.size() != 0)
  {
    cout << "\nStatus of all Accounts is as follows\n";
  }
  else
  {
    cout << "No Accounts to Display! Please Create an Account first.";
  }
    
  for (int i=0 ; i<accounts.type.size(); i++)
    cout << i+1 << ". " << accounts.date[i] << " " << accounts.type[i] << " HK$" << accounts.value[i] <<endl;
}

//
// Function to manage different accounts and amount remaining from monthly budget
// Input: structure user1
// Output: updated structure user1
void User::manageAccounts()
{
  cout << "Welcome to the Manage Accounts Screen.\n";
  string newAccountName;
  double newAccountBalance;
  unsigned int i=0;
  int userInput, changePos;
  do
  {
    accountsMenu();
    cin >> userInput;
    switch(userInput)
    {
      case 0: break;
      case 1:
        cout << "Please input ONE WORD for Account Name : ";
        cin >> newAccountName;
        cout << "Please input Initial Account Balance : ";
        cin >> newAccountBalance;
        if(newAccountBalance<0){
          cout << "\nInvalid Account Value. Try again!\n";
          break;
        }
        accounts.date.push_back(date);
        accounts.type.push_back(newAccountName);
        accounts.value.push_back(newAccountBalance);
        cout << "\nNew Account has been created!\n";
        break;

      case 2: 
        if(accounts.type.size() == 0)
        {
          cout << "Nothing to Delete! Please add an account using option 1 on the previous menu.\n";
        }
        else
        {
          cout << "Please select the number in the list below next to the account name you would like to Delete.\n";
          display_accounts_status();
          cin >> changePos;
          if(changePos > accounts.type.size())
          {
            cout << "Input integer does not link to any Account. Please try again!\n";
            break;
          }
          accounts.type.erase(accounts.type.begin()+changePos-1);
          accounts.value.erase(accounts.value.begin()+changePos-1);
        }
        break;

      case 3: 
        if(accounts.type.size() == 0)
        {
          cout << "Nothing to Edit! Please add an account using option 1 on the previous menu.\n";
        }
        else
        {
          cout << "Please select the number in the list below next to the account name you would like to Edit.\n";
          display_accounts_status();
          cin >> changePos;
          cout << "Please enter ONE WORD to update Account Name : ";
          cin >> newAccountName;
          cout << "Please enter updated Account Balance : ";
          cin >> newAccountBalance;
          if(newAccountBalance<0){
            cout << "\nInvalid Account Value. Try again!\n";
            break;
          }
          accounts.type[changePos-1] = newAccountName;
          accounts.value[changePos-1] = newAccountBalance;
        }
        break;

        case 4:
          display_accounts_status();
        break;  

      default: cout << "Invalid Input! Please choose a number from the Menu below.\n";       
    }
  } while (userInput != 0);
}

//
// Function to transfer money from one account to another
// Input: structure user1
// Output: updated structure user1
void User::transferAmount()
{
  int i;
  if(accounts.value.size() < 2)
  {
    cout << "You need at least 2 accounts to use the Transfer feature!\n";
    cout << "Please Create Accounts from Option 5 on the Main Menu below.\n"; 
    return;
  }
  else
  {
    int fromAccount, toAccount;
    double transferAmount;
    cout << "\nCurrent Accounts Status\n";
    for (i=0 ; i<accounts.value.size(); i++)
    {
      cout << i+1 << ". " <<  accounts.type[i] << " HK$" <<  accounts.value[i] <<endl;
    }
    cout << "\nTransfer FROM (Enter number from list above) : ";
    cin >> fromAccount;
    cout << "\nTransfer TO (Enter number from list above) : ";
    cin >> toAccount;
    cout << "\nTransaction amount = HK$";
    cin >> transferAmount;
    accounts.value[fromAccount-1] -= transferAmount;
    accounts.value[toAccount-1] += transferAmount;
  }
  cout << "Transfer Successful!\n";
  cout << "\nCurrent Accounts Status\n";
  for (i=0 ; i<accounts.value.size(); i++)
  {
    cout << i+1 << ". " <<  accounts.type[i] << " HK$" <<  accounts.value[i] <<endl;
  }
}

// Function to print menu on Statistics screen
void User::statsMenu(){
  cout << "\nPlease enter the number next to your preferred option from the menu below.\n\n";
  cout << "*************************************************" << endl;
  cout << "0. Exit to Main Menu." << endl;
  cout << "1. View Expense Statistics." << endl;
  cout << "2. View Income Statistics." << endl;
  cout << "*************************************************" << endl;
}

//
// Function to manage income inputs
// Input: structure user1
// Output: updated structure user1
void User::viewStats()
{
  cout << "\nWelcome to the Statistics screen.\n" << endl;
  int userInput;
  double total_expense=0, total_income=0;
  double sum=0;
  bool flag=false;
  unsigned int i=0, j=0;
  vector <string> temp;
  do
  {
    statsMenu();
    cin >> userInput;
    switch(userInput){
      case 0: break;
      case 1:
        temp = expense.type;
        for(i=0; i<expense.value.size(); i++){
          total_expense+=expense.value[i];
        }
        if(expense.type.size()>0){
          cout << "EXPENSES BY CATEGORY" << endl;
          for (i=0; i<temp.size(); i++)
          {
            if(temp[i] == "")
              continue;
            sum = expense.value[i];
            for (j=i+1; j<temp.size(); j++)
            {
              if(temp[j] == temp[i])
              {
                sum += expense.value[j];
                temp[j] = "";
              }
            }
            cout << temp[i] << " : " << fixed << setprecision(2) << sum/total_expense*100 << "%" << endl;
          }
        }
        else
          cout << "No Expense created! Please add expense using option 1 on the main menu.\n";
        total_expense = 0;
        break;

      case 2:
        temp = income.type;
        for(i=0; i<income.value.size(); i++){
          total_income+=income.value[i];
        }
        if(income.type.size()>0){
          cout << "INCOMES BY CATEGORY" << endl;
          for (i=0; i<temp.size(); i++)
          {
            if(temp[i] == "")
              continue;
            sum = income.value[i];
            for (j=i+1; j<temp.size(); j++)
            {
              if(temp[j] == temp[i])
              {
                sum += income.value[j];
                temp[j] = "";
              }
            }
            cout << temp[i] << " : " << fixed << setprecision(2) << sum/total_income*100 << "%" << endl;
          }
        }
        else{
          cout << "No Income created! Please add income using option 2 on the main menu.\n";
        }
        total_income = 0;
        break;
    }
  } while (userInput!=0);
  
}

//
//Function to change current instance of date
void User::changeDate()
{
  cout << "\nWelcome to Change Date Screen.\n";
  cout << "Please enter new date (DD/MM/YY) : ";
  cin >> date;
}

//
// Function to display all choices available (Main Menu)
// Input: none
// Output: List of options which are the features implemented in the project

void User::display_main_menu()
{
  cout << "\nPlease select the number next to your preferred option from the menu below.\n\n";
  cout << "*************************************************" << endl;
  cout << "0. Exit." << endl;
  cout << "1. Manage Expense." << endl;
  cout << "2. Manage Income." << endl;
  cout << "3. View User Records." << endl;
  cout << "4. Manage Monthly Budget." << endl;
  cout << "5. Manage Accounts." << endl;
  cout << "6. Transfer." << endl;
  cout << "7. View Statistics of Previous Expenses." << endl;
  cout << "8. Enter transactions for different Date." << endl;
  cout << "*************************************************" << endl;
}

//
// Function to coordinate user choice input
// Input: User choice in Main Menu
// Output: Depends on choice
// Call functions based on user input 
void User::coordinate_input(int choice)
{
  switch(choice)
  {
    case 0:
      // cout << "Thank you for using the system.\nUntil next time! :)" << endl;
    break;
    case 1: manageExpense();
    break;
    case 2: manageIncome();
    break;
    case 3: viewRecords();
    break;
    case 4: manageBudget();
    break;
    case 5: manageAccounts();
    break;
    case 6: transferAmount();
    break;
    case 7: viewStats();
    break;
    case 8 : changeDate();
    break;
    default: cout << "Invalid Input! Please choose an option from the Main Menu." << endl;
  }
}