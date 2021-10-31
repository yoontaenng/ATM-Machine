# bear_robotics
This is for BR custom task


# The flow 
-----------------

## Insert a card 
1. Simple standard input and output

## Enter PIN number
1. The PIN number is set as 1111
2. If the user enters wrong PIN number for 5 times, access is denied. Then the program terminates.

## Show the accounts that the user have and select
1. If the user does not have an account, then it is mandatory to create one to use ATM.
2. The account's name is created automatically, starting from 1. 
3. Everytime you select, ATM shows all the accounts that the user have.
4. A balance of each account is initalized as 0.

## Choose the operation
1. There are 5 options. Show my balance, deposit, withdraw, reselect the account, create new account, or exit.

#functions
----------------

## create_account
1. The name of each account is set as "user account 1, 2, 3,,,,"
2. As I mentioned, new object is created as a new element of account vector.

## select_account
1. First, show all accounts the user have.
2. Then select one of them. If it is out of range, keep asking. 

## check_PIN
1. To check if the user gives correct PIN number.
