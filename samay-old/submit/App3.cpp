#include "samayGUI.h"
#include "iostream.h"
void main()
{
	
	Controller c;

	Frame *f=new Frame(4,1,20,30);
        c.registerComp(f);
	
	TextBox *l=new TextBox(6,8,8,12);
	c.registerComp(l);
	TextBox *l1=new TextBox(18,14,15,5);
	c.registerComp(l1);

	l->setBorder(4);	
	l1->setColor(5);

	f->add(l);	
	f->add(l1);	
	c.start();
	endwin();
}
