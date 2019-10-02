#include "samayGUI.h"
void myEvent();
void main()
{
	Controller c;
	
	Frame *f=new Frame(10,2,38,80);
	c.registerComp(f);

	Label *l=new Label(13,6,12,3,"Name");
	c.registerComp(l);
	TextBox *t=new TextBox(30,6,15,3);
	c.registerComp(t);

	Label *l1=new Label(13,12,12,3,"PWord");
	c.registerComp(l1);
	TextBox *t1=new TextBox(30,12,15,3);
	c.registerComp(t1);

	ComboBox *c1=new ComboBox(13,18,3);
	c.registerComp(c1);
	ListBox *lb =new ListBox(50,18,3,true);
	c.registerComp(lb);

	CheckBox *cb =new CheckBox(13,30,"Save");
	c.registerComp(cb);
	
	Button *b1 =new Button(13,35,12,3,"Submit");
	c.registerComp(b1);
	Button *b2 =new Button(30,35,12,3,"Reset");
	c.registerComp(b2);
	b1->triggerEvent= &myEvent;
	b2->triggerEvent= &myEvent;
	c.start();
	endwin();
}
void myEvent(){
		
}
