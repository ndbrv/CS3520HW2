#include "seat_util.h"
#include <iostream>
#include <string>

using namespace std;

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

void display(char seats[8][10]){ 
  
	for(int i=0;i<8;i++){
    //cout << seats[i][0];
		for(int j=0;j<10;j++){
			cout<<seats[i][j]<<" ";
		}
		cout<<endl;
	}

	return;
}

void selectSeat(char seats[8][10]){ 
  string st;
  cout << "Enter a seat number(enter E to exit): ";
  cin >> st;
  while(true) {
  // exit seat selection
    if(st[0] == 'E'){
      break;
    }
  // check whether seat row no. is in range
    if(st[0] == '8' || st[0] == '1'){ 
      cout << "Invalid seat."<< endl;
      //display(seats);
    }
// Add case where everything is booked

  }
  cout << "Thanks for booking!" << endl;
}

