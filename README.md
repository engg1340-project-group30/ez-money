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
1. Create and manage accounts for different modes of payment(Octopus Card, Credit Card, Bank Account, etc.)
2. Create, Delete, and Edit Incomes and Expenses.
3. View a record of previous transactions. This feature also accommodates filters for search
4. Set a budget and we will alert you when you go overboard.
5. Transfer money between accounts (eg. Recharge Octopus Card from Credit Card)
6. Trying to cut down on expenditures? We will give you categorical statistics to give you insights on your means of expenditures. 

## Interface
The program is menu driven with the ability to handle dynamic inputs. As such, there is no sample file input that could describe all the features. Hence, a screen recording of how we expect it to be used can be found on the link below: 

***

## Build and Execute
Please ensure you have the following installed on your system (These are primarily for a Unix based system and in some cases, Windows):
- git `https://git-scm.com/book/en/v2/Getting-Started-Installing-Git`
- g++ compiler `https://linuxconfig.org/how-to-install-g-the-c-compiler-on-ubuntu-18-04-bionic-beaver-linux`
- Make `http://tldp.org/HOWTO/Software-Building-HOWTO-3.html`

To use the system, simply follow the following steps
1. Clone this repository using the following command on your command line interface

`git clone https://github.com/engg1340-project-group30/finance-tracking-system.git`

2. Go into the directory of the project

`cd finance-tracking-system`

3. Build the executable through the make command. Our default executable created is *main*

`make main`

4. Execute the generated executable 

`./main`

5. Follow instructions on the screen. You can refer to the link below to see how we expect the system to be used.