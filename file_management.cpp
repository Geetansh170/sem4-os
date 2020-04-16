#include<fstream>
#include<iostream>
#include<string>
using namespace std;

class stud
{
    int age;string name;
public:
    stud(int age,string name)
    {
        this->age=age;
        this->name=name;
    }
    void print()
    {
        cout<<" | "<<this->age<<" "<<this->name<<" | ";
    }
};

int main()
{
    cout<<"Binary files\n";
    fstream a;
    cout<<"Appending into the file name temp.dat\n";
    a.open("temp.dat",ios::binary|ios::app);
    cout<<"Enter the age and name of the student:";int age;string name;cin>>age>>name;
    stud ex(age,name);
    a.write((char*)&ex,sizeof(ex));
    cout<<"Closing file after appending\n";
    a.close();
    cout<<"Reading from file temp.dat\n\n";
    a.open("temp.dat",ios::binary|ios::in);
    while(a.read((char*)&ex,sizeof(ex)))
    {
        ex.print();
    }
    cout<<"\n\nClosing file";
    a.close();
    return 0;
}
