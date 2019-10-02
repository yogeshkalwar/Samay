#include "samayGUI.h"
#include "iostream.h"
void myEvent();
void main()
{
	Controller c;
	ComboBox *l=new ComboBox(2,4,6);
	c.registerComp(l);
/*	Button *b=new Button();
	c.registerComp(b);
	Button *b1=new Button();
	c.registerComp(b1);
	b->triggerEvent=&myEvent;
*/
	c.start();
	endwin();

}
/*
	void myEvent()
	{
		cout<<"Amar is learning Function pointer";
	}

*/
	
//	Label *l=new Label(6,8,8,12,"Mahe");
//	c.registerComp(l);
//	Label *l1=new Label(6,8,7,9,"Amar");
//	c.registerComp(l1);
//	Frame *f=new Frame();
//	c.registerComp(f);

//	TextArea *t=new TextArea();
//	c.registerComp(t);
/*	TextArea *t1=new TextArea(6,6);
	c.registerComp(t1);
	TextBox *t2=new TextBox(10,5);
	c.registerComp(t2);
	f->add(t2);

	TextBox *t2=new TextBox();
	c.registerComp(t2);
		 

	Frame *f = new Frame();
	c.registerComp(f);
	CheckBox *c2 = new CheckBox(1,1,"Amar");
	c.registerComp(c2);
	CheckBox *c1 = new CheckBox(1,1,"yogesh");
	c.registerComp(c1);

	c.start();
	endwin();
}
*/
