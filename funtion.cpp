#include <iostream>
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
	return choice;
}
