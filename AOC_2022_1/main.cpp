
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void update(int* table[], int val){
    for(int i = 0; i < 3; i ++){
        if(val > (*table)[i]){
            cout<<"table = { "<< (*table)[0]<<" , "<< (*table)[1]<<" , "<<(*table)[2]<<" }"<<endl;
            cout<<"valeur à maj: "<<val<< endl;
            (*table)[i] = val;
            cout<<"table = { "<< (*table)[0]<<" , "<< (*table)[1]<<" , "<<(*table)[2]<<" }"<<endl;
            return;
        }
    }
    return;
}

int main(){
    fstream file;
    file.open("inputs.txt", ios::in);
    int* max{new int [3] {0,0,0}};


    int sum=0;
    if(!file.is_open()){
        cout<<"erreur d'ouverture du fichier"<<endl;
        exit(-1);
    }
    string line;
    while(getline(file, line)){
        if(line == ""){
            update(&max, sum);
            sum = 0;
        }else{
            sum += stoi(line);
        }
    }
    cout <<"la valeur maximale vaut donc: "<<max[0]<<" + "<<max[1]<<  " + " << max[2]<<" = "<<max[0]+max[1]+max[2]<<endl;
    delete [] max;
    return 0;
}