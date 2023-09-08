#include<iostream>
using namespace std;
#include<fstream>
#include "mycontacts.cpp"
#include<iomanip>
#include<string.h>

contact obj;
void search_by_email()
{
    char email[50];
    cout<<endl<<"email";
    cin>>email;
    fstream rd;
    rd.open("datafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(obj.e,email)==0)
        {
            cout<<"record found";
            obj.display();
        }

            wr.write((char*)&obj,sizeof(obj));


    }
        rd.close();
        wr.close();
}

void search_by_mobile()
{
    char mobile[50];
    cout<<endl<<"mobile";
    cin>>mobile;
    fstream rd;
    rd.open("datafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(obj.m,mobile)==0)
        {
            cout<<"record found";
            obj.display();
        }

            wr.write((char*)&obj,sizeof(obj));


    }
        rd.close();
        wr.close();
}
void search_by_name()
{
    char name[50];
    cout<<endl<<"name";
    cin>>name;
    fstream rd;
    rd.open("datafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(obj.n,name)==0)
        {
            cout<<"record found";
            obj.display();
        }

            wr.write((char*)&obj,sizeof(obj));


    }
        rd.close();
        wr.close();
}
void update_contact()
{
    char name[50];
    cout<<endl<<"name";
    cin>>name;
    fstream rd;
    rd.open("datafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    wr.open("tempfile.txt",ios::app);
    int x=0;
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(obj.n,name)==0)
        {
            cout<<"record matched";
            obj.accept();
            x=1;
        }

            wr.write((char*)&obj,sizeof(obj));


    }
        if (x==0)
        {
            cout<<endl<<"record not found";
        }
        rd.close();
        wr.close();
        remove("datafile.txt");
        rename("tempfile.txt","datafile.txt");


}
void remove_contact()
{
    char name[50];
    cout<<endl<<"name";
    cin>>name;
    fstream rd;
    rd.open("datafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    wr.open("tempfile.txt",ios::app);
    int x=0;
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(obj.n,name)==0)
        {
            cout<<"record removed";
            x=1;
        }
        else
        {
            wr.write((char*)&obj,sizeof(obj));

        }
    }
        if (x==0)
        {
            cout<<"record not ";
        }

        rd.close();
        wr.close();
        remove("datafile.txt");
        rename("tempfile.txt","datafile.txt");

}
void addcontact()
{

    char name[50];
    cout<<endl<<"name";
    cin>>name;
    fstream rd;
    rd.open("datafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    int x=0;

    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(obj.n,name)==0)
        {
            cout<<"record found";
            x=1;
            break;

        }
    }


        if (x==0)
        {
            obj.accept();
            fstream wr;
            wr.open("datafile.txt",ios::app);
            wr.write((char*)&obj,sizeof (obj));
            wr.close();
            cout<<"file written ";
        }


    wr.close();
    rd.close();

}
void readdata()
{
    fstream rd;
    rd.open("datafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    cout<<endl;
    cout<<left;
    cout<<setw(30);
    cout<<"name";
    cout<<setw(30);
    cout<<"email";
    cout<<setw(30);
    cout<<"mobile number";
    cout<<setw(30);
    cout<<"instagram";
    cout<<setw(30);
    cout<<"twitter";
    cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    for(int i=1; i<=s; i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        obj.display();
    }
    cout<<endl<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
}

int main()
{
    int e=0;
    while(e==0)
    {
        cout<<endl<<"1 to add contact";
        cout<<endl<<"2 to read contacts";
        cout<<endl<<"3 to update contact";
        cout<<endl<<"4 to delete contact";
        cout<<endl<<"5 to search contact by name";
        cout<<endl<<"6 to search contact by mobile";
        cout<<endl<<"7 to search contact by email";
        cout<<endl<<"8 to exit";
        int choice;
        cin>>choice;
        if(choice==1)
        {
            addcontact();
        }
        else if(choice==2)
        {
            readdata();
        }
        else if(choice==3)
        {
            update_contact();
        }
        else if(choice==4)
        {
            remove_contact();
        }
        else if(choice==5)
        {
            search_by_name();
        }
        else if(choice==6)
        {
            search_by_mobile();
        }
        else if(choice==7)
        {
            search_by_email();
        }
        else
        {
            e=1;
        }
    }
}

