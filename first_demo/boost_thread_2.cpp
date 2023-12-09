/*
* C++ 菜鸟之路 （四） boost::thread 多线程全解析
* https://blog.csdn.net/Fourier_Legend/article/details/82020686
*
*/

#include <boost/thread/thread.hpp> 
#include <boost/thread/mutex.hpp> //定义锁
#include <iostream> 

//#include <unistd.h>

/*
 * g++ thread.cpp -lboost_system -lboost_thread
*/

//boost::shared_mutex  read_write_mutex;
boost::mutex lock; //使用的锁

using namespace std;
int num = 100;
void helloA()
{
    std::cout << "I'm thread A ! " << boost::this_thread::get_id() << " --- Start " << std::endl;

    lock.lock(); // 锁住变量 num， 另一处调用将在此处运行完后再继续运行

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
    // 建立并执行两个线程

    boost::thread thrdA(&helloA);


    boost::thread thrdB(&helloB);


    thrdA.join(); // 等待子线程完成后再继续执行主进程;


    thrdB.join();


    // 等待两个 join 后才会继续执行
    cout << " ==== over ==== " << endl;

    return 0;
}

/*结果
I'm thread A ! 7f5792ddc700 --- Start
101
I'm thread B ! 7f57925db700 --- Start
I'm thread A !  --- OVER
102
I'm thread B !  --- OVER
 ==== over ====

数据 num 被锁住， 线程B中的 num 将不能修该。 所以线程A 执行完才能修改 num 的值， 才能执行线程B。
*/