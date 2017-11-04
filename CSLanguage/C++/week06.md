# Sundy
## C++学习总结week06
### 一 复习


-  1 友元函数和友元类
 一个全局函数要想访问一个类的私有成员，就必须将该方法声明为该类的友元函数。
 友元类....
 
-  2 运算符重载：本质就是编写运算符函数。自定义的对象。(VIP)
   (1) 默认的运算符不能满足我们的要求，这时就需要运算符重载。
   (2) 关键字: operator
   (3) 实现方式：成员方式  VS 友员方式  （优先使用成员方式）


-  3 三原则(rule of three):当写了析构和拷贝构造函数之后，一定要写重载赋值运算符。否则会出现浅拷贝的现象。

	（1）赋值是两个已有的对象之间进行数据的拷贝。

	（2）而拷贝构造函数是用已有的一个对象的数据逐字节的拷贝给另外一个，同时创建另外一个对象。

### 二 字符串
1 c语言表示字符串的方式

	  int ds[10] = {3};
	  cout<<(void *)ds<<endl; //输出ds的地址
	  
	  char ds[10] = {3};      
	  cout<<ds<<endl;         ////输出3  （特例）
	
	  char *ds = NULL;

  2 C++中加了:string类

	  string str1;
	  string str2("chen");
	  string str3('c',3);
	  string str4(str1);
	  str1.size();   str1.length();
	  str1 = str2;
	  str1+= str2;
	  cin>>str1;
	  getline(cin,str1,128);
	  cout<<str2;

  3 如何转换char buf[32]  到 string s;

	string s(buf);
  
  4 将string s; 转换到char buf[32];

	   s.c_str();   
	   strcpy(buf,s.c_str());

  "chen"  在C++中是const char* 类型
  
  5 string s;也支持s[i]的访问方式。

	    sizeof(s) = 4;
	    是因为string类中包含成员：char *p;  //4byte

### 三 C++中的空类，默认产生哪些类成员函数？
1 默认无参构造函数

2 析构函数

3 拷贝构造函数

4 赋值运算符(operator=)

5 取址运算符(operator&) (一个非const的和一个const的)

**思考**:

(1) 当一个类中定义了拷贝构造函数，那么默认的无参构造函数还在不在？ 不在

(2) 当自己定义了一个构造函数，那么默认的拷贝构造函数还在不在？   在

(3) 当我调用子类对象的拷贝构造函数之前，会调用父类的无参构造函数还是拷贝构造函数？  拷贝构造函数


### 四 编写门禁系统
  1 弄清对象之间的 继承 ，组合，依赖关系。

### 作业:
1 实现自己的string类，实现c_str();

2 完成 (三) 中的思考题
















