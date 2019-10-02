#include"samayGUI.h"
#include"stdlib.h"
#define ENTER 10
#define ESCAPE 27

		GroupCheckBox::GroupCheckBox(int noOption)
		{
			no_Option = noOption;
			init();
                        boxCreate(); 
		}

		GroupCheckBox::GroupCheckBox(int iStartX, int iStartY, int noOption){  
			no_Option = noOption;
                        init();
                        GroupCheckBoxP->iInitX=iStartX;
                        GroupCheckBoxP->iInitY=iStartY;
                        boxCreate();
                }
                
		GroupCheckBox::GroupCheckBox(int iStartX, int iStartY, int iWidth, int noOption){  
			no_Option = noOption;
                        init();
                        GroupCheckBoxP->iInitX=iStartX;
                        GroupCheckBoxP->iInitY=iStartY;
                        GroupCheckBoxP->iWidth=iWidth;
                        boxCreate();
                }

		int GroupCheckBox::init(){
			initCurses();
			curs_set(0);
			idefault();
			label = new char*[no_Option];
                        GroupCheckBoxP->iHeight=no_Option*3 + 3;
                        GroupCheckBoxP->iWidth=30;
			for( int i = 0; i < no_Option;i++)
				label[i] = "GroupCheckBox";
			return 0;
		}

		int GroupCheckBox::setLabel(int noLabel, char *instr){
			label[noLabel] = instr;
			checkbox[noLabel]->setText(instr);
			boxCreate();
                        return 0;
                }

		char* GroupCheckBox::getSelected(){
                        return label[selected];
                }

 		WINDOW** GroupCheckBox::getWindow(){
                        return(&mainWin);
                }

		 Position* GroupCheckBox::getPosition()
                {
                        return(GroupCheckBoxP);
                }


 		int GroupCheckBox::idefault(){
                        GroupCheckBoxB = &DefB;
                        GroupCheckBoxP = &DefP;
                        return 0; 
                }

		int GroupCheckBox::boxCreate()
		{
		        noecho();
		        mainWin = newwin(no_Option*3+2,GroupCheckBoxP->iWidth,GroupCheckBoxP->iInitY,GroupCheckBoxP->iInitX);
		        touchwin(mainWin);
		        box(mainWin,ACS_VLINE,ACS_HLINE);
		        wrefresh(mainWin);
		        checkbox = new CheckBox*[no_Option];
		        subw = new WINDOW*[no_Option];
		        for(int j=0;j<no_Option;j++){
				checkbox[j] = new CheckBox(GroupCheckBoxP->iInitX+1,GroupCheckBoxP->iInitY+j*3+1,label[j]);
				pos = checkbox[j]->getPos();
				temp = checkbox[j]->getWindow();
				subw[j] = subwin(mainWin,(*pos)->iHeight,(*pos)->iWidth,(*pos)->iInitY,(*pos)->iInitX);
				subw[j] = *temp;
				checkbox[j]->setBg(1);
			}
			return 0;
		}
	
		void GroupCheckBox::getFocus(){
        		int w=1;
		        int count=no_Option;
		        int key;
		        selected=0;
		        touchwin(mainWin);
		        keypad(mainWin,true);
		        while (w) {
		                checkbox[selected]->setColor(4);
		                key = wgetch(mainWin);
                		if (key==KEY_DOWN || key==KEY_UP) {
		                        checkbox[selected]->setColor(4);
                		        wnoutrefresh(mainWin);
		                        if (key==KEY_DOWN) {
		                        	checkbox[selected]->setColor(1); // this is for refreshing color
        		                        selected=(selected+1) % count;
	                	        } 
					else {
		                        	checkbox[selected]->setColor(1); // this is for refreshing color
                        	        	selected=(selected+count-1) % count;
          		              	}
		                        checkbox[selected]->setColor(4); // this is for refreshing color
		                        wnoutrefresh(mainWin);
        		                doupdate();//refresh();
                		}
			
		                else if (key==ENTER) {
					touchwin(mainWin);
					mvwaddstr(mainWin,0,40,label[selected]);
					wrefresh(mainWin);
                		}
			
		                else if (key==char(9)) {
        	        	        w = 0;
                		}
			}
		        wrefresh(mainWin);
			return ;
		}
