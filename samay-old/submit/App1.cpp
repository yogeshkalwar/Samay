#include "samayGUI.h"
#include "iostream.h"
void main()
{
	Controller c;
	
	Frame *f=new Frame(4,1,20,30);
	c.registerComp(f);
	
	Label *l=new Label(6,8,7,5,"NCST");
	c.registerComp(l);

	Label *l1=new Label(12,8,7,5,"CDAC");
	c.registerComp(l1);
	
	f->add(l);
	f->add(l1);
	
	sleep(2);

	l->setBorder(4);	
	sleep(2);
	l1->setColor(5);	
	sleep(2);
	l1->setText(l->getText());	
	sleep(2);
	l1->setAlign(1);	
	c.start();
	endwin();
}
