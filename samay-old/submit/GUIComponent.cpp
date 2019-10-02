#include "samayGUI.h"

	GUIComponent::GUIComponent()
	{
		iCurWinID++;//=iCurWinID+1;
		iCurrWin=0;	
			// Behavior Pointer Initialisation.
		DefB.iBorderStyle=6;
        	DefB.bVisible= true;
	        DefB.iMaxTextW = 108;
	        DefB.iMaxXCo = 60;
	        DefB.iMaxYCo = 23;
	        DefB.iAlignment= 0;
	        DefB.iColorStyle = 1;		
			// Possition Pointer initialisation.
  		DefP.iHeight = 3;
	        DefP.iTabIndex= iCurWinID;
	        DefP.iWidth = 25;
	        DefP.iInitX = 1;
	        DefP.iInitY = 0;   
	}

	void GUIComponent::initCurses(){

		pWin = initscr();
		start_color();
        	getmaxyx(pWin,iMaxY,iMaxX);
	}
 
	void GUIComponent::endCurses(WINDOW *win){
		
		wgetch(win);
		endwin();
	
	}

	void GUIComponent::setFocus(){
                iCurrWin++;
                if(iCurrWin>getTabIndex())
                        iCurrWin=0;
 		//touchwin(*((cType->oAIndex[iCurrWin])->getWindow()));
 		(cType->oAIndex[iCurrWin])->getFocus();
	}

/*	GUIComponent::~GUIComponent()
	{
		endwin();
	}
*/	
	int GUIComponent::incCurrWin()
	{
		iCurrWin++;
		if( iCurrWin > iCurWinID )
			iCurrWin = 0;		
		return 0;
	}


	int GUIComponent::getCurrWin()
	{
		return iCurrWin;
	}

	int GUIComponent::getTabIndex()
	{
		return iCurWinID;
	}
	int GUIComponent::getColor(){
	
		return iShade;
	}

	void GUIComponent::setColor(int iShade1,WINDOW *win){
		switch(iShade1)
		{
			
		case 1:  
		     	init_pair(1,COLOR_WHITE,COLOR_BLUE);
			break;
		case 2:  
		    	init_pair(2,COLOR_BLUE,COLOR_WHITE);
			break;
		case 3:  
		     	init_pair(3,COLOR_WHITE,COLOR_BLACK);
			break;
		case 4:  
		     	init_pair(4,COLOR_BLUE,COLOR_YELLOW);
			break;
		default:  
		     	init_pair(5,COLOR_BLUE,COLOR_GREEN);
			break;
		
		}	
	}

	void GUIComponent::setBorder(int iBorOption,WINDOW *win){
		switch(iBorOption){
			case 1:
				box(win,ACS_VLINE,ACS_HLINE);
				break;

			case 2:
				wborder(win,'|','|','-','-','-','-','-','-');
				break;
		
			case 3:	
				wborder(win,'!','!','=','=','=','=','=','=');
				break;
			
			case 4:	
				wborder(win,'.','.','.','.','.','.','.','.');
				break;
				
			case 5:	
				wborder(win,'*','*','*','*','*','*','*','*');
				break;

			default:
				wborder(win,'|','|','-','-','-','-','-','-');
				break;
		}
	}

	//void GUIComponent::register(int cTemp)
	//{
	//	oAIndex[iCurWinID]=(GUIComponent*)cTemp;
	//}

	//virtual WINDOW** GUIComponent::getWindow()=0;
	int GUIComponent::iCurWinID=-1;	
