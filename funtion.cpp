﻿#include <iostream>
#include "header.h"
#include <fstream>

using namespace std;


void readData(std::string filename){
	ifstream in(filename);
	if(in){
		in>>maxCommodityNum;
		pCommodities=new CommodityInfo[maxCommodityNum];
		in>>commodityNum;
		if(commodityNum> maxCommodityNum)
			commodityNum= maxCommodityNum;
		string buf;
		for(int i=0;i<commodityNum;++i){
			in>> pCommodities [i].id;
			getline(in,buf);
			getline(in, pCommodities [i].name);
			in>> pCommodities [i].price>> pCommodities [i].num
					>> pCommodities [i].discount;
		}
	}
	else
		pCommodities=new CommodityInfo[maxCommodityNum];
}
void writeData(std::string filename){
	ofstream out(filename);
	if(out){
		out<<maxCommodityNum<<endl;
		out<<commodityNum<<endl;
		for(int i=0;i<commodityNum;++i){
			out<< pCommodities [i].id<<endl;
			out<< pCommodities [i].name<<endl;
			out<< pCommodities [i].price<<" "<< pCommodities [i].num
			   <<" "<< pCommodities [i].discount<<endl;
		}
	}
}

char menu(){
	cout<<" 0) 退出系统\n";
	cout<<" 1) 向购物篮添加商品\n";
	cout<<" 2) 从购物篮移除商品\n";
	cout<<" 3) 查看指定商品\n";
	cout<<" 4) 查看所有商品\n";
	cout<<" 5) 结算\n";
	cout<<"请输入功能选项:";
	char choice;
	cin>>choice;
	return choice;
}
void displayCommodities(CommodityInfo *pCommodities, int num){
	int i;
	cout<<"商品种类: "<<num<<endl;
	for(i=0;i<num;i++) {
		showCommodityInfo(&pCommodities[i]);
	}
	cout<<endl;
}
void addCommodity(CommodityInfo *&pCommodities, int &num){
	int id;
	cout<<" 输入商品编号(id): ";
	cin>>id;
	int index=findCommodityById(pCommodities,num,id);

	CommodityInfo *pCommodity=pCommodities;

	if(index!=NOT_FOUND){//找到商品，累加数量
		pCommodity=pCommodities+index;
		cout<<"编号为"<<id<<"的商品已经存在!\n";
		cout<<"请输入增加的商品数量: ";
		int number;
		cin>>number;
		pCommodity->num+=number;
		return;
	}
	if(num==maxCommodityNum){
		reAllocMemory(pCommodities,num);
	}
	pCommodity = &pCommodities[num];
	pCommodity->id=id;
	setCommodityInfo(pCommodity);
	num++;
	cout<<"商品添加成功!\n\n";
}
void removeCommodity(CommodityInfo *pCommodities, int &num){
	int id;
	cout<<" 输入商品编号(id): ";
	cin>>id;
	CommodityInfo *pCommodity=nullptr;
	int index=findCommodityById(pCommodities,num,id);
	if(index==NOT_FOUND){
		cout<<"编号为"<<id<<"的商品不存在!\n\n";
		return;
	}else{
		pCommodity=pCommodities+index;
	}
	num--;
	CommodityInfo *pNext=pCommodity+1;
	while(pCommodity < pCommodities + num){
		pCommodity->id=pNext->id;
		pCommodity->name=pNext->name;
		pCommodity->price=pNext->price;
		pCommodity->num=pNext->num;
		pCommodity->discount=pNext->discount;
		pCommodity++;
		pNext++;
	}
	cout<<"商品移除成功!\n\n";
}
void viewCommodity(CommodityInfo *pCommodities, int num){
	int id;
	cout<<" 输入商品的编号(id): ";
	cin>>id;
	CommodityInfo *pCommodity=nullptr;
	int index=findCommodityById(pCommodities,num,id);
	if(index==NOT_FOUND){
		cout<<"编号为"<<id<<"的商品不存在!\n\n";
		return;
	}else{
		pCommodity=pCommodities+index;
	}
	showCommodityInfo(pCommodity);
	cout<<endl;
}
void checkOut(CommodityInfo *pCommodities, int num){
	double totalPrice=0;
	int totalNum=0;
	cout<<"商品种类: "<<num<<endl;
	cout<<" 商品名称\t\t"<<"价格\t"<<"件数\t"<<"折扣\t"<<"总价\n";
	for(int i=0;i<num;++i){
		double price=getCommodityPrice(pCommodities+i);
		cout<<" "<<pCommodities[i].name<<"\t";
		cout<<pCommodities[i].price<<"\t"
		   <<pCommodities[i].num<<"\t"
		  <<pCommodities[i].discount<<"\t"
		 <<price<<endl;
		totalPrice+=price;
		totalNum+=pCommodities[i].num;
	}
	cout<<"购物篮商品总件数: "<<totalNum<<"\n";
	cout<<"购物篮结算总价: "<<totalPrice<<endl;
}
