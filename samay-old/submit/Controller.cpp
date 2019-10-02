#include "samayGUI.h"

	void Controller::registerComp(GUIComponent* cTemp)
        {
		oAIndex[cTemp->getTabIndex()]=cTemp;
        }

	void Controller::start()
	{
		
		oAIndex[0]->getFocus();
		while(1)
		{
			gVar->incCurrWin();
			oAIndex[gVar->getCurrWin()]->getFocus();
		}
	}
	
	GUIComponent* Controller::getSource()
	{
		return oAIndex[gVar->getCurrWin()];
	}
		
	
	



































/*void Controller::setFocus()
	{
		touchwin(*(oAIndex[currWin]->getWindow()));
		if(currWin==iMax)
			currWin=0;
		currWin++;
	}*/
	/*void Controller::setFocus()
	{
		touchwin(*(oAIndex[currWin]->getWindow()));
		currWin++;
	}*/
