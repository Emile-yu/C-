#include<iostream>
#include<stdio.h>
#include"Chanson.h"
#include"Artiste.h"
#include"Langues.h"
#include"Concert.h"
using namespace std;

struct People
{
	string name;
	int age;
	bool operator <(const People p) const  //运算符重载 
	{
		return age<p.age;       //按照年龄由小到大进行排序 
	}
	friend ostream& operator<<(ostream& out, const People &p)
	{
		out<<"People["<<p.name<<";"<<p.age<<"]";
		return out;
	}
}; 
int main()
{
	cout<<Langues::Fr<<endl;
	//cout<<&Langues::init(langues)<<endl;
	Artiste *a1=new Artiste("Michael",Langues::Fr);
	Artiste *a2=new Artiste("Joe",Langues::Ang);
	Artiste *a4 = a2;
	cout<<*a4<<endl;
	//Artiste *a3=new Artiste("Peter");
	//Artiste *a4=new Artiste("Claire");
	Chanson *c1=new Chanson("Sky",29,Langues::Ch);
	Chanson *c2=new Chanson("Blue",30,Langues::Ch);
	//Chanson *c3=new Chanson("Sea",31);
	
	cout<<endl;
	cout<<endl;
	cout<<endl;
	(*c1).addArtiste(a1);
	(*c2).addArtiste(a2);
	//(*c3).addArtiste(a4);

	cout<<*c1<<endl;
	Concert *c=new Concert("Jay Zhou","66.6");
	(*c).addChanson(c1);
	(*c).addChanson(c2);
	cout<<(*c).getDuree()<<endl;
	cout<<*c<<endl;
	(*c).afficher();

	Artiste a3("Joe",Langues::Ang);
	set<Artiste> ar;
	ar.insert(a3);
	set<Artiste>::iterator it0;
	it0=ar.begin();
	cout<<*it0<<endl;
	
	set<People*>s;
	People *p1=new People{"张三",14}; 
	s.insert(p1); 
	//s.insert(&((People){"李四",16})); 
	//s.insert(&((People){"王二麻子",10})); 
	set<People*>::iterator it; 
	for(it=s.begin();it!=s.end();it++) //使用迭代器进行遍历 { printf("姓名：%s 年龄：%d\n",(*it).name.c_str(),(*it).age); }
	cout<<*it<<endl;

	return 1;
}
