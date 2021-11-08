//IMPLEMENTATION OF BLOOD MANAGEMENT SYSTEM WITHIN A SMALL AREA

#include <iostream>
#include<string.h>
using namespace std;
class blood_bank
{
public:
    static int bloodgroup[8];
    static string group[8];

};
int blood_bank::bloodgroup[]={0,0,0,0,0,0,0,0};
string blood_bank::group[]={"A+","A-","B+","B-","O+","O-","AB+","AB-"};

class admin
{

public:

    void display();

    admin()
    {
        char s[20]="blood";
        char str[20];
        cout<<"Enter password: ";
        cin>>str;
        if(  strcmp(s,str)==0)
        {
            cout<<"welcome!!!"<<endl;
            display();
        }
        else
            cout<<"Please contact Admin to become an admin"<<endl;

    }
};


void admin::display()
{
    for (int i=0; i<8; i++)
        cout<<"\t"<<blood_bank::group[i]<< "  >>> "<<blood_bank::bloodgroup[i]<<endl;
}

class patient
{
    char name[50];
    char blood_group[20];


public:

    int save();
    void show(int);

};

int patient::save()
{
    int c,n;

    cout<<"Enter your name:";
    cin>>name;

    cout<<"Enter type of blood group you are looking for:"<<endl;

    for (int i=0; i<8; i++)
        cout<<"\t"<<i<<"\t"<<blood_bank::group[i]<<endl;


    cin>>c;

    show(c);
}

void patient::show(int c)
{
    cout<<"Availability of blood group : "<< blood_bank::bloodgroup[c]<<endl;

}

class donor
{
    char name[50];
    char sex[15];

    struct date
    {
        int day;
        int month;
        int year;
    }date;

    char blood_group[20];

    int phone_no[15];
public:

    int save();
    int display();

    int x,c;


};


int donor::save()
{
    cout<<"Enter your name:";
    cin>>name;

    cout<<"Enter your sex:";
    cin>>sex;

    cout<<"Enter date(DD MM YY):";
    cin>>date.day;
    cin>>date.month;
    cin>>date.year;


    cout<<"Enter type of blood group you are donating:"<<endl;

    for (int i=0; i<8; i++)
        cout<<"\t"<<i<<"\t"<<blood_bank::group[i]<<endl;

    cin>>c;

    blood_bank::bloodgroup[c]+=1;
    char ch;
    cout<<"Do you want your information to be displayed now(Y/N)";
    cin>>ch;

    if(ch=='Y'||ch=='y')
        donor::display();

}


int donor::display()
{
    cout<<"name:";
    cout<<name<<endl;

    cout<<"Date(DD MM YY):";
    cout<<date.day<<" ";
    cout<<date.month<<" ";
    cout<<date.year<<endl;

    cout<<"Blood group: "<< blood_bank::group[c];

}

int main()
{
    int i=0,j=0;
    donor a[100];
    patient b[50];

    int c=0;

    while(c!=4)
    {


        cout<<"\n\t 1 \t admin \n\t 2 \t donor \n\t 3 \t patient \n\t 4 \t exit \n";
        cin>>c;
        switch(c)
        {


            case 4:
                break;

            case 1:
            {
                admin t;
                char c;
                break;
            }

            case 2:
            {
                static int i=0;
                cout<<"welcome donor!!!"<<endl;
                cout<<"Please enter your information:"<<endl;
                a[i++].save();
                break;
            }

            case 3:
            {
                static int i=0;
                cout<<"Welcome patient!!!"<<endl;
                b[i++].save();
                break;
            }
        }
    }
    return 0;
}
