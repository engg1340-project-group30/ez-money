#include <iostream>
#include <string>
#include <fstream>
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
  User currentUser;
  int createUser, choice;
  string name, username = "", date;
  cout << "Please enter today's date (DD/MM/YY): ";
  cin >> currentUser.date;
  cout << endl;
  loginScreen();
  cin >> createUser;
  if(createUser != 3)
  {
    cout << "Please type your username and press Enter or Return : ";
    cin.ignore();
    getline(cin, name);
  }  
  bool userExists = false;
  vector <string> usernames; // vector to store usernames
  ofstream fout;
  ifstream fin;
  fin.open("usernames.txt"); 
  while(getline(fin, username))
  {
    usernames.push_back(username);
  }
  fin.close();
  switch(createUser)
  {
    case 1: 
      for(int i=0; i<usernames.size(); i++)
      {
        if(usernames[i] == name)
        {
          userExists = true;
          currentUser.username = name;
          break;
        }
      }
      if(!userExists)
      {
        cout << "Username does not exist. Please Sign Up first.\n";
        exit(1);
      }
    break;

    case 2:
      for(int i=0; i<usernames.size(); i++)
      {
        if(name == usernames[i])
        {
          cout << "Username already exists! Please try another one.\n";
          i = -1;
          getline(cin, name);
        }
      }
      currentUser.username = name;
      usernames.push_back(name);
    break;

    case 3:
      cout << "Application successfully closed!\n";
      exit(1);

    default: cout << "Invalid Input! Please try again." <<endl;   
  }
  // write updated username file
  fout.open("usernames.txt");
  if(fout.fail())
  {
    cout << "Could not open usernames.txt\n";
    return 1;
  }
  for(int i=0; i<usernames.size(); i++){
    fout << usernames[i] << "\n";
  }
  fout.close();

  // load values into currentUser object
  if(createUser != 2)
    currentUser.readFromFile();

  cout << "\nHello, " << currentUser.username << "!" << endl;

  //do-while loop to handle choices made by user
  //run till the user enters 0
  do {
    currentUser.display_main_menu();
    cout << "\nPlease enter the number next to your preferred option from the menu below: ";
    cin >> choice;
    currentUser.coordinate_input(choice);

  } while(choice != 0);

    // write updated entries to file
    currentUser.writeToFile();

  return 0;
}