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
<<<<<<< HEAD
        int age;  

        // mussie
        int account;
        int 23; 
        string lastname;
        string first;

=======
        int age;
        double change;
>>>>>>> b7f201f87abc2eb2051793de41f25583dde7d4d3
};