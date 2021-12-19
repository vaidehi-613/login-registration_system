#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool IsLoggedIn()
{
    string username,password;
    string un,pw;

    cout<<" Enter username : ";
    cin>>un;
    cout<<"Enter password : ";
    cin>>pw;

    ifstream fin;
    fin.open("Database.txt" );
    getline(fin,un);
    getline(fin,pw);

    if(un==username && pw==password)
    {
        return true;
    }
    else
    {
        return false;
    }

}


int main()
{
    int choice;
    cout<<"1.Registration "<<"\n"<<"2.Login "<<"\n"<<"3.Forgot credentials "<<endl;
    cout<<"enter your choice : ";
    cin>>choice;
    if(choice==1)
    {
        string username,password;

        cout<<" select username : ";
        cin>>username;
        cout<<" select password : ";
        cin>>password;

        ofstream fout;
        fout.open("Database.txt");
        fout<<username<<endl<<password;
        fout.close();

        main();
    }
    else if(choice==2){
        bool status = IsLoggedIn();

        if(!status)
        {
            cout<<"Failed to Login !!! "<<endl;
            return 0;
        }
        else{
            cout<<"Logged in Successfully !!!"<<endl;
            return 1;
        }
    }


}
