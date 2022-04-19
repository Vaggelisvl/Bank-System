#include <iostream>
#include <random>
#include <string>
#include "Person_Details.h"
#include "Bank_System.h"
using namespace std;
int main(){
    random_device randomdev;
    mt19937 rmt(randomdev());
    uniform_int_distribution<int>rn(1049120,9999999);
    string name_array[10] ={"Ivan","Jeremy","Jim","Charlie","Zoltan","Jason","Jo","Margot","Angelina","Allissa"};
    string last_array[10]={"Lewis","Greening","Spencer","Kael","Moody","Bathory","James","Robbie","White","Gluz"};
    Bank_System*bank=new Bank_System();
    Person_Details*p;
    srand(time(nullptr));
    for(int i=0;i<100;i++){
        if(i==0){

            p=new Person_Details(rand()%100+1,to_string((rand()%30+1))+"/"+ to_string(rand()%12+1)+"/"+to_string(rand()%2022+1950),rn(randomdev),"Street"+
                                                                                                                                                 to_string(i),name_array[rand()%9+0],last_array[rand()%9+0],rn(randomdev),"@admin"+
                                                                                                                                                                                                                          to_string(i),"@admin123"+
                                                                                                                                                                                                                                       to_string(i),2000);
            bank->add_costumer(p);
            continue;

        }
        if(i==1){
            p=new Person_Details(rand()%100+1,to_string((rand()%30+1))+"/"+ to_string(rand()%12+1)+"/"+to_string(rand()%2022+1950),rn(randomdev),"Street"+
                                                                                                                                                 to_string(i),name_array[rand()%9+0],last_array[rand()%9+0],rn(randomdev),"Username!"+
                                                                                                                                                                                                                          to_string(i),"password!"+
                                                                                                                                                                                                                                       to_string(i),2000);
            bank->add_costumer(p);
            continue;

        }
        if(i==2){
            p=new Person_Details(rand()%100+1,to_string((rand()%30+1))+"/"+ to_string(rand()%12+1)+"/"+to_string(rand()%2022+1950),rn(randomdev),"Street"+
                                                                                                                                                 to_string(i),name_array[rand()%9+0],last_array[rand()%9+0],rn(randomdev),"Username!"+
                                                                                                                                                                                                                          to_string(i),"password!"+
                                                                                                                                                                                                                                       to_string(i),2000);
            bank->add_costumer(p);
            continue;

        }

        p=new Person_Details(rand()%100+1,to_string((rand()%30+1))+"/"+ to_string(rand()%12+1)+"/"+to_string(rand()%2022+1950),rn(randomdev),"Street"+
                                                                                                                                             to_string(i),name_array[rand()%9+0],last_array[rand()%9+0],rn(randomdev),"Username!"+
                                                                                                                                                                                                                    to_string(i),"password!"+
                                                                                                                                                                                                                                 to_string(i),2000);
        bank->add_costumer(p);
    }
    cout<<"ok"<<endl;
    bank->actions();
    return 0;
}
