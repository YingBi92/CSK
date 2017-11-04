#include <iostream>    
#include <vector>      
#include <iomanip>     
#include <algorithm>   
#include <memory>      
#include <tuple>       
using namespace std;   

/*
* 1. ��templateʵ��һ��vector������Ԫ��+1,�����
* 2. ʹ��lambda���ʽ��� [capture clause](parameters){body}
* 3. auto: automatically deduced from its initializer
* 4. for_each();
* 5. decltype()
* 6. unique_ptr, shared_ptr and make_shared
*	 a. shared_ptr:������ָ��ָ��ͬһ������
*    b. unique_ptr: ��ռ��ָ��Ķ���(simply holds a pointer, and ensures that the pointer is deleted on destruction. 
*				unique_ptr objects cannot be copied).
*    c. make_shared: ����һ��shared_ptr�Ķ���
*    d. make_unique: ����һ��unique_ptr
* 7. std::tuple: Ԫ��
* 8. std::pair: Pair��һ������ģ�壬���а�����������ֵ���������ݵ����Ϳ��Բ�ͬ
*/
struct Sum{
	Sum(): sum{ 0 } { }
	Sum(float a):sum { a } { }
	void operator()(float n) { sum += n; }
	float sum;
};

template <typename Dtype>
Dtype sumVec(vector<Dtype>& vec_input) {
	// 1. template , 2. lambda
	std::for_each(vec_input.begin(), vec_input.end(), [](Dtype &n) { n++; });
	// 4. for_each
	Sum s = for_each(vec_input.begin(), vec_input.end(), Sum());
	return s.sum;
}

// 5. decltype
template<class T, class U>
auto add(T t, U u) -> decltype(t + u) // the return type is the type of operator+(T, U)
{
	return t + u;
}

auto get_fun(int arg) -> double(*)(double) // same as: double (*get_fun(int))(double)
{
	switch (arg)
	{
	case 1: return std::fabs;
	case 2: return std::sin;
	default: return std::cos;
	}
}


int main_c14(int argc, char** argv) {
	vector<float> vec_exp = { 1.0f,2.0f,3.0f,4.2f,4.2f};
	// 3. auto
	auto sum = sumVec(vec_exp);
	std::cout <<std::setprecision(4)<< "1. sum of vector:" << sum << std::endl;

	auto a = 1 + 2;
	auto b = a + 1.2;
	auto c = add(1,1.2);
	std::cout << std::setprecision(4) << "2. c=" << c << std::endl;
	std::cout << std::setprecision(4) << "3. get_fun=" << get_fun(1)(-3) << std::endl;

	//6. unique_ptr and make_unique
	unique_ptr<Sum> ptr1(new Sum(1));
	unique_ptr<Sum> ptr2(new Sum(2));
	auto p11 = make_unique<Sum>(11);
	//unique_ptr<Sum> ptr22 = p11;    //error, p11��ʱ�Ѿ�����
	ptr1.reset(new Sum(11));

	//6. make_shared����һ��shared_ptr
	auto ptr5 = make_shared<Sum>(3);
	shared_ptr<Sum> ptr6 = ptr5;		
	auto result = ptr6->sum;
	std::cout << std::setprecision(4) << "3. result=" << result << std::endl;

	//7. std::tuple, std::make_tuple Ԫ��
	auto tuple_test = std::make_tuple(3.8, 'A', "Lisa Simpson");
	std::cout << "4. GPA:" << std::get<0>(tuple_test) << ",grade:"  \
		<< std::get<1>(tuple_test) << ",name:" << std::get<2>(tuple_test) << std::endl;

	//8. std::pair, std::make_pair
	auto pair_test = std::make_pair("OK sample", 0);
	std::cout << "5.first:" << pair_test.first << ",second:" << pair_test.second << std::endl;
	system("pause");
	return 0;
}