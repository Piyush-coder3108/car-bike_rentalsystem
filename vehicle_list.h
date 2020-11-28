#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

class Node
{
    friend class List;

    int flag;
    int pos;
    Node *link;
    Node *down;
    string val;
        int rent;
    public:

        Node() {
            val = "NULL";
            link = NULL;
            flag=0;
            pos=0;
            rent=0;
            down=NULL;
        }
         Node(string v) {
            val = v;
            link = NULL;
            down=NULL;
            flag=0;
            pos=0;
            rent=0;

        }
        Node(string v,int p) {
            val = v;
            link = NULL;
            down=NULL;
            flag=0;
            pos=p;
            rent =0;
        }
        Node(string v,int p,int r) {
            val = v;
            link = NULL;
            down=NULL;
            flag=0;
            pos=p;
            rent =r;
        }

        string return_car_name(){
        return val;
        }
        int return_rent(){
        return rent;
        }
};

class List
{

    Node *head;
    public:
        List() {
            head = new Node();


        }
        void append(string,string,int);
        void append(string,string,string,int,int);
        void append(string);
        void show_cat();
        void show();
        void show(Node*);
        void display(Node*);
        Node* search_child(string,string);
        Node* search_element(string);
        Node* search_child_child(Node*,string);
        Node* return_child(string,int);
};
Node* List::search_element(string v){
Node * temp=head;
while(temp!=NULL){
    if(temp->val==v)
        return temp;
    temp=temp->link;
}

}


Node* List::search_child(string a,string b){
Node* temp= head;
while(temp!=NULL){
    if(temp->val==a){
        Node* temp2= temp->down;
        while(temp2!=NULL){
                if(temp2->val==b)
                    return temp2;
            temp2=temp2->link;
        }

    }
     temp=temp->link;
}


}

Node* List::return_child(string a,int b){
 Node* temp= head;
while(temp!=NULL){
    if(temp->val==a){
        Node* temp2= temp->down;
        while(temp2!=NULL){
            Node* tem= temp2->down;
                while(tem!=NULL){
                if(tem->pos==b)
                    return tem;
                  tem=tem->link;
                }
            temp2=temp2->link;

        }

    }
     temp=temp->link;
}

}




Node* List::search_child_child(Node* a,string b){
Node* temp= a->down;
while(temp!=NULL){
    if(temp->flag==1){
        Node* temp2= temp->down;
        while(temp2!=NULL){
                if(temp2->val==b)
                    return temp2;
            temp2=temp2->link;
        }

    }
     temp=temp->link;
}


}
void List::append(string item)
{
    Node *pivot = new Node(item);
    if (head==NULL) {
        head= pivot;
    }
    else {
        Node *temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = pivot;
    }

}


void List::append(string v,string item,int p)
{
    Node* newnode= new Node(item,p);

    Node *found= search_element(v);
    if(found->down==NULL){
            found->flag=1;
        found->down=newnode;
    }
    else{

        Node*temp= found->down;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=newnode;
    }

}
void List::append(string a,string b, string c,int p, int r){
Node* newnode=new Node(c,p,r);
Node* found= search_child(a,b);
if(found->down==NULL){
            found->flag=1;
        found->down=newnode;
    }
    else{

        Node* temp= found->down;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=newnode;
    }




}


void List::show()
{
   Node* temp= head;
    temp=temp->link;
   while(temp!=NULL){
    cout<<"\t"<<temp->val<<endl;
    if(temp->flag==1){
        display(temp);
    }
    temp=temp->link;
   }
}

void List::show_cat(){
Node* temp= head;
temp=temp->link;
int i=1;
while(temp!=NULL){
    cout<<"\t\t\t\t"<<i<<" ) "<<temp->val<<endl;
    temp=temp->link;
    i++;
}


}
void List::display(Node* h){
    Node* temp=h->down;
    int i=1;
    while(temp!=NULL){

                cout<<"\t\t# "<<temp->val<<endl;

            if(temp->flag==1){
                show(temp);
            }
        temp=temp->link;

    }

}

void List::show(Node* h){
 Node* temp=h->down;
    while(temp!=NULL){
            cout<<"\t\t\t"<<temp->pos<<"). "<<temp->val<<"      Rent: "<<temp->rent<<endl;
        temp=temp->link;
    }
}


class printcarlist{
List a;
public:
    printcarlist(){
        a.append("GOA");
        a.append("DELHI");
        a.append("AGRA");
        a.append("BENGALURU");
        a.append("UDAIPUR");
        a.append("SHIMLA");
        a.append("MANALI");
        a.append("KASOL");
        a.append("OOTY");
        a.append("RISHIKESH");
        a.append("MUSSOORIE");




        a.append("GOA","TATA",0);
        a.append("GOA","HYUNDAI",0);
        a.append("GOA","RENAULT",0);
        a.append("GOA","TOYOTA",0);
        a.append("GOA","MAHINDRA",0);
        a.append("GOA","HONDA",0);
        a.append("GOA","MARUTI SUZUKI",0);
        a.append("GOA","TATA","TIAGO",1,2000);
        a.append("GOA","TATA","HARRIER",2,3300);
        a.append("GOA","TATA","NEXON",3,2400);
        a.append("GOA","TATA","SAFARI",4,3400);
        a.append("GOA","HYUNDAI","i20",5,2000);
        a.append("GOA","HYUNDAI","Verna",6,2900);
        a.append("GOA","HYUNDAI","Creta",7,3200);
        a.append("GOA","HYUNDAI","Venue",8,3300);
        a.append("GOA","RENAULT","KWID",9,1900);
        a.append("GOA","RENAULT","DUSTER",10,2800);
        a.append("GOA","RENAULT","CAPTUR",11,3000);
        a.append("GOA","TOYOTA","INNOVA",12,2800);
        a.append("GOA","TOYOTA","FORTUNER",13,3500);
        a.append("GOA","TOYOTA","ETIOS",14,2600);
        a.append("GOA","MAHINDRA","THAR",15,3000);
        a.append("GOA","MAHINDRA","XUV 300",16,3000);
        a.append("GOA","HONDA","BRIO",17,2300);
        a.append("GOA","HONDA","CITY",18,2700);
        a.append("GOA","HONDA","WR-V",19,2500);
        a.append("GOA","MARUTI SUZUKI","BALENO",20,2300);
        a.append("GOA","MARUTI SUZUKI","SWIFT DEZIRE",21,2200);
        a.append("GOA","MARUTI SUZUKI","WAGONR",22,1900);
        a.append("GOA","MARUTI SUZUKI","RITZ",23,2000);


        a.append("DELHI","HONDA",0);
        a.append("DELHI","MARUTI SUZUKI",0);
        a.append("DELHI","TATA",0);
        a.append("DELHI","TOYOTA",0);
        a.append("DELHI","HYUNDAI",0);
        a.append("DELHI","HONDA","BRIO",1,2100);
        a.append("DELHI","HONDA","CITY",2,2500);
        a.append("DELHI","MARUTI SUZUKI","BALENO",3,2300);
        a.append("DELHI","MARUTI SUZUKI","SWIFT DEZIRE",4,2200);
        a.append("DELHI","MARUTI SUZUKI","WAGONR",5,1900);
        a.append("DELHI","MARUTI SUZUKI","RITZ",6,2000);
        a.append("DELHI","MARUTI SUZUKI","EECO",7,2200);
        a.append("DELHI","TATA","TIAGO",8,1800);
        a.append("DELHI","TATA","HARRIER",9,3000);
        a.append("DELHI","TATA","NEXON",10,2200);
        a.append("DELHI","TATA","SAFARI",11,3200);
        a.append("DELHI","TOYOTA","INNOVA",12,2800);
        a.append("DELHI","TOYOTA","FORTUNER",13,3500);
        a.append("DELHI","TOYOTA","ETIOS",14,2600);
        a.append("DELHI","HYUNDAI","Verna",15,2900);
        a.append("DELHI","HYUNDAI","Creta",16,3200);
        a.append("DELHI","HYUNDAI","Venue",17,3300);


         a.append("AGRA","HONDA",0);
        a.append("AGRA","MARUTI SUZUKI",0);
        a.append("AGRA","TATA",0);
        a.append("AGRA","TOYOTA",0);
        a.append("AGRA","HYUNDAI",0);
        a.append("AGRA","HONDA","BRIO",1,2200);
        a.append("AGRA","HONDA","CITY",2,2400);
        a.append("AGRA","MARUTI SUZUKI","BALENO",3,2000);
        a.append("AGRA","MARUTI SUZUKI","SWIFT DEZIRE",4,2100);
        a.append("AGRA","MARUTI SUZUKI","WAGONR",5,1800);
        a.append("AGRA","MARUTI SUZUKI","RITZ",6,2100);
        a.append("AGRA","MARUTI SUZUKI","EECO",7,2000);
        a.append("AGRA","TATA","TIAGO",8,1900);
        a.append("AGRA","TATA","HARRIER",9,2900);
        a.append("AGRA","TATA","NEXON",10,2100);
        a.append("AGRA","TATA","SAFARI",11,3000);
        a.append("AGRA","TOYOTA","INNOVA",12,2800);
        a.append("AGRA","TOYOTA","FORTUNER",13,3500);
        a.append("AGRA","HYUNDAI","Verna",14,2900);
        a.append("AGRA","HYUNDAI","Creta",15,3200);
        a.append("AGRA","HYUNDAI","Venue",16,3300);


        a.append("BENGALURU","HONDA",0);
        a.append("BENGALURU","MARUTI SUZUKI",0);
        a.append("BENGALURU","TATA",0);
        a.append("BENGALURU","TOYOTA",0);
        a.append("BENGALURU","HYUNDAI",0);
        a.append("BENGALURU","HONDA","BRIO",1,2100);
        a.append("BENGALURU","HONDA","CITY",2,2500);
        a.append("BENGALURU","MARUTI SUZUKI","BALENO",3,2300);
        a.append("BENGALURU","MARUTI SUZUKI","SWIFT DEZIRE",4,2200);
        a.append("BENGALURU","MARUTI SUZUKI","WAGONR",5,1900);
        a.append("BENGALURU","MARUTI SUZUKI","RITZ",6,2000);
        a.append("BENGALURU","MARUTI SUZUKI","EECO",7,2200);
        a.append("BENGALURU","TATA","TIAGO",8,1800);
        a.append("BENGALURU","TATA","HARRIER",9,3000);
        a.append("BENGALURU","TATA","NEXON",10,2200);
        a.append("BENGALURU","TATA","SAFARI",11,3200);
        a.append("BENGALURU","TOYOTA","INNOVA",12,2800);
        a.append("BENGALURU","TOYOTA","FORTUNER",13,3500);
        a.append("BENGALURU","TOYOTA","ETIOS",14,2600);
        a.append("BENGALURU","HYUNDAI","Verna",15,2900);
        a.append("BENGALURU","HYUNDAI","Creta",16,3200);
        a.append("BENGALURU","HYUNDAI","Venue",17,3300);

        a.append("UDAIPUR","HONDA",0);
        a.append("UDAIPUR","MARUTI SUZUKI",0);
        a.append("UDAIPUR","TATA",0);
        a.append("UDAIPUR","TOYOTA",0);
        a.append("UDAIPUR","HYUNDAI",0);
        a.append("UDAIPUR","HONDA","BRIO",1,2100);
        a.append("UDAIPUR","HONDA","CITY",2,2500);
        a.append("UDAIPUR","MARUTI SUZUKI","BALENO",3,2300);
        a.append("UDAIPUR","MARUTI SUZUKI","SWIFT DEZIRE",4,2200);
        a.append("UDAIPUR","MARUTI SUZUKI","WAGONR",5,1900);
        a.append("UDAIPUR","MARUTI SUZUKI","RITZ",6,2000);
        a.append("UDAIPUR","MARUTI SUZUKI","EECO",7,2200);
        a.append("UDAIPUR","TATA","TIAGO",8,1800);
        a.append("UDAIPUR","TATA","HARRIER",9,3000);
        a.append("UDAIPUR","TATA","NEXON",10,2200);
        a.append("UDAIPUR","TATA","SAFARI",11,3200);
        a.append("UDAIPUR","TOYOTA","INNOVA",12,2800);
        a.append("UDAIPUR","TOYOTA","FORTUNER",13,3500);
        a.append("UDAIPUR","TOYOTA","ETIOS",14,2600);
        a.append("UDAIPUR","HYUNDAI","Verna",15,2900);
        a.append("UDAIPUR","HYUNDAI","Creta",16,3200);
        a.append("UDAIPUR","HYUNDAI","Venue",17,3300);


        a.append("SHIMLA","HONDA",0);
        a.append("SHIMLA","MARUTI SUZUKI",0);
        a.append("SHIMLA","TATA",0);
        a.append("SHIMLA","TOYOTA",0);
        a.append("SHIMLA","HYUNDAI",0);
        a.append("SHIMLA","HONDA","BRIO",1,2100);
        a.append("SHIMLA","HONDA","CITY",2,2500);
        a.append("SHIMLA","MARUTI SUZUKI","BALENO",3,2300);
        a.append("SHIMLA","MARUTI SUZUKI","SWIFT DEZIRE",4,2200);
        a.append("SHIMLA","MARUTI SUZUKI","WAGONR",5,1900);
        a.append("SHIMLA","MARUTI SUZUKI","RITZ",6,2000);
        a.append("SHIMLA","MARUTI SUZUKI","EECO",7,2200);
        a.append("SHIMLA","TATA","TIAGO",8,1800);
        a.append("SHIMLA","TATA","HARRIER",9,3000);
        a.append("SHIMLA","TATA","NEXON",10,2200);
        a.append("SHIMLA","TATA","SAFARI",11,3200);
        a.append("SHIMLA","TOYOTA","INNOVA",12,2800);
        a.append("SHIMLA","TOYOTA","FORTUNER",13,3500);
        a.append("SHIMLA","HYUNDAI","Verna",14,2900);
        a.append("SHIMLA","HYUNDAI","Creta",15,3200);
        a.append("SHIMLA","HYUNDAI","Venue",16,3300);

        a.append("MANALI","HONDA",0);
        a.append("MANALI","MARUTI SUZUKI",0);
        a.append("MANALI","TATA",0);
        a.append("MANALI","TOYOTA",0);
        a.append("MANALI","HYUNDAI",0);
        a.append("MANALI","HONDA","BRIO",1,2100);
        a.append("MANALI","HONDA","CITY",2,2500);
        a.append("MANALI","MARUTI SUZUKI","BALENO",3,2300);
        a.append("MANALI","MARUTI SUZUKI","SWIFT DEZIRE",4,2200);
        a.append("MANALI","MARUTI SUZUKI","WAGONR",5,1900);
        a.append("MANALI","MARUTI SUZUKI","RITZ",6,2000);
        a.append("MANALI","MARUTI SUZUKI","EECO",7,2200);
        a.append("MANALI","TATA","TIAGO",8,1800);
        a.append("MANALI","TATA","HARRIER",9,3000);
        a.append("MANALI","TATA","NEXON",10,2200);
        a.append("MANALI","TATA","SAFARI",11,3200);
        a.append("MANALI","TOYOTA","INNOVA",12,2800);
        a.append("MANALI","TOYOTA","FORTUNER",13,3500);
        a.append("MANALI","TOYOTA","URBAN CRUISER",14,2600);
        a.append("MANALI","HYUNDAI","Verna",15,2900);
        a.append("MANALI","HYUNDAI","Creta",16,3200);
        a.append("MANALI","HYUNDAI","Venue",17,3300);


       a.append("KASOL","HONDA",0);
        a.append("KASOL","MARUTI SUZUKI",00);
        a.append("KASOL","TATA",0);
        a.append("KASOL","TOYOTA",0);
        a.append("KASOL","HYUNDAI",0);
        a.append("KASOL","HONDA","BRIO",1,2100);
        a.append("KASOL","HONDA","CITY",2,2500);
        a.append("KASOL","MARUTI SUZUKI","BALENO",3,2300);
        a.append("KASOL","MARUTI SUZUKI","SWIFT DEZIRE",4,2200);
        a.append("KASOL","MARUTI SUZUKI","WAGONR",5,1900);
        a.append("KASOL","MARUTI SUZUKI","RITZ",6,2000);
        a.append("KASOL","MARUTI SUZUKI","EECO",7,2200);
        a.append("KASOL","TATA","TIAGO",8,1800);
        a.append("KASOL","TATA","HARRIER",9,3000);
        a.append("KASOL","TATA","NEXON",10,2200);
        a.append("KASOL","TATA","SAFARI",11,3200);
        a.append("KASOL","TOYOTA","INNOVA",12,2800);
        a.append("KASOL","TOYOTA","FORTUNER",13,3500);
        a.append("KASOL","TOYOTA","ETIOS",14,2600);
        a.append("KASOL","HYUNDAI","Verna",15,2900);
        a.append("KASOL","HYUNDAI","Creta",16,3200);
        a.append("KASOL","HYUNDAI","Venue",17,3300);


        a.append("OOTY","HONDA",0);
        a.append("OOTY","MARUTI SUZUKI",0);
        a.append("OOTY","TATA",0);
        a.append("OOTY","TOYOTA",0);
        a.append("OOTY","HYUNDAI",0);
        a.append("OOTY","HONDA","BRIO",1,2100);
        a.append("OOTY","HONDA","CITY",2,2500);
        a.append("OOTY","MARUTI SUZUKI","BALENO",3,2300);
        a.append("OOTY","MARUTI SUZUKI","SWIFT DEZIRE",4,2200);
        a.append("OOTY","MARUTI SUZUKI","WAGONR",5,1900);
        a.append("OOTY","MARUTI SUZUKI","ERTIGA",6,2500);
        a.append("OOTY","MARUTI SUZUKI","VITARA BREZZA",7,2500);
        a.append("OOTY","TATA","TIAGO",8,1800);
        a.append("OOTY","TATA","HARRIER",9,3000);
        a.append("OOTY","TATA","NEXON",10,2200);
        a.append("OOTY","TATA","SAFARI",11,3200);
        a.append("OOTY","TOYOTA","INNOVA",12,2800);
        a.append("OOTY","TOYOTA","FORTUNER",13,3500);
        a.append("OOTY","TOYOTA","ETIOS",14,2600);
        a.append("OOTY","HYUNDAI","Verna",15,2900);
        a.append("OOTY","HYUNDAI","Creta",16,3200);
        a.append("OOTY","HYUNDAI","Venue",17,3300);



        a.append("RISHIKESH","HONDA",0);
        a.append("RISHIKESH","MARUTI SUZUKI",0);
        a.append("RISHIKESH","TATA",0);
        a.append("RISHIKESH","TOYOTA",0);
        a.append("RISHIKESH","HYUNDAI",0);
        a.append("RISHIKESH","MAHINDRA",0);
        a.append("RISHIKESH","HONDA","BRIO",1,2100);
        a.append("RISHIKESH","HONDA","CITY",2,2500);
        a.append("RISHIKESH","MARUTI SUZUKI","BALENO",3,2300);
        a.append("RISHIKESH","MARUTI SUZUKI","SWIFT DEZIRE",4,2200);
        a.append("RISHIKESH","MARUTI SUZUKI","WAGONR",5,1900);
        a.append("RISHIKESH","MARUTI SUZUKI","RITZ",6,2000);
        a.append("RISHIKESH","MARUTI SUZUKI","EECO",7,2200);
        a.append("RISHIKESH","TATA","TIAGO",8,1800);
        a.append("RISHIKESH","TATA","HARRIER",9,3000);
        a.append("RISHIKESH","TATA","NEXON",10,2200);
        a.append("RISHIKESH","TATA","SAFARI",11,3200);
        a.append("RISHIKESH","TOYOTA","INNOVA",12,2800);
        a.append("RISHIKESH","TOYOTA","FORTUNER",13,3500);
        a.append("RISHIKESH","TOYOTA","ETIOS",14,2600);
        a.append("RISHIKESH","HYUNDAI","SANTA FE",15,2900);
        a.append("RISHIKESH","HYUNDAI","Creta",16,3200);
        a.append("RISHIKESH","HYUNDAI","Venue",17,3300);
        a.append("RISHIKESH","MAHINDRA","SCORPIO",18,2800);



        a.append("MUSSOORIE","HONDA",0);
        a.append("MUSSOORIE","MARUTI SUZUKI",0);
        a.append("MUSSOORIE","TATA",0);
        a.append("MUSSOORIE","TOYOTA",0);
        a.append("MUSSOORIE","HYUNDAI",0);
         a.append("MUSSOORIE","MAHINDRA",0);
        a.append("MUSSOORIE","HONDA","BRIO",1,2100);
        a.append("MUSSOORIE","HONDA","CITY",2,2500);
        a.append("MUSSOORIE","MARUTI SUZUKI","BALENO",3,2300);
        a.append("MUSSOORIE","MARUTI SUZUKI","SWIFT DEZIRE",4,2200);
        a.append("MUSSOORIE","MARUTI SUZUKI","WAGONR",5,1900);
        a.append("MUSSOORIE","MARUTI SUZUKI","RITZ",6,2000);
        a.append("MUSSOORIE","MARUTI SUZUKI","S-CROSS",7,2300);
        a.append("MUSSOORIE","MARUTI SUZUKI","EECO",8,2200);
        a.append("MUSSOORIE","TATA","TIAGO",9,1800);
        a.append("MUSSOORIE","TATA","HARRIER",10,3000);
        a.append("MUSSOORIE","TATA","ETIOS",11,2200);
        a.append("MUSSOORIE","TATA","SAFARI",12,3200);
        a.append("MUSSOORIE","TOYOTA","INNOVA",13,2800);
        a.append("MUSSOORIE","TOYOTA","FORTUNER",14,3500);
        a.append("MUSSOORIE","TOYOTA","ETIOS",15,2600);
        a.append("MUSSOORIE","HYUNDAI","SANTA",16,3500);
        a.append("MUSSOORIE","HYUNDAI","Creta",17,3200);
       a.append("MUSSOORIE","MAHINDRA","XUV 500",18,2900);
        a.append("MUSSOORIE","MAHINDRA","XYLO",19,2500);
      a.append("MUSSOORIE","MAHINDRA","MARAZZO",20,3000);


    }

    void showcat(){
    a.show_cat();
    }
    void showshops(){
    a.show();
    }
    void show_shop_per_cat(string s){
    Node* h=a.search_element(s);
    a.display(h);
    }
    Node* return_car(string c,int p){

    return a.return_child(c,p);
    }
};


class printbikelist{
List a;
public:
    printbikelist(){
        a.append("GOA");
        a.append("DELHI");
        a.append("AGRA");
        a.append("BENGALURU");
        a.append("UDAIPUR");
        a.append("SHIMLA");
        a.append("MANALI");
        a.append("KASOL");
        a.append("OOTY");
        a.append("RISHIKESH");
        a.append("MUSSOORIE");


        a.append("GOA","HONDA",0);
        a.append("GOA","MARUTI SUZUKI",0);
        a.append("GOA","HERO",0);
        a.append("GOA","BAJAJ",0);
        a.append("GOA","TVS",0);
        a.append("GOA","HONDA","ACTIVA",1,700);
        a.append("GOA","HONDA","GROM",2,800);
        a.append("GOA","HONDA","SHINE",3,700);
        a.append("GOA","HONDA","FURY",4,900);
        a.append("GOA","HONDA","CB100R",5,800);
        a.append("GOA","MARUTI SUZUKI","ACCESS 125",6,800);
        a.append("GOA","MARUTI SUZUKI","GIXXER",7,900);
        a.append("GOA","MARUTI SUZUKI","HAYABUSA",8,2000);
        a.append("GOA","HERO","SPLENDOR",9,700);
        a.append("GOA","HERO","MAESTRO EDGE",10,800);
        a.append("GOA","HERO","XTREME",11,800);
        a.append("GOA","TVS","JUPITER",12,900);
        a.append("GOA","TVS","APACHE",13,1100);
        a.append("GOA","TVS","SPORT",14,800);
        a.append("GOA","BAJAJ","PULSAR",15,1200);
        a.append("GOA","BAJAJ","PLATINA",16,700);
        a.append("GOA","BAJAJ","CHETAK",17,800);





        a.append("DELHI","HONDA",0);
        a.append("DELHI","MARUTI SUZUKI",0);
        a.append("DELHI","HERO",0);
        a.append("DELHI","BAJAJ",0);
        a.append("DELHI","TVS",0);
        a.append("DELHI","HONDA","ACTIVA",1,700);
        a.append("DELHI","HONDA","GROM",2,800);
        a.append("DELHI","HONDA","SHINE",3,700);
        a.append("DELHI","HONDA","FURY",4,900);
        a.append("DELHI","HONDA","CB100R",5,800);
        a.append("DELHI","MARUTI SUZUKI","ACCESS 125",6,800);
        a.append("DELHI","MARUTI SUZUKI","GIXXER",7,900);
        a.append("DELHI","MARUTI SUZUKI","HAYABUSA",8,2000);
        a.append("DELHI","HERO","SPLENDOR",8,700);
        a.append("DELHI","HERO","MAESTRO EDGE",9,800);
        a.append("DELHI","HERO","XTREME",10,800);
        a.append("DELHI","TVS","JUPITER",11,900);
        a.append("DELHI","TVS","APACHE",12,1100);
        a.append("DELHI","TVS","SPORT",13,800);
        a.append("DELHI","BAJAJ","PULSAR",14,1200);
        a.append("DELHI","BAJAJ","PLATINA",15,700);
        a.append("DELHI","BAJAJ","CHETAK",16,800);

        a.append("AGRA","HONDA",0);
        a.append("AGRA","MARUTI SUZUKI",0);
        a.append("AGRA","HERO",0);
        a.append("AGRA","BAJAJ",0);
        a.append("AGRA","TVS",0);
        a.append("AGRA","HONDA","ACTIVA",1,700);
        a.append("AGRA","HONDA","GROM",2,800);
        a.append("AGRA","HONDA","SHINE",3,700);
        a.append("AGRA","HONDA","FURY",4,900);
        a.append("AGRA","HONDA","CB100R",5,800);
        a.append("AGRA","MARUTI SUZUKI","ACCESS 125",6,800);
        a.append("AGRA","MARUTI SUZUKI","GIXXER",7,900);
        a.append("AGRA","MARUTI SUZUKI","HAYABUSA",8,2000);
        a.append("AGRA","HERO","SPLENDOR",9,700);
        a.append("AGRA","HERO","MAESTRO EDGE",10,800);
        a.append("AGRA","HERO","XTREME",11,800);
        a.append("AGRA","TVS","JUPITER",12,900);
        a.append("AGRA","TVS","APACHE",13,1100);
        a.append("AGRA","TVS","SPORT",14,800);
        a.append("AGRA","BAJAJ","PULSAR",15,1200);
        a.append("AGRA","BAJAJ","PLATINA",16,700);
        a.append("AGRA","BAJAJ","CHETAK",17,800);

        a.append("BENGALURU","HONDA",0);
        a.append("BENGALURU","MARUTI SUZUKI",0);
        a.append("BENGALURU","HERO",0);
        a.append("BENGALURU","BAJAJ",0);
        a.append("BENGALURU","TVS",0);
        a.append("BENGALURU","HONDA","ACTIVA",1,700);
        a.append("BENGALURU","HONDA","GROM",2,800);
        a.append("BENGALURU","HONDA","SHINE",3,700);
        a.append("BENGALURU","HONDA","FURY",4,900);
        a.append("BENGALURU","HONDA","CB100R",5,800);
        a.append("BENGALURU","MARUTI SUZUKI","ACCESS 125",6,800);
        a.append("BENGALURU","MARUTI SUZUKI","GIXXER",7,900);
        a.append("BENGALURU","MARUTI SUZUKI","HAYABUSA",8,2000);
        a.append("BENGALURU","HERO","SPLENDOR",9,700);
        a.append("BENGALURU","HERO","MAESTRO EDGE",10,800);
        a.append("BENGALURU","HERO","XTREME",11,800);
        a.append("BENGALURU","TVS","JUPITER",12,900);
        a.append("BENGALURU","TVS","APACHE",13,1100);
        a.append("BENGALURU","TVS","SPORT",14,800);
        a.append("BENGALURU","BAJAJ","PULSAR",15,1200);
        a.append("BENGALURU","BAJAJ","PLATINA",16,700);
        a.append("BENGALURU","BAJAJ","CHETAK",17,800);

        a.append("UDAIPUR","HONDA",0);
        a.append("UDAIPUR","MARUTI SUZUKI",0);
        a.append("UDAIPUR","HERO",0);
        a.append("UDAIPUR","BAJAJ",0);
        a.append("UDAIPUR","TVS",0);
        a.append("UDAIPUR","HONDA","ACTIVA",1,700);
        a.append("UDAIPUR","HONDA","GROM",2,800);
        a.append("UDAIPUR","HONDA","SHINE",3,700);
        a.append("UDAIPUR","HONDA","FURY",4,900);
        a.append("UDAIPUR","HONDA","CB100R",5,800);
        a.append("UDAIPUR","MARUTI SUZUKI","ACCESS 125",6,800);
        a.append("UDAIPUR","MARUTI SUZUKI","GIXXER",7,900);
        a.append("UDAIPUR","MARUTI SUZUKI","HAYABUSA",8,2000);
        a.append("UDAIPUR","HERO","SPLENDOR",9,700);
        a.append("UDAIPUR","HERO","MAESTRO EDGE",10,800);
        a.append("UDAIPUR","HERO","XTREME",11,800);
        a.append("UDAIPUR","TVS","JUPITER",12,900);
        a.append("UDAIPUR","TVS","APACHE",13,1100);
        a.append("UDAIPUR","TVS","SPORT",14,800);
        a.append("UDAIPUR","BAJAJ","PULSAR",15,1200);
        a.append("UDAIPUR","BAJAJ","PLATINA",16,700);
        a.append("UDAIPUR","BAJAJ","CHETAK",17,800);

        a.append("SHIMLA","HONDA",0);
        a.append("SHIMLA","MARUTI SUZUKI",0);
        a.append("SHIMLA","HERO",0);
        a.append("SHIMLA","BAJAJ",0);
        a.append("SHIMLA","TVS",0);
        a.append("SHIMLA","HONDA","ACTIVA",1,700);
        a.append("SHIMLA","HONDA","GROM",2,800);
        a.append("SHIMLA","HONDA","SHINE",3,700);
        a.append("SHIMLA","HONDA","FURY",4,900);
        a.append("SHIMLA","HONDA","CB100R",5,800);
        a.append("SHIMLA","MARUTI SUZUKI","ACCESS 125",6,800);
        a.append("SHIMLA","MARUTI SUZUKI","GIXXER",7,900);
        a.append("SHIMLA","MARUTI SUZUKI","HAYABUSA",8,2000);
        a.append("SHIMLA","HERO","SPLENDOR",9,700);
        a.append("SHIMLA","HERO","MAESTRO EDGE",10,800);
        a.append("SHIMLA","HERO","XTREME",11,800);
        a.append("SHIMLA","TVS","JUPITER",12,900);
        a.append("SHIMLA","TVS","APACHE",13,1100);
        a.append("SHIMLA","TVS","SPORT",14,800);
        a.append("SHIMLA","BAJAJ","PULSAR",15,1200);
        a.append("SHIMLA","BAJAJ","PLATINA",16,700);
        a.append("SHIMLA","BAJAJ","CHETAK",17,800);

        a.append("MANALI","HONDA",0);
        a.append("MANALI","MARUTI SUZUKI",0);
        a.append("MANALI","HERO",0);
        a.append("MANALI","BAJAJ",0);
        a.append("MANALI","TVS",0);
        a.append("MANALI","HONDA","ACTIVA",1,700);
        a.append("MANALI","HONDA","GROM",2,800);
        a.append("MANALI","HONDA","SHINE",2,700);
        a.append("MANALI","HONDA","FURY",3,900);
        a.append("MANALI","HONDA","CB100R",4,800);
        a.append("MANALI","MARUTI SUZUKI","ACCESS 125",5,800);
        a.append("MANALI","MARUTI SUZUKI","GIXXER",6,900);
        a.append("MANALI","MARUTI SUZUKI","HAYABUSA",7,2000);
        a.append("MANALI","HERO","SPLENDOR",8,700);
        a.append("MANALI","HERO","MAESTRO EDGE",9,800);
        a.append("MANALI","HERO","XTREME",10,800);
        a.append("MANALI","TVS","JUPITER",11,900);
        a.append("MANALI","TVS","APACHE",12,1100);
        a.append("MANALI","TVS","SPORT",13,800);
        a.append("MANALI","BAJAJ","PULSAR",14,1200);
        a.append("MANALI","BAJAJ","PLATINA",15,700);
        a.append("MANALI","BAJAJ","CHETAK",16,800);

        a.append("KASOL","HONDA",0);
        a.append("KASOL","MARUTI SUZUKI",0);
        a.append("KASOL","HERO",0);
        a.append("KASOL","BAJAJ",0);
        a.append("KASOL","TVS",0);
        a.append("KASOL","HONDA","ACTIVA",1,700);
        a.append("KASOL","HONDA","GROM",2,800);
        a.append("KASOL","HONDA","SHINE",3,700);
        a.append("KASOL","HONDA","FURY",4,900);
        a.append("KASOL","HONDA","CB100R",5,800);
        a.append("KASOL","MARUTI SUZUKI","ACCESS 125",6,800);
        a.append("KASOL","MARUTI SUZUKI","GIXXER",7,900);
        a.append("KASOL","MARUTI SUZUKI","HAYABUSA",8,2000);
        a.append("KASOL","HERO","SPLENDOR",9,700);
        a.append("KASOL","HERO","MAESTRO EDGE",10,800);
        a.append("KASOL","HERO","XTREME",11,800);
        a.append("KASOL","TVS","JUPITER",12,900);
        a.append("KASOL","TVS","APACHE",13,1100);
        a.append("KASOL","TVS","SPORT",14,800);
        a.append("KASOL","BAJAJ","PULSAR",15,1200);
        a.append("KASOL","BAJAJ","PLATINA",16,700);
        a.append("KASOL","BAJAJ","CHETAK",17,800);

        a.append("OOTY","HONDA",0);
        a.append("OOTY","MARUTI SUZUKI",0);
        a.append("OOTY","HERO",0);
        a.append("OOTY","BAJAJ",0);
        a.append("OOTY","TVS",0);
        a.append("OOTY","HONDA","ACTIVA",1,700);
        a.append("OOTY","HONDA","GROM",2,800);
        a.append("OOTY","HONDA","SHINE",3,700);
        a.append("OOTY","HONDA","FURY",4,900);
        a.append("OOTY","HONDA","CB100R",5,800);
        a.append("OOTY","MARUTI SUZUKI","ACCESS 125",6,800);
        a.append("OOTY","MARUTI SUZUKI","GIXXER",7,900);
        a.append("OOTY","MARUTI SUZUKI","HAYABUSA",8,2000);
        a.append("OOTY","HERO","SPLENDOR",9,700);
        a.append("OOTY","HERO","MAESTRO EDGE",10,800);
        a.append("OOTY","HERO","XTREME",11,800);
        a.append("OOTY","TVS","JUPITER",12,900);
        a.append("OOTY","TVS","APACHE",13,1100);
        a.append("OOTY","TVS","SPORT",14,800);
        a.append("OOTY","BAJAJ","PULSAR",15,1200);
        a.append("OOTY","BAJAJ","PLATINA",16,700);
        a.append("OOTY","BAJAJ","CHETAK",17,800);

        a.append("RISHIKESH","HONDA",0);
        a.append("RISHIKESH","MARUTI SUZUKI",0);
        a.append("RISHIKESH","HERO",0);
        a.append("RISHIKESH","BAJAJ",0);
        a.append("RISHIKESH","TVS",0);
        a.append("RISHIKESH","HONDA","ACTIVA",1,700);
        a.append("RISHIKESH","HONDA","GROM",2,800);
        a.append("RISHIKESH","HONDA","SHINE",3,700);
        a.append("RISHIKESH","HONDA","FURY",4,900);
        a.append("RISHIKESH","HONDA","CB100R",5,800);
        a.append("RISHIKESH","MARUTI SUZUKI","ACCESS 125",6,800);
        a.append("RISHIKESH","MARUTI SUZUKI","GIXXER",7,900);
        a.append("RISHIKESH","MARUTI SUZUKI","HAYABUSA",8,2000);
        a.append("RISHIKESH","HERO","SPLENDOR",9,700);
        a.append("RISHIKESH","HERO","MAESTRO EDGE",10,800);
        a.append("RISHIKESH","HERO","XTREME",11,800);
        a.append("RISHIKESH","TVS","JUPITER",12,900);
        a.append("RISHIKESH","TVS","APACHE",13,1100);
        a.append("RISHIKESH","TVS","SPORT",14,800);
        a.append("RISHIKESH","BAJAJ","PULSAR",15,1200);
        a.append("RISHIKESH","BAJAJ","PLATINA",16,700);
        a.append("RISHIKESH","BAJAJ","CHETAK",17,800);

        a.append("MUSSOORIE","HONDA",0);
        a.append("MUSSOORIE","MARUTI SUZUKI",0);
        a.append("MUSSOORIE","HERO",0);
        a.append("MUSSOORIE","BAJAJ",0);
        a.append("MUSSOORIE","TVS",0);
        a.append("MUSSOORIE","HONDA","ACTIVA",1,700);
        a.append("MUSSOORIE","HONDA","GROM",2,800);
        a.append("MUSSOORIE","HONDA","SHINE",3,700);
        a.append("MUSSOORIE","HONDA","FURY",4,900);
        a.append("MUSSOORIE","HONDA","CB100R",5,800);
        a.append("MUSSOORIE","MARUTI SUZUKI","ACCESS 125",6,800);
        a.append("MUSSOORIE","MARUTI SUZUKI","GIXXER",7,900);
        a.append("MUSSOORIE","MARUTI SUZUKI","HAYABUSA",8,2000);
        a.append("MUSSOORIE","HERO","SPLENDOR",9,700);
        a.append("MUSSOORIE","HERO","MAESTRO EDGE",10,800);
        a.append("MUSSOORIE","HERO","XTREME",11,800);
        a.append("MUSSOORIE","TVS","JUPITER",12,900);
        a.append("MUSSOORIE","TVS","APACHE",13,1100);
        a.append("MUSSOORIE","TVS","SPORT",14,800);
        a.append("MUSSOORIE","BAJAJ","PULSAR",15,1200);
        a.append("MUSSOORIE","BAJAJ","PLATINA",16,700);
        a.append("MUSSOORIE","BAJAJ","CHETAK",17,800);
    }
     void showcat(){
    a.show_cat();
    }
    void showshops(){
    a.show();
    }
    void show_shop_per_cat(string s){
    Node* h=a.search_element(s);
    a.display(h);
    }
    Node* return_bike(string c,int p){

    return a.return_child(c,p);
    }

};
