#include <iostream>
#include <cassert>
using namespace std;

void empty_board()
{
    system("cls");  //clear screen for every new game
    cout<<"\nWELCOME TO TIC-TAC-TOE.CPP\n\nHere is the board:\n\n"<<endl;
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
    cout<<endl;
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
    //assert(x>=1 && x<=9);
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
        }
    }
    else{
        cout<<"\nPosition already occupied! Please try again.\n"; return;
    }
}

//returns 1 if game is over and tied, 0 otherwise
int game_tied()
{
    int i;
    for(i=0; i<9; ++i)
    {
        if(positions[i]!=' ') {continue;}
        return 0;
    }
    return 1;
}

void win_message(char *z)
{
    if(*z=='X') {
        cout<<"\nPLAYER 1 (X) WINS!\n\n";
    }
    else if(*z=='O'){
        cout<<"\nPLAYER 2 (O) WINS!\n\n";
    }
}


//return 1 for win, 0 for draw, -1 ongoing game
int check_win()
{
    for(int i=1; i<9; i+=3)
    {   //check all horizontal win conditions
        if(positions[i]!=' ' && positions[i] == positions[i+1] && positions[i+1] == positions[i+2])
        {
            win_message(&positions[i]);
            return 1;
        }
    }
    for(int i=0; i<3; ++i)
    {   //check all vertical win conditions
        if(positions[i]!=' ' && positions[i] == positions[i+3] && positions[i+3] == positions[i+6])
        {
            win_message(&positions[i]);
            return 1;
        }
    }
    //check for diagonal wins
    if(positions[0]!=' ' && positions[0] == positions[4] && positions[4] == positions[8])
    {
        win_message(&positions[0]);
        return 1;
    }
    if(positions[2]!=' ' && positions[2] == positions[4] && positions[4] == positions[6])
    {
        win_message(&positions[2]);
        return 1;
    }
    else if (game_tied()) 
    {return 0;}
    return -1; //no result yet
}


int main() {
    empty_board();
    int player = 1;      //1 or 2
    char mark;           //'X' or 'O'
    int position;        //1...9
    int f;               //win flag
    
    do {
    player=(player%2)?1:2; //alternating between 1 and 2
    printf("\nPlayer %d (%c), enter a position to play: ", player, (player==1)?'X':'O');
    cin>>position;
    mark=(player == 1) ? 'X' : 'O';

    make_move(position,mark);
    player--;

    draw_board();
    f = check_win();

    } while(f==-1);
}
