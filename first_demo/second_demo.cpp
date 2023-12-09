/*
* win10+vs2019配置boost库（超详细教程）
* https://blog.csdn.net/qq_42598221/article/details/121890273
*
* Test a boost demo
*
*/

#include <boost/thread/thread.hpp>
#include <boost/function/function0.hpp>
#include <iostream>

//#pragma comment(lib, "libboost_thread-vc142-mt-gd-x64-1_70.lib")
//#pragma comment(lib, "libboost_date_time-vc142-mt-gd-x64-1_70.lib")

class boostTest
{
private:
    boost::thread* thread_;
    bool running;
public:
    boostTest()
    {
        std::cout << "Hello world, I''m a thread!" << std::endl;
        running = true;
    }

    ~boostTest()
    {
        std::cout << "Destroy the object!" << std::endl;
        thread_->join();
    }

    void startThread()
    {
        thread_ = new boost::thread(boost::bind(&boostTest::sayHello, this));
        std::cout << " Thread " << thread_->get_id() << " is started! " << std::endl;
    }

    void stopThread()
    {
        running = false;
    }

    void sayHello()
    {
        int counter = 1;
        std::cout << " Hello world! " << std::endl;
        while (running)
        {
            std::cout << " Trapped in the loop! Time:" << counter++ << std::endl;
            Sleep(1000);
        }
    }

};

int main(int argc, char* argv[])
{
    boostTest* test = new boostTest();
    test->startThread();
    Sleep(2500);
    test->stopThread();
    delete test;
    return 0;
}
