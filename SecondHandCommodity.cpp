#include "header.h"
#include <iostream>
#include <sstream>

using namespace std;

SecondHandCommodity::SecondHandCommodity
(long id, std::string name, double p, int n, double dis, double dep):
	NormalCommodity(id, name, p, n, dis), depreciation(dep) {}

SecondHandCommodity::SecondHandCommodity
(std::string name, double p, int n, double dis, double dep):
	NormalCommodity(name, p, n, dis), depreciation(dep){}

double SecondHandCommodity::getNetPrice() const{
	return NormalCommodity::getNetPrice ()*this->depreciation;
}

void SecondHandCommodity::output() const{
	Commodity::output();
	cout<<" 商品总价:"<<getNetPrice()<<" (价格:"
	   <<getPrice()<<", 数量:"<<getNum()<<", 折扣:"
	  <<getDiscount ()<<", 商品折旧:"<<getDepreciation ()<<" )\n";
	return ;
}

int SecondHandCommodity::getType() const{
	return SECONDHAND;
}

string SecondHandCommodity::getInfo() const{
	ostringstream ostr;
	ostr<<SecondHandCommodity::getType ()<<" "; //先输出类型编码
	ostr<<Commodity::getInfo (); //输出基类的信息
	ostr<<getDiscount ()<<" "<<this->depreciation<<endl; //输出子类信息
	return ostr.str();
}

void SecondHandCommodity::editInfo(){
#ifdef DEBUG
	cerr<<"SecondHandCommodity\n";
#endif
	this->printEditMenu ();
	this->judgeChoois (this->getChoois ());
	cout<<"修改后的商品如下: \n";
	this->output ();
	return ;
}

void SecondHandCommodity::printEditMenu(){
	NormalCommodity::printEditMenu ();
	printf(
				"%d) 商品折旧程度\n"
				,DEPRECIATION);
	return ;
}

int SecondHandCommodity::getChoois(){
	char choois=0;
	cin>>choois;
	while(getchar()!='\n');
	while(choois<'0'+NAME||choois>'0'+DEPRECIATION){
		cout<<"非法输入, 请重试!\n";
		cin>>choois;
		while(getchar()!='\n');
	}
	choois-='0';
	return static_cast<int>(choois);
}

void SecondHandCommodity::judgeChoois(int choois){
	NormalCommodity::judgeChoois (choois);
	switch (choois) {
		case DEPRECIATION:
			cout<<"输入折旧程度: ";
			cin>>this->depreciation;
			break;
		default:
			break;
	}
	return ;
}


