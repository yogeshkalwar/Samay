#include"samayGUI.h"
		
		TextArea::TextArea():TextBox()
		{
		}
		
		TextArea::TextArea(int i, int j):TextBox(i,j)
		{
		}
		
		TextArea::TextArea(int i,int j, int k, int l):TextBox( i, j, k, l)
		{}

 		Position* TextArea::getPosition()
                {
                        return(TextAreaP);
                }
			
		
		void TextArea::getFocus()
		{
			bMultiLine=true;
			TextBox::getFocus();
		}

		WINDOW** TextArea::getWindow()
		{
			return(&wnd);
		}
