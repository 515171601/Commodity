#include <iostream>
#include "function.h"
using namespace std;
int main(){
	cout<<"欢迎使用购物篮管理系统!\n";
	char choice;
	while(true){
		choice=menu();
		if(choice=='0')
			break;
		switch(choice){
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
