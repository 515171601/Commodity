#include <iostream>
#include "datatype.h"
#include "header.h"
#include <algorithm>

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
	std::cout<<"选择需要修改的信息:\n";
	std::cout<<"0) 商品数量\n";
	std::cout<<"1) 商品价格\n";
	std::cout<<"2) 商品折扣\n";
	std::cout<<"3) 退出\n";
	std::cout<<"请输入功能选项: ";
	char choois;
	std::cin>>choois;
	while(getchar()!='\n');
	return choois;
}

void setCommodityPrice(CommodityInfo *pCommodity){
	std::cout<<"输入商品价格: ";
	std::cin>>pCommodity->price;
	while(getchar()!='\n');
	return ;
}

void setCommodityNum(CommodityInfo *pCommodity){
	std::cout<<"输入商品数量: ";
	std::cin>>pCommodity->num;
	while(getchar()!='\n');
	return ;
}

void setCommodityDiscount(CommodityInfo *pCommodity){
	std::cout<<"输入商品折扣: ";
	std::cin>>pCommodity->discount;
	while(getchar()!='\n');
	return ;
}

char displayMenu(void){
	std::cout<<"选择打印时的排序标准\n";
	std::cout<<"0) 按商品ID升序输出\n";
	std::cout<<"1) 按商品名称升序输出\n";
	std::cout<<"2) 按商品价格升序输出\n";
	std::cout<<"3) 按商品折扣升序输出\n";
	std::cout<<"4) 按商品总价格升序输出\n";
	char choois;
	std::cin>>choois;
	while(getchar()!='\n');
	return choois;
}

void sortById(CommodityInfo *pCommodities, int num){
	std::sort(pCommodities, pCommodities+num,
			  [](CommodityInfo &c1, CommodityInfo &c2)->bool{
		return c1.id<c2.id;
	});
	return ;
}

void sortByName(CommodityInfo *pCommodities, int num){
	std::sort(pCommodities, pCommodities+num,
			  [](CommodityInfo &c1, CommodityInfo &c2)->bool{
		return c1.name<c2.name;
	});
	return ;
}

void sortByPrice(CommodityInfo *pCommodities, int num){
	std::sort(pCommodities, pCommodities+num,
			  [](CommodityInfo &c1, CommodityInfo &c2)->bool{
		return c1.price<c2.price;
	});
	return ;
}

void sortByDiscount(CommodityInfo *pCommodities, int num){
	std::sort(pCommodities, pCommodities+num,
			  [](CommodityInfo &c1, CommodityInfo &c2)->bool{
		return c1.discount<c2.discount;
	});
	return ;
}

void sortByTotalPrice(CommodityInfo *pCommodities, int num){
	std::sort(pCommodities, pCommodities+num,
			  [](CommodityInfo &c1, CommodityInfo &c2)->bool{
		return getCommodityPrice(&c1)<getCommodityPrice(&c2);
	});
	return ;
}







