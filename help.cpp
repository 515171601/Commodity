#include <iostream>
#include "datatype.h"
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
CommodityInfo *findCommodityById(CommodityInfo *pCommodities,
								 int num, long id){
	CommodityInfo *pCommodity=pCommodities;
	for(; pCommodity < pCommodities+num; pCommodity++){
		if(pCommodity->id==id){
			return pCommodity;
		}
	}
	return nullptr;
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
