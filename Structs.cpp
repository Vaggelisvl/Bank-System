//
#include "Person_Details.h"
#include "Structs.h"
#include <fstream>
using namespace std;
LinkedList::LinkedList(){
    this->head=NULL;
    this->tmp=NULL;

}
void LinkedList::Insert(Person_Details *R){
    Node*temp =new Node;
    temp->upcoming=NULL;
    temp->personDetails=R;
    if(head!=NULL){
        tmp->upcoming=temp;
        tmp=tmp->upcoming;
    }else{
        head=temp;
        tmp=temp;
    }
}
void LinkedList::Insertfront(Person_Details &R){
    Node*tempt=new Node;
    tempt->personDetails=&R;
    tempt->upcoming=head;
    head=tempt;
}
void LinkedList::InsertAfter(Person_Details &R,Node*node){
    Node*newn=new Node;
    newn->personDetails=&R;
    newn->upcoming=node->upcoming;
    node->upcoming=newn;

}
Person_Details* LinkedList::search(int givenId){

    Node*temp;
    bool hasbeenfound=0;
    temp=head;

    while(temp!=NULL){

        if(temp->personDetails->return_Int_Data(1)==givenId){
            //	cout <<"Person_Details with name: "<<temp->Person_Detailsdata->getName()<<" already exists!"<<endl;
            hasbeenfound=1;
            return temp->personDetails;
            break;
        }
        temp=temp->upcoming;
    }
    if(hasbeenfound==0){
//		cout <<"Person_Details with name: "<<temp->Person_Detailsdata->getName()<<" hasnt been found"<<endl;
        return NULL;
    }

}
void LinkedList::print(){
    Node*temp;
    temp=head;
    if(temp==NULL){
        cout<<"Empty List"<<endl;
    }
    while(temp!=NULL){
        temp->personDetails->printData();
        cout<<endl;
        temp=temp->upcoming;
    }
}

void LinkedList::ResetCostumer(int id) {
    if(search(id)!=NULL){
        Node*temp;
        temp=head;

        while(temp!=NULL){

            if(temp->personDetails->return_Int_Data(1)==id){
                //	cout <<"Person_Details with name: "<<temp->Person_Detailsdata->getName()<<" already exists!"<<endl;

                temp->personDetails->reset();
                break;
            }
            temp=temp->upcoming;
        }
    }else
         cout<<"The given id:"+ to_string(id)+"does not exist in costumer list"<<endl;

}

Person_Details* LinkedList::check(std::string s1, std::string s2) {
    Node*temp;
    temp=head;

    while(temp!=NULL){

        if(temp->personDetails->return_String_Data(4).compare(s1)==0&&temp->personDetails->return_String_Data(3).compare(s2)==0){
            //	cout <<"Person_Details with name: "<<temp->Person_Detailsdata->getName()<<" already exists!"<<endl;
            return temp->personDetails;

        }
        temp=temp->upcoming;
    }

    return nullptr;
}

void LinkedList::setAmount(int ib,int ibs, int amount) {
    file.open("out.txt", ios::app);
    string st;
    Node*temp;
    temp=head;
    bool can_continue=true;
    while(temp!=NULL){

        if(temp->personDetails->return_Int_Data(2)==ib){
             if(temp->personDetails->setamountminus(amount)){
                 cout<<"Sufficient amount"<<endl;
                 break;
             }else{
                 cout<<"Transfer failed no sufficient amount"<<endl;
                 can_continue= false;
             }


        }
        temp=temp->upcoming;
    }
    bool second_iban_exists=false;
    if(can_continue==true){
        temp=head;

        while(temp!=NULL){

            if(temp->personDetails->return_Int_Data(2)==ibs){
                temp->personDetails->setamount(amount);
                second_iban_exists=true;
            }
            temp=temp->upcoming;
        }
    }
    if(can_continue){
        if(second_iban_exists==true){
            cout<<"Transfer completed \tThank you for using our services"<<endl;

//        std::ofstream out("out.txt");
//        std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
//        std::cout.rdbuf(out.rdbuf());
        st="User with iban: "+ to_string(ib)+"transfered amount:"+ to_string(amount)+ " to user with iban: "+ to_string(ibs);
        file.write(st.c_str(),st.length());
//        std::cout.rdbuf(coutbuf);
        }
        else{
            cout<<"No such iban:"+ to_string(ibs)<<endl;
            cout<<"Transfer Failed"<<endl;
            st="User with iban:"+ to_string(ib)+" had an unsuccessful transfer to user with iban : "+ to_string(ibs);
            file.write(st.c_str(),st.length());
            st="Reason of rejected transfer:No such iban"+ to_string(ibs);
            file.write(st.c_str(),st.length());

            //return amount
            temp=head;
            while(temp!=NULL){

                if(temp->personDetails->return_Int_Data(2)==ib){
                    temp->personDetails->setamount(amount);
                    break;
                }
                temp=temp->upcoming;
            }
        }
    }
    file.close();

}
//
//int LinkedList::returnTax(std::string nm) {
//
//    Node*temp;
//    temp=head;
//
//    while(temp!=NULL){
//
//        if(temp->personDetails->return_String_Data(4).compare(nm)){
//            return temp->personDetails->return_Int_Data(true);
//            break;
//        }
//        temp=temp->upcoming;
//    }
//}


