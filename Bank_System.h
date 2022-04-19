#include "Person_Details.h"
#include "Structs.h"
#include <fstream>
class Bank_System {
    LinkedList*costumerList;
    Person_Details*log_in_person;
    bool is_admin=false;
    std::ofstream file;

public:
    Bank_System();
    void add_costumer(Person_Details*);
    void actions(Person_Details*p= nullptr);
    bool log_in(std::string,std::string);
    void moneyTransfer(int,int);

};


