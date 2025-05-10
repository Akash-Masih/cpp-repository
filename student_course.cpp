#include<iostream>
#include<string>
#include<array>
using namespace std;

class Course
{
    private:
        string code;
        string title;
        float creditHours;
    public:
        string getCode()
        {
            return code;
        }
        
        void setCode(string _code)
        {
            code = _code;
        }
        
        string getTitle()
        {
            return title;
        }
        
        void setTitle(string _title)
        {
            title = _title;
        }
        
        float getCreditHours()
        {
            return creditHours;
        }
        
        void setCreditHours(float _crHrs)
        {
            creditHours = _crHrs;
        }
        
};
class student
{
    private:
        string rn;
        string name;
        float crh;
        float pmarks;
    public:
        string getrn()
        {
        return rn;
        }
        void setrn(string _rn)
        {
            rn = _rn;
        }
        string getname()
        {
        return name;
        }
        void setrn(string _name)
        {
            name = _name;
        }
        float getcrh()
        {
        return crh;
        }
        void setcrh(float _crh)
        {
            crh = _crh;
        }
        float getpmarks()
        {
            return pmarks;
        }
        void setpmarks(float _pmarks)
        {
            pmarks = _pmarks;
        }
        void input_data()
        {
            cout << "Enter Student name : ";
            cin  >> rn;
            cout <<"Enter Roll number : ";
            cin  >> name;
            cout << "Enter Credit hours : ";
            cin  >> crh;

        }
        void show_data()
        {
            cout << "Details of The Student" << endl;
            cout << "Student Name   : " << name << endl;
            cout << "Roll number  : " << rn  << endl;
            cout << "Credit Hours: " << crh << endl;
        }
        void pmarks()
        {

        }


};

int main()
{
    Course a[4];
        a[0].setCode("CC-211");
        a[0].setTitle("Programing Fundamentals");
        a[0].setCreditHours(3);

        a[1].setCode("CC-212");
        a[1].setTitle("object orinted programming");
        a[1].setCreditHours(3);

        a[2].setCode("CC-213");
        a[2].setTitle("Data Structures and Algorithims");
        a[2].setCreditHours(3);

        a[3].setCode("CC-214");
        a[3].setTitle("Data Visualation");
        a[3].setCreditHours(3);
    
    for(int i=0; i<4; i++){

        cout << "Details of The Course" << endl;
        cout << "Code   : " << a[i].getCode() << endl;
        cout << "Title  : " << a[i].getTitle() << endl;
        cout << "Credits: " << a[i].getCreditHours() << endl;
    }
    
	return 0;
};

int main1()
{
    student obj[3];
        for (int i=0; i<3; i++)
        {
            obj[i].input_data();
        }
        for (int i=0; i<3; i++)
        {
            obj[i].show_data();
        }
    return 0;
    
}