#include <iostream>
#include "header.h"
#include <sstream>

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


int NormalCommodity::getType()const{
	return NORMAL;
}

string NormalCommodity::getInfo()const{
	ostringstream ostr;
	ostr<<getType()<<" "; //先输出类型编码
	ostr<<Commodity::getInfo (); //输出基类的信息
	ostr<<discount<<endl; //输出子类信息
	return ostr.str();
}

void NormalCommodity::editInfo(){
#ifdef DEBUG
	cerr<<"NormalCommodity\n";
#endif
	this->printEditMenu ();
	this->judgeChoois (this->getChoois ());
	cout<<"修改后的商品如下: \n";
	this->output ();
	return ;
}

void NormalCommodity::printEditMenu(){
	Commodity::printEditMenu ();
	printf(
				"%d) 商品折扣\n"
				, DISCOUNT);
	return ;
}

int NormalCommodity::getChoois(){
	char choois=0;
	cin>>choois;
	while(getchar()!='\n');
	while(choois<'0'+NAME||choois>'0'+DISCOUNT){
		cout<<"非法输入, 请重试!\n";
		cin>>choois;
		while(getchar()!='\n');
	}
	choois-='0';
	return static_cast<int>(choois);
}

void NormalCommodity::judgeChoois(int choois){
	Commodity::judgeChoois (choois);
	switch (choois) {
		case DISCOUNT:
			cout<<"输入商品折扣: ";
			cin>>this->discount;
			break;
		default:
			break;
	}
	return ;
}
