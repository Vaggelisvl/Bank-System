//
// Created by snz on 4/17/2022.
//

#include "Bank_System.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;
Bank_System::Bank_System() {
    file.open("out.txt", ios::app);
    string flag="Not ok";
    this->costumerList=new LinkedList();
    cout<<"ok"<<endl;
    flag="Ok";
//    std::ofstream out("out.txt");
//    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
//    std::cout.rdbuf(out.rdbuf());
    string st="Bank has just been created";
    file.write(st.c_str(),st.length());
    st="Everyting has been created";
    file.write((st).c_str(),st.length())<<endl;
    st="Status:"+flag;
    file.write((st).c_str(),st.length())<<endl;
//    std::cout.rdbuf(coutbuf);
    cout<<"Status:"+flag<<endl;
    file.close();

}

void Bank_System::add_costumer(Person_Details *p) {
    string st;
    file.open("out.txt", ios::app);
    this->costumerList->Insert(p);
//    std::ofstream out("out.txt");
//    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
//    std::cout.rdbuf(out.rdbuf());
    st="Admin added costumer:"+ p->return_String_Data(0)+" "+p->return_String_Data(1)+"\n";
    file.write(st.c_str(),st.length());
    //    std::cout.rdbuf(coutbuf);
    file.close();
}


void Bank_System::actions(Person_Details*P) {
    int opt;
    string answer;
    string  username,password;
    bool loged_in= false;
    int option;
    while(1){
        cout<<"Please log in"<<endl;
        cout<<"Give your username"<<endl;
        cin>>username;
        cout<<"Give your password"<<endl;
        cin>>password;
        if(log_in(username,password)){
            if(username.compare("admin")==0)
                this->is_admin=true;
            break;

        }

    }
    bool cont= true;
    bool welcome_printed=false;
    string st;
    file.open("out.txt", ios::app);
    while(1){

        if(is_admin){
            if(!welcome_printed){
                cout<<"Welcome admin"<<endl;
                welcome_printed=true;
            }

            cout<<"Please select your action\n 1 for reset \n 2 for add costumer"<<endl;
            cin>>option;
            if(option==1){
                cout<<"You have choose reset costumer Data"<<endl;
                cout<<"Please give the id of the costumer you want to change"<<endl;
                cin>>opt;
                this->costumerList->ResetCostumer(opt);
//                std::ofstream out("out.txt");
//                std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
//                std::cout.rdbuf(out.rdbuf());
                st="Admin change data of costumer:"+ to_string(opt)+"\n";
                file.write(st.c_str(),st.length());
//                std::cout.rdbuf(coutbuf);
            }else if(option==2){
                if(is_admin)
                    this->add_costumer(P);
            }
            cout<<"Do you want to choose another action?"<<endl;
            cin>>answer;
            transform(answer.begin(), answer.end(), answer.begin(),
                      [](unsigned char c){ return std::tolower(c); });
            if(answer.compare("No"))
                break;
        }else{
            if(!welcome_printed){
                cout<<"Welcome User:"+this->log_in_person->return_String_Data(0)+" "+this->log_in_person->return_String_Data(1)<<endl;
                welcome_printed=true;
            }
            cout<<"Please select your action\n 1 for reset \n 2 for money transfer"<<endl;
            cin>>option;
            int iban,amount;
            if(option==1){
//                std::ofstream out("out.txt");
//                std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
//                std::cout.rdbuf(out.rdbuf());
                st="User" +this->log_in_person->return_String_Data(0)+" "+this->log_in_person->return_String_Data(1)+ "change their data\n";
                file.write(st.c_str(),st.length());
//                std::cout.rdbuf(coutbuf);
                cout<<"You have choose reset your Data"<<endl;
                this->costumerList->ResetCostumer(this->log_in_person->return_Int_Data(1));
            } else{
                cout<<"You have choose to transfer Money\n Please be careful with the data of the other person you insert"<<endl;
                cout<<"Give the iban you want to transfer to"<<endl;
                cin>>iban;
                cout<<"Give the amount you want to transfer"<<endl;
                cin>>amount;
                cout<<"this->log_in_person->return_Int_Data(2)"<<this->log_in_person->return_Int_Data(2)<<endl;
                this->costumerList->setAmount(this->log_in_person->return_Int_Data(2),iban,amount);
            }


            cout<<"Do you want to choose another action?"<<endl;
            cin>>answer;
            transform(answer.begin(), answer.end(), answer.begin(),
                      [](unsigned char c){ return std::tolower(c); });
            if(answer.compare("No")==0)
                break;

        }



    }
    file.close();


}



bool Bank_System::log_in(std::string s1, std::string s2) {
    file.open("out.txt", ios::app);
    string st;
    log_in_person=this->costumerList->check(s1,s2);
    if(log_in_person!= nullptr){
        st="user:"+log_in_person->return_String_Data(0)+" "+log_in_person->return_String_Data(1)+" "+"connected\n";
        file.write(st.c_str(),1024)<<endl;
        cout<<"Password and UserName accepted!"<<endl;
        cout<<"Welcome"<<endl;

        return true;
    }
    cout<<"Wrong UserName or Password"<<endl;
    file.close();
    return false;

}




