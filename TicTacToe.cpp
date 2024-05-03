// Tic Tac Toe Game

// Author : The_mantux(C)
// Date : 03-05-2024
// github : https://github.com/The-mantux

#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>


using namespace std;

// Colors
#define RESET       "\033[0m"
#define BLUE        "\033[1m\033[34m"  /*Player0*/
#define RED         "\033[1m\033[31m"  /*Player1*/
#define YELLOW      "\033[1m\033[33m"  /*beware error*/
#define GREEN       "\033[1m\033[32m"  /*Winner*/

// Prototypes
int  menu();
void printTutorialTable0();
void printTutorialTable1();
void gameTable(char table[3][3]);
int  game(char table[3][3],int x);
void tablePrint(char table[3][3]);
int  player0(char table[3][3],int vet[],int &counter);
int  checker(int cell[],int number);
void selectCell(int &row,int &col,int number);
void next();

int main(){

    int s,x,counter=0,row,col;

    char table[3][3]={
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };

    int cell[3*3];

    do{
        system("cls");
        s=menu();

        switch(s){

            case 1:{
                //Game

                x=rand() % 2 + 1;
                break;
            }

            case 2:{
                //Tutorial

                cout<<"\nPlayer 1 : "<<BLUE<<"X"<<RESET<<endl;
                cout<<"Player 2 : "<<RED<<"O"<<RESET<<endl;

                cout<<"\n";

                cout<<"At the beginning of the game you will be randomly chosen which player will start the game..."<<endl;

                next();
                cin.get();

                cout<<"This is the game table: \n";
                printTutorialTable0();
                cout<<"\nSelect the cell number you want to select..."<<endl;

                next();

                cout<<"At the end of the game the result will be such a thing: "<<endl;
                printTutorialTable1();

                next();

                cout<<"Keep track of your victories and defeats..."<<endl;
                cout<<"Game"<<endl;
                cout<<"Player 1 : "<<BLUE<< 15<<" Wins"<<RESET<<endl;
                cout<<"Player 2 : "<<RED<< 11<<" Wins"<<RESET<<endl;
                cout<<"Draws : "<<2<<endl;

                cout<<"\n\nNow it's time to play";

                next();

                break;
            }

            case 0:{
                //Exit
                cout<<BLUE<<"Bye"<<RESET<<endl;
                break;
            }

            default:{
                //Error
                cout<<RED<<"Error"<<RESET<<endl;
                break;
            }
        }

    }while(s!=0);

    return 0;
}

int game(char table[3][3],int x){
    
    if(x==1){
        //Player 0
        cout<<"Player 1 starts the game"<<endl;
    }
    else if(x==2){
        cout<<"Player 2 starts the game"<<endl;
    }

}

void tablePrint(char table[3][3]){

    cout<<"     |     |     "<<endl;
    cout<<"  "<<table[0][0]<<"  |  "<<table[0][1]<<"  |  "<<table[0][2]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<table[1][0]<<"  |  "<<table[1][1]<<"  |  "<<table[1][2]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<table[2][0]<<"  |  "<<table[2][1]<<"  |  "<<table[2][2]<<"  "<<endl;
    cout<<"     |     |     "<<endl;
}

int player0(char table[3][3],int vet[],int &counter){
    //Player 1

    int cell,c=0,c1=0;

    void tablePrint(char table[3][3]);

    do{

        cout<<"Select the cell number you want to select..."<<endl;
        cin>>cell;

        if(cell<1 || cell>9){
            cout<<RED<<"Insert an existing cell"<<RESET<<endl;
            c=-1;
        }

        c1=checker(vet,cell);
        
        if(c1==-1){
            cout<<RED<<"The cell is already occupied\n";
        }


    }while(c==-1 || c1==-1);

    vet[counter]=cell;
    counter++;

    return cell;
}

void selectCell(int &row,int &col,int number){

    if(number==1){
        row=0;
        col=0;
    }
    else if(number==2){
        row=0;
        col=1;
    }
    else if(number==3){
        row=0;
        col=2;
    }
    else if(number==4){
        row=1;
        col=0;
    }
    else if(number==5){
        row=1;
        col=1;
    }
    else if(number==6){
        row=1;
        col=2;
    }
    else if(number==7){
        row=2;
        col=0;
    }
    else if(number==8){
        row=2;
        col=1;
    }
    else if(number==9){
        row=2;
        col=2;
    }
}

int checker(int cell[],int number){

    bool check=false;

    for(int i=0;i<sizeof(cell);i++){

        if(cell[i]==number){
            check=true;
        }
    }

    if(check==true){
        return -1;
    }
    else{
        return 0;
    }
}

void printTutorialTable0(){

    cout<<"     |     |     "<<endl;
    cout<<"  1  |  2  |  3  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  4  |  5  |  6  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  7  |  8  |  9  "<<endl;
    cout<<"     |     |     "<<endl;
}

void printTutorialTable1(){

    cout<<"     |     |     "<<endl;
    cout<<"  "<<BLUE<<'X'<<RESET<<"  |  "<<RED<<'O'<<RESET<<"  |  "<<BLUE<<'X'<<"  "<<RESET<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<RED<<'O'<<RESET<<"  |  "<<RED<<'O'<<RESET<<"  |  "<<BLUE<<'X'<<"  "<<RESET<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<BLUE<<'X'<<RESET<<"  |  "<<BLUE<<'X'<<RESET<<"  |  "<<RED<<'O'<<"  "<<RESET<<endl;
    cout<<"     |     |     "<<endl;
}

int menu(){
    int s;

    cout<<BLUE<<"\t -----Menu'-----\n"<<RESET;
    cout<<BLUE<<"1."<<RESET<<" Play\n";
    cout<<BLUE<<"2."<<RESET<<" Tutorial\n";
    cout<<BLUE<<"0."<<RESET<<" Exit\n";

    cout<<"\nMake a choice: ";
    cin>>s;

    return s;
}

void next(){
    cout<<GREEN<<"\nPress any key to continue..."<<RESET;
    cin.ignore();
}