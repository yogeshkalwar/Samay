#include"samayGUI.h"
		CheckBox::CheckBox()
		{
			init();
                        CheckBoxP->iWidth=30;
			sInp = "CheckBox";
                        boxCreate(); 
		}

		CheckBox::CheckBox(char *instr){  
                        init();
                        CheckBoxP->iWidth=strlen(instr)+15;
			sInp = instr;
                        boxCreate();
                }
                
		CheckBox::CheckBox(int iStartX, int iStartY, char *instr){  
                        init();
                        CheckBoxP->iInitX=iStartX;
                        CheckBoxP->iInitY=iStartY;
                        CheckBoxP->iWidth=28;
			sInp = instr;
                        boxCreate();
                }

		int CheckBox::init(){
			initCurses();
			curs_set(0);
			idefault();
                        CheckBoxP->iHeight=3;
			return 0;
		}

		Position* CheckBox::getPosition()
                {
                        return(CheckBoxP);
                }


		int CheckBox::setText(char* sText){
                        sInp = sText;
			touchwin(wnd);
			werase(wnd);
			boxCreate();
			wrefresh(wnd);
                        return 0;
                }

		char* CheckBox::getText(){
                        return sInp;
                }

 		int CheckBox::idefault(){
                        CheckBoxB = &DefB;
                        CheckBoxP = &DefP;
                        return 0; 
                }

		int CheckBox::setBorder(int iBorOption)
		{
			touchwin(wnd);
			CheckBoxB->iBorderStyle = iBorOption;	
			GUIComponent::setBorder(iBorOption,wnd);
			touchwin(wnd);
			wrefresh(wnd);
			return 0;	
		}

		int CheckBox::setColor(int iShade)
		{
			CheckBoxB->iColorStyle = iShade;
			touchwin(wch);
			wrefresh(wch);
			noecho();
			GUIComponent::setColor(iShade,wch);
			wbkgd(wch,COLOR_PAIR(iShade));
			wrefresh(wch);	
			return 0;
		}
	
		int CheckBox::setBg(int iShade)
		{
			CheckBoxB->iColorStyle = iShade;
			touchwin(wnd);
			wrefresh(wnd);
			noecho();
			GUIComponent::setColor(iShade,wnd);
			wbkgd(wnd,COLOR_PAIR(iShade));
			wrefresh(wnd);	
			return 0;
		}

 		WINDOW** CheckBox::getWindow(){
                        return(&wnd); 
                }

 		Position** CheckBox::getPos(){
                        return(&CheckBoxP); 
                }

		int CheckBox::boxCreate(){
			curs_set(0);
			noecho();
			wnd = newwin(CheckBoxP->iHeight,CheckBoxP->iWidth,CheckBoxP->iInitY,CheckBoxP->iInitX);
			touchwin(wnd);
			box(wnd,ACS_VLINE,ACS_HLINE);
			mvwaddstr(wnd,1,7,sInp);
			wrefresh(wnd);
			wcheck =subwin(wnd,3,4,CheckBoxP->iInitY+0,CheckBoxP->iInitX+2);
			box(wcheck,ACS_VLINE,ACS_HLINE);
			wrefresh(wcheck);
			wch = subwin(wcheck,1,2,CheckBoxP->iInitY+1,CheckBoxP->iInitX+3);
			touchwin(wch);
			wrefresh(wch);
			return(0);
		}

		void CheckBox::getFocus(){
			touchwin(wnd);
			wrefresh(wnd);
			curs_set(1);
			keypad(wnd,true);
			select = false;
			int f = 1;
			while(f){
				ch = getch();
				if( ch == char(10)){
					touchwin(wcheck);
					curs_set(0);
					if( select == false){
						select = true;
						touchwin(wch);
						curs_set(0);
						setColor(4);
					}
					else{
						select = false;
						touchwin(wch);
						curs_set(0);
						setColor(3);
					}
					wrefresh(wcheck);
				}
				if( ch == char(9)){
					f = 0;
				}
				continue;
			}
			return ;
		}
