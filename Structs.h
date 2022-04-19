#include "Person_Details.h"

class MessageList;
class Node{
public:
    Node*upcoming;
    Person_Details*personDetails;

    MessageList*messageList;
};


class MessageNode{
public:
    MessageNode*upcoming;
    std::string message;

};

class LinkedList {
public:
    void ResetCostumer(int id);
    LinkedList();

    void Insert(Person_Details *);

    void print();

    void InsertAfter(Person_Details &, Node *);

    void Insertfront(Person_Details &);
    Person_Details* check(std::string ,std::string);
    Person_Details *search(int string);
    int returnTax(std::string);
    void setAmount(int,int,int);

private:
    std::ofstream file;
    Node *head;
    Node *tmp;


};

