#include <iostream>
#include "User.h"
using namespace std;

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
  cout << "Welcome to the Manage Expense screen.\n" << endl;
  vector <string> categoryName = expense.type;
  vector <double> categoryExpense = expense.value;
  string newCategory;
  double newExpense;
  int userInput, userChoice, accountChoice;
  unsigned int i=0;
  //string category[] = {"Food", "Travel", "Shopping", "Bill payment", "Miscellaneous"};
  cout << "\nPlease select an account to deduct expense from.\n";
  for(i=0; i<accounts.type.size(); i++){
    cout << i+1 << ". " <<  accounts.type[i] << " HK$" << accounts.value[i] << endl;
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
        cout << "Please enter a suitable category for the expense : ";
        //expenseCategoryMenu();
        cin >> newCategory;
        /*switch(newCategory){
          case 0: return;
          case 1: 
            cout << "Please enter the expense incurred : ";
            cin >> newExpense;
        }*/
        cout << "Please enter the expense incurred : ";
        cin >> newExpense;
        categoryName.push_back(newCategory);
        categoryExpense.push_back(newExpense);
        cout << "\nNew expense has been added!\n";
        accounts.value[accountChoice-1] -= newExpense;
        break;

      case 2:
        if(categoryName.size() == 0){
          cout << "No expense added!\n";
          }
        else{
          cout << "Please select the number corresponding to the expense you would like to edit.\n";
          for(i=0; i<categoryName.size(); i++){
            cout << i+1 << ". " << categoryName[i] << " HK$ " << categoryExpense[i] << endl;
          }
          cout << i+1 << ". Exit to previous screen." << endl;
          cin >> userChoice;
          if(userChoice > categoryName.size())
          {
            cout << "Input integer does not link to any expense incurred. Try again!\n";
            break;
          }
          accounts.value[accountChoice-1] += categoryExpense[userChoice-1];
          cout << "Please enter updated Expense Category : ";
          cin >> newCategory;
          cout << "Please enter updated expense : ";
          cin >> newExpense;
          categoryName[userChoice-1] = newCategory;
          categoryExpense[userChoice-1] = newExpense;
        }
        accounts.value[accountChoice-1] -= newExpense;
        break;

        case 3:
          if(categoryName.size() == 0){
          cout << "No expense to delete!\n";
          }
        else{
          cout << "Please select the number corresponding to the expense you would like to delete.\n";
          for(i =0; i<categoryName.size(); i++){
            cout << i+1 << ". " << categoryName[i] << " HK$ " << categoryExpense[i] << endl;
          }
          cout << i+1 << ". Exit to previous screen." << endl;
          cin >> userChoice;
          if(userChoice > categoryName.size())
          {
            cout << "Input integer does not link to any expense incurred. Try again!\n";
            break;
          }
          accounts.value[accountChoice-1] += categoryExpense[userChoice-1];
          categoryName.erase(categoryName.begin()+userChoice-1);
          categoryExpense.erase(categoryExpense.begin()+userChoice-1);
        }
        break;

    default: cout << "Invalid input. Please choose a number from the menu below. \n";
    
    }

    if(categoryName.size()!=0){
      cout << "\nStatus of all expenses is as follows\n";
    }
    /*else{
      cout << "No expense added!";
    }*/

    for(i=0; i<categoryName.size(); i++){
      cout << i+1 << ". " << categoryName[i] << " HK$ " << categoryExpense[i] << endl;
    }
  } while (userInput!=0);
  expense.type = categoryName;
  expense.value = categoryExpense;
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

//Function to display income source menu
//Input: none
//Output: Income source menu for the user to choose from
void User::incomeSourceMenu()
{
  cout << "*************************************************" << endl;
  cout << "0. Exit to Income Menu." << endl;
  cout << "1. Compensation of employment" << endl;
  cout << "2. Interest/Share/Bond" << endl;
  cout << "3. Lottery/Windfall gains" << endl;
  cout << "4. Others" << endl;
  cout << "*************************************************" << endl;
}

//
// Function to manage income inputs
// Input: structure user1
// Output: updated structure user1
void User::manageIncome()
{
  cout << "Welcome to the Income screen.\n";
  vector <double> incomeAmount = income.value;
  vector <string> incomeSource = income.type;
  double newIncome;
  unsigned int i=0;
  int userInput, choice, sourceChoice;
  do
  {
    incomeMenu();
    cin >> userInput;
    switch(userInput)
    {
      case 0: break;
      case 1: 
        cout << "Please choose the Income source from the menu below : " << endl;
        incomeSourceMenu();
        cin >> sourceChoice;
        cout << "Please input amount : ";
        cin >> newIncome;
        switch(sourceChoice)
        {
          case 0: break;
          case 1:
            incomeSource.push_back("Compensation of employment");
            incomeAmount.push_back(newIncome);
            break;
          case 2:
            incomeSource.push_back("Interest/Share/Bond");
            incomeAmount.push_back(newIncome);
            break;
          case 3:
            incomeSource.push_back("Lottery/Windfall gains");
            incomeAmount.push_back(newIncome);
            break;
          case 4:
            incomeSource.push_back("Others");
            incomeAmount.push_back(newIncome);
            break;
        }
        break;

      case 2:
        if(incomeSource.size() == 0){
          cout << "Nothing to edit!\n";
        }
        else{
          cout << "Please select the number corresponding to the income you would like to edit.\n";
          for(i=0; i<incomeSource.size(); i++){
            cout << i+1 << ". " << incomeSource[i] << " HK$" << incomeAmount[i]<< endl;
          }
          cin >> choice;
          cout << "Please choose the updated Income source from the menu below : " << endl;
          incomeSourceMenu();
          cin >> sourceChoice;
          cout << "Please input amount : ";
          cin >> newIncome;
          switch(sourceChoice){
            case 0 : break;
            case 1:
              incomeSource[choice-1] = "Compensation of employment";
              incomeAmount[choice-1] = newIncome;
              break;
            case 2:
              incomeSource[choice-1] = "Interest/Share/Bond";
              incomeAmount[choice-1] = newIncome;
              break;
            case 3:
              incomeSource[choice-1] = "Lottery/Windfall gains";
              incomeAmount[choice-1] = newIncome;
              break;
            case 4:
              incomeSource[choice-1] = "Others";
              incomeAmount[choice-1] = newIncome;
              break;
          }
          
        }
        break;
      
      case 3 :
        if(incomeSource.size()== 0){
          cout << "Nothing to delete!\n";
        }
        else {
          cout << "Please select the number corresponding to the income you would like to delete.\n";
          for(i=0; i<incomeSource.size(); i++){
            cout << i+1 << ". " << incomeSource[i] << " HK$" << incomeAmount[i]<< endl;
          }
          cout << i+1 << ". Exit to previous screen." << endl;
          cin >> choice;
          if(choice>incomeSource.size()){
            cout << "Invalid input. Please try again!\n";
            break;
          }
          incomeSource.erase(incomeSource.begin()+choice-1);
          incomeAmount.erase(incomeAmount.begin()+choice-1);
        }
        break;

        default: cout << "Invalid Input! Please choose a number from the Menu below. \n ";
    }

    if(incomeSource.size()!=0){
      cout << "\nStatus of all Income Sources is as follows\n";
    }        
    else{
      cout << "No income record to display! Please create a new record by entering 1 below.";
    }

    for(i=0; i<incomeSource.size(); i++){
      cout << i+1 << ". " << incomeSource[i] << " HK$" << incomeAmount[i] << endl;
    }
  } while (userInput!=0);
  income.type = incomeSource;
  income.value = incomeAmount;
}

//
// Function to view records with filters
// Input: structure user1
// Output: user's choice of records
void User::viewRecords()
{
  cout << "This is the view records feature."<< endl;
}

//
// Function to set and edit budget
// Input: structure user1
// Output: updated structure user1 with monthly budget
void User::manageBudget()
{
  cout << "Welcome to the Manage Budget screen.\n" << endl;
  double newBudget = budget;
  cout << "Please enter the amount: ";
  cin >> newBudget;
  cout << "\nNew budget has been set!\n";
  cout << "\nBudget limit has been set to: HK$ " << newBudget << endl;
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

void User::display_accounts_status(vector<string> accountNames, vector<double> accountBalances)
{
  if(accountNames.size() != 0)
  {
    cout << "\nStatus of all Accounts is as follows\n";
  }
  else
  {
    cout << "No Accounts to Display! Please Create an Account by entering 1 below.";
  }
    
  for (int i=0 ; i<accountNames.size(); i++)
    cout << i+1 << ". " << accountNames[i] << " HK$" << accountBalances[i] <<endl;
}

//
// Function to manage different accounts and amount remaining from monthly budget
// Input: structure user1
// Output: updated structure user1
void User::manageAccounts()
{
  vector <string> accountNames =  accounts.type;
  vector <double> accountBalances =  accounts.value;
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
        accountNames.push_back(newAccountName);
        accountBalances.push_back(newAccountBalance);
        cout << "\nNew Account has been created!\n";
        break;

      case 2: 
        if(accountNames.size() == 0)
        {
          cout << "Nothing to Delete!\n";
        }
        else
        {
          cout << "Please select the number in the list below next to the account name you would like to Delete.\n";
          display_accounts_status(accountNames, accountBalances);
          cout << i+1 << ". Exit to previous screen." << endl;
          cin >> changePos;
          if(changePos > accountNames.size())
          {
            cout << "Input integer does not link to any Account. Please try again!\n";
            break;
          }
          accountNames.erase(accountNames.begin()+changePos-1);
          accountBalances.erase(accountBalances.begin()+changePos-1);
        }
        break;

      case 3: 
        if(accountNames.size() == 0)
        {
          cout << "Nothing to Edit!\n";
        }
        else
        {
          cout << "Please select the number in the list below next to the account name you would like to Edit.\n";
          display_accounts_status(accountNames, accountBalances);
          cin >> changePos;
          cout << "Please enter updated Account Name : ";
          cin >> newAccountName;
          cout << "Please enter updated Account Balance : ";
          cin >> newAccountBalance;
          accountNames[changePos-1] = newAccountName;
          accountBalances[changePos-1] = newAccountBalance;
        }
        break;

        case 4:
          display_accounts_status(accountNames, accountBalances);
        break;  

      default: cout << "Invalid Input! Please choose a number from the Menu below.\n";       
    }
    
  } while (userInput != 0);
     accounts.type = accountNames;
     accounts.value = accountBalances;
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