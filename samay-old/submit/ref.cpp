#include "iostream.h"


class base
{
	public:
		int a;
		base(){
			cout<<"HI";
		}
		void print(){
			cout<<a;
		}
		void input(){
			cin>>a;
		}
};

class child:public base{
	private:
		base *c;
	public:
		child(){
			c=new base();
		}
		//base b;
		void process(){
			c->input();
			c->print();
		}
/*		~child(){
			free(c);
		}
*/
};

void main(){
	child *c=new child();
	c->process();
	c->process();
}

