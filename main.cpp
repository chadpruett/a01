/****************************************************************************
# Author:           Chad Pruett
# Lab:              Assignment #1
# Date:             April 4th, 2025
# Description:      This program will prompt the user for an input if they
would like to place an order or quit. If they choose to place an order, the
program will ask them for the name of what they ate and how much it cost.
Then the program will calculate their cost to dine, tip, and add a discount
if they reach a total cost threshold.
# Input:            option as int, item name as string, cost and tip as double
# Output:           itemized cost, tip, discount, and final total

****************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// FUNCTION PROTOTYPES
void welcome();
void displayMenu();
int readOption(int &option);
int readInt(string prompt, int &num);
void readDouble(string prompt, double &num);
void placeOrder(double &cost);
double tipDiscount(double &tip, double &discount, double cost);
void goodbye();

// MAIN FUNCTION
int main() {
  cout << fixed << setprecision(2); // FORMAT 2 DECIMAL PLACES

  // INITIALIZE VARIABLES
  int userChoice;

  welcome(); // CALL WELCOME FUNCTION

  // DO
  do {
    displayMenu();          // CALL DISPLAY MENU
    readOption(userChoice); // CALL READ OPTION
    if (userChoice == 1) {

      // INITIALIZE VARIABLES
      double cost = 0.0;
      double discountCost = 0.0;
      double userTip = 0.0;

      placeOrder(cost); // CALL PLACE ORDER

      // DISPLAY COST
      cout << '\n' << "Your total is: $" << cost << '\n' << endl;

      // CALL TIP DISCOUNT FUNCTION AND DISPLAY FINAL TOTAL
      double finalTotal = tipDiscount(userTip, discountCost, cost);

      // DISPLAY TOTAL, DISCOUNT, AND FINAL TOTAL
      cout << '\n' << "Your total is: $" << cost + userTip << endl;
      if (finalTotal > 50) {
        cout << "You get a 10% discount!" << endl;
        cout << "Your discount is: $" << discountCost << endl;
      } else if ((finalTotal > 35) && (finalTotal < 50)) {
        cout << "You get a 5% discount!" << endl;
        cout << "Your discount is: $" << discountCost << endl;
      }
      cout << "Your final total is: $" << finalTotal << '\n' << endl;
    }

  } while (userChoice != 2); // WHILE USER CHOICE IS NOT 2

  // CALL GOODBYE FUNCTION
  goodbye();

  return 0; // END MAIN FUNCTION
}

// FUNCTION DEFINITIONS

// WELCOME FUNCTION
void welcome() { cout << "Welcome to my Food Cart Program!" << endl; }

// DISPLAY MENU FUNCTION
void displayMenu() {
  cout << "Pick an option from below: " << endl;
  cout << "1. Place an order" << endl;
  cout << "2. Quit" << endl;
}

// READ OPTION FUNCTION
int readOption(int &option) {
  readInt(">> ", option);

  while ((option < 1) || (option > 2)) {
    cout << "Invalid Choice! Please enter a number between 1 and 2." << endl;
    option = readInt(">> ", option);
  }
  return option;
}

// READ INT FUNCTION
int readInt(string prompt, int &num) {
  int tempVar;
  cout << prompt;
  cin >> tempVar;
  while (!cin) {
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> tempVar;
  }
  cin.ignore(10, '\n');
  num = tempVar;
  return num;
}

// READ DOUBLE FUNCTION
void readDouble(string prompt, double &num) {
  double tempVar;
  cout << prompt;
  cin >> tempVar;
  while ((!cin) || (tempVar < 0)) {
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> tempVar;
  }
  cin.ignore(10, '\n');
  num = tempVar;
}

// PLACE ORDER FUNCTION
void placeOrder(double &cost) {
  string item;
  char option;
  double itemCost = 0.0;

  do {
    cout << '\n' << "Enter the name of your item: " << endl;
    cin >> item;
    readDouble("Enter the cost of your item: $", itemCost);
    cost += itemCost;
    cout << "Would you like to add another item? (y/n)" << endl;
    cin >> option;
    option = tolower(option);
    while ((option != 'y') && (option != 'n')) {
      cout << "Invalid input! Please enter y or n." << endl;
      cin >> option;
      option = tolower(option);
    }

  } while (option != 'n');
}

// TIP DISCOUNT FUNCTION
double tipDiscount(double &tip, double &discount, double cost) {
  discount = 0.0;

  readDouble("Enter the amount of tip you want to add: $", tip);
  double total = cost + tip;

  if (total > 50) {
    discount = total * 0.10;
  } else if ((total > 35) && (total < 50)) {
    discount = total * 0.05;
  }
  double finalTotal = total - discount;
  return finalTotal;
}

// GOODBYE FUNCTION
void goodbye() { cout << '\n' << "Thank you for using my program!" << endl; }