#include "GetValid.h"
#include <array>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctype.h>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

void SelectionSort(vector<double> &, vector<string> &, vector<string> &,
                   vector<string> &, vector<int> &);
void ExchangeSort(vector<int> &, vector<string> &, vector<string> &,
                  vector<string> &, vector<double> &);
void ShellSort(vector<string> &, vector<string> &, vector<string> &,
               vector<int> &, vector<double> &);
void BubbleSort(vector<string> &, vector<string> &, vector<string> &,
                vector<int> &, vector<double> &);

int main() {
  srand((unsigned)time(0));
  vector<string> items;
  vector<string> donators;
  vector<string> brands;
  vector<int> ids;
  vector<double> prices;

  int menu = 0, id, sort = 0, rhelp, remove;
  double price;
  string name, donate, donator, dummy, brand;
  cout << "Welcome to Goodwill's Inventory System!\n";

  while (menu != 5) {
    do {
      cout << "\nWhat would you like to do? ";
      cout << "\n1. Store item";
      cout << "\n2. Remove item";
      cout << "\n3. Sort items";
      cout << "\n4. Recommendations";
      cout << "\n5. Exit Program\n";
    } while ((!(getValidInt(menu)) || (menu < 0)));

    if (menu == 1) {

      // name of item
      cout << "\nWhat did you purchase? ";
      getline(cin, name);
      items.push_back(name);
      id = (rand() % 999) + 1;
      ids.push_back(id);

      // getting the price
      do {
        cout << "\nWhat was the price of " << name << "? ";
      } while ((!(getValidDouble(price)) || (price < 0)));
      prices.push_back(price);

      // donators
      cout << "\nDid anyone donate " << name << " (Y/N)? ";
      cin >> donate;
      if (donate == "Y" || donate == "y") {
        cout << "\nWho donated " << name << "? ";
        getline(cin, dummy);
        getline(cin, donator);
        donators.push_back(donator);
      } else {
        donator = "N/A";
        donators.push_back(donator);
      }

      // getting the brand
      cout << "\nWhat brand made " << name << "? ";
      if (donate != "Y" && donate != "y") {
        getline(cin, dummy);
      }
      getline(cin, brand);
      brands.push_back(brand);
    }
    // REMOVING
    else if (menu == 2) {
      if (items.size() <= 0) {
        cout << "You need to store items before you remove any.\n";
      } else {
        do {
          cout << "What would you like to remove?\n";
          for (int i = 0; i < items.size(); i++) {
            cout << "\n" << i + 1 << ". " << items[i];
          }
          cout << endl;
        } while ((!(getValidInt(remove)) || (remove <= 0) ||
                  (remove > items.size())));
        remove = remove - 1;
        items.erase(items.begin() + remove);
        ids.erase(ids.begin() + remove);
        brands.erase(brands.begin() + remove);
        donators.erase(donators.begin() + remove);
        prices.erase(prices.begin() + remove);

        cout << "\n\nNew list of items:\n";
        for (int index = 0; index < items.size(); index++) {
          cout << items[index] << endl;
        }
      }
    } else if (menu == 3) {
      if (items.size() <= 0) {
        cout << "You need to store items before you sort any.\n";
      } else {
      cout << "\n1. ID NUMBERS";
      cout << "\n2. Item name";
      cout << "\n3. Price";
      cout << "\n4. Donator";
      do {
        cout << "\nHow would you like to sort?\n";
      } while ((!(getValidInt(sort)) || (sort < 1) || (sort > 4)));
      if (sort == 1) {
        ExchangeSort(ids, items, donators, brands, prices);
        cout << endl;
        for (int index = 0; index < items.size(); index++) {
          cout << items[index] << " --> "
               << "#" << ids[index] << endl;
        }
      }
      if (sort == 2) {
        ShellSort(items, donators, brands, ids, prices);
        cout << endl;
        for (int index = 0; index < items.size(); index++) {
          cout << items[index] << endl;
        }
      }
      if (sort == 3) {
        SelectionSort(prices, items, donators, brands, ids);
        cout << endl;
        for (int index = 0; index < items.size(); index++) {
          cout << items[index] << " --> "
               << "$" << prices[index] << endl;
        }
      }
      if (sort == 4) {
        BubbleSort(donators, items, brands, ids, prices);
        for (int index = 0; index < items.size(); index++) {
          cout << items[index] << " --> " << donators[index] << endl;
        }
      }
    }
    }
    else if(menu == 4){
      string reccom;
      cout << "\nThis option is for users to submit recommendations for this site and others to come in the future!";
      cout << "\nPlease submit your recommendation here: ";
      getline(cin, reccom);

      cout << "\n\nThank you for submitting a recommendation!\n";
    }
  }
}

void SelectionSort(vector<double> &num, vector<string> &num2,
                   vector<string> &num3, vector<string> &num4,
                   vector<int> &num5) {
  double i, j, first, temp;
  string temp2, temp3, temp4;
  int temp5;
  double numLength = num.size();
  for (i = numLength - 1; i > 0; i--) {
    first = 0;               // initialize to subscript of first element
    for (j = 1; j <= i; j++) // locate smallest between positions 1 and i.
    {
      if (num[j] > num[first])
        first = j;
    }
    temp = num[first]; // Swap smallest found with element in position i.
    num[first] = num[i];
    num[i] = temp;

    temp2 = num2[first];
    num2[first] = num2[i];
    num2[i] = temp2;

    temp3 = num3[first];
    num3[first] = num3[i];
    num3[i] = temp3;

    temp4 = num4[first];
    num4[first] = num4[i];
    num4[i] = temp4;

    temp5 = num5[first];
    num5[first] = num5[i];
    num5[i] = temp5;
  }
}

// Exchange Sort Function for Ascending Order
void ExchangeSort(vector<int> &num, vector<string> &num2, vector<string> &num3,
                  vector<string> &num4, vector<double> &num5) {
  int i, j;
  int temp; // holding variable
  string temp2, temp3, temp4;
  double temp5;
  int numLength = num.size();
  for (i = 0; i < (numLength - 1); i++) // element to be compared
  {
    for (j = (i + 1); j < numLength; j++) // rest of the elements
    {
      if (num[i] > num[j]) // ascending order
      {
        temp = num[i]; // swap
        num[i] = num[j];
        num[j] = temp;

        temp2 = num2[j];
        num2[j] = num2[i];
        num2[i] = temp2;

        temp3 = num3[j];
        num3[j] = num3[i];
        num3[i] = temp3;

        temp4 = num4[j];
        num4[j] = num4[i];
        num4[i] = temp4;

        temp5 = num5[j];
        num5[j] = num5[i];
        num5[i] = temp5;
      }
    }
  }
}

void ShellSort(vector<string> &num, vector<string> &num2, vector<string> &num3,
               vector<int> &num4, vector<double> &num5) {
  string temp, temp2, temp3;
  int i, temp4, flag = 1, numLength = num.size();
  double temp5;
  int d = numLength;
  while (flag || (d > 1)) // boolean flag (true when not equal to 0)
  {
    flag = 0; // reset flag to 0 to check for future swaps
    d = (d + 1) / 2;
    for (i = 0; i < (numLength - d); i++) {
      if (num[i + d] < num[i]) {
        temp = num[i + d];
        num[i + d] = num[i];
        num[i] = temp;

        temp2 = num2[i + d];
        num2[i + d] = num2[i];
        num2[i] = temp2;

        temp3 = num3[i + d];
        num3[i + d] = num3[i];
        num3[i] = temp3;

        temp4 = num4[i + d];
        num4[i + d] = num4[i];
        num4[i] = temp4;

        temp5 = num5[i + d];
        num5[i + d] = num5[i];
        num5[i] = temp5;
        flag = 1;
      }
    }
  }
}

// Bubble Sort Function for Descending Order
void BubbleSort(vector<string> &num, vector<string> &num2, vector<string> &num3,
                vector<int> &num4, vector<double> &num5) {
  string temp, temp2, temp3;
  int i, j, flag = 1; // set flag to 1 to start first pass
  int temp4;          // holding variable
  double temp5;
  int numLength = num.size();
  for (i = 1; (i <= numLength) && flag; i++) {
    flag = 0;
    for (j = 0; j < (numLength - 1); j++) {
      if (num[j + 1] < num[j]) // ascending order simply changes to <
      {
        temp = num[j]; // swap elements
        num[j] = num[j + 1];
        num[j + 1] = temp;

        temp2 = num2[j]; // swap elements
        num2[j] = num2[j + 1];
        num2[j + 1] = temp2;

        temp3 = num3[j]; // swap elements
        num3[j] = num3[j + 1];
        num3[j + 1] = temp3;

        temp4 = num4[j]; // swap elements
        num4[j] = num4[j + 1];
        num4[j + 1] = temp4;

        temp5 = num5[j]; // swap elements
        num5[j] = num5[j + 1];
        num5[j + 1] = temp5;
        flag = 1; // indicates that a swap occurred.
      }
    }
  }
}
