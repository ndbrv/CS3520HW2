// Nikola Dobrev, Jaeson Pyeon 5/25/2022

#include "seat_util.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
  char seats[8][11] = {{' ', 'A', 'B', 'D', 'E', 'F', 'G', 'I', 'J', 'K'}, {' ', 'A', 'B', 'D', 'E', 'F', 'G', 'I', 'J', 'K'}, {' ', 'A', 'B', 'D', 'E', 'F', 'G', 'I', 'J', 'K'}, {' ', 'A', 'B', 'D', 'E', 'F', 'G', 'I', 'J', 'K'}, {' ', 'A', 'B', 'D', 'E', 'F', 'G', 'I', 'J', 'K'}, {' ', 'A', 'B', 'D', 'E', 'F', 'G', 'I', 'J', 'K'}, {' ', 'A', 'B', 'D', 'E', 'F', 'G', 'I', 'J', 'K'}, {' ', 'A', 'B', 'D', 'E', 'F', 'G', 'I', 'J', 'K'}};
  char seat_occupancy[8][11];
  string names[88];

  for (int i = 0; i < 8; i++)
  {
    seats[i][0] = '0' + i + 1;

    for (int j = 0; j < 11; j++)
    {
      if (j == 2 || j == 7)
      {
        seat_occupancy[i][j] = ' ';
      }
      else
      {
        seat_occupancy[i][j] = 'E';
      }
    }
  }

  int input;
  vector<int> selected_seat;
  string passenger_name;
  string seat;
  while (true)
  {
    cout << "Seat" << seat_to_coordinate("K2").at(0) << seat_to_coordinate("K2").at(1);
    getOptions();
    cin >> input;

    switch (input)
    {
    case 1:
      /* code */
      break;
    case 2:

    case 3:
      display(seat_occupancy);
      break;

    case 4:
      selected_seat = selectSeat(seat_occupancy);
      if (selected_seat.at(0) != -1)
      {
        seat_occupancy[selected_seat.at(0)][selected_seat.at(1)] = 'F';
        cout << endl
             << "Input passenger name";
        cin >> passenger_name;
        names[twoD_to_oneD(selected_seat.at(0), selected_seat.at(1))];
        cout << "Seat : " << selected_seat.at(0) << selected_seat.at(1);
      }

      break;

    case 5:

    case 6:

    case 7:
      cout << "Enter seat: ";
      cin >> seat;
      passenger_name = names[twoD_to_oneD(seat_to_coordinate(seat).at(0), seat_to_coordinate(seat).at(1))];
      cout << endl
           << seat << "," << passenger_name;
      break;
    case 8:

    case 9:
      break;
    }
  }
  return 0;
}