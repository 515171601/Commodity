﻿#include <iostream>
#include "commodity.h"

using namespace std;

long Commodity::nextId=100;
Commodity::Commodity(string n,double p,int nu)
	:Commodity(autoNextId(),n,p,nu){}

Commodity::Commodity(long i,std::string n,double p,int nu)
	:id(i),name(n),price(p),num(nu){}

double Commodity::getNetPrice()const{
	return price*num;
}

void Commodity::output()const{
	cout<<" 商品编号(id):"<<id<<endl;
	cout<<" 商品名称:"<<name<<endl;
}
