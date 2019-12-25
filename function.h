#ifndef FUNCTION_H
#define FUNCTION_H
#include "commoditymanage.h"

char menu();
void doAddCommodity(CommodityManage& cm);
void doRemoveCommodity(CommodityManage& cm);
void doViewCommodity(const CommodityManage& cm);
void doViewAllCommodity(const CommodityManage& cm);
void doCheckout(const CommodityManage& cm);
void doEditCommodity(CommodityManage& cm);

#endif // FUNCTION_H
