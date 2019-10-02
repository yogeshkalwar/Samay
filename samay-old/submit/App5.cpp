#include "samayGUI.h"
#include "iostream.h"
void main()
{
	Controller c;
	ListBox *lb1 = new ListBox(4,true);
	c.registerComp(lb1);
	ListBox *lb2 = new ListBox(5,false);
	c.registerComp(lb2);
	//sleep(1);
	/*lb2->addItem("NCST",2);
	lb1->addItem("JUHU",1);
	lb1->setBorder(5);
	lb1->setBg(4);*/
//	lb2->clear();
	//c.registerComp(lb2);

	c.start();
	endwin();
}

