#ifndef User_h
#define User_h
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Category
{
  vector <string> type;
  vector <double> value;
};

class User
{
  public:
    void expenseMenu();
    void manageExpense();
    void incomeMenu();
    void manageIncome();
    void viewRecords();
    void manageBudget();
    void accountsMenu();
    void display_accounts_status(vector<string> , vector<double>);
    void manageAccounts();
    void transferAmount();
    void viewStats();
    void display_main_menu();
    void coordinate_input(int);

  //protected: 
    string username;
    double budget;
    Category accounts, expense, income;
};

#endif