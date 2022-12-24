
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define PLAYER_ROCK 1
#define PLAYER_PAPER 2
#define PLAYER_SCISOR 3

#define PLAYER_WIN 6
#define PLAYER_DRAW 3
#define PLAYER_LOSE 0


int main(){
    fstream file;
    file.open("inputs.txt", ios::in);
    int sum=0;
    if(!file.is_open()){
        cout<<"erreur d'ouverture du fichier"<<endl;
        exit(-1);
    }
    string line;
    while(getline(file, line)){
       switch(line[0]){
        case 'A': //l'ennemi joue pierre
            switch(line[2]){
                case 'X': //On doit perdre
                    sum = sum + PLAYER_LOSE+PLAYER_SCISOR;
                break;
                case 'Y': //on doit faire un draw
                    sum = sum + PLAYER_DRAW+PLAYER_ROCK;
                break;
                case 'Z': //on doit gagner
                    sum = sum + PLAYER_WIN+PLAYER_PAPER;
                break;
            }
        break;
        case 'B':// l'ennemi joue papier
             switch(line[2]){
                case 'X': //On doit perdre
                    sum = sum + PLAYER_LOSE+PLAYER_ROCK;
                break;
                case 'Y': //on doit faire un draw
                    sum = sum + PLAYER_DRAW+PLAYER_PAPER;
                break;
                case 'Z': //on doit gagner
                    sum = sum + PLAYER_WIN+PLAYER_SCISOR;
                break;
            }
        break;
        case 'C':// l'ennemi joue ciseaux
             switch(line[2]){
                case 'X': //On doit perdre
                    sum = sum + PLAYER_LOSE+PLAYER_PAPER;
                break;
                case 'Y': //on doit faire un draw
                    sum = sum + PLAYER_DRAW+PLAYER_SCISOR;
                break;
                case 'Z': //on doit gagner
                    sum = sum + PLAYER_WIN+PLAYER_ROCK;
                break;
            }
        break;
        
       }
    }
    cout<<"points totaux: "<<sum<<endl;
    return 0;
}