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

void BargainCommodity::editInfo(){
	this->printEditMenu ();
	this->judgeChoois (this->getChoois ());
	cout<<"修改后的商品如下: \n";
	this->output ();
	return ;
}

void BargainCommodity::printEditMenu(){
	Commodity::printEditMenu ();
	printf(
				"%d) 商品特价\n"
				,SPECIALPRICE);
	return ;
}

int BargainCommodity::getChoois(){
	char choois=0;
	cin>>choois;
	while(getchar()!='\n');
	while(choois<'0'+NAME||choois>'0'+SPECIALPRICE){
		cout<<"非法输入, 请重试!\n";
		cin>>choois;
		while(getchar()!='\n');
	}
	choois-='0';
	return static_cast<int>(choois);
}

void BargainCommodity::judgeChoois(int choois){
	Commodity::judgeChoois (choois);
	switch (choois) {
		case SPECIALPRICE:
			cout<<"输入商品特价: ";
			cin>>this->specialPrice;
			break;
		default:
			break;
	}
	return ;
}





