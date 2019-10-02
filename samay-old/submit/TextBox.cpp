#include "samayGUI.h"

		TextBox::TextBox()
		{
			init();
                        boxCreate(); 
		}

		TextBox::TextBox(int iWinL, int iWinB){  
                        init();
                        TextBoxP->iHeight=iWinB;
                        TextBoxP->iWidth=iWinL;
                        boxCreate();
                }

		void TextBox::setMultLine()
		{
			bMultiLine=false;
		}	
                

		TextBox::TextBox(int iWinX, int iWinY, int iWinL, int iWinB){
                        init();
                        TextBoxP->iInitX=iWinX; 
                        TextBoxP->iInitY=iWinY;
                        TextBoxP->iHeight=iWinB;
                        TextBoxP->iWidth=iWinL;
                        boxCreate(); 
                }

		int TextBox::init(){
			initCurses();
			idefault();
			return 0;
		}

		char* TextBox::getText(){
                        return sInp;
                }

		Position* TextBox::getPosition()
                {
                        return(TextBoxP);
                }

 		int TextBox::idefault(){
                        TextBoxB = &DefB;
                        TextBoxP = &DefP;
                        return 0; 
                }

		int TextBox::setBorder(int iBorOption)
		{
			touchwin(wnd);
			TextBoxB->iBorderStyle = iBorOption;	
			GUIComponent::setBorder(iBorOption,wnd);
			wrefresh(wnd);
			return 0;	
		}

		int TextBox::setColor(int iShade)
		{
			TextBoxB->iColorStyle = iShade;
			touchwin(wnd);
			GUIComponent::setColor(iShade,wnd);
			wbkgd(wnd,COLOR_PAIR(iShade));
			wrefresh(wnd);	
			return 0;
		}
	
		int TextBox::boxCreate()
		{
			wnd = subwin(pWin,TextBoxP->iHeight,TextBoxP->iWidth,TextBoxP->iInitY,TextBoxP->iInitX);
			touchwin(wnd);
			box(wnd,ACS_VLINE,ACS_HLINE);
			setColor(2);
			wrefresh(wnd);	
			return 0;
		}
		
		void TextBox::getFocus()
		{
			int f=1;
			int i = 1;
			char str[108];
			int icount = 0;
			int len = TextBoxP->iWidth;	
			touchwin(wnd);
			keypad(wnd,true);
			wmove(wnd,1,i+1);
			wrefresh(wnd);
			int isame = i;

			while(f){
				int k = 1;
				ch = wgetch(wnd);
				if(ch == char(263)){ //backspace
					if(i - 1 == 0){
							wmove(wnd,1,1);
						if(icount == 0){
							beep();
							continue;
						}
						else{
							wdelch(wnd);
							wrefresh(wnd);
							int j = 0;
							if(icount - (len-2) < 0) j = 0;
							else 
								j = icount - (len-2)+1;
							for(; j < icount; j++)
							{
								wdelch(wnd);
								winsch(wnd,str[j]);
								wmove(wnd,1,++k);
							}
							winsch(wnd,' ');
							i = k;
						}
					}
					else{
						wmove(wnd,1,i-1);
						wdelch(wnd);
						winsch(wnd,' ');
						wrefresh(wnd);
						str[icount] = ' ';
						i--;
						if(icount != 0)
							icount--;
					}
				}// backspace
				else if(ch==char(27)){ //escape
					f=0;
					}
			  	else if(ch == char(260)){
					wmove(wnd,1,i--);
				}
				else if(ch == char(261)){
					wmove(wnd,1,i++);
				}	
				else if(ch == char(9)){
					f = 0;
				}	
				else if(ch!=char(331) && ch!=char(262) && ch!=char(339) && ch!=char(269) && 
							ch!=char(270) && ch!=char(265) && ch!=char(266) && ch!=char(267) && 
							ch!=char(268) && ch!=char(271) && ch!=char(272) && ch!=char(273) && 
							ch!=char(274) && ch!=char(275) && ch!=char(276) && ch!=char(338) && 
							ch!=char(360) && ch!=char(330) && ch!=char(258) && ch!=char(259) && 
							ch!=char(126) && ch!=char(10))
				{ //9
					if(bMultiLine==false)
					{
						if(i >= (len-2))
						{
			                        	int k = 1;
                       					wmove(wnd,1,1);
			                        	for(int l = 1; l <= (len-1); l++)
							{
		                                        	wdelch(wnd);
                           			        	winsch(wnd,' ');
				                        	wmove(wnd,1,l);
							}
				                	wmove(wnd,1,1);
				                	str[icount] = ch;
                                			icount++;
				                	for(int j = (icount-len+2)+1; j < icount; j++)
							{
				                        	wdelch(wnd);
                                				winsch(wnd,str[j]);
				                        	wmove(wnd,1,++k);
  			                        	}
							touchwin(wnd);
                                        		wrefresh(wnd);
				                	continue;
						}
                                		else
						{
                                			str[icount] =  ch;
                                			echo();
				                	wmove(wnd,1,i+1);
                                			wrefresh(wnd);
				                	i++;
							icount++;
                        		//}
				}//9
					}
					else
					{
						str[icount] =  ch;
                                                        echo();
                                                        wmove(wnd,1,i+1);
                                                        wrefresh(wnd);
                                                        i++;
                                                        icount++;
					}
						}
				}
		}
						
		WINDOW** TextBox::getWindow()
		{
                        return(&wnd);
                }



