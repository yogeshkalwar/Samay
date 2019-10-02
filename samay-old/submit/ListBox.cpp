#include "samayGUI.h"
#include<stdlib.h>
#include<iostream.h>
#define ENTER 10
#define ESCAPE 27

                ListBox::ListBox(){}

		ListBox::ListBox(int noOpt, bool bmult)
                {
                        bMult = bmult;
                        noOption = noOpt;
                        init();
                        boxCreate();
                }

                ListBox::ListBox(int iStartX, int iStartY, int noOpt, bool bmult){
                        bMult = bmult;
                        noOption = noOpt;
                        init();
                        ListBoxP->iInitX=iStartX;
                        ListBoxP->iInitY=iStartY;
                        boxCreate();
                }

                int ListBox::init(){
                        initCurses();
                        curs_set(0);
                        idefault();
			start_color();
		        init_pair(1,COLOR_WHITE,COLOR_BLUE);
		        init_pair(2,COLOR_BLUE,COLOR_WHITE);
		        init_pair(3,COLOR_WHITE,COLOR_RED);
                        str =new char*[noOption+1];
                        label =new int[noOption+1];
                        return 0;
                }

 		Position* ListBox::getPosition()
                {
                        return(ListBoxP);
                }

                int ListBox::addItem(char* sText,int iPos)
                {
                        str[iPos]=sText;
                        werase(items[iPos]);
                        waddstr(items[iPos],str[iPos]);
                        return 0;
                }

                int ListBox::idefault(){
                        ListBoxB = &DefB;
                        ListBoxP = &DefP;
                        return 0;
                }

                int ListBox::setBorder(int iBorOption)
                {
                        touchwin(items[0]);
                        ListBoxB->iBorderStyle = iBorOption;
                        GUIComponent::setBorder(iBorOption,items[0]);
                        touchwin(items[0]);
                        wrefresh(items[0]);
                        return 0;
                }

                int ListBox::setColor(int iShade)
                {
                        touchwin(items[0]);
                        for(int j=1;j<=noOption+1;j++){
                                wbkgd(items[j],COLOR_PAIR(iShade)); // this is for refreshing color
                                wnoutrefresh(items[j]);
                        }
                        doupdate();//refresh();
                        return 0;
                }

		int ListBox::delete_menu()
                {
                        int i;
                        for (i=0;i<= noOption;i++)
                                delwin(items[i]);
                        return 0;
                }

                int ListBox::setBg(int iShade)
                {
                        ListBoxB->iColorStyle = iShade;
                        touchwin(items[0]);
                        wrefresh(items[0]);
                        noecho();
                        GUIComponent::setColor(iShade,items[0]);
                        wbkgd(items[0],COLOR_PAIR(iShade));
                        wrefresh(items[0]);
                        return 0;
                }

		WINDOW** ListBox::getWindow(){
                        return(items);
                }
                 
                int ListBox::clear()
                {
                        for (int i=1;i<=count;i++)
                        wclear(items[i]);
                        wrefresh(items[0]);
                        sleep(1);
                        return 0;
                }

                int ListBox::getSelectedIndices(){
                                for(int i=1;i<=noOption+1;i++){
                                        if( label[i] == 1){
                        			touchwin(items[i]);
                        			wprintw(items[i],"%s",str[i]);
                        			wrefresh(items[i]);
					}
                                }
                        return 0;
                }

                char* ListBox::getSelected(){
                        return str[selected];
                }

		int ListBox::boxCreate()
		{
		        int i;
			count=noOption;
			int start_col=0;
		        curs_set(0);
		        noecho();
			str=new char*[noOption+1];
			items=new WINDOW*[noOption+1];
			items[0]=subwin(pWin,noOption+2,19,ListBoxP->iInitY,ListBoxP->iInitX);
			touchwin(items[0]);
        		wbkgd(items[0],COLOR_PAIR(2));             // this is for individual highlighting
	        	box(items[0],ACS_VLINE,ACS_HLINE);
			wrefresh(items[0]);
        		for(int j=1;j<=noOption+1;j++)
			{
				items[j]=subwin(items[0],1,17,ListBoxP->iInitY+j,ListBoxP->iInitX+1);
			}
		        for (i=1;i<=noOption;i++)
			{
				str[i]="ListBox";
				touchwin(items[i]);
				waddstr(items[i],str[i]);
				wrefresh(items[i]);
			}
		        wbkgd(items[1],COLOR_PAIR(1));
			wrefresh(items[1]);
			//wrefresh(pWin);
			return 0;
		}//change starts

		void ListBox::getFocus()
		{
			int w=0;
			int key;
		        selected=1;
			touchwin(items[0]);
			keypad(items[0],true);
			scrollok(items[0],true);
		        while (w==0) {
		                key=wgetch(items[0]);
		                if (key==KEY_DOWN || key==KEY_UP) 
				{
					touchwin(items[0]);
					if( label[selected] == 0 || bMult == false)
					{
						touchwin(items[selected]);
			                       	wbkgd(items[selected],COLOR_PAIR(2));//white
		        	                wnoutrefresh(items[selected+1]);
			                        doupdate();//refresh();
					}
					else
					{
						touchwin(items[selected]);
		                	        wbkgd(items[selected],COLOR_PAIR(3)); // this is for refreshing color
		                        	wnoutrefresh(items[selected]);
			                        doupdate();//refresh();
					}
		                        if (key==KEY_DOWN) {
						selected++;
						if( selected > count)
							selected = 1;
                			} else {
						selected--;
						if( selected < 1)
							selected = count;
				        }
					touchwin(items[selected]);
				        wbkgd(items[selected],COLOR_PAIR(1)); // blue
				        wnoutrefresh(items[selected]);
				        doupdate();//refresh();
			        }	
				else if (key == char(9)) 
                		        w=-1;
			       	else if (key==ENTER) 
				{
			               	if( label[selected] == 1 && bMult == true)
					{
			                        label[selected] = 0;
						touchwin(items[selected]);
                        			wbkgd(items[selected],COLOR_PAIR(1)); // this is for refreshing color
				                wnoutrefresh(items[selected]);
			                        doupdate();//refresh();
					}
                        		else
					{
                                		label[selected] = 1;
						touchwin(items[selected]);
			               	        wbkgd(items[selected],COLOR_PAIR(3)); // this is for refreshing color
			                       	wnoutrefresh(items[selected]);
	                		        doupdate();//refresh();
					}
                		}
				wrefresh(items[0]);
				wrefresh(pWin);
			}
			return;	
		}
