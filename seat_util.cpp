#include "seat_util.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <unordered_map>

using namespace std;

unordered_map<char, int> letter_to_number_seat;
void init_map()
{
  letter_to_number_seat['A'] = 0;
  letter_to_number_seat['B'] = 1;
  letter_to_number_seat['D'] = 3;
  letter_to_number_seat['E'] = 4;
  letter_to_number_seat['F'] = 5;
  letter_to_number_seat['G'] = 6;
  letter_to_number_seat['I'] = 8;
  letter_to_number_seat['J'] = 9;
  letter_to_number_seat['K'] = 10;
}

void getOptions()
{
  cout << "(1) Load Previous Seat Assignment and Passenger Manifest"
       << endl
       << "(2) Save Current Seat Assignment and Passenger Manifest"
       << endl
       << "(3) Display the seating map"
       << endl
       << "(4) Choose a seat(with the help of automated system)"
       << endl
       << "(5) Update a seat assignment"
       << endl
       << "(6) Cancel seat assignment"
       << endl
       << "(7) Print boarding pass"
       << endl
       << "(8) Print passenger manifest"
       << endl
       << "(9) Quit program" << endl;
};

void display(char seats[8][11])
{
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 11; j++)
    {
      cout << seats[i][j] << " ";
    }
    cout << endl;
  }

  return;
}

int twoD_to_oneD(int r, int col)
{
  return r * 11 + col + 1;
}

vector<int> seat_to_coordinate(string seat)
{
  vector<int> coords;
  init_map();
  coords.push_back(seat.at(1) - 48);
  coords.push_back(letter_to_number_seat[seat.at(0)]);

  return coords;
}

vector<int> checkFirstClass(char o[8][11])
{
  vector<vector<int>> freeSeats;
  vector<int> rand_seat;
  for (int i = 0; i < 11; i++)
  {
    // if a seat is empty add it the vector of empty seats
    if (o[0][i] == 'E')
    {
      freeSeats.push_back({0, i});
    }
    if (freeSeats.size() == 0)
    {
      return {-1, -1};
    }

    // randomly pick a seat from the empty first class seats and return a vector of its seat index
    int rand_num = rand() % freeSeats.size();
    rand_seat = freeSeats.at(rand_num);
  }
  return rand_seat;
}

vector<int> checkBusinessClass(char o[8][11])
{
  vector<vector<int>> freeSeats;
  vector<int> rand_seat;
  for (int i = 1; i < 3; i++)
  {
    for (int j = 0; j < 11; j++)
    {
      if (o[i][j] == 'E')
      {
        freeSeats.push_back({i, j});
      }
    }
  }
  // if no seats are free return -1,-1 to indicate there are no valud indices
  if (freeSeats.size() == 0)
  {
    return {-1, -1};
  }
  // randomly pick a seat from the empty first class seats and return a vector of its seat index
  int rand_num = rand() % freeSeats.size();
  rand_seat = freeSeats.at(rand_num);
  return rand_seat;
}

vector<int> checkEconomyClass(char o[8][11])
{
  vector<vector<int>> freeSeats;
  vector<int> rand_seat;
  for (int i = 3; i < 8; i++)
  {
    for (int j = 0; j < 11; j++)
    {
      if (o[i][j] == 'E')
      {
        freeSeats.push_back({i, j});
      }
    }
  }
  // if no seats are free return -1,-1 to indicate there are no valud indices
  if (freeSeats.size() == 0)
  {
    return {-1, -1};
  }
  // randomly pick a seat from the empty first class seats and return a vector of its seat index
  int rand_num = rand() % freeSeats.size();
  rand_seat = freeSeats.at(rand_num);
  return rand_seat;
}

vector<int> selectSeat(char seats[8][11])
{
  string st;
  vector<int> noSeatVector;
  cout << "Please type 'F' for first class "
       << endl
       << "Please type 'B' for business class"
       << endl
       << "Others will be economy class";
  cin >> st;
  while (true)
  {
    // check for first class
    if (st == "F")
    {
      if (checkFirstClass(seats) == noSeatVector)
      {
        st = "B";
      }
      else
      {
        return checkFirstClass(seats);
      }
    }
    // check for business class
    if (st == "B")
    {
      if (checkBusinessClass(seats) == noSeatVector)
      {
        st = "E";
      }
      else
      {
        // book business seat
        return checkBusinessClass(seats);
      }
    }
    else
    {
      if (checkEconomyClass(seats) == noSeatVector)
      {
        cout << "All seats are booked";
        break;
      }
      else
      {
        // book economy seat
        return checkEconomyClass(seats);
      }
    }
  }
}
