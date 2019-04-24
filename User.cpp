#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "User.h"
using namespace std;

//
//Function to load values from username.txt into currentUser object
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
  for(int i=0; i<accounts.type.size(); i++){
    fout << accounts.type[i] << " ";
  }
  fout << endl;
  for(int i=0; i<accounts.value.size(); i++){
    fout << accounts.value[i] << " ";
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

  for(int i=0; i<income.type.size(); i++){
    fout << income.type[i] << " ";
  }
  fout << endl;
  for(int i=0; i<income.value.size(); i++){
    fout << income.value[i] << " ";
  }
  fout << endl;
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
// Function will also alert in case expenses are 75% or 100% of budget
// Input: structure user1
// Output: updated structure user1
//         Conditional Alerts
void User::manageExpense()
{
  cout << "\nWelcome to the Manage Expense screen.\n" << endl;
  string newCategory;
  double newExpense;
  int userInput, userChoice, accountChoice;
  double sum=0;
  unsigned int i=0;
  bool append = false;
  if(accounts.type.size()==0){
    cout << "No Accounts found! Please create an account using 5 on the previous menu.";
    return;
  }
  else{
    cout << "\nPlease select an account to deduct expense from.\n";
    for(i=0; i<accounts.type.size(); i++){
      cout << i+1 << ". " <<  accounts.type[i] << " HK$" << accounts.value[i] << endl;
    }
  }
  cin >> accountChoice;
  do
  {
    expenseMenu();
    cin >> userInput;
    switch(userInput)
    {
      case 0 : break;
      case 1 :
        cout << "Please enter a suitable expense type/category : ";
        cin >> newCategory;
        cout << "Please enter the expense incurred : ";
        cin >> newExpense;
        if(newExpense > accounts.value[accountChoice-1]){
          cout << "\nNot sufficient balance in account! Try again.\n";
        }
        else{
          for(i=0; i<expense.type.size(); i++){
            if(newCategory==expense.type[i]){
              expense.value[i] += newExpense;
              append=true;
              break;
            }
            append=false;
          }
          if(append==false){
            expense.type.push_back(newCategory);
            expense.value.push_back(newExpense);
          }
          
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
          cout << "No expense added!\n";
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
          cout << "Please enter updated Expense Category : ";
          cin >> newCategory;
          cout << "Please enter updated expense : ";
          cin >> newExpense;
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
              cout << "Alert! Budget has been exceeded by HK$" << abs(budget-newExpense) << endl; 
            }
            expense.type[userChoice-1] = newCategory;
            expense.value[userChoice-1] = newExpense;
          }
        }
        accounts.value[accountChoice-1] -= newExpense;
        break;

        case 3:
          if(expense.type.size() == 0){
          cout << "No expense to delete!\n";
          }
        else{
          cout << "Please select the number corresponding to the expense you would like to delete.\n";
          for(i =0; i<expense.type.size(); i++){
            cout << i+1 << ". " << expense.type[i] << " HK$" << expense.value[i] << endl;
          }
          cout << i+1 << ". Exit to previous screen." << endl;
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

    if(expense.type.size()!=0){
      cout << "\nStatus of all expenses is as follows\n";
    }

    for(i=0; i<expense.type.size(); i++){
      cout << i+1 << ". " << expense.type[i] << " HK$" << expense.value[i] << endl;
    }
  } while (userInput!=0);
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
    cout << "No Accounts found! Please create an account using 5 on the previous menu.";
    return;
  }
  else{
    cout << "\nPlease select an account to add Income to.\n";
    for(i=0; i<accounts.type.size(); i++){
      cout << i+1 << ". " <<  accounts.type[i] << " HK$" << accounts.value[i] << endl;
    }
  }
  cin >> accountChoice;
  do
  {
    incomeMenu();
    cin >> userInput;
    switch(userInput)
    {
      case 0: break;
      case 1: 
        cout << "Please enter suitable Income source : " ;
        cin >> newSource;
        cout << "Please input amount : ";
        cin >> newIncome;
        
        for(i=0; i<income.type.size(); i++){
          if(newSource==income.type[i]){
            income.value[i]+=newIncome;
            append=true;
            break;
          }
          append=false;
        }
        if(append==false){
          income.type.push_back(newSource);
          income.value.push_back(newIncome);
        }
        cout << "\nNew Income has been added!\n";
        accounts.value[accountChoice-1] += newIncome;
        break;

      case 2:
        if(income.type.size() == 0){
          cout << "No income added!\n";
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
          cout << "Please enter updated Income Source : ";
          cin >> newSource;
          cout << "Please enter updated Income Amount : ";
          cin >> newIncome;
          income.type[choice-1] = newSource;
          income.value[choice -1] = newIncome;
        }
        accounts.value[accountChoice-1] += newIncome;
        break;
      
      case 3 :
        if(income.type.size()== 0){
          cout << "Nothing to delete!\n";
        }
        else {
          cout << "Please select the number corresponding to the income you would like to delete.\n";
          for(i=0; i<income.type.size(); i++){
            cout << i+1 << ". " << income.type[i] << " HK$" << income.value[i]<< endl;
          }
          cout << i+1 << ". Exit to previous screen." << endl;
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

    if(income.type.size()!=0){
      cout << "\nStatus of all Income Sources is as follows\n";
    }        
    else{
      cout << "No income record to display! Please create a new record by entering 1 below.";
    }

    for(i=0; i<income.type.size(); i++){
      cout << i+1 << ". " << income.type[i] << " HK$" << income.value[i] << endl;
    }
  } while (userInput!=0);
}

//
// Function to display Menu for View Records Feature
void User::viewRecordsMenu()
{
  cout << "\nPlease enter the number next to your preferred option from the menu below.\n\n";
  cout << "0. Exit to Main Menu." << endl;
  cout << "1. View Expense Records." << endl;
  cout << "2. View Income Records." << endl;
  cout << "3. View Current Accounts Status." << endl;
  cout << "4. View Budget Status." << endl;
}

//
// Function to view records with filters
// Input: structure user1
// Output: user's choice of records
void User::viewRecords()
{
  int choice; 
  viewRecordsMenu();
  cin >> choice;
  switch(choice)
  {
    case 0: return;
    case 1: 
      break;
    case 2:
      break;
    case 3: display_accounts_status();
      break;
     default: 
      cout << "Invalid Input! Please try again!";     
  }
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
        cout << "% of Budget left : " << sum/budget*100  << "%" << endl; 
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
    cout << "No Accounts to Display! Please Create an Account by entering 1 below.";
  }
    
  for (int i=0 ; i<accounts.type.size(); i++)
    cout << i+1 << ". " << accounts.type[i] << " HK$" << accounts.value[i] <<endl;
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
        cout << "Please input Account Name : ";
        cin >> newAccountName;
        cout << "Please input Initial Account Balance : ";
        cin >> newAccountBalance;
        accounts.type.push_back(newAccountName);
        accounts.value.push_back(newAccountBalance);
        cout << "\nNew Account has been created!\n";
        break;

      case 2: 
        if(accounts.type.size() == 0)
        {
          cout << "Nothing to Delete!\n";
        }
        else
        {
          cout << "Please select the number in the list below next to the account name you would like to Delete.\n";
          display_accounts_status();
          cout << i+1 << ". Exit to previous screen." << endl;
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
          cout << "Nothing to Edit!\n";
        }
        else
        {
          cout << "Please select the number in the list below next to the account name you would like to Edit.\n";
          display_accounts_status();
          cin >> changePos;
          cout << "Please enter updated Account Name : ";
          cin >> newAccountName;
          cout << "Please enter updated Account Balance : ";
          cin >> newAccountBalance;
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
    cout << "\nTranfer FROM (Enter number from list above) : ";
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

//
// Function to manage income inputs
// Input: structure user1
// Output: updated structure user1
void User::viewStats()
{
  cout << "This is the Statistics feature." << endl;
}


//
// Function to display all choices available (Main Menu)
// Input: none
// Output: List of options which are the features implemented in the project

void User::display_main_menu()
{
  //system("clear");
  cout << "\nPlease select the number next to your preferred option from the menu below.\n\n";
  cout << "*************************************************" << endl;
  cout << "0. Exit." << endl;
  cout << "1. Manage Expense." << endl;
  cout << "2. Manage Income." << endl;
  cout << "3. View Previous Expenses and Incomes." << endl;
  cout << "4. Manage Monthly Budget." << endl;
  cout << "5. Manage Accounts." << endl;
  cout << "6. Transfer." << endl;
  cout << "7. Manage Expense Reminders." << endl;
  cout << "8. View Statistics of Previous Expenses." << endl;
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
    case 0: cout << "Thank you for using the system.\nUntil next time! :)" << endl;
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
    //case 7: reminders();
    //break;
    case 8: viewStats();
    break;
    default: cout << "Invalid Input! Please choose an option from the Main Menu." << endl;
  }
}