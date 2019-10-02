
#include "Event.h"

int Event::setEvent(WINDOW* win, char inp)
{
	cEType=inp;
	keypad(win,true);
	c = wgetch(win);
	return 0;
}

char Event::getSource()
{
	return c;
}

int Event::triggerEvent()
{
	if(cEType=='B')
		printf("%s","Button event registered");
	return 0;
}


