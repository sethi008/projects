#include<iomanip>
#include<iostream>
#include<fstream>
using namespace std;
class contact
{
protected:
    char n[50],m[50],e[50],i[50],t[50];
public:
    void accept()
    {

        cout<<endl<<"name";
        cin>>n;
        cout<<endl<<"mobile number";
        cin>>m;
        cout<<endl<<"email";
        cin>>e;
        cout<<endl<<"insta id";
        cin>>i;
        cout<<endl<<"twitter id";
        cin>>t;

    }
    void display()
    {
        cout<<endl;
        cout<<left;
        cout<<setw(30);
        cout<<n;
        cout<<setw(30);
        cout<<e;
        cout<<setw(30);
        cout<<m;
        cout<<setw(30);
        cout<<i;
        cout<<setw(30);
        cout<<t;

    }
    friend void remove_contact();
    friend void update_contact();
    friend void search_by_name();
    friend void search_by_mobile();
    friend void search_by_email();
    friend void addcontact();
};
void remove_contact();
void update_contact();
void search_by_name();
void search_by_mobile();
void search_by_email();
void addcontact();

