#include <iostream>
#include "header.h"

using namespace std;

char menu(){
	cout<<" 0) 退出系统\n";
	cout<<" 1) 向购物篮添加商品\n";
	cout<<" 2) 从购物篮移除商品\n";
	cout<<" 3) 修改指定的商品\n";
	cout<<" 4) 查看指定商品\n";
	cout<<" 5) 查看所有商品\n";
	cout<<" 6) 结算\n";
	cout<<"请输入功能选项:";
	char choice;
	cin>>choice;
	return choice;
}

void doEditCommodity(CommodityManage& cm){
	string name;
	cout<<"Input name:";
	cin>>name;
	cm.editCommodity (name);
	return ;
}

void doRemoveCommodity(CommodityManage& cm){
	string name;
	cout<<"Input name:";
	cin>>name;
	cm.removeCommodity(name);
}

void doViewCommodity(const CommodityManage& cm){
	string name;
	cout<<"Input name:";
	cin>>name;
	cm.viewCommodity(name);
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
	Commodity* pCommodity=cm.findCommodityByName (name);
	if(pCommodity!=nullptr){
		cout<<"名称为"<<name<<"的商品已经存在\n";
		cout<<"输入添加的数量: ";
		int newNum=0;
		cin>>newNum;
		pCommodity->setNum (newNum);
	}else{
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
	}
	return ;
}
