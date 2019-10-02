#include "samayGUI.h"
#include "iostream.h"
void main()
{
	
	Controller c;

	Frame *f=new Frame(4,1,20,30);
        c.registerComp(f);
	
	TextArea *l=new TextArea(6,8,8,12);
	c.registerComp(l);
	TextArea *l1=new TextArea(18,14,15,5);
	c.registerComp(l1);
	l->setBorder(4);	
	l1->setColor(5);
	//f->add(l);	
	//f->add(l1);	
	//f->add(p);	
	c.start();
	endwin();
}
