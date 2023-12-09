/*
* C++ ����֮· ���ģ� boost::thread ���߳�ȫ����
* https://blog.csdn.net/Fourier_Legend/article/details/82020686
*
*/

#include <boost/thread/thread.hpp> 
#include <boost/thread/mutex.hpp> //������
#include <iostream> 

//#include <unistd.h>

/*
 * g++ thread.cpp -lboost_system -lboost_thread
*/

//boost::shared_mutex  read_write_mutex;
boost::mutex lock; //ʹ�õ���

using namespace std;
int num = 100;
void helloA()
{
    std::cout << "I'm thread A ! " << boost::this_thread::get_id() << " --- Start " << std::endl;

    lock.lock(); // ��ס���� num�� ��һ�����ý��ڴ˴���������ټ�������

    num++;

    std::cout << num << std::endl;

    boost::thread::sleep(boost::get_system_time() + boost::posix_time::seconds(3));

    lock.unlock();

    std::cout << "I'm thread A !  --- OVER " << std::endl;

}


void helloB()
{
    std::cout << "I'm thread B ! " << boost::this_thread::get_id() << " --- Start " << std::endl;

    lock.lock();

    num++;

    std::cout << num << std::endl;

    boost::thread::sleep(boost::get_system_time() + boost::posix_time::seconds(3));

    lock.unlock();

    std::cout << "I'm thread B !  --- OVER " << std::endl;

}

int main(int argc, char* argv[])
{
    // ������ִ�������߳�

    boost::thread thrdA(&helloA);


    boost::thread thrdB(&helloB);


    thrdA.join(); // �ȴ����߳���ɺ��ټ���ִ��������;


    thrdB.join();


    // �ȴ����� join ��Ż����ִ��
    cout << " ==== over ==== " << endl;

    return 0;
}

/*���
I'm thread A ! 7f5792ddc700 --- Start
101
I'm thread B ! 7f57925db700 --- Start
I'm thread A !  --- OVER
102
I'm thread B !  --- OVER
 ==== over ====

���� num ����ס�� �߳�B�е� num �������޸á� �����߳�A ִ��������޸� num ��ֵ�� ����ִ���߳�B��
*/