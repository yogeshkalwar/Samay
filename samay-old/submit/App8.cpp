#include "samayGUI.h"
#include "iostream.h"
void main()
{
	Controller c;
	ListBox *t=new ListBox(2,9,5,true);
	c.registerComp(t);
	ListBox *t1=new ListBox(5,false);
	c.registerComp(t1);
	c.start();
	endwin();

}
