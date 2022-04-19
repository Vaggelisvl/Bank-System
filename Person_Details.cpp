//
// Created by snz on 4/17/2022.
//

#include "Person_Details.h"
#include <fstream>
using namespace std;
Person_Details::Person_Details(int d,string s,int d1,string s1,string first,string last,int ib,string usern,string userp,int amount) {
    this->first_name=first;
    this->last_name=last;
    this->age=d;
    this->date_of_birth=s;
    this->street=s1;
    this->tax_identification_number=d1;
    this->iban=ib;
    this->username=usern;
    this->password=userp;
    this->money=amount;

    cout<<"\nPerson has just been saved with data: "<<endl;
    printData();
    string option;
//    cout<<"Do you want to reset any data?"<<endl;
//    getline(cin,option);
//    if(stoi(option)==1)
//        reset();



}

int Person_Details::return_Int_Data(int val) {
    if(val==1)
        return this->tax_identification_number;
    else if(val==2)
        return this->iban;
    return this->age;
}

void Person_Details::printData() {
    int margin=fixMargin();
    for(int i=0;i<margin;i++) {
        cout<<"-";
    }
    cout<<"\nName:"+this->first_name<<endl;
    cout<<"Last Name:"+this->last_name<<endl;
    cout<<"Age:"+to_string(this->age)<<endl;
    cout<<"Street:"+this->street<<endl;
    cout<<"Tax Number:"+to_string((this->tax_identification_number))<<endl;
    cout<<"Iban:"+ to_string(iban)<<endl;
    for(int i=0;i<margin;i++)
        cout<<"-";

}

int Person_Details::fixMargin() {
    //No need to check age
    string tmp=("Tax Number:");
    tmp.append(to_string(this->tax_identification_number));
    int tmp_lengh=tmp.length();
    if((tmp="Birth Date:"+this->date_of_birth).length()>tmp_lengh)
        tmp_lengh=tmp.length();
    if((tmp="Street Name and Number:"+this->street).length()>tmp_lengh)
        tmp_lengh=tmp.length();
    return tmp_lengh;
}

string Person_Details::return_String_Data(int val) {
    if(val==0)
        return this->first_name;
    else if(val==1)
        return this->last_name;
    else if(val==2)
        return this->street;
    else if(val==3)
        return this->password;
    else
        return this->username;
}

void Person_Details::reset() {
    file.open("out.txt", ios::app);
    string what_has_changed="";
    string st;
    string opt;
    int option;

    while(1){
        cout<<endl<<"Which Data do you want to change?"<<endl;
        cout<<"Press:\n"<<"1 for First Name\n"<<"2 for Last Name\n"<<"3 for Age\n"<<"4 for Street\n"<<"5 for Tax Number\n"<<"6 for password\n"<<endl;
        cin >>option;
        cout<<"Type the Change:"<<endl;
        cin>>opt;
        if(option==1){
            this->first_name=opt;
            what_has_changed.append("first name to:"+opt+",");
        }

        else if(option==2){
            this->last_name=opt;
            what_has_changed.append("last name to:"+opt+",");
        }
        else if(option==3){
            this->age= stoi(opt);
            what_has_changed.append("age to:"+ to_string(this->age)+",");
        }
        else if(option==4){
            this->street= opt;
            what_has_changed.append("street name to:"+opt+",");
        }
        else if(option==5){
            this->tax_identification_number= stoi(opt);
            what_has_changed.append("tax identification number to:"+opt+",");

        }
        else if(option==6){
            bool accept=false;
            while(1){
                if(this->password_policy()){
                   accept=true;
                }else{
                    cout<<"Password is not meet our policy"<<endl;
                    cout<<"Try again"<<endl;
                }
                if(accept){
                    break;
                    what_has_changed.append("password,");
                }
            }

        }
        else
            cout<<"Out of range option"<<endl;
        cout<<"Do you want to continue with changes?\n Press 1 for Yes \n Press 2 for No\n"<<endl;
        cin>>option;

         if (option==2){
            cout<<"\nData after Reset\n"<<endl;
            printData();
//            std::ofstream out("out.txt");
//            std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
//            std::cout.rdbuf(out.rdbuf());
            st="User: "+this->first_name+" "+this->last_name +" change their: "+ what_has_changed;
            file.write(st.c_str(),st.length())<<endl;

//            std::cout.rdbuf(coutbuf);
            file.close();
            break;
        }

    }
}

bool Person_Details::password_policy() {
    string pas;
    cout<<"Give your new password"<<endl;
    cin>>pas;
    bool lower= false,upper=true,dig= false,specialchars= false;
    int len=0;
    len=pas.length();
    for(int i=0;i<len;i++){
        if(isupper(pas[i])){
            upper= true;
            continue;
        }

        if(isdigit(pas[i])){
            dig=true;
            continue;
        }

        if(islower(pas[i])){
            lower=true;
            continue;
        }
        if(!isdigit(pas[i])){
            if(!isalpha(pas[i]))
                specialchars=true;
        }
    }
    if(lower&&upper&&dig&&specialchars&&len>=8){
        cout<<"Password accepted"<<endl;
        this->password=pas;
        return true;
    }
    return false;
}

bool Person_Details::setamountminus(int amount) {
   if(this->money>=amount){
       this->money-=amount;
       return true;
   }
   return false;
}

void Person_Details::setamount(int am) {
    this->money+=am;

}





