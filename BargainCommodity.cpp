#include "header.h"
#include <iostream>
#include <sstream>

using namespace std;

BargainCommodity::BargainCommodity
(long id, std::string name, double p, int nn, double sp):
	Commodity(id,name, p, nn), specialPrice(sp) {}

BargainCommodity::BargainCommodity
(std::string name, double p, int nn, double sp):
	Commodity(name, p, nn), specialPrice(sp) {}

double BargainCommodity::getNetPrice() const{
	return this->specialPrice*getNum ();
}

void BargainCommodity::output() const{
	Commodity::output ();
	cout<<" 商品总价:"<<getNetPrice()<<" (特价:"
	   <<getSpecialPrice ()<<", 数量:"<<getNum()<<" )\n";
	return ;
}

int BargainCommodity::getType() const{
	return BARGAIN;
}

std::string BargainCommodity::getInfo() const{
	ostringstream ostr;
	ostr<<BargainCommodity::getType ()<<" "; //先输出类型编码
	ostr<<Commodity::getInfo (); //输出基类的信息
	ostr<<this->specialPrice<<endl; //输出子类信息
	return ostr.str();
}





