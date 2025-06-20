#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
    string line;
    ifstream MyFile("student.txt");
    while(getline(MyFile,line)){
        cout << line <<endl;
    }
    MyFile.close();
    return 0;
}