#include <iostream>
using namespace std;

/*
void meaningless_board()
{
    cout << "     |     |     " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "     |     |     " << endl;
}
*/

void empty_board()
{
    system("cls");  //clear screen for every new game
    cout<<"\nWELCOME TO TIC-TAC-TOE.CPP\n\nHere is the board:\n"<<endl;
    char squares[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    cout << "     |     |     " << endl;
    cout << "  " << squares[0] << "  |  " << squares[1] << "  |  " << squares[2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << squares[3] << "  |  " << squares[4] << "  |  " << squares[5] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << squares[6] << "  |  " << squares[7] << "  |  " << squares[8] << endl;
    cout << "     |     |     " << endl;
    cout<<"\nRefer to these numbers for tile positions\n";
}

void draw_board()
{
    //board without numbers.
    //updates every round.
}



int main() {
    empty_board();
}
