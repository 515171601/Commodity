#ifndef BARGINCOMMODITY_H
#define BARGINCOMMODITY_H

#include "commodity.h"

class BargainCommodity : public Commodity{
public:
	virtual ~BargainCommodity() =default;

	BargainCommodity(long id,std::string name,double p=0,int nn=0, double sp=0);
	BargainCommodity(std::string name,double p=0,int nn=0, double sp=0);

	double getSpecialPrice(void) const{
		return this->specialPrice;
	}

	void setSpecialPrice(double sp){
		this->specialPrice=sp;
		return ;
	}

	virtual double getNetPrice()const;
	virtual void output()const;
	virtual int getType()const;
	virtual std::string getInfo()const;

private:
	double specialPrice;
};


#endif // BARGINCOMMODITY_H
