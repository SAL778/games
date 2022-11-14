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


//make move at position x-1 by placing char y   //x-1 since position is (flat index + 1)
void make_move(int x, char y) {
    if(x<1 || x>9) {cout<<"Error! Inavlid position. Please try again\n"; return;}
    if(positions[x-1] == ' ')
    {
        switch (x)
        {
            case 1: positions[0] = y; break;
            case 2: positions[1] = y; break;
            case 3: positions[2] = y; break;
            case 4: positions[3] = y; break;
            case 5: positions[4] = y; break;
            case 6: positions[5] = y; break;
            case 7: positions[6] = y; break;
            case 8: positions[7] = y; break;
            case 9: positions[8] = y; break;
            //default: { cout<<"Error! Inavlid position. Please try again\n"; return; }
        }
    }
    else{
        cout<<"Position already occupied! Please try again\n"; return;
    }
}


int main() {
    empty_board();
    int player = 1; //1 or 2
    char mark;      //'X' or 'O'
    int position;     //1...9
    

    player=(player%2)?1:2; //alternating between 1 and 2
    printf("\nPlayer %d (%c), enter a position to play: ", player, (player==1)?'X':'O');
    cin>>position;
    mark=(player == 1) ? 'X' : 'O';

    make_move(position,mark);
    player--;

    draw_board();
}
