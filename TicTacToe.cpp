// Tic Tac Toe Game

// Author : The_mantux(C)
// Date : 03-05-2024
// github : https://github.com/The-mantux

#include<iostream>
#include <windows.h>
#include<string>

using namespace std;

// Colors
#define RESET       "\033[0m"
#define BLUE        "\033[1m\033[34m"  /*Player0*/
#define RED         "\033[1m\033[31m"  /*Player1*/
#define YELLOW      "\033[1m\033[33m"  /*beware error*/
#define GREEN       "\033[1m\033[32m"  /*Winner*/

// Prototypes
int menu();
void printTutorialTable();

int main(){

    int s;

    char table[3][3]={
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };

    do{
        system("cls");
        s=menu();

        switch(s){

            case 1:{
                //Game
                break;
            }

            case 2:{
                //Tutorial
                break;
            }

            case 0:{
                //Exit
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

void printTutorialTable(){

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