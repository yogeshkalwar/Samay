#include "samayGUI.h"

	Container::Container()
	{

		bContainer.iBorderStyle=6;
                bContainer.bVisible= true;
                bContainer.iMaxTextW = 108;
                bContainer.iMaxXCo = 60;
                bContainer.iMaxYCo = 23;
                bContainer.iAlignment= 0;
                bContainer.iColorStyle = 1;
                        // Possition Pointer initialisation.
                pContainer.iHeight = 23;
                pContainer.iTabIndex= 0;
                pContainer.iWidth = 34;
                pContainer.iInitX = 7;
                pContainer.iInitY = 5;
	}

	Position Container::pContainerDefault()
	{
		return pContainer;
	}

	
	Behaviour Container::bContainerDefault()
	{
		return bContainer;
	}

	

