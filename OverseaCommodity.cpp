#include <iostream>
#include "overseacommodity.h"
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
