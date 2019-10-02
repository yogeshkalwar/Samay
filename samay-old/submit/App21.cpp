#include "samayGUI.h"
#include "iostream.h"
void main()
{
	Controller c;
	Label *l=new Label(6,2,12,4,"Name");
	c.registerComp(l);
	Label *l1=new Label(6,8,12,4,"Name");
	c.registerComp(l1);
	TextBox *t1=new TextBox(20,2,15,4);
	c.registerComp(t1);
	TextBox *t2=new TextBox(20,8,15,4);
	c.registerComp(t2);
	TextArea *ta=new TextArea(10,15,10,5);
	c.registerComp(ta);
	TextArea *ta2=new TextArea(35,15,10,5);
	c.registerComp(ta2);
	ComboBox *cb=new ComboBox(6,21,3);
	c.registerComp(cb);
	ListBox *lb=new ListBox(30,21,3,true);
	c.registerComp(lb);
	CheckBox* ch = new CheckBox(10,30,"Working");
	c.registerComp(ch);
	GroupCheckBox* gch = new GroupCheckBox(10,30,2);
	c.registerComp(gch);
/*	Button *b=new Button(10,30,10,3,"Submit");
	c.registerComp(b);
	Button *b1=new Button(25,30,10,3,"Reset");
	c.registerComp(b1);
*/
	c.start();
	endwin();

}
