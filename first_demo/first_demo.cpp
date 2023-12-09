/*
* Visual Studio 2022,  Boost 1.81.0, windows ����C++ boost�⣨����ϸ��
* https://blog.csdn.net/weixin_50964512/article/details/128499318
*
* windows��boost��İ�װ��ʹ�� - lylygoing - ����԰
* https://www.cnblogs.com/lylygoing/p/BoostDownload.html
*/


#include <cstdlib>

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#include <boost/timer.hpp>
#include <boost/progress.hpp>

#include <libs/date_time/src/gregorian/greg_names.hpp>
#include <libs/date_time/src/gregorian/greg_month.cpp>
#include <libs/date_time/src/gregorian/gregorian_types.cpp>

#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost;

int main()
{
	boost::timer t;

	boost::progress_display pd(100);

	for (int i = 0; i < 100; ++i) //������
	{
		++pd;
	}

	boost::gregorian::date dt(2009, 12, 8); //date_time ��
	assert(dt.year() == 2009);
	assert(dt.day() == 8);
	boost::gregorian::date::ymd_type ymd = dt.year_month_day();
	std::cout << "\n" << ymd.year << "/" << ymd.month << "/" << ymd.day << " the day is "
		<< dt.day_of_year() << " days of this year" << std::endl;

	std::cout << boost::gregorian::to_iso_extended_string(dt) << std::endl; //ת��Ϊ������ʽ
	std::cout << boost::gregorian::to_iso_string(dt) << std::endl;
	std::cout << boost::gregorian::to_simple_string(dt) << std::endl << std::endl;

	//�������������
	std::vector<int> test_vc(100);
	std::vector<int>::iterator beg_it = test_vc.begin();
	std::vector<int>::iterator end_it = test_vc.end();
	std::srand(std::time(NULL));

	std::for_each(beg_it, end_it, [](int& n) {n = rand(); });
	std::copy(beg_it, end_it, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl << std::endl;
	std::sort(beg_it, end_it, std::greater<int>());
	std::copy(beg_it, end_it, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl << std::endl;

	boost::posix_time::ptime pt(boost::gregorian::date(2005, 2, 6));

	std::cout << t.elapsed() << "s" << std::endl; //��������ʱ��

	system("pause");

	return 0;
}