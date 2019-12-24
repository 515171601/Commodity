#include "CommodityManage.h"
#include "Commodity.h"
#include <iostream>

CommodityManage::CommodityManage()
	:CommodityManage(100){}

CommodityManage::CommodityManage(int s)
	:maxSize(s),size(0){
	pCommodities=new Commodity[maxSize];
}

Commodity* CommodityManage::findCommodityById(int id)const{
	for(int i=0;i<size;++i)
		if(pCommodities[i].getId()==id)
			return pCommodities+i;
	return nullptr;
}

void CommodityManage::reAllocMemory(){
	maxSize*=2;
	int i;
	Commodity *temp=pCommodities;
	pCommodities=new Commodity[maxSize];
	for(i=0;i<size;++i)
		pCommodities[i]=temp[i];
	delete[] temp;
}

void CommodityManage::addCommodity(const Commodity& c){
	if(size==maxSize){
		reAllocMemory();
	}
	Commodity* pCommodity=findCommodityById(c.getId());
	if(pCommodity!=nullptr){
		std::cout<<"编号为"<<c.getId()<<"的商品已经存在!累加其数量\n";
		pCommodity->setNum(pCommodity->getNum()+c.getNum());
		return;
	}
	pCommodities[size]=c;
	size++;
}
void CommodityManage::removeCommodity(int id){
	Commodity* pCommodity=findCommodityById(id);
	if(pCommodity==nullptr){
		std::cout<<"编号为"<<id<<"的商品不存在!\n";
		return;
	}
	Commodity *pNext;
	size--;
	while(pCommodity<pCommodities+size){//后面的商品往前移动
		pNext=pCommodity+1;
		*pCommodity=*pNext;
		pCommodity++;
	}
}
void CommodityManage::viewCommodity(int id)const{
	Commodity* pCommodity=findCommodityById(id);
	if(pCommodity==nullptr){
		std::cout<<"编号为"<<id<<"的商品不存在!\n";
		return;
	}
	pCommodity->output();
}
void CommodityManage::viewAllCommodities()const{
	std::cout<<"商品种类:"<<size<<std::endl;
	for(int i=0;i<size;++i)
		pCommodities[i].output();
}
void CommodityManage::checkOut()const{
	double totalPrice=0;
	int totalNum=0;
	std::cout<<"商品种类: "<<size<<std::endl;
	std::cout<<" 商品名称\t\t"<<"价格\t"<<"件数\t"<<"折扣\t"<<"总价\n";
	for(int i=0;i<size;++i){
		double price=(pCommodities+i)->getNetPrice();
		std::cout<<" "<<pCommodities[i].getName()<<"\t";
		std::cout<<pCommodities[i].getPrice()<<"\t"
		   <<pCommodities[i].getNum()<<"\t"
		  <<pCommodities[i].getDiscount()<<"\t"
		 <<price<<std::endl;
		totalPrice+=price;
		totalNum+=pCommodities[i].getNum();
	}
	std::cout<<"购物篮商品总件数: "<<totalNum<<"\n";
	std::cout<<"购物篮结算总价: "<<totalPrice<<std::endl;
}
