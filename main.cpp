#include <iostream>
#include "commodity.h"
#include "normalcommodity.h"
#include "overseacommodity.h"
using namespace std;
int main(){
	NormalCommodity c1("Java Programming",108,2,0.9);
	c1.output();
	OverseaCommodity c2("C++ Programming",100,3,0.8,23.4);
	c2.output();
	Commodity *p=&c1;
	p->output();
	p=&c2;
	p->output();
	return 0;
}
