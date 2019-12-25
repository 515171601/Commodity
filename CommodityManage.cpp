#include "CommodityManage.h"
#include "Commodity.h"
#include <string>
#include <fstream>
#include <iostream>
#include "header.h"

//#define DEUBG

using namespace std;

CommodityManage::CommodityManage(const int s)
	:maxSize(s),size(0){
	pCommodities=new Commodity*[maxSize];
}

CommodityManage::~CommodityManage(){
	for(int i=0;i<size;++i)
		delete pCommodities[i];
	delete[] pCommodities;
	pCommodities=nullptr;
}

void CommodityManage::addCommodity(Commodity* p){
	if(size==maxSize){
		reAllocMemory();
	}
	Commodity* pCommodity=findCommodityById(p->getId());
	if(pCommodity!=nullptr){
		cout<<"编号为"<<p->getId()<<"的商品已经存在!累加其数量\n";
		pCommodity->setNum(pCommodity->getNum()+p->getNum());
		return;
	}
	pCommodities[size]=p;
	size++;

	return ;
}

void CommodityManage::editCommodity(int id){
	Commodity *pCommodity=findCommodityById (id);
	if(pCommodity==nullptr){
		cout<<"编号为"<<id<<"的商品不存在!\n";
		return ;
	}
#ifdef	DEBUG
	pCommodity->output ();
#endif
	cout<<"输入需要修改的商品信息项: \n";
	//todo: 调用commodity的成员函数进行修改, 此处使用多态调用
	pCommodity->editInfo ();
	return ;
}


void CommodityManage::removeCommodity(int id){
	Commodity* pCommodity=findCommodityById(id);
	if(pCommodity==nullptr){
		cout<<"编号为"<<id<<"的商品不存在!\n";
		return;
	}
	delete pCommodity;
	size--;
	Commodity **pos=pCommodities+size;
	while(*pos!=pCommodity){
		pos--;
	}
	while(pos<pCommodities+size){ //移动指针数组中的元素
		*pos=*(pos+1);
		pos++;
	}
}

void CommodityManage::viewCommodity(int id)const{
	Commodity* pCommodity=findCommodityById(id);
	if(pCommodity==nullptr){
		cout<<"编号为"<<id<<"的商品不存在!\n";
		return;
	}
	pCommodity->output();
}

void CommodityManage::viewAllCommodities()const{
	cout<<"商品种类:"<<size<<endl;
	for(int i=0;i<size;++i)
		pCommodities[i]->output();
}

Commodity* CommodityManage::findCommodityById(int id)const{
	for(int i=0;i<size;++i){
		if(pCommodities[i]->getId()==id){
			return pCommodities[i];
		}
	}
	return nullptr;
}

void CommodityManage::reAllocMemory(){
	maxSize*=2;
	int i;
	Commodity **temp=pCommodities;
	pCommodities=new Commodity*[maxSize];
	for(i=0;i<size;++i)
		pCommodities[i]=temp[i];
	delete[] temp;
}

void CommodityManage::checkOut()const{
	double totalPrice=0;
	int totalNum=0;
	cout<<"商品种类: "<<size<<endl;
	cout<<" 商品名称\t\t"<<"价格\t"<<"件数\t"<<"总价\n";
	for(int i=0;i<size;++i){
		double price=pCommodities[i]->getNetPrice();
		cout<<" "<<pCommodities[i]->getName()<<"\t";
		cout<<pCommodities[i]->getPrice()<<"\t"
		   <<pCommodities[i]->getNum()<<"\t"
		  <<price<<endl;
		totalPrice+=price;
		totalNum+=pCommodities[i]->getNum();
	}
	cout<<"购物篮商品总件数: "<<totalNum<<"\n";
	cout<<"购物篮结算总价: "<<totalPrice<<endl;
}

void CommodityManage::saveData(string filename){
	ofstream out(filename);
	if(out){
		out<<maxSize<<endl;
		out<<size<<endl;
		out<<Commodity::getNextId()<<endl;
		for(int i=0;i<size;++i){
			out<< pCommodities[i]->getInfo();
		}
	}
#ifdef DEBUG
	cerr<<"保存完成\n";
#endif
}

void CommodityManage::readData(string filename) {
	ifstream in(filename);
	if(in) {
		int fileMax,fileSize;
		long nextId;
		in>>fileMax>>fileSize>>nextId;
		Commodity::setNextId(nextId);
		int type;
		long id;
		string name,buf;
		double price,discount;
		double tariff;
		int num;
		for(int i=0; i<fileSize; ++i) {
			in>>type;
			in>>id;
			getline(in,buf);
			getline(in,name);
			in>>price>>num;
			switch(type) {
				case 0:
					in>>discount;
					addCommodity(new
								 NormalCommodity(id,name,price,num,discount));
					break;
				case 1:
					in>>discount>>tariff;
					addCommodity(new
								 OverseaCommodity(id,name,price,num,discount,tariff));
					break;
				case 2:
					double depreciation;
					in>>discount>>depreciation;
					addCommodity (new SecondHandCommodity
								  (id,name, price, num, discount, depreciation));
					break;
				case 3:
					double specialPrice;
					in>>specialPrice;
					addCommodity (new BargainCommodity
								  (id,name, price, num, specialPrice));
					break;
				default:
					break;
			}
		}
	}
}
