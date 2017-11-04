#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class GSC {
public:
	// 1. method 
	template <typename Dtype>
	int vectorUnique(vector<Dtype>& vec) {
		if (vec.empty()) {
			return 0;
		}
		int index = 0;
		for (int i = 1; i < vec.size(); i++) {
			if (vec[index] != vec[i]) {
				vec[++index] = vec[i];
			} 
		}
		//erase invalid items.
		vec.erase(vec.begin() + index + 1,vec.end());
		return index + 1;
	}

	// 2. STL method1
	template <typename Dtype>
	int vectorUnique1(vector<Dtype>& vec) {
		vector<Dtype>::iterator last = unique(vec.begin(), vec.end());
		//erase invalid items.
		vec.erase(vec.begin(),last);
		return vec.size();//distance(vec.begin(), vec.end());
	}

	// 3. STL method2
	template <typename Dtype>
	int vectorUnique2(vector<Dtype>& vec) {
		vector<Dtype>::iterator it = removeDuplicates(vec.begin(), vec.end(), vec.begin());
		vec.erase(it,vec.end());
		return vec.size();
	}
	template <typename InType, typename OutType>
	OutType removeDuplicates(InType first,InType last, OutType output){
		while (first != last) {
			*output++ = *first;
			first = upper_bound(first, last, *first);
		}
		return output;
	}

	// 4. compare 
	template <typename Dtype>
	bool compareItems(vector<Dtype>& vec) {
		if (vec.empty()) {
			return false;
		}
		/************************************************************************/
		/* ��ΪSTL�е�begin��end�������һ���뿪�����䡰[begin, end)����end�����һ��Ԫ�صĺ�һ��λ�á�
		/* �������������ô���1���ж��Ƿ�β����ֻҪ!=end�����ˣ�<������STL����Ҫ����ģ���Ϊ���������ܻ�Ƚϴ�
		/* 2���жϿ�����ܼ�begin()==end()Ҫȡ���һ��Ԫ�صĻ���last()������      */
		/************************************************************************/
		return *(vec.end() - 1) > *(vec.begin());
	}
};

int main_exp2(int argc, char** argv) {
	GSC gsc_test;
	vector<int> vec_test = { 1,1,1,2,2,3};
	int len = gsc_test.vectorUnique2(vec_test);
	cout << "len:"<< len << endl;
	for_each(vec_test.begin(), vec_test.end(), [](int n) {cout << n << " "; });
	cout << endl;

	//compare test
	bool ret = gsc_test.compareItems(vec_test);
	cout << "compare:"<< ret << endl;
	system("pause");
	return 0;
}


