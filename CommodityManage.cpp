#include "CommodityManage.h"
#include "Commodity.h"
#include <string>
#include <fstream>
#include <iostream>
#include "header.h"
#include <algorithm>


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
	sortCommodities(); //添加商品后根据当前规则重新排序
	return ;
}

void CommodityManage::sortCommodities(){
	switch(sortType){
		case SORT_BY_ID: //根据 id 排序
			sort(pCommodities.begin(),pCommodities.end(),
				 [=](Commodity* p1,Commodity* p2){
				return p1->getId()<p2->getId();
			});
			break;
		case SORT_BY_NAME: //根据名称排序
			sort(pCommodities.begin(),pCommodities.end(),
				 [=](Commodity* p1,Commodity* p2){
				bool flag=0;
				if(p1->getName()==p2->getName()){
					flag=(p1->getId()<p2->getId());
				}else{
					flag=(p1->getName()<p2->getName());
				}
				return flag;
			});
			break;
		case SORT_BY_TOTAL_PRICE: //根据净价排序
			sort(pCommodities.begin(),pCommodities.end(),
				 [=](Commodity* p1,Commodity* p2){
				return p1->getNetPrice()<p2->getNetPrice();
			});
			break;
		case SORT_BY_PRICE:
			sort(pCommodities.begin (), pCommodities.end (),
				 [=](Commodity* p1,Commodity* p2){
				return p1->getPrice ()<p2->getPrice ();
			});
			break;
		case SORT_BY_NUM:
			sort(pCommodities.begin (), pCommodities.end (),
				 [=](Commodity* p1,Commodity* p2){
				return p1->getNum ()<p2->getNum ();
			});
			break;
		default:
			break;
	}
}

void CommodityManage::sortCommoditiesByType(int type){
	if(type==sortType){ //已经按指定规则排序，直接返回
		return;
	}
	sortType=type;
	sortCommodities();
}

//todo: 添加菜单
void CommodityManage::printSortMenu() const{
	printf(
				"指定排序方式: \n"
				"%d) 商品ID\n"
				"%d) 商品名称\n"
				"%d) 商品净价\n"
				"%d) 商品数量\n"
				"%d) 商品价格\n"
				"输入选择项: \n"
				, SORT_BY_ID, SORT_BY_NAME, SORT_BY_TOTAL_PRICE
				, SORT_BY_NUM, SORT_BY_PRICE);
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
	if(pCommodities.size()==0)
		return;
	this->printSortMenu ();
	int type;
	cin>>type;
	while(getchar()!='\n');
	const_cast<CommodityManage*>(this)->sortCommoditiesByType(type);
	for(auto e:pCommodities)
		e->output();
}

Commodity* CommodityManage::findCommodityById(int id){
	vector<Commodity*>::iterator it=find_if(pCommodities.begin(),
											pCommodities.end(),
											[=](Commodity* p){
		return p->getId()==id;});
	if(it!=pCommodities.end())
		return *it;
	return nullptr;
}

const Commodity* CommodityManage::findCommodityById(int id)const{
	vector<Commodity*>::const_iterator it=find_if(pCommodities.begin(),
												  pCommodities.end(),
												  [=](const Commodity* p){
		return p->getId()==id;});
	if(it!=pCommodities.end())
		return *it;
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
	sortCommodities();
	return ;
}
