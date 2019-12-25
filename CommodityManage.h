#ifndef COMMODITYMANAGE_H
#define COMMODITYMANAGE_H
#include "commodity.h"
#include <vector>

class CommodityManage{
public:
	CommodityManage()=default;
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
	std::vector<Commodity*> pCommodities;
	Commodity* findCommodityById(int id);
	const Commodity* findCommodityById(int id)const;
	std::vector<Commodity*>::iterator getIterator(Commodity* p);
};
#endif // COMMODITYMANAGE_H

