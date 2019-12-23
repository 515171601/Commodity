#ifndef HELP_HEADER
#define HELP_HEADER
#include "datatype.h"

const int NOT_FOUND=-1;

int findCommodityById (CommodityInfo *pCommodities,
					   int num, long id);
void showCommodityInfo(CommodityInfo *pCommodity);
void setCommodityInfo(CommodityInfo *pCommodity);
double getCommodityPrice(CommodityInfo *pCommodity);
void reAllocMemory(CommodityInfo *&pCommodities,int num);
char editMenu(void);
void setCommodityPrice(CommodityInfo *pCommodity);
void setCommodityNum(CommodityInfo *pCommodity);
void setCommodityDiscount(CommodityInfo *pCommodity);
char displayMenu(void);
void sortById(CommodityInfo *pCommodities, int num);
void sortByName(CommodityInfo *pCommodities, int num);
void sortByPrice(CommodityInfo *pCommodities, int num);
void sortByDiscount(CommodityInfo *pCommodities, int num);
void sortByTotalPrice(CommodityInfo *pCommodities, int num);




#endif
