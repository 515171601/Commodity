#include <iostream>
#include "commodity.h"
#include <sstream>

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

string Commodity::getInfo()const{
	ostringstream ostr;
	ostr<<getId()<<endl;
	ostr<<getName()<<endl;
	ostr<<price<<" "<<num<<" ";
	return ostr.str();
}

void Commodity::printEditMenu()const{
	printf (
				"%d) 商品名称\n"
				"%d) 商品价格\n"
				"%d) 商品数量\n"
				,NAME, PRICE, NUM);
	return ;
}

int Commodity::getChoois() const{
	char choois=0;
	cin>>choois;
	while(getchar()!='\n');
	while(choois<'0'+NAME||choois>'0'+NUM){
		cout<<"非法输入, 请重试!\n";
		cin>>choois;
		while(getchar()!='\n');
	}
	choois-='0';
	return static_cast<int>(choois);
}

void Commodity::judgeChoois(int choois){
	switch(choois){
		case NAME:
			cout<<"输入商品名称: ";
			cin>>this->name;
			break;
		case PRICE:
			cout<<"输入商品价格: ";
			cin>>this->price;
			break;
		case NUM:
			cout<<"输入商品数量: ";
			cin>>this->num;
			break;
		default:
			break;
	}
	return ;
}

void Commodity::editInfo(){
	this->printEditMenu ();
	this->judgeChoois (this->getChoois ());
	cout<<"修改后的商品如下: \n";
	this->output ();
	return ;
}


