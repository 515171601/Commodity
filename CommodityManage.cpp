﻿#include "CommodityManage.h"
#include "Commodity.h"
#include <string>
#include <fstream>
#include <iostream>
#include "header.h"


using namespace std;

CommodityManage::~CommodityManage(){
	for(auto e:pCommodities){
		delete e;
	}
}

void CommodityManage::addCommodity(Commodity* p){
	Commodity* pCommodity=findCommodityById(p->getId());
	if(pCommodity!=nullptr){
		cout<<"编号为"<<p->getId()<<"的商品已经存在!累加其数量\n";
		pCommodity->setNum(pCommodity->getNum()+p->getNum());
		return;
	}
	pCommodities.push_back(p);
	return ;
}

//todo: 根据最终版本修改内容实现相同的功能
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
	pCommodities.erase(getIterator(pCommodity));
}

void CommodityManage::viewCommodity(int id)const{
	const Commodity* pCommodity=findCommodityById(id);
	if(pCommodity==nullptr){
		cout<<"编号为"<<id<<"的商品不存在!\n";
		return;
	}
	pCommodity->output();
}

void CommodityManage::viewAllCommodities()const{
	cout<<"商品种类:"<< pCommodities.size()<<endl;
	for(auto e:pCommodities)
		e->output();
}

Commodity* CommodityManage::findCommodityById(int id){
	for(auto e : pCommodities)
		if(e->getId()==id)
			return e;
	return nullptr;
}

const Commodity* CommodityManage::findCommodityById(int id)const{
	for(auto e : pCommodities)
		if(e->getId()==id)
			return e;
	return nullptr;
}

vector<Commodity*>::iterator CommodityManage::getIterator(Commodity* p){
	for(auto it=pCommodities.begin();it!=pCommodities.end();++it)
		if(*it==p)
			return it;
	return pCommodities.end();
}

void CommodityManage::checkOut()const{
	double totalPrice=0;
	int totalNum=0;
	cout<<"商品种类: "<< pCommodities.size()<<endl;
	cout<<" 商品名称\t\t"<<"价格\t"<<"件数\t"<<"总价\n";
	for(auto e : pCommodities){
		double price=e->getNetPrice();
		cout<<" "<<e->getName()<<"\t";
		cout<<e->getPrice()<<"\t"
		   <<e->getNum()<<"\t"
		  <<price<<endl;
		totalPrice+=price;
		totalNum+=e->getNum();
	}
	cout<<"购物篮商品总件数: "<<totalNum<<"\n";
	cout<<"购物篮结算总价: "<<totalPrice<<endl;
}

void CommodityManage::saveData(string filename){
	ofstream out(filename);
	if(out){
		out<< pCommodities.size()<<endl;
		out<<Commodity::getNextId()<<endl;
		for(auto e : pCommodities){
			out<<e->getInfo();
		}
	}
#ifdef DEBUG
	cerr<<"保存完成\n";
#endif
}


void CommodityManage::readData(string filename) {
	ifstream in(filename);
	if(in) {
		int fileSize;
		long nextId;
		in>>fileSize>>nextId;
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
