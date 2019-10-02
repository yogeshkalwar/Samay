#include <curses.h>
#include <unistd.h>
class Event {
        private:
                char cEType;
		WINDOW* win;
		char c;
        public:
                int setEvent(WINDOW*,char);
                char getSource();
                int triggerEvent();
};

