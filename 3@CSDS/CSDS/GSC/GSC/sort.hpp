#include <limits>
#include <iostream>
using namespace std;

namespace sort {

	template <typename Dtype>
	class Solution {
	public:
		explicit Solution() {};
		virtual ~Solution() {};

		// 1. Comparison based sorting algorithm
		// ��������
		int insertionSort(Dtype A[], int N);              // ֱ�Ӳ�������
		int shellSort(Dtype A[], int N);                  // ϣ������

		// ��������
		int bubbleSort(Dtype A[], int N);                 // ð������
		int quickSort(Dtype A[], int low, int high);      // ��������

		// ѡ������
		int selectionSort(Dtype A[], int N);              // ֱ��ѡ������
		void heapBuild(Dtype a[], int root, int length);
		int heapSort(Dtype a[], int N);                     // ������

		//�鲢����
		int merge(Dtype A[], int p, int q, int r);
		int mergeSort(Dtype A[], int p, int r);

		//2. Non-comparison sorting algorithm
		int radixSort(Dtype A[], int N);
		int countingSort(Dtype A[], int N);
		int bucketSort(Dtype A[], int N);

	public:
		int inf = std::numeric_limits<int>::max();
	};


	//������������  
	template <typename Dtype>
	void swaptwo(Dtype *a, Dtype *b) {
		Dtype temp = *a;
		*a = *b;
		*b = temp;
	}

	/*
	* 1. ��������(insertion sort)
	*/
	template <typename Dtype>
	int Solution<Dtype>::insertionSort(Dtype A[], int N) {
		if (N == 0) {
			return 0;
		}

		for (int j = 1; j < N; j++) {
			int key = A[j];
			int i = j - 1;
			while (i >= 0 && A[i] > key) {
				A[i + 1] = A[i];
				i--;
			}
			A[i + 1] = key;
		}
		return 1;
	}

	/*
	* 2. ϣ������(shell sort)
	*/
	template <typename Dtype>
	int Solution<Dtype>::shellSort(Dtype A[], int N) {
		if (N == 0) {
			return 0;
		}

		Dtype temp = 0;
		for (int gap = N / 2; gap >= 1; gap = gap / 2) {
			for (int i = gap; i < N; i++) {
				for (int j = i; j >= gap && A[j] < A[j - gap]; j -= gap) {
					temp = A[j];
					A[j] = A[j - gap];
					A[j - gap] = temp;
				}
			}
		}

		return 1;
	}

	/*
	* 3. ð������(Bubble Sort)
	*/
	template <typename Dtype>
	int Solution<Dtype>::bubbleSort(Dtype A[], int N) {
		if (N == 0) {
			return 0;
		}
		Dtype temp = 0;
		for (int i = N - 1; i > 0; --i) {
			bool exchange = false;
			for (int j = 0; j < i; j++) {
				if (A[j + 1] < A[j]) {
					exchange = true;
					temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;
				}
			}
			if (!exchange) {
				return 1;
			}
		}
		return 1;
	}

	/*
	* 4. quickSort(��������)
	*/
	/* This function takes last element as pivot, places
	the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
	to left of pivot and all greater elements to right
	of pivot */
	template <typename Dtype>
	int partition(Dtype arr[], int low, int high) {
		Dtype pivot = arr[high];    // pivot
		int i = (low - 1);  // Index of smaller element

		for (int j = low; j <= high - 1; j++) {
			// If current element is smaller than or
			// equal to pivot
			if (arr[j] <= pivot) {
				i++;    // increment index of smaller element
				swaptwo(&arr[i], &arr[j]);
			}
		}
		swaptwo(&arr[i + 1], &arr[high]);
		return (i + 1);
	}

	/* The main function that implements QuickSort
	arr[] --> Array to be sorted,
	low  --> Starting index,
	high  --> Ending index */
	template <typename Dtype>
	int Solution<Dtype>::quickSort(Dtype arr[], int low, int high) {
		if (low < high) {
			/* pi is partitioning index, arr[p] is now
			at right place */
			Dtype pi = partition(arr, low, high);

			// Separately sort elements before
			// partition and after partition
			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
		else {
			return 0;
		}
		return 1;
	}

	/* Function to print an array */
	void printArray(int arr[], int size)
	{
		int i;
		for (i = 0; i < size; i++)
			cout<<arr[i];
		cout << endl;
	}

	/*
	* 5. selectionSort(ѡ������)
	*/
	template <typename Dtype>
	int Solution<Dtype>::selectionSort(Dtype A[], int N) {
		if (N == 0) {
			return 0;
		}
		Dtype temp = 0;
		int min = 0;
		for (int i = 0; i < N - 1; i++) {
			min = i;
			for (int j = i + 1; j < N; j++) {
				if (A[j] < A[min]) {
					min = j;
				}
			}
			temp = A[i];
			A[i] = A[min];
			A[min] = temp;
		}
		return 1;
	}

	/*
	*  6. �����򣨴���ѣ�С���ѣ���Ҫ�ڽ��ѡ�  ʵ�ֵ����ݽṹ��priority_queue��
	*/
	//������ĺ����ǽ���,�������Ϊ���飬���ڵ�λ�ã����鳤��  
	template <typename Dtype>
	void Solution<Dtype>::heapBuild(Dtype a[], int root, int length) {
		int lchild = root * 2 + 1;   //���ڵ�����ӽ���±�  
		if (lchild < length) {        //���ӽ���±겻�ܳ�������ĳ���  
			int flag = lchild;       //flag�������ҽڵ������ֵ���±�  
			int rchild = lchild + 1; //���ڵ�����ӽ���±�  
			if (rchild < length) {   //���ӽ���±겻�ܳ�������ĳ���(����еĻ�) 
				if (a[rchild] > a[flag]) {//�ҳ������ӽ���е����ֵ  
					flag = rchild;
				}
			}
			if (a[root] < a[flag]) {
				//���������ͱȸ����������ӽڵ�  
				swaptwo(&a[root], &a[flag]);
				//�Ӵ˴�����ӽڵ���Ǹ�λ�ÿ�ʼ�ݹ齨��  
				heapBuild(a, flag, length);
			}
		}
	}

	template <typename Dtype>
	int Solution<Dtype>::heapSort(Dtype a[], int N) {
		for (int i = N / 2; i >= 0; --i) { //�����һ����Ҷ�ӽڵ�ĸ���㿪ʼ���� 
			heapBuild(a, i, N);
		}

		for (int j = N - 1; j > 0; --j) { //j��ʾ�����ʱ�ĳ��ȣ���Ϊlen�����Ѿ������ˣ���len-1��ʼ  
			swaptwo(&a[0], &a[j]);         //������βԪ��,�����ֵ��������������λ�ñ���  
			heapBuild(a, 0, j);          //ȥ�����λ�õ�Ԫ�����½��ѣ��˴�j��ʾ����ĳ��ȣ����һ��λ���±��Ϊlen-2  
		}
		return 1;
	}

	/*
	* 7. �鲢����(merge sort)
	*/
	template <typename Dtype>
	int Solution<Dtype>::merge(Dtype A[], int left, int mid, int right) {
		int n1 = mid - left + 1;
		int n2 = right - mid;
		int i = 0, j = 0, k = 0;

		int* L = new int[n1 + 1];
		int* R = new int[n2 + 1];
		for (i = 0; i < n1; i++) {
			L[i] = A[left + i];
		}

		for (j = 0; j < n2; j++) {
			R[j] = A[mid + j + 1];
		}

		L[n1] = inf;
		R[n2] = inf;

		i = 0, j = 0;
		for (k = left; k <= right; k++) {
			if (L[i] <= R[j]) {
				A[k] = L[i++];
			}
			else {
				A[k] = R[j++];
			}
		}
		delete[] L;
		delete[] R;
		return 1;
	}

	template <typename Dtype>
	int Solution<Dtype>::mergeSort(Dtype A[], int left, int right) {
		if (left < right) {
			int mid = (left + right) / 2;  //�м�����
			mergeSort(A, left, mid);       //����߽�������
			mergeSort(A, mid + 1, right);   //���ұ߽�������
			merge(A, left, mid, right);    //�鲢2����������
			return 1;
		}
		return 0;
	}


	/*
	* 8. radixSort(������)
	*/
	template <typename Dtype>
	int Solution<Dtype>::radixSort(Dtype A[], int N) {
		return 1;
	}

	
	/*
	* 9. countingSort(��������)
	*/
	template <typename Dtype>
	int Solution<Dtype>::countingSort(Dtype A[], int N) {
		return 1;
	}

	/*
	* 10.bucketSort(Ͱ����)
	*/
	template <typename Dtype>
	int Solution<Dtype>::bucketSort(Dtype A[], int N) {
		return 1;
	}

}