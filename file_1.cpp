#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ofstream MyFile("student.txt");

    MyFile << "Student Name:  Akash Masih '\n' Student ID:  BSDSF22M050 '\n' Department:  Data Science";

    MyFile.close();
    return 0;
}