#include "samayGUI.h"

Frame::Frame()
{
	cuWin=initscr();
	pTemp=Container::pContainerDefault();	
	cuWinMain=subwin(cuWin,pTemp.iHeight,pTemp.iWidth,pTemp.iInitY,pTemp.iInitX);
	box(cuWinMain,ACS_VLINE,ACS_HLINE);
	touchwin(cuWinMain);
	wrefresh(cuWinMain);
	cuWinTitle=subwin(cuWinMain,3,pTemp.iWidth,pTemp.iInitY,pTemp.iInitX);
	box(cuWinTitle,ACS_VLINE,ACS_HLINE);
	wrefresh(cuWinTitle);
	wrefresh(cuWinMain);
	cuWinCross=subwin(cuWinTitle,3,3,5,36);
	box(cuWinCross,ACS_VLINE,ACS_HLINE);
	//scrollok(cuWinCross,true);
	mvwaddstr(cuWinCross,1,1,"X");
	touchwin(cuWinCross);
	wrefresh(cuWinCross);
	wrefresh(cuWinTitle);
	wrefresh(cuWinMain);
	wrefresh(cuWinMain);
		
}

Frame::Frame(int iInitX, int iInitY, int iHeight, int iWidth)
{

	cuWin=initscr();
	pTemp.iHeight=iHeight;
	pTemp.iWidth=iWidth;
	pTemp.iInitY=iInitY;
	pTemp.iInitX=iInitX;
        cuWinMain=subwin(cuWin,iHeight,iWidth,iInitY,iInitX);
        box(cuWinMain,ACS_VLINE,ACS_HLINE);
        touchwin(cuWinMain);
        wrefresh(cuWinMain);
        cuWinTitle=subwin(cuWinMain,3,iWidth,iInitY,iInitX);
        box(cuWinTitle,ACS_VLINE,ACS_HLINE);
        wrefresh(cuWinTitle);
        wrefresh(cuWinMain);
        cuWinCross=subwin(cuWinTitle,3,3,iInitY,iWidth+3);
        box(cuWinCross,ACS_VLINE,ACS_HLINE);
        //scrollok(cuWinCross,true);
	//char ch=wgetch(cuWinCross);
        mvwaddstr(cuWinCross,1,1,"X");
        touchwin(cuWinCross);
        wrefresh(cuWinCross);
        wrefresh(cuWinTitle);
        wrefresh(cuWinMain);
        wrefresh(cuWinMain);

	
}

void Frame::add(Control *cType)
{
	Position* tempPos=cType->getPosition();
	WINDOW** tempWin=cType->getWindow();
	WINDOW* win1=subwin(cuWinMain,tempPos->iHeight,tempPos->iWidth,pTemp.iInitY+tempPos->iInitY,pTemp.iInitX+tempPos->iInitX);
	win1=*tempWin;
	wrefresh(win1);
	wrefresh(cuWinMain);
}

  Position* Frame::getPosition()
  {
		return(&pTemp);		
  }


WINDOW** Frame::getWindow(){
                        return(&cuWinMain);
                }

/*
Frame::~Frame()
{
	endwin();
}
*/

int Frame::isetHTitleBar(int iTemp)
{
	 iHTitleBar=iTemp;
	 return 0;
}

int Frame::isetHCross(int iTemp)
{
	 iHCross=iTemp;
	 return 0;
}
	
int Frame::isetWCross(int iTemp)
{
	 iWCross=iTemp;
	 return 0;
}

int Frame::isetYCoCross(int iTemp)
{
	iYCoCross=iTemp;
	 return 0;
}

int Frame::igetHTitleBar()
{
	 return iHTitleBar;
}

int Frame::igetHCross()
{
	 return iHCross;
}
	
int Frame::igetWCross()
{
	 return iWCross;
}

int Frame::igetYCoCross()
{
	return iYCoCross;
}

void Frame::getFocus(){
                        touchwin(cuWinMain);
                        wrefresh(cuWinMain);
                        curs_set(0);
                        keypad(cuWinMain,true);
			noecho();
                        int f = 1;
                        while(f){
                                ch = getch();
                                if( ch == char(9)){
                                        f = 0;
                                }
				if( ch == char(27)){
                                	//ch = getch();
					//if( ch == 'x'){
						endwin();
					//}
				}
                                continue;
                        }
                        return ;
                }

