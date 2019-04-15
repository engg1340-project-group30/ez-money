#include <iostream>
#include "User.h"
using namespace std;

void loginScreen()
{
  cout << "Welcome to EZ-Money\n\n";
  cout << "1. Login." << endl;
  cout << "2. Sign Up." << endl;
  cout << "3. Exit Application" << endl;
  cout << "\nPlease enter the number next to your preferred option from the menu above : ";
}

int main()
{
  //Create a vector to store objects for each user
  vector <User> users;

  User currentUser;
  int createUser, choice;
  string name;
  loginScreen();
  cin >> createUser;
  cout << "Please type your username and press Enter or Return : ";
  cin.ignore();
  getline(cin, name);
  bool userExists= false;
  switch(createUser)
  {
    case 1: 
      for(int i=0; i<users.size(); i++)
      {
        if(name == users[i].username)
        {
          currentUser = users[i];
          userExists= true;
        }
      } 
      if(!userExists)
      {
        cout << "Username does not exist. Please Sign Up first.\n";
        exit(1);
      }
    break;

    case 2:
      users.push_back(currentUser);
      for(int i=0;i<users.size();i++)
      {
        if(name == users[i].username)
        {
          cout << "Username already exists! Please try another one.\n";
          i=0;
          getline(cin,name);
        }
      }
      currentUser.username = name;
    break;

    case 3:
      cout << "Application successfully closed!\n";
      exit(1);

    default: cout << "Invalid Input! Please try again." <<endl;   
  }

  cout << "\nHello, " << currentUser.username << "!" << endl;

  //do-while loop to handle choices made by user
  //run till the user enters 0
  do {
    currentUser.display_main_menu();
    cout << "\nPlease enter the number next to your preferred option from the menu below: ";
    cin >> choice;
    currentUser.coordinate_input(choice);
  } while(choice != 0);

  return 0;
}