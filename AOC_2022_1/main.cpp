
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void update(int* table[], int val){
    for(int i = 0; i < 3; i ++){
        if(val > (*table)[i]){
            for(int j = 2; j>i; j--){
                (*table)[j] = (*table)[j-1];
            }
            (*table)[i] = val;
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