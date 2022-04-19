//
// Created by snz on 4/17/2022.
//
#include <iostream>
#include <fstream>
#ifndef BANKING_SYSTEM_PERSON_DETAILS_H
#define BANKING_SYSTEM_PERSON_DETAILS_H


class Person_Details {
private:
    std::string first_name;
    std::string last_name;
    int age;
    std::string date_of_birth;
    int tax_identification_number;
    std::string street;
    int iban;
    std::string password;
    std::string username;
    int money;
    std::ofstream file;

public:
    Person_Details(int,std::string,int,std::string,std::string,std::string,int,std::string,std::string,int);
    std::string return_String_Data(int);
    int return_Int_Data(int );
    void printData();
    int fixMargin();
    void reset();
    bool password_policy();
    bool setamountminus(int amount);
    void setamount(int);

};


#endif //BANKING_SYSTEM_PERSON_DETAILS_H
