#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <vector>
using namespace std;

class Transaction{
private:
    int info;
	int quantity, price;
public:
    Transaction(int quantity, int price);
    void setInfo(int info);
    void setQuantity(int quantity);
    int getInfo();
    int getQuantity();
    int getPrice();
};

Transaction::Transaction(int quantity, int price){
    this->quantity = quantity;
    this->price = price;
}
void Transaction::setInfo(int info){
    this->info = info;
}
void Transaction::setQuantity(int quantity){
    this->quantity = quantity;
}
int Transaction::getInfo(){
    return info;
}
int Transaction::getQuantity(){
    return quantity;
}
int Transaction::getPrice(){
    return price;
}


#endif // TRANSACTION_H