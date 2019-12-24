#include <iostream>
#include "header.h"

using namespace std;

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
	//	while(getchar()!='\n');
	return choice;
}

void doRemoveCommodity(CommodityManage& cm){
	long id;
	cout<<"Input id:";
	cin>>id;
	cm.removeCommodity(id);
	//	while(getchar()!='\n');
}

void doViewCommodity(const CommodityManage& cm){
	long id;
	cout<<"Input id:";
	cin>>id;
	cm.viewCommodity(id);
	//	while(getchar()!='\n');
}

void doViewAllCommodity(const CommodityManage& cm){
	cm.viewAllCommodities();
}

void doCheckout(const CommodityManage& cm){
	cm.checkOut();
}

char commodityClassificationMenu(void){
	printf(
				"选择商品类型:\n"
				"%d) 普通商品\n"
				"%d) 海外购商品\n"
				"%d) 二手商品\n"
				"%d) 特价商品\n"
				,NORMAL, OVERSEA, SECONDHAND, BARGAIN);
	char choois=0;
	cin>>choois;
	while(getchar()!='\n');			//清空缓冲区
	while(choois<'0'||choois>BARGAIN+'0'){
		cout<<"无效输入, 请重试!\n";
		cin>>choois;
		while(getchar()!='\n');		//清空缓冲区
	}
	return choois;
}

void doAddCommodity(CommodityManage& cm){
	string name;
	double price,discount;
	double tariff;
	int num;
	char choois=commodityClassificationMenu ();
	cout<<"输入商品名称:";
	getline(cin,name);
	cout<<"输入价格和商品数量:";
	cin>>price>>num;
	switch(choois){
		case '0':
			cout<<"输入商品折扣:";
			cin>>discount;
			cm.addCommodity(new
							NormalCommodity(name,price,num,discount));
			break;
		case '1':
			cout<<"输入商品折扣和关税:";
			cin>>discount>>tariff;
			cm.addCommodity(new
							OverseaCommodity(name,price,num,discount,tariff));
			break;
		case '2':
			cout<<"输入商品折扣和折旧程度: ";
			double depreciation;
			cin>>discount>>depreciation;
			cm.addCommodity (new SecondHandCommodity
							 (name, price, num, discount, depreciation));
			break;
		case '3':
			cout<<"输入商品特价: ";
			double specialPrice;
			cin>>specialPrice;
			cm.addCommodity (new BargainCommodity
							 (name, price, num, specialPrice));
			break;
		default:
			break;
	}
	return ;
}
