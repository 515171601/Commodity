#include <iostream>
#include "NormalCommodity.h"
using namespace std;
NormalCommodity::NormalCommodity(long id,std::string name,
								 double p,int n,double d)
	:Commodity(id,name,p,n),discount(d){}
NormalCommodity::NormalCommodity(std::string name,double p,
								 int n,double d)
	:Commodity(name,p,n),discount(d){}
double NormalCommodity::getNetPrice()const{
	return Commodity::getNetPrice()*discount;
}
void NormalCommodity::output()const{
	Commodity::output();
	cout<<" 商品总价:"<<getNetPrice()<<" (价格:"
	   <<getPrice()<<", 数量:"<<getNum()<<", 折扣:"
	  <<discount<<" )\n";
}
