# finance-tracking-system
## ENGG 1340 Course Project Group 30
### Contributors
- Rhea Gupta 3035550731
- Siddhant Bagri 3035551785

## Problem Statement
### Presenting EZ-Money (Inspired by Accounting system by TA Shumin)

Managing our finances is important for all of us. With all the transaction receipts, bills and accounts, money management can be a tedious and vexing task. Gone are the days of keeping log books and physical copies of financial transactions.  
People have switched to technology to keep a track of their daily expenditures, incomes, and so much more. Group 30 has built a system which provides users with a simple platform to store and organize their expenses and incomes and gives statistical insights on them based on your monthly budget.

## Features
### Basic Requirements
- Create and Manage **Accounts** for different modes of payment (Octopus Card, Credit Card, Bank Account, etc.)
- Create, Delete, and Edit **Incomes** and **Expenses**
- **View Previous Records** of transactions. This feature also accommodates **Filters** by date and categories
- Set a **Budget** and we will **Alert** you when you go overboard
- Trying to cut down on expenditures? We provide **Categorical Statistics** to give you insights on your means of expenditures
- Store **Transaction Dates** and input transactions for different dates without much fuss
### Additional Features
- **Login Authentication** by Username 
- **Transfer** between accounts (eg. Recharge Octopus Card from Credit Card)
- Option to **Save or Discard Changes** at the end of execution

## Interface
The program is menu driven with the ability to handle dynamic inputs. We have provided 2 sample file inputs for input/output redirection:
1. sampleinputfile1.txt: This file creates a username 'TestName1', and 2 each of Accounts, Expenses, and Incomes for the user. It then has inputs for the various features whose outputs can be redirected to another text file with the following commands  
`make main`  
`./main < sampleinputfile1.txt > sampleoutputfile.txt`

2. sampleinputfile2.txt: This file creates a username 'TestName2', creates 2 accounts, and sets the budget to HK$500. You can then run the system again to test different functionalities. Follow the commands below:  
`make main`  
`./main < sampleinputfile2.txt`  
`./main`

For further clarity, screen recordings demonstrating the features and input error handling can be found on our YouTube Channel. Follow the link below: 
Feature Demonstration  [https://www.youtube.com/watch?v=O_6yr7iO81c&t=2s]  
Input Error Handling  [https://youtu.be/m5zJYnp5DVE]  

***

## Build and Execute
Please ensure you have the following installed on your system (These are primarily for a Unix based system and in some cases, Windows):
- **git**  `https://git-scm.com/book/en/v2/Getting-Started-Installing-Git`
- **g++ compiler** `https://linuxconfig.org/how-to-install-g-the-c-compiler-on-ubuntu-18-04-bionic-beaver-linux`
- **Make** `http://tldp.org/HOWTO/Software-Building-HOWTO-3.html`

**To use the system, simply follow the following steps**
1. Clone this repository using the following command on your command line interface

`git clone https://github.com/engg1340-project-group30/finance-tracking-system.git`

2. Go into the directory of the project

`cd finance-tracking-system`

3. Build the executable through the make command. Our default executable generated is *main*

`make main`

4. Execute *main* 

`./main`

5. Follow instructions on the screen. You can refer to the YouTube Channel mentioned above for further clarity.

***

## Technical Information
### Data Structure
Our implementation consists of a class which has all variables and member functions. 
In main.cpp, we create an object of the class and make use of usernames stored in *usernames.txt* to handle multiple users. The username input by the user on the login screen becomes the current instance of the class.

The member variables of the class are
- username, date- string
- budget- double
- accounts, expense, income- struct with vectors for date(string), category(string), and value(double).

### File I/O
The backend of our system uses files with .txt files. Every user has a file assigned to them which is named by their username. In addition, there is an admin *usernames.txt* file which stores these usernames.

Example: `username.txt`  
Shumin  
Marco  
Lavender  

Then the files created for the users are
  * Shumin.txt
  * Marco.txt
  * Lavender.txt

The program starts by loading values into the current user's object from the user's file. At the end of execution, the updated values are overwritten into the same user's file.

## How does the System meet Project Requirements?
1. **Dynamic Memory Management**- The use of a class and vectors allows for any number of users with their data being stored independently. This data can be of different sizes for different users and can be as large as required.
2. **File Input/Output**- As described above, we use .txt files to load values into the attributes of the current object and write updated values into the user's file.
3. **Data Manipulation**- The system can add, delete, and edit any record (Please refer to the features heading for details). Moreover, the Statistics feature processes the data to give meaningful insights to the user.
4. **Program Codes in Multiple Files**- The code for the system is divided into 3 files which implement the class and ensure chronological execution. We have implemented a makefile to generate the executable to run the system.
5. **Proper Indentation and Naming Styles**- Variables, files, and functions have been named based on their utility. This ensures better code readability and understanding. Coding the system was much simpler with these meaningful names.
6. **In code documentation**- Comments have been included to describe the usage of every function. Further comments have been included where explanation is required. Variables have been given mnemonic names such that their utility is clear without comments.

## Potential to Improve
> *Dynamism is a function of change*
> <cite>- Hillary Clinton</cite>

- The ideal system should be able to read Date of transaction from the user's computer. The user should not be required to input date manually but the C++ STL lacks this implementation. Our solution is to make use of **ctime**
- Displaying graphs for Statistics for a better user experience. This can be implemented using Boost Python and matplotlib. There are other libraries for the same as well.