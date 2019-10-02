#include "samayGUI.h"
#include "string.h"

		ComboBox::ComboBox() 
                {
			
                } 

		ComboBox::ComboBox(int iWinX, int iWinY, int Opt):ListBox(iWinX,iWinY+2,Opt,false){
			idefault();
			iStr = "ComboBox";
			noOption = Opt;
			ComboBoxP->iInitX=iWinX;
                        ComboBoxP->iInitY=iWinY;
			boxCreate();
                }
                
		int ComboBox::setBorder(int iBorOption)
		{
			 ComboBoxB->iBorderStyle = iBorOption;	
			 GUIComponent::setBorder(iBorOption,wnd);
			touchwin(wnd);
			wrefresh(wnd);
			return 0;	
		}

		int ComboBox::setColor(int iShade)
		{
			 ComboBoxB->iColorStyle = iShade;
			touchwin(wnd);
			wrefresh(wnd);
			 GUIComponent::setColor(iShade,wnd);
			wbkgd(wnd,COLOR_PAIR(iShade));
			wrefresh(wnd);	
			return 0;
		}	

               int ComboBox::boxCreate(){
			wnd = subwin(pWin,ComboBoxP->iHeight,ComboBoxP->iWidth,ComboBoxP->iInitY,ComboBoxP->iInitX);
                        box(wnd,ACS_VLINE,ACS_HLINE);
                        touchwin(wnd);
                        mvwaddstr(wnd,1,1,iStr);
                        setColor(4);
                        wrefresh(wnd);
                        wrefresh(pWin);
                        return 0;
                }


		WINDOW** ComboBox::getWindow(){
			return(&wnd);
		}
		 
	
                int ComboBox::idefault(){
                         ComboBoxB = & DefB;
                         ComboBoxP = & DefP;
                        return 0; 
                }

		Position* ComboBox::getPosition()
                {
                        return(ComboBoxP);
                }

		void ComboBox::getFocus()
		{
			int w=0;
        		int key;
        		selected=1;
			touchwin(ListBox::items[0]);
		        wrefresh(ListBox::items[0]);
		        keypad(items[0],true);
			noecho();
		        scrollok(items[0],true);
		        while (w==0) {
                		key=wgetch(wnd);
		                if (key == char(9)){
		                        w=-1;
                		}
		                else if (key==char(10)){
					ListBox::getFocus();
					iStr = ListBox::getSelected();
					temp = newwin(noOption,19,ComboBoxP->iInitY,ComboBoxP->iInitX);
					touchwin(wnd);
					werase(wnd);				
					wrefresh(wnd);
					boxCreate();
				}
                	}	        
                        wrefresh(pWin);
			return ;
			

		}


