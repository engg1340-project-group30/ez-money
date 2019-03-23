#include <iostream>

using namespace std;

//
// Function to display all choices available (Main Menu)
// Input: none
// Output: List of options which are the features implemented in the project
void display_main_menu()
{
  system("clear");
  cout << "\nSelect the number next to preferred option below.\n\n";
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
void coordinate_input(int choice)
{

}

int main()
{
  int choice;

  //do-while loop to handle choices made by user
  //run till the user enters 0
  do {
    display_main_menu();
    cin >> choice;
    coordinate_input(choice);
    
    
  } while(choice != 0);



  return 0;
}