#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

char table[3][3][2];
char command[10], player1_name[30], player2_name[30] = "Computer";

int choose_player = 0, game_started = 0, pposx = 0, pposy = 0, pturn, win = -1;

void get_command(){
    cin.get(command, 10), cin.get();
}

void show_table() {
    system("cls");
    for(int i=0; i<3; i++)
    {
        cout<<" ";
        for(int j=0; j<3; j++)
            if(pposy == i && pposx == j && win == -1) cout<<"? | ";
            else cout<<table[i][j]<<" | ";
        cout<<endl;
        cout<<"------------"<<endl;
    }
    if(win == -1) cout<<endl<<"Move with: w, s, a, d and press \"enter\" for execute the move ;)"<<endl<<"For place the character type: \"place\"."<<endl;
}

void winner() {
    system("cls");
    show_table();
    cout<<endl;
    if(win == 0) cout<<"Match ended, the winner is "<<player1_name<<", good job!"<<endl;
    else cout<<"Match ended, the winner is "<<player2_name<<", good job!"<<endl;
}

void move_ch() {
    int tryagain = 0, placed = 0, stop = -1;
    if(strcmp(player2_name, "Computer")!=0 || pturn ==0) {
        if(pturn == 0) cout<<"Is "<<player1_name<<"'s turn."<<endl;
        else cout<<"Is "<<player2_name<<"'s turn."<<endl;
        get_command();
        while(strcmp(command, "w")!=0 && strcmp(command, "a")!=0 && strcmp(command, "s")!=0 && strcmp(command, "d")!=0 && strcmp(command, "place")!=0 && strcmp(command, "")!=0) {
            cout<<"Unknown move/command, try again"<<endl;
            cout<<endl<<"Move with: w, s, a, d and press \"enter\" for execute the move ;)"<<endl<<"For place the character type: \"place\"."<<endl;
            get_command();
        }
        if(strcmp(command, "")==0) stop = 1;
        if(strcmp(command, "w")==0) {
            if(pposy>0) pposy-=1;
            else tryagain =1;
        }
        else if(strcmp(command, "d")==0) {
            if(pposx<2) pposx+=1;
            else tryagain =1;
        }
        else if(strcmp(command, "s")==0) {
            if(pposy<2) pposy+=1;
            else tryagain =1;
        }
        else if(strcmp(command, "a")==0) {
            if(pposx>0) pposx-=1;
            else tryagain =1;
        }
        else {
            if(table[pposy][pposx][0] == '_') {
                if(pturn == 1 && choose_player == 1) table[pposy][pposx][0] = '0';
                else if(pturn == 1 && choose_player == 0) table[pposy][pposx][0] = 'x';
                else if(pturn == 0 && choose_player == 0) table[pposy][pposx][0] = '0';
                else if(pturn == 0 && choose_player == 1) table[pposy][pposx][0] = 'x';
                placed = 1;
                if(pposy == 0 && pposx == 0) {
                    if(table[0][1][0] == table[0][0][0] && table[0][2][0] == table[0][0][0]) win = pturn;
                    else if(table[1][0][0] == table[0][0][0] && table[2][0][0] == table[0][0][0]) win = pturn;
                    else if(table[1][1][0] == table[0][0][0] && table[2][2][0] == table[0][0][0]) win = pturn;
                }
                else if(pposy == 1 && pposx == 0) {
                    if(table[0][0][0] == table[1][0][0] && table[2][0][0] == table[1][0][0]) win = pturn;
                    else if(table[1][1][0] == table[1][0][0] && table[1][2][0] == table[1][0][0]) win = pturn;
                }
                else if(pposy == 2 && pposx == 0) {
                    if(table[2][1][0] == table[2][0][0] && table[0][0][0] == table[2][0][0]) win = pturn;
                    else if(table[1][0][0] == table[2][0][0] && table[2][0][0] == table[2][0][0]) win = pturn;
                    else if(table[1][1][0] == table[2][0][0] && table[0][2][0] == table[2][0][0]) win = pturn;
                }
                else if(pposy == 2 && pposx == 1) {
                    if(table[2][0][0] == table[2][1][0] && table[2][2][0] == table[2][1][0]) win = pturn;
                    else if(table[1][1][0] == table[2][1][0] && table[0][1][0] == table[2][1][0]) win = pturn;
                }
                else if(pposy == 2 && pposx == 2) {
                    if(table[2][1][0] == table[2][2][0] && table[2][0][0] == table[2][2][0]) win = pturn;
                    else if(table[1][2][0] == table[2][2][0] && table[0][2][0] == table[2][2][0]) win = pturn;
                    else if(table[1][1][0] == table[2][2][0] && table[0][0][0] == table[2][2][0]) win = pturn;
                }
                else if(pposy == 1 && pposx == 2) {
                    if(table[0][2][0] == table[1][2][0] && table[2][2][0] == table[1][2][0]) win = pturn;
                    else if(table[1][1][0] == table[1][2][0] && table[1][0][0] == table[1][2][0]) win = pturn;
                }
                else if(pposy == 0 && pposx == 2) {
                    if(table[1][2][0] == table[0][2][0] && table[2][2][0] == table[0][2][0]) win = pturn;
                    else if(table[0][1][0] == table[0][2][0] && table[0][0][0] == table[0][2][0]) win = pturn;
                    else if(table[1][1][0] == table[0][2][0] && table[2][0][0] == table[0][2][0]) win = pturn;
                }
                else if(pposy == 0 && pposx == 1) {
                    if(table[0][2][0] == table[0][1][0] && table[0][0][0] == table[0][1][0]) win = pturn;
                    else if(table[1][1][0] == table[0][1][0] && table[2][1][0] == table[0][1][0]) win = pturn;
                }
                else if(pposy == 1 && pposx == 1) {
                    if(table[0][2][0] == table[1][1][0] && table[2][0][0] == table[1][1][0]) win = pturn;
                    else if(table[2][2][0] == table[1][1][0] && table[0][0][0] == table[1][1][0]) win = pturn;
                    else if(table[0][1][0] == table[1][1][0] && table[2][1][0] == table[1][1][0]) win = pturn;
                    else if(table[1][0][0] == table[1][1][0] && table[1][2][0] == table[1][1][0]) win = pturn;
                }
            }
            else tryagain = 1;
        }
    }
    else {
        int randposx = rand() % 10, randposy = rand() % 10;
        while(table[randposy][randposx][0] != '_' || randposx > 2 || randposy > 2) randposx = rand() % 10, randposy = rand() % 10;
        pposy = randposy, pposx = randposx;
        if(pturn == 1 && choose_player == 1) table[pposy][pposx][0] = '0';
        else if(pturn == 1 && choose_player == 0) table[pposy][pposx][0] = 'x';
        placed = 1;
        if(pposy == 0 && pposx == 0) {
            if(table[0][1][0] == table[0][0][0] && table[0][2][0] == table[0][0][0]) win = pturn;
            else if(table[1][0][0] == table[0][0][0] && table[2][0][0] == table[0][0][0]) win = pturn;
            else if(table[1][1][0] == table[0][0][0] && table[2][2][0] == table[0][0][0]) win = pturn;
        }
        else if(pposy == 1 && pposx == 0) {
            if(table[0][0][0] == table[1][0][0] && table[2][0][0] == table[1][0][0]) win = pturn;
            else if(table[1][1][0] == table[1][0][0] && table[1][2][0] == table[1][0][0]) win = pturn;
        }
        else if(pposy == 2 && pposx == 0) {
            if(table[2][1][0] == table[2][0][0] && table[2][2][0] == table[2][0][0]) win = pturn;
            else if(table[1][0][0] == table[2][0][0] && table[0][0][0] == table[2][0][0]) win = pturn;
            else if(table[1][1][0] == table[2][0][0] && table[0][2][0] == table[2][0][0]) win = pturn;
        }
        else if(pposy == 2 && pposx == 1) {
            if(table[2][0][0] == table[2][1][0] && table[2][2][0] == table[2][1][0]) win = pturn;
            else if(table[1][1][0] == table[2][1][0] && table[0][1][0] == table[2][1][0]) win = pturn;
        }
        else if(pposy == 2 && pposx == 2) {
            if(table[2][1][0] == table[2][2][0] && table[2][0][0] == table[2][2][0]) win = pturn;
            else if(table[1][2][0] == table[2][2][0] && table[0][2][0] == table[2][2][0]) win = pturn;
            else if(table[1][1][0] == table[2][2][0] && table[0][0][0] == table[2][2][0]) win = pturn;
        }
        else if(pposy == 1 && pposx == 2) {
            if(table[0][2][0] == table[1][2][0] && table[2][2][0] == table[1][2][0]) win = pturn;
            else if(table[1][1][0] == table[1][2][0] && table[1][0][0] == table[1][2][0]) win = pturn;
        }
        else if(pposy == 0 && pposx == 2) {
            if(table[1][2][0] == table[0][2][0] && table[2][2][0] == table[0][2][0]) win = pturn;
            else if(table[0][1][0] == table[0][2][0] && table[0][0][0] == table[0][2][0]) win = pturn;
            else if(table[1][1][0] == table[0][2][0] && table[2][0][0] == table[0][2][0]) win = pturn;
        }
        else if(pposy == 0 && pposx == 1) {
            if(table[0][2][0] == table[0][1][0] && table[0][0][0] == table[0][1][0]) win = pturn;
            else if(table[1][1][0] == table[0][1][0] && table[2][1][0] == table[0][1][0]) win = pturn;
        }
        else if(pposy == 1 && pposx == 1) {
            if(table[0][2][0] == table[1][1][0] && table[2][0][0] == table[1][1][0]) win = pturn;
            else if(table[2][2][0] == table[1][1][0] && table[0][0][0] == table[1][1][0]) win = pturn;
            else if(table[0][1][0] == table[1][1][0] && table[2][1][0] == table[1][1][0]) win = pturn;
            else if(table[1][0][0] == table[1][1][0] && table[1][2][0] == table[1][1][0]) win = pturn;
        }
    }
    int verif = 0;
    for(int i=0; i<3; i++)
        for(int j=0;j<3;j++)
            if(table[i][j][0] == '_') verif = 1;
    if(verif == 0 && win == -1) cout<<endl<<"Ohh, no one wins!"<<endl;
    else if(tryagain == 0 && placed == 1 && stop == -1 && win == -1) {
        show_table();
        if(pturn == 0) pturn = 1;
        else pturn = 0;
        move_ch();
    }
    else if(tryagain == 1 && stop == -1 && win == -1) {
        cout<<"You are at edge or on this position is already placed a character, plase try another move.";
        move_ch();
    }
    else if(stop == -1 && win == -1) show_table(),move_ch();
    else if(win != -1) winner();
}



void start_game() {
    if(game_started == 0) {
        cout<<"The game will be started by player with 0 character."<<endl;
        if(choose_player == 0) cout<<player1_name<<"'s character is 0 and "<<player2_name<<"'s character is x.", pturn = 0;
        else cout<<player1_name<<"'s character is x and "<<player2_name<<"'s character is 0.", pturn = 1;
        cout<<endl<<endl;
    }
    cout<<"Type anything to continue! :)"<<endl;
    get_command();
    show_table();
    move_ch();
}

void choose_xor0()
{
    if(strcmp(player2_name, "Computer")==0) {
        cout<<"Because you play with computer you can choose your character, x or 0?:"<<endl;
        get_command();
        while(strcmp(command, "0")!=0 && strcmp(command, "x")!=0 && strcmp(command, "")!=0) {
            cout<<"Error, please enter x or 0:"<<endl;
            get_command();
        }
        if(strcmp(command, "0")==0) choose_player = 0;
        else choose_player = 1;
    }
    else {
        int randomvar;
        cout<<"Because you play with "<<player2_name<<" the character will be assigned randomly."<<endl<<endl;
        randomvar = rand()%100;
        if(randomvar%2 == 0) choose_player = 0;
        else choose_player = 1;
    }
    start_game();
}

void ready() {
    cout<<"Are you ready? If you are type \"start\", but if you want to cancel the game type \"cancel\"."<<endl;
    get_command();
    while(strcmp(command, "start")!=0 && strcmp(command, "cancel")!=0 && strcmp(command, "")!=0) {
        cout<<"Unrecognized command, please try again one of those variants: start or cancel."<<endl;
        get_command();
    }
    if(strcmp(command, "start")==0) choose_xor0();
    else cout<<"Bye! :(";
}

void welcome() {
    system("cls");
    cout<<"Hello this is a simple x and 0 game, you want to play with a real player or with computer?"<<endl;
    cout<<"Type \"player2\" if you want a real player or \"computer\" for a computer"<<endl;
    get_command();
    while(strcmp(command, "player2")!=0 && strcmp(command, "computer")!=0 && strcmp(command, "")!=0) {
        cout<<"Oops, your choice isn't one of the valid ones!"<<endl;
        cout<<"Type \"player2\" if you want a real player or \"computer\" for a computer"<<endl;
        get_command();
    }
    if(strcmp(command, "computer")==0) {
        cout<<"You chosed to play with a virtual opponent, now you need to add your player name:"<<endl;
        cin.get(player1_name, 30),cin.get();
    }
    else {
        cout<<"You chosed to play with a real opponent, now you need to add your player name:"<<endl;
        cin.get(player1_name, 30),cin.get();
        cout<<"Now add the opponent name:"<<endl;
        cin.get(player2_name, 30),cin.get();
    }
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            table[i][j][0] = '_';
    ready();
}

int main()
{
    srand(time(NULL));
    welcome();
    return 0;
}
