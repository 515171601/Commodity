#include <iostream>
#include "datatype.h"
#include "header.h"

void reAllocMemory(CommodityInfo *&pCommodities,int num){
	maxCommodityNum*=2;
	CommodityInfo *temp=pCommodities;
	pCommodities=new CommodityInfo[maxCommodityNum];
	for(int i=0;i<num;++i)
		pCommodities[i]=temp[i];
	delete[] temp;
}

void setCommodityInfo (CommodityInfo *pCommodity){ //读取商品信息
	fflush(stdin); //确保之前残留的回车被清理，商品名称取整行
	std::cout<<" 输入商品名称: ";
	getline(std::cin,pCommodity->name);
	std::cout<<" 输入商品价格: ";
	std::cin>>pCommodity->price;
	std::cout<<" 输入商品数量: ";
	std::cin>>pCommodity->num;
	std::cout<<" 输入商品折扣: ";
	std::cin>>pCommodity->discount;
}

void setCommodityPrice(CommodityInfo *pCommodity){
	while(getchar()!='\n');
	std::cout<<"输入商品价格: ";
	std::cin>>pCommodity->price;
	return ;
}

void setCommodityNum(CommodityInfo *pCommodity){
	while(getchar()!='\n');
	std::cout<<"输入商品数量: ";
	std::cin>>pCommodity->num;
	return ;
}

void setCommodityDiscount(CommodityInfo *pCommodity){
	while(getchar()!='\n');
	std::cout<<"输入商品折扣: ";
	std::cin>>pCommodity->discount;
	return ;
}

int findCommodityById (CommodityInfo *pCommodities,
					   int num, long id){
	int index=0;
	for(;index<num;index++){
		if((pCommodities+index)->id==id){
			return index;
		}
	}
	return NOT_FOUND;
}

double getCommodityPrice(CommodityInfo *pCommodity){
	return pCommodity->price*pCommodity->num*pCommodity->discount;
}

void showCommodityInfo(CommodityInfo *pCommodity){
	std::cout<<"商品编号(id):"<<pCommodity->id<<std::endl;
	std::cout<<" 商品名称:"<<pCommodity->name<<std::endl;
	std::cout<<" 商品总价:"<<getCommodityPrice(pCommodity)
			<<" (价格:"<<pCommodity->price<<", 数量:"
		   <<pCommodity->num<<", 折扣:"<<pCommodity->discount<<" )\n";
}

char editMenu(void){
	while(getchar()!='\n');	//清空缓冲区
	std::cout<<"选择需要修改的信息:\n";
	std::cout<<"0) 商品数量\n";
	std::cout<<"1) 商品价格\n";
	std::cout<<"2) 商品折扣\n";
	std::cout<<"3) 退出\n";
	std::cout<<"请输入功能选项: ";
	char choois;
	std::cin>>choois;

	return choois;
}
