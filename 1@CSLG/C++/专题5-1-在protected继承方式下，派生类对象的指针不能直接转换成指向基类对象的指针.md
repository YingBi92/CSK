#Sundy

1.在protected继承方式下，派生类对象的指针不能直接转换成指向基类对象的指针

###实例分析1:

	#include <iostream>
	using namespace std;
	
	class Father{
	public:
		void show(){
			cout<<"father"<<endl;
		}
	};
	
	class Child:public Father{
	
	};
	
	int main(){
		 //Child* p = new Father;//error子类指针不能指向父类对象
		 Child* pc = new Child;
		 pc->show();   //ok
	
		Father* pf = pc;
		pf->show();   //ok
		return 0;
	}

###分析：

 1 如果派生类以共有的方式继承基类，则可以用派生类的指针转换成指向基类对象的指针。
根据访问修饰分析。

 2 Child* p = new Father;//error子类指针不能指向父类对象
因为子类对象的内存空间比父类大，如果子类指针可以指向父类对象的话，那么在delete的时候，就会delete掉额外的内存空间，造成错误。

###实例分析2:

	#include <iostream>
	using namespace std;
	
	class Father{
	public:
		void show(){
			cout<<"father"<<endl;
		}
	};
	
	class Child:protected Father{
	
	};
	
	int main(){
		 //Child* p = new Father;//error
		 Child* pc = new Child;
		 pc->show();   //error
	
		Father* pf = pc;
		pf->show();   //error
		return 0;
	}

 2 如果派生类以protected的方式继承基类，则不可以用派生类的指针转换成指向基类对象的指针。

	因为protected的方式继承，父类中public成员在子类中变为protected，在类外部是不能访问的。

	如果可以指向基类对象的话，外部中的pf就可以访问父类中的public方法，违背上述，所以不能这样。
