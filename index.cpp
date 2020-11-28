#include<iostream>>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<fstream>
#include<windows.h>
#include<conio.h>
#include<string>
#include<vector>
#include"vehicle_list.h"
#include<unordered_map>
using namespace std;

string username;
int customer=1;
string enterpassword();
void wallet_func();
bool login();
//Our starting page
void startpage()
{
    system("COLOR F0");
    cout<<"     \n\n\n+++++++++++++++++++++++++++++++++++++++++++|  WELCOME TO RENTO   |++++++++++++++++++++++++++++++++++++++++++ \n\n\n ";
    cout<<"\n\n\n\n";
    cout<<"Loading required files...!!!!"<<endl;
    Sleep(1000);

    int choice;
    cout<<"1.Login \n";
    cout<<"2.Register \n";
    cout<<"Enter Your choice : ";
    cin>>choice;
    if(choice==1)
    {
        bool success=login();
        if(!success)
        {
            system("COLOR FC");
            cout<<"\n Sorry!!!!!!!! Login is unsuccessful !!!!!!!!!\n";
            cout<<"############Try to Login again###########\n";
            Sleep(2000);
            system("cls");
            startpage();
        }
        else
        {
            system("COLOR F2");
            cout<<"\n!!!!Welcome to our system , You have been successfully logged in!!!!!\n";
            Sleep(1000);
            system("cls");
        }
    }
    else if(choice==2)
    {
        string password;
        system("COLOR 60");
        cout<<"________Register form_________\n\n\n";
        cout<<"Enter username : ";
        cin>>username;
        cout<<endl;
        cout<<"Enter password(max:10 characters) : ";
        password=enterpassword();
        ofstream file;
        file.open(username+".txt");
        file<<username<<endl<<password;
        cout<<"\nThank you for registering with us!!!!!!!!!!!!!!!!!!!! \n";
        file.close();
        Sleep(1000);
        system("cls");
        startpage();

    }
}
//Our Login system which check details from the files
bool login()
{
    string pass,u,p;
    cout<<"Enter user name : ";
    cin>>username;
    cout<<"Enter Password(max:10 characters) : ";
    pass=enterpassword();
    ifstream read(username+".txt");
    getline(read,u);
    getline(read,p);

    if(username.compare("admin")==0)
        customer=0;
    if(u==username && p==pass)
        return true;
    else
        return false;


}
string enterpassword()
{
    char password[32];
    char a;
    int i=0;
    for(i=0;;)
    {
        a=getch();
        if(a>='a'&&a<='z'|| a>='A'&& a<='Z'|| a>='0'&& a<='9')
        {
            password[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b' && i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            password[i]='\0';
            break;
        }
    }
    return password;
}


class wallet
{
    int balance;
    string name,email,mobile_no;

public:
    void newregistration(string n,string mail,string mobile)
    {
        name=n;
        email=mail;
        mobile_no=mobile;
        fstream f;
        f.open("wallets.txt",ios::app);
        f<<endl<<username<<"  "<<name<<"  "<<email<<"   "<<mobile_no<<endl;
        f.close();
        balance=0;
        ofstream newf;
        newf.open(username+"_wallet.txt");
        newf<<"Balance: 0       "<<endl;
        newf<<"Previous Transactions are: ";
        newf.close();
    }
    void payment(){
    cout<<"Which mode you would like to choose: "<<endl;
    cout<<"1.) Credit card"<<endl;
    cout<<"2.) Debit card"<<endl;
    cout<<"3.) UPI"<<endl;
    int choice;
    cout<<"Enter your choice: ";
    cin>>choice;
    cout<<endl;
    do{
    switch(choice){
    case 1: {
    cout<<"Enter card number: ";
    string n;
    cin>>n;
    cout<<endl;
    cout<<"Enter expiration month: ";
    int m;
    cin>>m;
    cout<<endl;
    cout<<"Enter expiration Year: ";
    int y;
    cin>>y;
    cout<<endl;
    cout<<"Enter security code: ";
    int c;
    cin>>c;
    cout<<endl;

    break;}
    case 2: {cout<<"Enter card number: ";
    string n1;
    cin>>n1;
    cout<<endl;
    cout<<"Enter expiration month: ";
    int m1;
    cin>>m1;
    cout<<endl;
    cout<<"Enter expiration Year: ";
    int y1;
    cin>>y1;
    cout<<endl;
    cout<<"Enter security code: ";
    int c1;
    cin>>c1;
    cout<<endl;
    break;
    }
    case 3: {cout<<"Enter UPI id: ";
    string upi;
    cin>>upi;
    break;}
    default: cout<<"Choose correct option!!!!!"<<endl;
    }
    }while(choice>=4);
    }

    string wallet_handler(int bal){
        string s;
        string b=to_string(bal);
    int count=0;
    if(bal==0){
        s="Balance: "+b+"       ";
        return s;
    }
    while(bal>0){
        bal=bal/10;
        count++;
    }
    if(count==1){
    s="Balance: "+b+"       ";
    }
    else if(count==2){
        s="Balance: "+b+"      ";
    }
    else if(count==3){
        s="Balance: "+b+"     ";
    }

    else if(count==4){
        s="Balance: "+b+"    ";
    }
    else if(count==5){
        s="Balance: "+b+"   ";
    }
    else if(count==6){
        s="Balance: "+b+"  ";
    }
    else if(count==7){
        s="Balance: "+b+" ";
    }
    else{
        s="Balance: "+b;
    }

    return s;

    }

    void addmoney(int money)
    {   payment();
        if(money>0)
        {
            fstream fin;
            fin.open(username+"_wallet.txt");
            string u,v;
            fin>>u>>v;
            int balance= stoi(v);
            fin.close();
            fstream fout;
            fout.open(username+"_wallet.txt");
            balance+=money;
            //fout<<"Balance: "<<balance<<"    ";
            string a=wallet_handler(balance);
            fout<<a;
            fout.seekg(0,ios::end);
            fout<<"+"<<money<<" ";
            fout.close();
            cout<<endl<<"-------------------- AMOUNT IS ADDED SUCCESSFULLY!!!!!!!!--------------------------"<<endl;
        }
        else
        {
            cout<<"!!!!!!-------Sorry! please fill a valid entry--------!!!!!!!!"<<endl;
        }
    }
    void withdraw(int money)
    {
        fstream fin;
        fin.open(username+"_wallet.txt");
        string u,v;
        fin>>u>>v;
        int balance= stoi(v);
        fin.close();
        if(balance-money>=0)
        {
            fstream fout;
            fout.open(username+"_wallet.txt");
            string a;
            balance-=money;
            a=wallet_handler(balance);
            fout<<a;
            //fout<<"Balance: "<<balance<<"                ";
            fout.seekg(0,ios::end);
            fout<<"-"<<money<<" ";
            fout.close();
            cout<<endl<<"----------------------- AMOUNT IS WITHDRAWN SUCCESSFULLY!!!!!----------------------"<<endl;
        }
        else
            cout<<"!!!!!--------Sorry!! Insufficient balance------!!!!!"<<endl;
    }
    int checkbalance()
    {
        fstream fin;
        fin.open(username+"_wallet.txt");
        string u,v;
        fin>>u>>v;
        int balance= stoi(v);
        fin.close();
        return balance;
    }

    void print_previoustransaction()
    {
        fstream f;
        f.open(username+"_wallet.txt");
        string ux,vx;
        getline(f,ux);
        getline(f,vx);
        cout<<vx;
        f.close();

    }
};


class customer
{
public:
    string customer_name;
    string customer_email;
    string customer_phoneno;

};


class vehicle
{
public:

    int rent;
    int advance;
    int total_amount;
    int amount_left;
    int days;
    string document_to_be_submitted;
    string vehicle_number;
    static string city[];
    static int invoiceno;
    static string document[];

};
string vehicle::city[]= {"GOA","DELHI","AGRA","BENGALURU","UDAIPUR","SHIMLA","MANALI","KASOL","OOTY","RISHIKESH","MUSSOORIE"};
string vehicle::document[]={"PAN CARD","ADHAAR CARD","DRIVING LICENSE","PASSPORT"};

int vehicle::invoiceno=1000;

class car:private vehicle,private customer
{
    string car_name;

public:
    car()
    {
        rent=1000;
        advance=0;

    }
    void cars_startpage()
    {  printcarlist ca;
        cout<<"Please choose city in which you would like to rent a CAR!!!"<<endl;
        ca.showcat();
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        string choosen_city=city[choice-1];
        int ch;
        cout<<"\n\nFollowings CARS are available\n\n";
        ca.show_shop_per_cat(choosen_city);
        cout<<"\n\nEnter Your choice: ";
        cin>>ch;
        Node* found= ca.return_car(choosen_city,ch);
        car_name=found->return_car_name();
        rent=found->return_rent();
        cout<<"\n Chosen Car is: "<<car_name<<" and rent is: "<<rent<<endl;
        cout<<"Number of days you wish to rent the car : ";
        cin>>days;
        cout<<endl;
        cout<<"Do you want driver (y/n)"<<endl;
        cout<<"Note: Driver fees will be 25% of the rent of the car!!!"<<endl;
        char c;
        cin>>c;
        if(c=='y')
        {
            total_amount=1.25*rent*days;
        }
        else
            total_amount=rent*days;
        cout<<endl;
        cout<<"Total amount you have to pay is: "<<total_amount;
        cout<<endl;
        cout<<"Document you want to submit: "<<endl;
        for(int i=0;i<4;i++){
            cout<<i+1<<" ). "<<document[i]<<endl;
        }
        int dch;
        cout<<"Enter your choice: ";
        cin>>dch;
        document_to_be_submitted=document[dch-1];

        ifstream f(username+"_wallet.txt");
        wallet w;
        if(f){
                int b=w.checkbalance();
            cout<<"\n Your wallet balance is: "<<b<<endl;
          if(b<total_amount){

            int t=total_amount-b;
            if(t<=(total_amount*4)/5){
                    w.withdraw(b);
               cout<<"You have successfully paid for your car!!!!!!!!"<<endl;
               cout<<"Remaining amount is: "<<t;
               amount_left=t;
               cout<<"\n\nYou can pay the remaining amount later when you use our service"<<endl;
               cout<<"Enter your name: ";
               cin>>customer_name;
               cout<<"\nEnter your mobile number: ";
        cin>>customer_phoneno;
               book(choosen_city,c);
            }
            else{
                    int x= total_amount/5;
                cout<<"Please add "<<x-b<<" to your wallet as we require 20% advance payment"<<endl;
                wallet_func();

            }

          }
            else{
                w.withdraw(total_amount);
                cout<<"You have successfully paid for your car!!!!!!!!"<<endl;
                amount_left=0;
                cout<<"Enter your name: ";
               cin>>customer_name;
               cout<<"\nEnter your mobile number: ";
        cin>>customer_phoneno;
               book(choosen_city,c);
            }

        }
        else{
        cout<<"Total amount you have to pay: "<<total_amount<<endl;
        cout<<"Advance money you want to pay: ";
        cin>>advance;
        int temp=total_amount/2;
        while(advance<=temp){
            cout<<"Please pay advance more than 50% of your total rental amount!!!!!!!!!!"<<endl;
            cout<<"Advance money you want to pay: ";
        cin>>advance;
        }
        wallet w;
        w.payment();
        cout<<"----------------- You have successfully paid your Advance ----------------------------"<<endl;
        amount_left=total_amount-advance;
        cout<<"Enter your name: ";
        cin>>customer_name;
        cout<<"\nEnter your mobile number: ";
        cin>>customer_phoneno;
        book(choosen_city,c);
        }

    }

    void display_cites()
    {
        for(int i=0; i<11; i++)
        {
            cout<<" "<<i+1<<") "<<city[i]<<endl;
        }

    }

    void book(string city,char c)
    {   fstream fout;
    fout.open(customer_phoneno+".txt",ios::app);
        invoiceno++;
        fout << "\n\t\t                       Rento - Customer Invoice                  "<<endl;
        fout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
        fout << "\t\t	| Invoice No. :"<<"------------------|"<<setw(10)<<"#Cnb"<<invoiceno<<" |"<<endl;
        fout << "\t\t	| City Name   :"<<"-----------------|"<<setw(10)<<city<<" |"<<endl;
        fout << "\t\t	| Customer Name:"<<"-----------------|"<<setw(10)<<customer_name<<" |"<<endl;
        fout << "\t\t	| Customer Phone_no:"<<"-----------------|"<<setw(10)<<customer_phoneno<<" |"<<endl;
        fout << "\t\t	| Car Model :"<<"--------------------|"<<setw(10)<<car_name<<" |"<<endl;
        fout << "\t\t	| Required driver:"<<"-----------------|"<<setw(10)<<c<<" |"<<endl;
        fout << "\t\t	| Document submitted:"<<"-----------------|"<<setw(10)<<document_to_be_submitted<<" |"<<endl;
        fout << "\t\t	| Number of days :"<<"---------------|"<<setw(10)<<days<<" |"<<endl;
        fout << "\t\t	| Your Rental Amount is :"<<"--------|"<<setw(10)<<rent<<" |"<<endl;
        fout << "\t\t	| Advanced :"<<"---------------------|"<<setw(10)<<advance<<" |"<<endl;
        fout << "\t\t	 ________________________________________________________"<<endl;
        fout <<"\n";
        fout << "\t\t	| Total Rental Amount is :"<<"-------|"<<setw(10)<<amount_left<<" |"<<endl;
        fout << "\t\t	 ________________________________________________________"<<endl;
        fout << "\t\t	 # This is a computer generated invoice and it does not"<<endl;
        fout << "\t\t	 require an authorised signature #"<<endl;
        fout <<" "<<endl;
        fout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
        fout << "\t\t	Please pay the remaining amount at the time of pickup"<<endl;
        fout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
        print_bill();
        fout.close();
        system("PAUSE");

        system ("CLS");


    }
    void print_bill(){
    ifstream f;
    f.open(customer_phoneno+".txt");
    string line;
    while(f){
        getline(f,line);
        if(line=="-1")
            break;
        cout<<line<<endl;
    }
    f.close();

    }

};





class bike:private vehicle,private customer
{
    string bike_name;
public:
    bike()
    {

        rent=0;
    }

    void bike_startpage()
    {
        printbikelist ba;
        cout<<"Please choose city in which you would like to rent a BIKE/SCOOTY!!!"<<endl;
        ba.showcat();
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        string choosen_city=city[choice-1];
        int ch;
        cout<<"\n\nFollowings Bikes/Scooty are available\n\n";
        ba.show_shop_per_cat(choosen_city);
        cout<<"\n\nEnter Your choice: ";
        cin>>ch;
        Node* found= ba.return_bike(choosen_city,ch);
        bike_name=found->return_car_name();
        rent=found->return_rent();
        cout<<"\n Chosen Bike/Scooty is: "<<bike_name<<" and rent is: "<<rent<<endl;
        cout<<"Number of days you wish to rent the car : ";
        cin>>days;
        cout<<endl;
            total_amount=rent*days;
        cout<<endl;
        cout<<"Total amount you have to pay is: "<<total_amount;
        cout<<endl;
        cout<<"Document you want to submit: "<<endl;
        for(int i=0;i<4;i++){
            cout<<i+1<<" ). "<<document[i]<<endl;
        }
        int dch;
        cout<<"Enter your choice: ";
        cin>>dch;
        document_to_be_submitted=document[dch-1];
        ifstream f(username+"_wallet.txt");
        wallet w;
        if(f){
                int b=w.checkbalance();
            cout<<"\n Your wallet balance is: "<<b<<endl;
          if(b<total_amount){

            int t=total_amount-b;
            if(t<=(total_amount*4)/5){
                    w.withdraw(b);
               cout<<"You have successfully paid for your car!!!!!!!!"<<endl;
               cout<<"Remaining amount is: "<<t;
               amount_left=t;
               cout<<"\n\nYou can pay the remaining amount later when you use our service"<<endl;
               cout<<"Enter your name: ";
               cin>>customer_name;
               cout<<"\n Enter your mobile no: ";
               cin>>customer_phoneno;
               book(choosen_city);
            }
            else{
                    int x= total_amount/5;
                cout<<"Please add "<<x-b<<" to your wallet as we require 20% advance payment"<<endl;
                wallet_func();

            }

          }
            else{
                w.withdraw(total_amount);
                cout<<"You have successfully paid for your car!!!!!!!!"<<endl;
                amount_left=0;
                cout<<"Enter your name: ";
               cin>>customer_name;
               cout<<"\nEnter your mobile number: ";
        cin>>customer_phoneno;
               book(choosen_city);
            }

        }
        else{
        cout<<"Advance money you want to pay: ";
        cin>>advance;
        int temp=total_amount/2;
        while(advance<=temp){
            cout<<"Please pay advance more than 50% of your total rental amount";
            cin>>advance;
        }
        amount_left=total_amount-advance;
        cout<<"Enter customer name: ";
        cin>>customer_name;
        cout<<"\nEnter your mobile number: ";
        cin>>customer_phoneno;
        book(choosen_city);
        }

    }

    void display_cites()
    {
        for(int i=0; i<11; i++)
        {
            cout<<" "<<i+1<<") "<<city[i]<<endl;
        }

    }

    void book(string city)
    {
        fstream fout;
    fout.open(customer_phoneno+".txt",ios::app);
        invoiceno++;
        fout << "\n\t\t                       Rento - Customer Invoice                  "<<endl;
        fout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
        fout << "\t\t	| Invoice No. :"<<"------------------|"<<setw(10)<<"#Cnb"<<invoiceno<<" |"<<endl;
        fout << "\t\t	| City Name   :"<<"-----------------|"<<setw(10)<<city<<" |"<<endl;
        fout << "\t\t	| Customer Name:"<<"-----------------|"<<setw(10)<<customer_name<<" |"<<endl;
        fout << "\t\t	| Customer Phone no:"<<"-----------------|"<<setw(10)<<customer_phoneno<<" |"<<endl;
        fout << "\t\t	| Bike Model :"<<"--------------------|"<<setw(10)<<bike_name<<" |"<<endl;
        fout << "\t\t	| Number of days :"<<"---------------|"<<setw(10)<<days<<" |"<<endl;
        fout << "\t\t	| Your Rental Amount is :"<<"--------|"<<setw(10)<<rent<<" |"<<endl;
        fout << "\t\t	| Advanced :"<<"---------------------|"<<setw(10)<<advance<<" |"<<endl;
        fout << "\t\t	 ________________________________________________________"<<endl;
        fout <<"\n";
        fout << "\t\t	| Total Rental Amount is :"<<"-------|"<<setw(10)<<amount_left<<" |"<<endl;
        fout << "\t\t	 ________________________________________________________"<<endl;
        fout << "\t\t	 # This is a computer generated invoce and it does not"<<endl;
        fout << "\t\t	 require an authorised signture #"<<endl;
        fout <<" "<<endl;
        fout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
        fout << "\t\t	You are advised to pay up the amount before due date."<<endl;
        fout << "\t\t	Otherwise penalty fee will be applied"<<endl;
        fout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
        print_bill();
        system("PAUSE");

        system ("CLS");


    }
    void print_bill(){
    ifstream f;
    f.open(customer_phoneno+".txt");
    string line;
    while(f){
        getline(f,line);
        if(line=="-1")
            break;
        cout<<line<<endl;
    }
    f.close();

    }

};


void menu(){
 cout<<"What you would like to do: "<<endl;
        cout<<"1). Book CAR"<<endl;
        cout<<"2). Book BIKE"<<endl;
        cout<<"3). Wallet services"<<endl;
        cout<<"4.) Return from software"<<endl;
        cout<<"\n\n\n Note: 20% advance is required for our wallet user and 50% for non wallet user "<<endl;
int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice==1)
        {
            car c;
            c.cars_startpage();
        }
        else if(choice==2)
        {
            bike b;
            b.bike_startpage();
        }
        else if(choice==3)
        {
            wallet_func();

        }
        else
        {
            return;
        }
 menu();
}
int main()
{
    startpage();
          menu();



    return 0;
}


void wallet_func(){
wallet w1;
            ifstream fin(username+"_wallet.txt");
            if(fin)
            {   wal: cout<<endl<<"Welcome "<<username<<" to your RENTO Wallet"<<endl<<endl;
                cout<<"1). Add money"<<endl;
                cout<<"2). View previous transaction"<<endl;
                cout<<"3). Want to go to previous menu"<<endl;
                cout<<"Enter your choice: ";
                int wc;
                cin>>wc;
                switch(wc){

              case 1:
                cout<<"Enter amount you want to add to your wallet: ";
                int m;
                cin>>m;
                w1.addmoney(m);
                break;
              case 2:
                w1.print_previoustransaction();
                cout<<"\n\n";
                cout<<"Note: (+) means money is credited and (-) means money is debited"<<endl;
                break;
              case 3: cout<<"previous menu";
                    menu();
              break;

              default:
                cout<<"Please choose valid options!!!!!"<<endl;
                goto wal;

                }

            }
            else{
                cout<<"Sorry!!!!!!! you have not registered yourself to avail wallet benefits "<<endl<<endl<<endl;
                cout<<"1). Want to register for a wallet"<<endl;
                int c;
                cin>>c;
                if(c==1){
                string name,email,mobile;
                cout<<"Enter your name: ";
                cin.ignore();
                getline(cin,name);
                cout<<endl;
                cout<<"Enter your email id: ";
                //cin.ignore();
                getline(cin,email);
                cout<<endl;
                cout<<"Enter your mobile number: ";
                //cin.ignore();
                getline(cin,mobile);
                cout<<endl;
                wallet w;
                w.newregistration(name,email,mobile);

                }
            }

}
