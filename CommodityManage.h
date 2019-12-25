#ifndef COMMODITYMANAGE_H
#define COMMODITYMANAGE_H
#include "commodity.h"

class CommodityManage{
public:
	CommodityManage():CommodityManage(100) {}
	CommodityManage(const int s);
	~CommodityManage();
	CommodityManage(const CommodityManage& c)=delete;
	CommodityManage& operator=(const CommodityManage& c)=delete;
	void addCommodity(Commodity* p);
	void addCommodity(const Commodity& p);
	void editCommodity(int id);
	void removeCommodity(int id);
	void viewCommodity(int id)const;
	void viewAllCommodities()const;
	void checkOut()const;
	void readData(std::string filename);
	void saveData(std::string filename);
private:
	Commodity **pCommodities; //指向动态创建的商品指针数组
	int maxSize; //当前分配的空间上限
	int size; //实际的商品数量
	Commodity* findCommodityById(int id)const;
	void reAllocMemory();
};
#endif // COMMODITYMANAGE_H

