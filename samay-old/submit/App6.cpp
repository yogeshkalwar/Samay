#include "samayGUI.h"
#include "iostream.h"
void event();
void main()
{
	Controller c;

	//Frame *f=new Frame(4,7,2,5);
	//c.registerComp(f);

	Button *b=new Button(5,6,6,6,"OK");
	c.registerComp(b);
	
	//Button *e=new Button(5,9,6,6,"CANCEL");
	//c.registerComp(e);
	//f->add(b);

	b->triggerEvent=&event;
	//e->triggerEvent=&event;
	c.start();
	endwin();
}

void event()
{
	cout<<"Amar";
}
	
	
