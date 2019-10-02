#include "samayGUI.h"
void myEvent();
void main()
{
	Controller c;
	
	Frame *f=new Frame(10,2,38,80);
	c.registerComp(f);

	Button *l=new Button("Name");
	c.registerComp(l);
	i->triggerEvent=&myEvent;
	//Button *t=new TextBox(30,6,15,3);
	//c.registerComp(t);

	//Label *l1=new Label(13,12,12,3,"PWord");
	/*c.registerComp(l1);
	TextBox *t1=new TextBox(30,12,15,3);
	c.registerComp(t1);
*/
	//ComboBox *c1=new ComboBox(13,18,3);
	//c.registerComp(c1);
	//ListBox *lb =new ListBox(50,18,3,true);
	//c.registerComp(lb);

	c.start();
	endwin();
}
void myEvent(){
	wprintw(stdscr,"Amar");		
}
