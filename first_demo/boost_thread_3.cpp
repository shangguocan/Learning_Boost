/*
* C++ thread 中join 和 detach 的区别
* https://blog.csdn.net/Fourier_Legend/article/details/89306896
*/


// g++ test.cpp -std=gnu++11 -lpthread

#include<iostream>
#include<boost/thread/thread.hpp>
#include<thread>
//#include<unistd.h>

void fun1(int n) {

	for (int i = 0; i < 10; i++) {
		std::cout << "Func1" << std::endl;
		boost::thread::sleep(boost::get_system_time() + boost::posix_time::seconds(1));;
	}
}

int main() {
	int n = 0;
	std::thread th1(fun1, n);
	// th1.join();
	th1.detach();
	std::cout << "OVER !!! " << std::endl;
	return 1;
}

//
//// join() 会停止主线程
//Func1
//Func1
//Func1
//Func1
//Func1
//Func1
//Func1
//Func1
//Func1
//Func1
//OVER !!!
//
//
//// detach 将线程对象和线程解耦合,主线不等子线程结束
//OVER !!!
//Func1
