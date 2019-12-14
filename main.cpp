#include <iostream>

using namespace std;

int main(){
	cout<<"欢迎使用购物篮管理系统!\n";
	cout<<" 0) 退出系统\n";
	cout<<" 1) 向购物篮添加商品\n";
	cout<<" 2) 从购物篮移除商品\n";
	cout<<" 3) 查看指定商品\n";
	cout<<" 4) 查看所有商品\n";
	cout<<" 5) 结算\n";
	cout<<"请输入功能选项:";
	char choice;
	while(true){
		cin>>choice;
		if(choice=='0')
			break;
		switch(choice) {
			case '1': //具体功能省略
				break;
			case '2': //具体功能省略
				break;
			case '3': //具体功能省略
				break;
			case '4': //具体功能省略
				break;
			case '5': //具体功能省略
				break;
			default:
				cout<<"无效输入! 请重试!\n";
				break;
		}
	}
	cout<<"再见!\n";
	return 0;
}
