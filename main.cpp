// Nikola Dobrev, Jaeson Pyeon 5/25/2022

#include "seat_util.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    getOptions();
  
    char seats[8][10] = {{' ', 'A', 'B', 'D', 'E', 'F', 'G', 'I', 'J', 'K'}, {' ', 'A', 'B', 'D', 'E', 'F', 'G', 'I', 'J', 'K'}, {' ', 'A', 'B', 'D', 'E', 'F', 'G', 'I', 'J', 'K'}, {' ', 'A', 'B', 'D', 'E', 'F', 'G', 'I', 'J', 'K'}, {' ', 'A', 'B', 'D', 'E', 'F', 'G', 'I', 'J', 'K'}, {' ', 'A', 'B', 'D', 'E', 'F', 'G', 'I', 'J', 'K'}, {' ', 'A', 'B', 'D', 'E', 'F', 'G', 'I', 'J', 'K'}, {' ', 'A', 'B', 'D', 'E', 'F', 'G', 'I', 'J', 'K'}};
  
    for (int i = 0; i < 8; i++) {
      seats[i][0]='0'+i+1;
      for (int j = 0; j < 10; j++) {
      }
    }
    cout << "Seating Arrangements:\n";
    display(seats);

    cout << "Choose seat:\n";
    //int setSeat(char seats[8][10], string st);
    //string st = enterSeat();
    selectSeat(seats);
  
  
    return 0;
}