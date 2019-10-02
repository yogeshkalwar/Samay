#include "samayGUI.h"
#include "iostream.h"
void main()
{
	Controller c;
	Frame *f=new Frame();
	c.registerComp(f);
	
	Label *li=new Label();
	c.registerComp(li);

	f->add(li);
	c.start();
	endwin();
}	









/*	Event *e=new Event();
	Button *b=new Button();
	c.registerComp(b);
	b->addEvent(e);
	Button *b1=new Button(21,2);
	c.registerComp(b1);
	e->triggerEvent();
*/	
/*	ComboBox *lb1 = new ComboBox(8,5,4);
	c.registerComp(lb1);
	ComboBox *lb2 = new ComboBox(13,8,4);
	c.registerComp(lb2);*/
	//ComboBox *lb = new ComboBox(3,4,true);
	//c.registerComp(lb);
/*	ListBox *lb1 = new ListBox(8,5,3,false);
	c.registerComp(lb1);
*/


	//ComboBox *lb = new ComboBox(3,4,true);
	//c.registerComp(lb);
/*	ListBox *lb1 = new ListBox(8,5,3,false);
	c.registerComp(lb1);
*/

