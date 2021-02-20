#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
class hostel
{
    int room_no;
    char name[30];
    char address[50];
    char phone[11];
    public:
    int main_menu();
    int add();
    int display();
    int rooms();
    int edit();
    int check(int);
    int modify(int);
    int delete_rec(int);
};
int hostel::main_menu()
{
    system("COLOR 30");
    int choice=0;
    while(choice!=5)
    {
        system("cls");
        system("COLOR 30");
        cout<<"\n\t\t\t\t*************";
        cout<<"\n\t\t\t\t* MAIN MENU *";
        cout<<"\n\t\t\t\t*************";
        cout<<"\n\n\n\t\t\t1.Book A Room";
        cout<<"\n\t\t\t2.student Record";
        cout<<"\n\t\t\t3.Rooms Allotted";
        cout<<"\n\t\t\t4.Edit Record";
        cout<<"\n\t\t\t5.Exit";
        cout<<"\n\n\t\t\tEnter Your Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1: add();
                    break;
            case 2: display();
                    break;
            case 3: rooms();
                    break;
            case 4: edit();
                    break;
            case 5:
                cout<<"\n\nThank you for using this application"<<endl;
                getch();
                break;
            default:
                    {
                        cout<<"\n\n\t\t\tWrong choice!!!";
                        cout<<"\n\t\t\tPress any key to continue!!";
                        getch();
                        break;
                    }
        }
    }
    return 0;
}
int hostel::add()
{
    int r,flag;
    ofstream fout("Record.dat",ios::app|ios::binary);
    system("cls");
    system("COLOR 81");
    cout<<"\n\t\t\t Enter Customer Detalis";
    cout<<"\n\t\t\t **********************";

    pqr:
    system("cls");
    cout<<"\n\n\t Enter room number between 1-100 .";
    cout<<"\n\n\t\t Room no: ";
    cin>>r;
    if(r>=1&&r<=100){
    flag=check(r);
    if(flag){
        cout<<"\n Sorry..!!!Room is already booked"<<endl;
        cout<<"\n Enter another Room number "<<endl;
        getch();
        goto pqr;
    }
    else
    {
        room_no=r;
        cout<<"\n\t\t Name:\t ";
        fflush(stdin);
        cin.getline(name,29);
        cout<<"\n\t\t Address:\t ";
        fflush(stdin);
        cin.getline(address,49);
        cout<<"\n\t\t Phone No:\t ";
        fflush(stdin);
        cin.getline(phone,10);
              cout<<endl;
        fout.write((char*)this,sizeof(*this));
        cout<<"\n\t\t Room is booked!!!";
    }
    }
    else{
        cout<<"\n\t\tRoom does not exist";
        goto pqr;
    }
    cout<<"\n \t\tPress any key to continue!!";
  getch();
    fout.close();
    return 0;
}
int hostel::display()
{
    ifstream fin("Record.dat",ios::app|ios::binary);
    int r,z=0;
    cout<<"\n\t\t Enter room no: ";
    cin>>r;
    if(r>=1 && r<=100)
        {
    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(*this));
           if(room_no == r)
                 {
                     system("cls");
                     system("COLOR B0");
            cout<<"\n\t\t\t Cusromer Details";
            cout<<"\n\t\t\t ****************";
            cout<<"\n\n\t\t\t\t Room no: "<<room_no;
            cout<<"\n\t\t\t\t Name: "<<name;
            cout<<"\n\t\t\t\t Address: "<<address;
            cout<<"\n\t\t\t\t Phone no: "<<phone<<endl;
            z=1;
              }
            fin.read((char*)this,sizeof(*this));
    }
     if(z==0){
        cout<<"\n\t\t Sorry Room no. not found or vacant!!";
              cout<<"\n\n\t\t Press any key to continue!!";
              }
    }
    else{
        cout<<"\n\t\tInvalid room number!!";
    }
    system("pause");
    fin.close();
    return 0;
}
int hostel::rooms()
{
    ifstream fin("Record.dat",ios::app|ios::binary);
     if(!fin)
    {
        cout<<"\nCan't open file!!"<<endl;
    }
    else
    {
        system("cls");
        system("COLOR 6F");
    cout<<"\n\t\t\tList Of Rooms Allotted";
    cout<<"\n\t\t\t*********************";
    cout<<"\n\n"<<setw(10)<<"ROOM NO."<<setw(30)<<"NAME"<<setw(50)<<"ADDRESS"<<setw(15)<<"PHONE NO.\n";
    cout<<""<<setw(10)<<"--------"<<setw(30)<<"----"<<setw(50)<<"-------"<<setw(15)<<"---------\n";
       while(!fin.eof())
       {
        fin.read((char*)this,sizeof(*this));
        cout<<"\n\n"<<setw(10)<<room_no<<setw(30)<<name;
        cout<<setw(50)<<address<<setw(15)<<phone;
       }
    cout<<"\n\n\n\t\t\tPress any key to continue!!";
       system("pause");
    fin.close();
    }
    return 0;
}
int hostel::edit()
{
    int choice=0,r;
    while(choice!=3){
    system("cls");
    system("COLOR D0");
    cout<<"\n\t\t\t EDIT MENU";
    cout<<"\n\t\t\t *********";
    cout<<"\n\n 1.Modify Customer Record";
    cout<<"\n 2.Delete Customer Record";
    cout<<"\n 3.Exit";
    cout<<"\n Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
             cout<<"\n Enter room no: ";
             cin>>r;
             if(r>=1 && r<=100)
                  {modify(r);
                  getch();
                  }
            else
                {cout<<"\nInvalid room number!!";
                getch();
                }
                break;
        case 2: cout<<"\n Enter room no: ";
                cin>>r;
                if(r>=1 && r<=100)
                   {delete_rec(r);
                   getch();
                   }
                else
                    {cout<<"\nInvalid room number!!";
                    getch();}
                break;
        case 3:
               cout<<"Thank you for using this system \n";
               getch();
               break;
        default: cout<<"\n Wrong Choice!!";
        getch();
        break;

    }
    }
    cout<<"\n Press any key to continue!!!";
    getch();
    return 0;
}
int hostel::check(int r)
{
    int flag=0;
    ifstream fin("Record.dat",ios::app|ios::binary);
    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(*this));
        if(room_no==r)
        {
            flag=1;
                break;
        }
    }
    fin.close();
    return(flag);
}
int hostel::modify(int r)
{
    long pos , flag;
    fstream file("Record.dat",ios::in|ios::out|ios::binary);
    flag=0;
    while(!file.eof())
       {
         pos=file.tellg();
        file.read((char*)this,sizeof(*this));
        if(room_no==r)
              {
                  system("cls");
                  system("COLOR F5");
            cout<<"\n\t\t\t Enter New Details";
            cout<<"\n\t\t\t *****************";
            cout<<"\n Name: ";
            fflush(stdin);
            cin.getline(name,29);
            cout<<" Address: ";
            fflush(stdin);
            cin.getline(address,49);
            cout<<" Phone no: ";
            cin>>phone;
            file.seekg(pos);
            file.write((char*)this,sizeof(*this));
            cout<<"\n Record is modified!!"<<endl;
            system("pause");
               flag=1;
            break;
              }}
    if(flag==0)
                     cout<<"\n Sorry Room no. not found or vacant!!";
              file.close();
              return 0;
              system("pause");
      return 0;
       }
int hostel::delete_rec(int r)
{
    int flag=0;
    char ch;
    ifstream fin("Record.dat",ios::in|ios::binary);
    ofstream fout("temp.dat",ios::out|ios::binary);
    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(*this));
        if(room_no==r)
        {
            system("cls");
            system("COLOR C0");
            cout<<"\n Name: "<<name;
            cout<<"\n Address: "<<address;
            cout<<"\n Pone No: "<<phone;
            cout<<"\n\n Do you want to delete this record(y/n): ";
            cin>>ch;
            if(ch=='n')
            fout.write((char*)this,sizeof(*this));
            flag=1;
        }
        else
            fout.write((char*)this,sizeof(*this));
    }
    fin.close();
    fout.close();
    if(flag==0)
        cout<<"\n Sorry room no. not found or vacant!!";
    else
    {
        remove("Record.dat");
        rename("temp.dat","Record.dat");
        return 0;
    }
    return 0;
}
class login
{
   public:
   char username[25];
   char password[25];
   char user[25];
   int role;
   public:
   login()
   {
       strcpy(username,"nothing");
       strcpy(password,"nothing");
       role = 0;
   }
   void enter_information()
   {
       system("cls");
    system("COLOR 5E");
    cout<<"\n\t\t\t Enter Customer Detalis";
    cout<<"\n\t\t\t **********************";
       name:
     cout<<"\n\t\t\tEnter username : ";
       fflush(stdin);
       cin.getline(username,24);
      int i=0;
      while(username[i]!='\0')
      {
          if(username[i]>='a'&&username[i]<='z'||username[i]>='A'&&username[i]<='Z')
            i++;
          else
          {
              cout<<"\n\t\tEnter a valid username (only use alphabets) ";
              goto name;
          }
      }
       pass:
      cout<<"\n\t\t\tEnter password : ";
       fflush(stdin);
       cin.getline(password,24);
        int j=0;
      while(password[j]!='\0')
      {
          if(!(password[j]==' '))
            j++;
          else
          {
              cout<<"\n\t\tEnter a valid password (Don't use spaces) ";
              goto pass;
          }
      }

       abc:
       cout<<"\n\t\tenter 1.student\t2.faculty";
       cin>>role;
       if(!(role == 1 || role == 2 ))
       {
           cout<<"\nwrong choice!!! "<<endl;
           goto abc;
       }
   }
   void show_information()
   {
       strcpy(user,(role==1)?"student":((role==2)?"faculty":"Invalid choice"));

       cout<<"\n"<<setw(30)<<username<<setw(30)<<password<<setw(20)<<user<<endl;
   }
    int show_information1()
   {
       strcpy(user,(role==1)?"student":((role==2)?"faculty":"Invalid choice"));

       cout<<"\n"<<setw(30)<<username<<setw(30)<<password<<setw(20)<<user<<endl;
       return role;
   }
   int store_information();
   void view_all_users();
   void search_user(char *u,char *p);
   int search_user1(char *u,char *p);
   void delete_user(char *u,char *p);
   void update_record(char *u,char *p);
};
void login::update_record(char *u,char *p)
{
    fstream file;
    file.open("login.dat",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof())
    {
        if(!strcmp(u,username))
        {
            if(!strcmp(p,password))
            {
                enter_information();
                //here we can write seekg or seekp both are same
                file.seekp(file.tellp()-sizeof(*this));
                file.write((char*)this,sizeof(*this));
            }
        }
        file.read((char*)this,sizeof(*this));
    }
    file.close();
}
void login::delete_user(char *u,char *p)
{
     ifstream fin;
     ofstream fout;
     fin.open("login.dat",ios::app|ios::binary);
     if(!fin)
     cout<<"\nFile not found!!";
     else{
         fout.open("templogin.dat",ios::out|ios::binary);
         fin.read((char*)this,sizeof(*this));
         while(!fin.eof()){

              if(strcmp(password,p)&&strcmp(username,u))
             {
                fout.write((char*)this,sizeof(*this));
             }
             fin.read((char*)this,sizeof(*this));
         }
         fin.close();
         fout.close();
         remove("login.dat");
         rename("templogin.dat","login.dat");
     }

}
void login::search_user(char *u,char *p)
{
    int counter=0;
    ifstream fin;
    fin.open("login.dat",ios::app|ios::binary);
    if(!fin)
    cout<<"\nCan't open file";
    else{
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            if(!strcmp(u,username))
            {if(!strcmp(p,password))
            {
                show_information();
                counter++;
            }
            }
            fin.read((char*)this,sizeof(*this));
        }
        if(counter==0)
        cout<<"\n\t\t\t\tYou are not registered!!!!!\n";
        fin.close();
        getch();
    }
}
int login::search_user1(char *u,char *p)
{
    int a=0;
    int counter=0;
    ifstream fin;
    fin.open("login.dat",ios::app|ios::binary);
    if(!fin)
    cout<<"\nCan't open file";
    else{
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            if(!strcmp(u,username))
            {if(!strcmp(p,password))
            {
                a=show_information1();
                counter++;
            }
            }
            fin.read((char*)this,sizeof(*this));
        }
        if(counter==0)
        cout<<"\n\t\t\t\tYou are not registered!!!!!\n";
        fin.close();
        getch();
    }
    return a;
}
void login::view_all_users()
{

       system("cls");
    system("COLOR F1");
    ifstream fin;
    fin.open("login.dat",ios::app|ios::binary);
    if(!fin)
    {
        cout<<"\nCan't open file!!"<<endl;
    }
    else
    {

        cout<<"\n\t\t\t*******************************************";
        cout<<"\n\t\t\t            List Of All Users              ";
        cout<<"\n\t\t\t*******************************************";
        cout<<"\n\n"<<setw(30)<<"USERNAME"<<setw(30)<<"PASSWORD"<<setw(20)<<"USER"<<endl;
        cout<<setw(30)<<"--------"<<setw(30)<<"--------"<<setw(20)<<"----"<<endl;
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            show_information();
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
    }

}
int login::store_information()
{
    if(strcmp(username,"nothing")==0 && strcmp(password,"nothing")==0)
    {
        cout<<"\t\t\t\tyou are not registered\n";
        return 0;
    }
    else
    {
        ofstream fout;
        fout.open("login.dat",ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
        return(1);
    }
}
class hostel_management:public hostel,public login
{
    public:
    int choice=0;
    int op=0;
    int r=0;
    char username[25];
    char password[25];
    void login_1()
    {
        system("COLOR 60");
        choice=0;
         while(choice!=3)
    {
        system("cls");
        system("COLOR 60");
        cout<<"\n\t\t\t\t |---------------------------------|";
        cout<<"\n\t\t\t\t<===================================>";
        cout<<"\n\t\t\t\t |---------------------------------|";
        cout<<"\n\t\t\t\t |          Login System           |";
        cout<<"\n\t\t\t\t |---------------------------------|";
        cout<<"\n\t\t\t\t<===================================>";
        cout<<"\n\t\t\t\t |---------------------------------|\n\n\n";
    cout<<"\n\t\t\t\t\t1. Register";
    cout<<"\n\t\t\t\t\t2. login";
    cout<<"\n\t\t\t\t\t3. Exit";
    cout<<"\n\t\t\t\tEnter your choice : ";
    cin>>choice;
        switch(choice)
        {
            case 1:
            enter_information();
            store_information();
            cout<<"\nRecord inserted";
            break;
            case 2:
            cout<<"\nEnter username :";
            fflush(stdin);
            cin.getline(username,24);
            cout<<"\nEnter password :";
            fflush(stdin);
            cin.getline(password,24);
            r=search_user1(username,password);
            switch(r){
                    case 2:
                   {
                       op=0;
                       while(op!=3){
                    system("cls");
                    system("COLOR 74");
                    cout<<"\n\n\t\t\t\tWelcome as faculty...."<<endl;
                    cout<<"\t\t\t\t----------------------\n\n"<<endl;
                    cout<<"\t\t1. View login information"<<endl;
                    cout<<"\t\t2. View Hostel information"<<endl;
                    cout<<"\t\t3. Exit"<<endl;
                    cout<<"\n\tEnter your choice : ";
                    cin>>op;
                         switch(op)
                         {
                           case 1:
                              login_menu();
                              system("pause");
                              break;
                           case 2:
                               main_menu();
                               system("pause");
                               break;
                            case 3:
                               cout<<"\n\t\t\t\t____Thank you for using this application___\n";
                               cout<<"\n\t\t\t\tPress any key to exit\n";
                               getch();
                               break;
                           default:
                               cout<<"\n\t\t\t\tInvalid choice!!!\n";
                               break;
                         }
                         getch();
                       }
                    }
                    break;
                    case 1:
                    {
                        op=0;
                        while(op!=3){
                        system("cls");
                        system("COLOR 03");
                        cout<<"\n\n\t\t\t\tWelcome as student....."<<endl;
                        cout<<"\t\t\t\t-----------------------\n\n\n"<<endl;
                        cout<<"\t\t1. Register for a room"<<endl;
                        cout<<"\t\t2. Visit your room"<<endl;
                        cout<<"\t\t3. Exit"<<endl;
                        cout<<"\n\tEnter your choice : ";
                         cin>>op;
                         switch(op)
                         {
                           case 1:
                              add();
                              system("pause");
                              break;
                           case 2:
                               cout<<"Enter your room information "<<endl;
                               display();
                               system("pause");
                               break;
                            case 3:
                               cout<<"\n\t\t\t\t____Thank you for using this application___\n";
                               cout<<"\n\t\t\t\tPress any key to exit\n";
                               getch();
                              break;
                           default:
                               cout<<"\n\t\t\t\tInvalid choice!!!\n";
                               getch();
                               break;
                         }
                         getch();
                          }}
                          break;
                  default:
                     cout<<"Invalid user!!!"<<endl;
                     getch();
                     break;
            }
            case 3:
            cout<<"\n\t\t\t\t___Thank you for using this application___\n";
            cout<<"\n\t\t\t\tPress any key to exit\n";
            getch();
            break;
            default:
            cout<<"\n\t\t\t\tInvalid choice\n";
            getch();
            break;
        }
    }
    }
    void login_menu()
    {
        system("COLOR 20");
        choice=0;
    while(choice!=6)
    {
        system("cls");
        system("COLOR 20");
         cout<<"\n\n\t\t\t\t*******Login System*******";
    cout<<"\n\t\t\t1. Register";
    cout<<"\n\t\t\t2. View all record";
    cout<<"\n\t\t\t3. Search a user";
    cout<<"\n\t\t\t4. Delete a user";
    cout<<"\n\t\t\t5. Update Student record";
    cout<<"\n\t\t\t6. Exit";
    cout<<"\n\t\tEnter your choice : ";
    cin>>choice;
        switch(choice)
        {
            case 1:
            enter_information();
            store_information();
            cout<<"\nRecord inserted";
            break;
            case 2:
            view_all_users();
            getch();
            break;
            case 3:
            cout<<"\nEnter username :";
            fflush(stdin);
            cin.getline(username,24);
            cout<<"\nEnter password :";
            fflush(stdin);
            cin.getline(password,24);
            search_user(username,password);
            break;
            case 4:
            cout<<"\nEnter details to delete record :-";
            cout<<"\nEnter username :";
            fflush(stdin);
            cin.getline(username,24);
            cout<<"\nEnter password :";
            fflush(stdin);
            cin.getline(password,24);
            delete_user(username,password);
            break;
            case 5:
            cout<<"\nEnter username and password to update:-";
            cout<<"\nEnter username :";
            fflush(stdin);
            cin.getline(username,24);
            cout<<"\nEnter password :";
            fflush(stdin);
            cin.getline(password,24);
            update_record(username,password);
            break;
            case 6:
            cout<<"\n\t\t\t\tThank you for using this application\n";
            cout<<"\n\t\t\t\tPress any key to exit\n";
            getch();
            break;
            default:
            cout<<"\n\t\t\t\tInvalid choice!!!\n";
            getch();
            break;
        }
    }
        getch();
}
};
int main()
{
    hostel_management h;
    h.login_1();
     system("pause");
     getch();
     return 0;
}
