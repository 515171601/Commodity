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


#endif
