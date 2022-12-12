#include <iostream>
using namespace std;

class Child
{
    public:
        Child();
        Child(string first, string last, int age);
        ~Child();

        bool operator <(const Child &c);
        bool operator >(const Child &c);
        bool operator ==(const Child &c);
        bool operator !=(const Child &c);
        friend ostream& operator <<(ostream &os, const Child &c);
        friend istream& operator >>(istream &in, Child &c);

    private:
        string firstname;
        string lastname;
        int age;
        double change;
};