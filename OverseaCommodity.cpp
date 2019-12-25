﻿#include <iostream>
#include "header.h"
#include <sstream>

using namespace std;

OverseaCommodity::OverseaCommodity(long id,std::string name,
								   double p,int n,double d,double t)
	:Commodity(id,name,p,n),discount(d),tariff(t){}

OverseaCommodity::OverseaCommodity(std::string name,double p,
								   int n,double d,double t)
	:Commodity(name,p,n),discount(d),tariff(t){}

double OverseaCommodity::getNetPrice()const{
	return Commodity::getNetPrice()*discount+tariff;
}

void OverseaCommodity::output()const{
	Commodity::output();
	cout<<" 商品总价:"<<getNetPrice()<<" (价格:"
	   <<getPrice()<<", 数量:"<<getNum()<<", 折扣:"
	  <<discount<<", 关税:"<<tariff<<" )\n";
}


int OverseaCommodity::getType()const{
	return OVERSEA; //1 表示海外购商品
}

string OverseaCommodity::getInfo()const{
	ostringstream ostr;
	ostr<<getType()<<" "; //先输出类型编码
	ostr<<Commodity::getInfo(); //输出基类的信息
	ostr<<discount<<" "<<tariff<<endl; //输出子类信息
	return ostr.str();
}

void OverseaCommodity::editInfo(){
#ifdef DEBUG
	cerr<<"OverseaCommodity\n";
#endif
	this->printEditMenu ();
	this->judgeChoois (this->getChoois ());
	cout<<"修改后的商品如下: \n";
	this->output ();
	return ;
}

void OverseaCommodity::printEditMenu(){
	Commodity::printEditMenu ();
	printf(
				"%d) 商品折扣\n"
				"%d) 商品关税\n"
				, DISCOUNT, TARIFF);
	return ;
}

int OverseaCommodity::getChoois(){
	char choois=0;
	cin>>choois;
	while(getchar()!='\n');
	while(choois<'0'+NAME||choois>'0'+TARIFF){
		cout<<"非法输入, 请重试!\n";
		cin>>choois;
		while(getchar()!='\n');
	}
	choois-='0';
	return static_cast<int>(choois);
}

void OverseaCommodity::judgeChoois(int choois){
	Commodity::judgeChoois (choois);
	switch (choois) {
		case DISCOUNT:
			cout<<"输入商品折扣: ";
			cin>>this->discount;
			break;
		case TARIFF:
			cout<<"输入商品关税: ";
			cin>>this->tariff;
			break;
		default:
			break;
	}
	return ;
}

