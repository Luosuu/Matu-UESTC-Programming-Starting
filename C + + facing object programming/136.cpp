#include<iostream>

class Location {
private:
	int X, Y;
public:
	void init(int initX, int initY) {
		X = initX;
		Y = initY;
	}
	int GetX() {
		return X;
	}
	int GetY() {
		return Y;
	}
};
int main() {
	Location A1;
	A1.init(20, 90);
	Location & rA1 = A1;    //定义一个指向A1的引用rA1;
	//马图真就不支持 auto 啊
	std::cout << rA1.GetX() << rA1.GetY();   //用rA1在屏幕上依次输出对象A1的数据成员X和Y的值;
	return 0;
}