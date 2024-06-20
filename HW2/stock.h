#ifndef STOCK_H
#define STOCK_H

#include "transaction.h"
#include <vector>
#include <exception>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

class StockTrade{
private:
    int total;
    int total_gain;
    vector<Transaction> stock;

public:
    StockTrade();
    void buy(Transaction t);
    void sell(Transaction t);
    int getTotalGain();
};

class SellMoreSharesException : public exception{
private:
    int insufficientQuantity;
public:
    SellMoreSharesException(int insufficientQuantity);
    const char* what() const noexcept override;
    int getInsufficientQuantity() const;
};

StockTrade::StockTrade(){
    this->total = 0;
    this->total_gain = 0;
}
void StockTrade::buy(Transaction t){
    t.setInfo(1);
    total += t.getQuantity();
    stock.push_back(t);
}

void StockTrade::sell(Transaction t){
    if(total < t.getQuantity()){
        throw SellMoreSharesException(t.getQuantity() - total);
    }
    else {
        t.setInfo(2);
        stock.push_back(t);
        total -= t.getQuantity();
    }
}

int StockTrade::getTotalGain(){
    int gain = 0;
    deque<Transaction> dq;
    for(auto x : stock){
        int info = x.getInfo();
        if(info == 1){
            dq.push_back(x);
        }
        else if(info == 2){
            int sellQuantity = x.getQuantity();
            int sellPrice = x.getPrice();
            while(!dq.empty()){
                if(sellQuantity==0)break;
                auto now = dq.front();dq.pop_front();

                int nowQuantity = now.getQuantity();
                int nowPrice = now.getPrice();
                
                if(nowQuantity <= sellQuantity){
                    gain += (sellPrice-nowPrice) * nowQuantity;
                    sellQuantity -= nowQuantity;
                }
                else {
                    gain += (sellPrice-nowPrice) * sellQuantity;
                    now.setQuantity(nowQuantity - sellQuantity);
                    sellQuantity = 0;
                    dq.push_front(now);
                }
            }
        }
    }
    return gain;
}

SellMoreSharesException::SellMoreSharesException(int insufficientQuantity){
    this->insufficientQuantity = insufficientQuantity;
}
const char* SellMoreSharesException::what() const noexcept{
    return "Insufficient shares";
}
int SellMoreSharesException::getInsufficientQuantity() const {
    return insufficientQuantity;
}


#endif // STOCK_H