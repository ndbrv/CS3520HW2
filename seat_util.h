#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void getOptions();
void display(char seats[8][11]);
int twoD_to_oneD(int r, int col);
vector<int> seat_to_coordinate(string seat);
vector<int> selectSeat(char seats[8][11]);
vector<int> checkFirstClass(char o[8][11]);
vector<int> checkBusinessClass(char o[8][11]);
vector<int> checkEconomyClass(char o[8][11]);