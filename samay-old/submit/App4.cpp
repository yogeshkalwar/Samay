#include "samayGUI.h"
#include "iostream.h"
void main()
{
	Controller c;
	CheckBox *c2 = new CheckBox(1,1,"Amar");
	c.registerComp(c2);
	CheckBox *c1 = new CheckBox(5,9,"yogesh");
	c.registerComp(c1);
//	c1->getFocus();
	c.start();
	endwin();
}
