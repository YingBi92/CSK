#include <iostream>
#include <utility>
#include <string>
#include <map>
#include <unordered_map>
#include <list>
#include <forward_list>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <array>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int main_data_structure(int argc, char** argv) {
	//1. arrayΪc++�ڽ�(build-in)����,array�Ǿ�̬�ռ䣬һ�������˾Ͳ��ܸı䣻Ҫ�����󣨻�С�� 
	array<int, 1> array_test;
	array_test.fill(3);
	array_test.fill(4);
	//int array_test[1];
	cout << "array:" << sizeof(array_test) << endl; // 4 bytes

	/************************************************************************/
	/*	2. vector�ײ����ݽṹΪ��̬����,֧�ֿ����������,dynamic array, resizable array.
		ע�⣬��ν��̬���Ӵ�С����������ԭ�ռ�֮������¿ռ䣨��Ϊ�޷���֤ԭ��
		��֮�����пɹ����õĿռ䣩��������ԭ��С��������������һ��ϴ�ռ䣬Ȼ
		��ԭ���ݿ���������Ȼ��ſ�ʼ��ԭ����֮�󽨹���Ԫ�أ����ͷ�ԭ�ռ䡣��
		�ˣ���vector���κβ�����һ������ռ��������ã�ָ��ԭvector�����е�
		�����Ͷ�ʧЧ�ˡ����ǳ���Ա�׷���һ����������С�ġ�                     */
	/************************************************************************/
	vector<int> vec_test;
	cout << "vector:" << sizeof(vec_test) << endl; // 12 bytes(32bits), 24 bytes(64bits) T* pb, T* pe, T* pc;

	/************************************************************************/
	/*3. list �ײ����ݽṹΪ˫������(double linked-list),֧�ֿ�����ɾ      */
	/************************************************************************/
	list<int> list_test;
	cout << "list:" << sizeof(list_test) << endl;

	//4. forward_list �ײ����ݽṹΪ������
	forward_list<int> forward_list_test;
	cout << "forward_list:" << sizeof(forward_list_test) << endl;

	//5. deque  vector�ǵ��򿪿ڵ��������Կռ䣬deque����һ��˫�򿪿ڵ��������Կռ䡣 
	// �ײ����ݽṹΪһ������������Ͷ������������ϸ��STLԴ������P146��֧����β���м䲻�ܣ�������ɾ��Ҳ֧���������
	//  deque��һ��˫�˶���(double - ended queue)��Ҳ���ڶ��б������ݵ�.���ı�����ʽ����:
	//  [��1] -- > [��2] -- > [��3] -- > ...
	//	ÿ���ѱ���ü���Ԫ��, Ȼ��ѺͶ�֮����ָ��ָ��, ����������list��vector�Ľ��Ʒ.
	deque<int> deque_test;
	cout << "deque:" << sizeof(deque_test) << endl;

	//6. stack,�ײ�һ����list��dequeʵ�֣����ͷ�����ɣ�����vector��ԭ��Ӧ����������С�����ƣ����ݺ�ʱ
	stack<int> stack_test;
	cout << "stack:" << sizeof(stack_test) << endl;

	/************************************************************************/
	/*7. queue �ײ�һ����list��dequeʵ�֣����ͷ�����ɣ�����vector��ԭ��Ӧ����������С�����ƣ����ݺ�ʱ
  	  (stack��queue��ʵ��������,��������������Ϊ�Ƕ��������ٷ�װ��                */                                                         
	/************************************************************************/
	queue<int> queue_test;
	cout << "queue:" << sizeof(queue_test) << endl;

	/************************************************************************/
	/* 8. priority_queue�ĵײ����ݽṹ��heap, heap����������STL������������Ǹ�Ļ��Ӣ�ۣ�����priority queue������                                                                  
		binary max heap(complete binary tree) */
	/************************************************************************/
	priority_queue<int> pri_queue_test;
	cout << "priority_queue:" << sizeof(pri_queue_test) << endl;

	/************************************************************************/
	/* 9.  �ײ����ݽṹΪ����������򣬲��ظ�                                  */
	/************************************************************************/
	set<int> set_test;
	cout << "set:" << sizeof(set_test) << endl;

	/************************************************************************/
	/* 10.  �ײ����ݽṹΪ����������򣬿��ظ�                                  */
	/************************************************************************/
	multiset<int> multiset_test;
	cout << "multiset:" << sizeof(multiset_test) << endl;

	/************************************************************************/
	/* 11.�ײ����ݽṹΪ����������򣬲��ظ�                                   */
	/************************************************************************/
	map<int, int> map_test;
	cout << "map:" << sizeof(map_test) << endl;

	/************************************************************************/
	/* 12. �ײ����ݽṹΪ����������򣬿��ظ�                                   */
	/************************************************************************/
	multimap<int, int> multimap_test;
	cout << "multimap:" << sizeof(multimap_test) << endl;

	/************************************************************************/
	/* 13. unordered_set �ײ����ݽṹΪhashtable,����,���ظ�                  */
	/************************************************************************/
	unordered_set<int> unordered_set_test;
	cout << "unordered_set:" << sizeof(unordered_set_test) << endl;

	/************************************************************************/
	/* 14. unordered_multiset  �ײ����ݽṹΪhashtable,����,�ظ�              */
	/************************************************************************/
	unordered_multiset<int> unordered_multiset_test;
	cout << "unordered_multiset_test:" << sizeof(unordered_multiset_test) << endl;

	/************************************************************************/
	/* 15. unordered_map�ײ����ݽṹΪhashtable,���򣬲��ظ�                   */
	/************************************************************************/
	unordered_map<int, int> hash_test;
	cout << "unordered_map:" << sizeof(hash_test) << endl;

	/************************************************************************/
	/* 16. unordered_multimap   �ײ����ݽṹΪhashtable,�����ظ�             */
	/************************************************************************/
	unordered_multimap<int, int> unordered_multimap_test;
	cout << "unordered_multimap_test:" << sizeof(unordered_multimap_test) << endl;

	system("pause");
	return 0;
}


/************************************************************************/
/*Output:
array:4
vector:32
list:24
forward_list:16
deque:40
stack:40
queue:40
priority_queue:40
set:24
multiset:24
map:24
multimap:24
unordered_set:80
unordered_multiset_test:80
unordered_map:80
unordered_multimap_test:80
*/
/************************************************************************/