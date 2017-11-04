# Sundy
## C++学习总结week05

### 一 试题分析 
 1 C++中引用变量不能引用字面常量，但是常量引用可以引用字面常量。

	例如:(1)void fun(int &n){}         (2) void fun(const int &n){}
	        a.fun(10)//error               a.fun(10);   //ok

 2 C++中解决命名冲突的机制是:命名空间(namespace)(相当于java中的包packet)。

	例如：#include <iostream>
	using namespace std;

	namespace one{
		int i = 100;
		int inf  = -10;
	}
	
	namespace two{
		const int i = 200;
		int inf  = -20;
	}
	
	using namespace one;
	//using namespace two;
	int main(){
		i += 10;
		cout<<"i="<<i<<endl;
		cout<<"inf = "<<inf<<endl;
		cout<<"i="<<two::i<<endl;
		cout<<"inf="<<two::inf<<endl;
		return 0;
	}

 3 初始化(init) VS 赋值(assigment)：

	初始化:int a = 3;          A a1 = 5;
	赋值：int i;		      A a2;
	   i = 4;		      a2 = a1;

 4 常对象和常对象的引用只能调用常函数，普通对象既能调用常函数，也能调用普通函数。

 5 友员类中的所有成员函数都可以访问类的私有成员。

 6 内部类(嵌套类):定义在一个类里面的类

	(1) 成员内部类
	(2) 局部内部类
！！！内部类当作外部类的静态成员类型看待，同样受访问修饰符的限制。
所以在类外部创建内部类的对象时，应该用域作用符调用内部类方可，不可用对象调用。因为内部类为static类型。

例如:

	#include <iostream>
	using namespace std;
	
	/*void fn(){
		A a2;   //error
		a.show();
	}*/
	
	class B{public:
		void show(){
			cout<<"this is B"<<endl;
		}};
	
	class C{
	static int i;
	public:
		 class B{  //成员内部类
			public:
			void show(){
				cout<<"this is C::B"<<",i="<<i<<endl;
				C c;
				cout<<c.i<<endl;
			}}; //内部类当作外部类的静态成员类型看待，同样受访问修饰符的限制。
	};
	int C::i = 3;
	
	class D{public:class B{
		public:
		void show(){
			cout<<"this is D::B"<<endl;
		}};
	};
	
	int main(){
		class A{    //局部内部类
		public:
			void show(){
				cout<<"this is A"<<endl;
			}
		};
		A a1;
		a1.show();
		B b;
		b.show();
		C::B b2;
		b2.show();
		D::B b3;
		b3.show();
		return 0;
	}

7  若静态成员函数中调用了一个函数f,则该函数一定不是虚函数。

分析: 只有对象才可以拜访虚函数，因为虚函数地址全部存放在V TABLE中，而V TABLE的指针是对象的一个成员，所以要访问虚函数就一定要有对象
而静态函数中没有对象。
  static成员一定属于类的，virtual一定属于对象的，属于类的东西一定不能访问属于对象的。

8 构造函数的函数体中，不能使用return语句；但在实现该类的自动类型转化函数时，必须有return 语句。

强制类型转换运算符的重载
	class E{
		char n;
	public:
		E(int n=0):n(n){}
		operator int(){   //强制类型转换运算符的重载
			return n+100;
		}
	
		operator char(){  //更通用
				return 'A';
			}
	};
	
	int main(){
		E e;
		int i = (char)e; //type(data) (type)data
		cout<<"i="<<i<<endl;
		return 0;
	}

9 异常(try{throw xx}catch{})
	#include <iostream>
	using namespace std;
	
	class MyException{
		int errcode;
		string errormsg;
	public:
		MyException(int code,string msg):errcode(code),errormsg(msg){
			cout<<"cons"<<endl;
		}
	
		~MyException(){
			cout<<"des"<<endl;
		}
		void what() const{
			cout<<"错误码:"<<errcode<<",错误信息:"<<errormsg<<endl;
		}
	};
	
	int main(){
		try{
		int a = 3,b = 0;
		if(b==0){
			//throw "250,除数被0除了!";
			throw MyException(250,"除数被0除了!");
		}
		int c=a/b;
		cout<<"c="<<c<<endl;
		}catch(const MyException& e){
			e.what();
		}catch(const char* e){
			cout<<"exception:"<<e<<endl;
		}catch(const int& e){ //根据抛出的类型进行捕获，如果没有匹配的就用...
			cout<<"exception:"<<e<<endl;
		}catch(...){ //...代表什么样的异常都可以捕捉到
			cout<<"other exception"<<endl;
		}
	
		cout<<"come here?"<<endl;
		return 0;
	}

 10 多重继承

- 菱形结构：会引发很多问题。

- 虚继承会解决上述问题。合并父类成员的。

		#include <iostream>
		using namespace std;
		
		class J{        //虚基类
		public:
			void f1(){cout<<"f1"<<endl;}
		};
		
		class M:virtual public J{  //利用虚继承解决
		
		};
		
		class N:virtual public J{
		
		};
		
		class O:public M,public N{
		
		};
		
		int main(){
			O o;
			o.f1();
			return 0;
		}
		
		
11 多态的时候，父类指针不能访问子类中独有的成员。

		#include <iostream>
		using namespace std;
		
		class A1{
		public:
			virtual ~A1(){}
			virtual void f(){
				cout<<"A1::f()"<<endl;
			}
		
			virtual void g(){
				cout<<"A1::g()"<<endl;
			}
		};
		
		class B1:public A1{
		public:
			virtual void g(){
				cout<<"B1::g()"<<endl;
			}
		
			virtual void k(){
				cout<<"B1::k()"<<endl;
			}
		};
		
		int main(){
			A1* a = new B1;
			a->f();
			a->g();
			//a->k(); //error  父类指针不能访问子类中独有的成员
			return 0;
		}

  
 12 ostream 和istream是标准输入输出流、文件流、字符串流的基类

 13 若静态成员函数中调用了一个函数f，那么f 一定不是虚函数。
对，静态成员函数不能是虚函数，因为虚函数入口需要在保存在对象中的虚函数表中，而静态成员函数不属于对象。

 14 调用子类构造函数之前一定会调用父类对应的构造函数，同理调用子类拷贝构造函数之前，也会调用父类的构造函数。

###作业:

1 关于虚表的资料

2 关于多态的资料











  