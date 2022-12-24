
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

int normalize(char c){
    string vec = "abcdefghijklmnopqrstuvwxyz";
    return isupper(c)? vec.find((char) tolower(c))+27:vec.find(c)+1; 
}

int  parse(string p1, string p2){
    for(int i =0; i<p1.size(); i++){
        if(p2.find(p1[i]) != std::string::npos){
            cout<<"carractère commun: "<<p1[i]<<endl;
            cout<<"priorité: " <<normalize(p1[i])<<endl;
            return normalize(p1[i]);
        }
    }
    return -1;
}

int main(){
    fstream file;
    file.open("inputs.txt", ios::in);
    int sum=0;
    if(!file.is_open()){
        cout<<"erreur d'ouverture du fichier"<<endl;
        exit(-1);
    }
    string line;
    string m1, m2;
    while(getline(file, line)){
      /*m1 = line.substr(0, (line.length()/2));
      m2 = line.substr(line.length()/2,line.length());
      cout<<"ligne totale: "<<line<<endl<<"moitié 1: "<<m1<<endl<<"moitié 2: "<<m2<<endl;*/
      sum += parse(m1,m2);
    }
    cout<<"somme "<<sum<<endl;
    return 0;
}