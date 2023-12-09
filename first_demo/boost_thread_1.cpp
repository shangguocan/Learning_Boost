/*
* C++ ����֮· ���ģ� boost::thread ���߳�ȫ����
* https://blog.csdn.net/Fourier_Legend/article/details/82020686
* 
*/



/*
thread.cpp
*/
#include <boost/thread/thread.hpp> 
#include <iostream> 

//#include <unistd.h>

/*
 * g++ thread.cpp -lboost_system -lboost_thread
*/

void helloA()
{
    std::cout << "I'm thread A !  --- Start " << std::endl;

    boost::thread::sleep(boost::get_system_time() + boost::posix_time::seconds(10));

    std::cout << "I'm thread A !  --- OVER " << std::endl;

}


void helloB()
{
    std::cout << "I'm thread B !  --- Start " << std::endl;

    boost::thread::sleep(boost::get_system_time() + boost::posix_time::seconds(10));

    std::cout << "I'm thread B !  --- OVER " << std::endl;

}

int main(int argc, char* argv[])
{
    boost::thread thrdA(&helloA);
    boost::thread thrdB(&helloB);
    thrdA.join();
    thrdB.join();
    // join() ���������������̵ȴ����߳�ִ����Ϻ��ټ���ִ�С�
    // ����᲻������߳�ִ��״����ֱ���˳��ˡ�
    return 0;
}


/*���
I'm thread A !  --- Start
I'm thread B !  --- Start
I'm thread A !  --- OVER
I'm thread B !  --- OVER
*/