#include <iostream>
#include <string>
#include <fstream>

using namespace std;

  // standard template of structure which is
  // used for accounts, expenses, and incomes
  struct Category
  {
    string type;
    double value;
  };

  // declare a structure for every user which
  // contains all the information of one user
  struct User 
  {
    string username;
    Category accounts, expense, income;
    double budget;
  };
  
//
// Function to manage expense inputs
// Function will also alert in case expenses are 75% or 100% of budget
// Input: structure user1
// Output: updated structure user1
//         Conditional Alerts
void manageExpense(User &user1)
{
  cout << "This is the Expense Input feature." << endl;
}

//
// Function to manage income inputs
// Input: structure user1
// Output: updated structure user1
void manageIncome(User &user1)
{
  cout << "This is the Income Input feature." << endl;
}

//
// Function to view records with filters
// Input: structure user1
// Output: user's choice of records
void viewRecords(User &user1)
{
  cout << "This is the view records feature."<< endl;
}

//
// Function to set and edit budget
// Input: structure user1
// Output: updated structure user1 with monthly budget
void manageBudget(User &user1)
{
  cout << "This is the Budget feature." << endl;
}

//
// Function to manage different accounts and amount remaining from monthly budget
// Input: structure user1
// Output: updated structure user1
void manageAccounts(User &user1)
{
  cout << "This is the Accounts feature." << endl;
}

//
// Function to transfer money from one account to another
// Input: structure user1
// Output: updated structure user1
void transferAmount(User &user1)
{
  cout << "This is the Transfer amount feature." << endl;
}

//
// Function to manage income inputs
// Input: structure user1
// Output: updated structure user1
void viewStats(User &user1)
{
  cout << "This is the Statistics feature." << endl;
}


//
// Function to display all choices available (Main Menu)
// Input: none
// Output: List of options which are the features implemented in the project
void display_main_menu()
{
  //system("clear");
  cout << "\nSelect the number next to your preferred option below.\n\n";
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
void coordinate_input(int choice, User user1)
{
  switch(choice)
  {
    case 0: cout << "Thank you for using the system.\nUntil next time! :)" << endl;
            exit(1);
    break;
    case 1: manageExpense(user1);
    break;
    case 2: manageIncome(user1);
    break;
    case 3: viewRecords(user1);
    break;
    case 4: manageBudget(user1);
    break;
    case 5: manageAccounts(user1);
    break;
    case 6: transferAmount(user1);
    break;
    //case 7: reminders(user1);
    //break;
    case 8: viewStats(user1);
    break;
    default: cout << "Invalid Input! Please choose an option from the Main Menu." << endl;
  }
}

int main()
{
  int choice;


  cout << "Please type your username and press Enter or Return : ";
  string name;
  getline(cin, name);

  // create an instance of structure User with username 
  // as user input string name
  User user1 = { name };
  cout << "\nHello, " << user1.username << "!" << endl;

  //do-while loop to handle choices made by user
  //run till the user enters 0
  do {
    display_main_menu();
    cin >> choice;
    coordinate_input(choice, user1);
    
    
  } while(true);



  return 0;
}