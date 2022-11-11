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
    char squares[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};    //flat array for tiles
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


//global positions, update every round
char positions[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};    //blanks for now, update every round

//board without numbers.updates every round.
void draw_board()
{
    cout << "     |     |     " << endl;
    cout << "  " << positions[0] << "  |  " << positions[1] << "  |  " << positions[2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << positions[3] << "  |  " << positions[4] << "  |  " << positions[5] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << positions[6] << "  |  " << positions[7] << "  |  " << positions[8] << endl;
    cout << "     |     |     " << endl;    
}


void make_move() {}



int main() {
    empty_board();
    int player = 1; //1 or 2
    char mark;      //'X' or 'O'
    int position;     //1...9
    //draw_board();

    player=(player%2)?1:2; //alternating between 1 and 2
    printf("\nPlayer %d (%c), enter a position to play: ", player, (player==1)?'X':'O');
    cin>>position;
    make_move();

}
