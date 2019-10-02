#include "samayGUI.h"
#include "string.h"

		Label::Label() 
                {
                        init();
                        sInp = "Label";
                        boxCreate(); //sInp needs refinement
			
                } 

                Label::Label(int iWinX, int iWinY){  
                        init();
                         LabelP->iInitX=iWinX;
                         LabelP->iInitY=iWinY;
                        sInp = "Label";
                        boxCreate(); //sInp needs refinement 
                }

                Label::Label(int iWinL, int iWinB,char *isInp){  
                        init();
                         LabelP->iHeight=iWinB;
                         LabelP->iWidth=iWinL;
                        sInp = isInp;
                        boxCreate(); //sInp needs refinement 
                }
                
		Label::Label(char *isInp){
                        init();
                        sInp=isInp;
                        boxCreate(); //sInp needs refinement 
                }
                
		Label::Label(int iWinX, int iWinY, int iWinL, int iWinB, char *isInp){
                        init();
                         LabelP->iInitX=iWinX; 
                         LabelP->iInitY=iWinY;
                         LabelP->iHeight=iWinB;
                         LabelP->iWidth=iWinL;
                        sInp=isInp;
			cInp='3';
                        boxCreate(); //sInp needs refinement 
                }
                
		int Label::init(){
			initCurses();
			idefault();
			curs_set(0);
			noecho();
			return 0;
		}

		int Label::setBorder(int iBorOption)
		{
			 LabelB->iBorderStyle = iBorOption;	
			 GUIComponent::setBorder(iBorOption,wnd);
			touchwin(wnd);
			wrefresh(wnd);
			return 0;	
		}

		int Label::setColor(int iShade)
		{
			 LabelB->iColorStyle = iShade;
			touchwin(winn);
			wrefresh(winn);
			 GUIComponent::setColor(iShade,winn);
			wbkgd(winn,COLOR_PAIR(iShade));
			wrefresh(winn);	
			return 0;
		}	

               int Label::boxCreate(){
			wnd = subwin(pWin,LabelP->iHeight,LabelP->iWidth,LabelP->iInitY,LabelP->iInitX);
			box(wnd,ACS_VLINE,ACS_HLINE);
			winn = subwin(wnd,LabelP->iHeight-2,LabelP->iWidth-2,LabelP->iInitY+1,LabelP->iInitX+1);
			touchwin(winn);
			setColor(4);
			mvwaddstr(winn,0,1,sInp);
			wrefresh(winn);
		//	touchwin(wnd);
			wrefresh(pWin);
                        return 0;
                }

                char* Label::getText(){
                        return sInp;
                }

		WINDOW** Label::getWindow(){
			return(&wnd);
		}
		 
                int Label::ok(){
			endCurses(wnd);
                        return 0;
                }

                int Label::setText(char* sText){
			sInp = sText;
			touchwin(wnd);
			werase(wnd);
			box(wnd,ACS_VLINE,ACS_HLINE);
			touchwin(wnd);
			mvwaddstr(wnd,1,1,sText);
                        wrefresh(wnd);
                        return 0;
                }
	
                int Label::idefault(){
                         LabelB = & DefB;
                         LabelP = & DefP;
                        return 0; 
                }
	        
		int Label::setAlign( int iOption){
			 LabelB->iAlignment = iOption;
			char *temp ;
			temp = this->getText();
			touchwin(wnd);
			werase(wnd);
			box(wnd,ACS_VLINE,ACS_HLINE);
			touchwin(wnd);
			int l = strlen(temp);
			switch( iOption){
				case -1 :
					mvwaddstr(wnd,1,1,temp);
					break;
				case 0 :
					mvwaddstr(wnd,1, LabelP->iWidth/2 - l/2,temp);
					break;
				case 1 :
					mvwaddstr(wnd,1, LabelP->iWidth-(l+2),temp);
					break;
				default:
					printw("%s\n","Use only -1,0,1 as Parameters for Alignment");
					
			}
                        wrefresh(wnd);
                        return 0;
		}

		void Label::getFocus()
		{
			touchwin(wnd);
                        wrefresh(wnd);
			/*
                        curs_set(0);
			noecho();
                        keypad(wnd,true);
                        int f = 1;
                        while(f){
                                ch = getch();
                                touchwin(winn);
                                //curs_set(0);
                                wrefresh(winn);
                                if( ch == char(9)){
                                        f = 0;
                                }
                                continue;
                        }
                                wrefresh(winn);
                        wrefresh(wnd);*/
                        return ;

		}

		Position* Label::getPosition()
		{
			return(LabelP);
		}
