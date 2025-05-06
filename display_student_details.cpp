#include<iostream>
using namespace std;

class Student{
    private:
        int roll;
        string name;
        string degree;
    public:
        void set_roll(int rn)
        {
            roll = rn;
        }
        int getroll()
        {
            return roll;
        }
        void set_name(string nm)
        {
            name = nm;
        }
        string getname(){
            return name;
        }
        void set_degree(string dg){
            degree = dg;
        }
        string getdegree(){
            return degree;
        }
    
};
int main()
{
    Student s1;
    s1.set_name("Akash");
    s1.set_roll(050);
    s1.set_degree("Data Science");
    cout <<"Name of Student is: " << s1.getname() << endl;
    cout <<"Roll NO of Student is: " << s1.getdegree() << endl;
    cout <<"Degree of Student is: " << s1.getroll() << endl;
    return 0;
}