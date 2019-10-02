#include "samayGUI.h"

  		Button::Button()
                {
                        // initialise the curses library
                        initCurses();
                        idefault();
                        // third parameter of below function removed
                        // the text box needs to be well designed ,do it later.
                        sInp = "Button";
                        boxCreate(ButtonP ,sInp); //sInp needs refinement
                }

                Button::Button(int iWinX, int iWinY){   
                        initCurses();
                        idefault();
                        ButtonP->iInitX=iWinX;
                        ButtonP->iInitY=iWinY;
                        sInp = "Button";
                        boxCreate(ButtonP ,sInp); //sInp needs refinement
                }

                Button::Button(int iWinL, int iWinB,char *isInp){   
                        initCurses();
                        idefault();
                        ButtonP->iHeight=iWinB;
                        ButtonP->iWidth=iWinL;
                        sInp = isInp;
                        boxCreate(ButtonP ,sInp); //sInp needs refinement
                }

                Button::Button(char *isInp){
                        initCurses();
                        idefault();
                        sInp=isInp;
                        boxCreate(ButtonP ,sInp); //sInp needs refinement
                }

	 	Button::Button(int iWinX, int iWinY, int iWinL, int iWinB, char *isInp){
                        initCurses();
                        idefault();
                        ButtonP->iInitX=iWinX;
                        ButtonP->iInitY=iWinY;
                        ButtonP->iHeight=iWinB;
                        ButtonP->iWidth=iWinL;
                        sInp=isInp;
                        boxCreate(ButtonP ,sInp); //sInp needs refinement
                }

 		Position* Button::getPosition()
                {
                        return(ButtonP);
                }


		int Button::boxCreate(Position *temp, char *isInp){
                        int m = temp->iInitY;
                        int n = temp->iInitX;
                        win=subwin(pWin,temp->iHeight,temp->iWidth,temp->iInitY,temp->iInitX);
                        box(win,ACS_VLINE,ACS_HLINE);
                        touchwin(stdscr);
                        mvwprintw(win,1,2,"%s",isInp);
                        touchwin(win);
			setColor(4);
                        wrefresh(win);
                        wrefresh(pWin);
                        return 0;

                }

	 	int Button::setBorder(int iBorOption)
                {
                        GUIComponent::setBorder(iBorOption,win);
                        touchwin(win);
                        wrefresh(win);
                        return 0;
                }
                
		int Button::setColor(int iShade)
                {
                        touchwin(win);
                        GUIComponent::setColor(iShade,win);
                        wbkgd(win,COLOR_PAIR(iShade));
                        wrefresh(win);
                        return 0;
                }

/*		int Button::addEvent(Event* L1)
		{
			L1->setEvent(this->win,'B');
			return 0;
		}	
*/
                int Button::idefault(){
                        ButtonB = &DefB;
                        ButtonP = &DefP;
                        return 0;
                }
		
		//Button:: (*triggerEvent)();
	
		WINDOW** Button::getWindow(){
                        return(&win);
                }

		void Button::getFocus()
		{
			touchwin(win);
			//boxCreate(ButtonP,sInp);
			keypad(win,true);
			noecho();
			ch=wgetch(win);
			while(ch!=9)
			{
				if (ch==10){
					(*triggerEvent)(); 
					setColor(5);
					sleep(1);
                        		wrefresh(win);
					setColor(4);
                        		wrefresh(win);
				}
				ch=wgetch(win);
			}
                        wrefresh(win);
                        wrefresh(pWin);
			return;
		}
					
