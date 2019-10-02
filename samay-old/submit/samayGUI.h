/*                      *****************  samayGUI.h  *************
					  Header file 							*/



#include<curses.h>
#include<unistd.h>
#include<string.h> 
#include "Data.h"
#ifndef SAMAYGUI_H
#define SAMAYGUI_H


class Controller;							/*	This Class have a forward declaration */

class GUIComponent{							/*	Class at the Top of the hierarchy	*/
	
	protected:							
			
		WINDOW* pWin;						
		int iMaxX;					
		int iMaxY;							
		int iCurrWin;
		Behaviour DefB;				
		Position DefP;
		int iShade;
		char cInp;
		static int iCurWinID;
		Controller* cType;					/*	bi - directional association */
	
	public:
	
		GUIComponent();	

		void initCurses();					
		void setColor(int iShade,WINDOW *pwin);
		void setFocus();
		void setBorder(int iBorOption,WINDOW *win);
		void endCurses(WINDOW*);

		int getTabIndex();
		int incCurrWin();
		int getCurrWin();
		int getColor();

		virtual WINDOW** getWindow()=0; 
		virtual void getFocus()=0;
		//virtual int setAlign(int iOption) = 0;
};

/*     Controller Class keeps track of all the GUI components in an GUIComponent type array oAIndex   */

class Controller					
{
        private:
 
               GUIComponent* gVar;
        
    	public:
 
                GUIComponent* oAIndex[50];
		GUIComponent* getSource();
                
		void start();
                void registerComp(GUIComponent*);

};

/*	Inherited from GUIComponent */

class Control:public GUIComponent{
	
	public:
		Control();
		virtual WINDOW** getWindow()=0;
 		virtual void getFocus()=0;
 		virtual Position* getPosition()=0;

};

/*	Label is a type of Control, which displays static text on the container		*/

class Label:public Control{
        
	private:
                char* sInp;
		char ch;
	
               	Behaviour *LabelB;
               	Position  *LabelP;

		WINDOW* wnd;
		WINDOW* winn;

        public:

                Label() ;
                Label(int iWinX, int iWinY);
                Label(int iWinL, int iWinB,char *isInp);
		Label(char *isInp);
		Label(int iWinX, int iWinY, int iWinL, int iWinB, char *isInp);
                
		WINDOW** getWindow();
		Position* getPosition();

		void getFocus();

		char* getText();

                int setText(char* sText);
                int idefault();
                int boxCreate();
		int init();
		int ok();
		int setAlign(int iOption);
		int setColor(int iShade);
		int setBorder(int iBorOption);
};


class CheckBox:public Control{
        private:
                char* sInp;
                Behaviour *CheckBoxB;
                Position  *CheckBoxP;
                WINDOW* wcheck;
                WINDOW* wnd;
                char ch;
                bool select;
                WINDOW* wch;

        public:
                CheckBox() ;
                CheckBox(char *instr);
                CheckBox(int iStartX, int iStartY, char *instr);

                char* getText();
                int init();
                void getFocus();
                int idefault();
		int delete_menu(WINDOW**);
                int boxCreate();
                int setWin(WINDOW* mainWin);
                Position** getPos();
                int setText(char* sText);
                int setColor(int iShade);
                int setBg(int iShade);
                int setBorder(int iBorOption);
                WINDOW** getWindow();
		Position* getPosition();
};

/*	A Container is inherited from GUIComponent	*/

class Container: public GUIComponent{

	private:

		Behaviour bContainer;
		Position  pContainer;	
	public:

		Container();

		Behaviour bContainerDefault();
		Position pContainerDefault();

		virtual WINDOW** getWindow()=0;
 		virtual Position* getPosition()=0;
		virtual void getFocus() = 0;
};	


class GroupCheckBox:public Container{
        private:
                CheckBox** checkbox ;
                WINDOW** subw ;
                WINDOW** temp ;
                char** label;
                char ch;
                int no_Option;
                int selected;
                Behaviour *GroupCheckBoxB;
                Position  *GroupCheckBoxP;
                Position** pos;
                WINDOW* mainWin;
		  char** str;
	
        public:
                GroupCheckBox(int noOption) ;
                GroupCheckBox(int iStartX, int iStartY, int noOption);
                GroupCheckBox(int noOption, int iStartX, int iStartY, int iWidth);

                char* getSelected();
		
                int process();
                int setLabel(int noOption, char* instr);
                int init();
                int idefault();
                void getFocus();
                int boxCreate();
                int setColor(int iShade,WINDOW *temp);
                int setBorder(int iBorOption);
		Position* getPosition();
                WINDOW** getWindow();
};

/*	TextBox is a type of Control that accepts single line alpha numeric controls	*/

class TextBox:public Control{
  	
	protected:
                char* sInp;
                Behaviour *TextBoxB;
                Position  *TextBoxP;
		WINDOW* wnd;
		WINDOW* wsub;
		char ch;
		bool bMultiLine;	
 	public:

		TextBox() ;
                TextBox(int iWinL, int iWinB);
                TextBox(int iWinX, int iWinY, int iWinL, int iWinB);
                
		char* getText();
		int init();
		void  setMultLine() ;
                int idefault();
                int boxCreate();
		int setColor(int iShade);
		int setBorder(int iBorOption);
		int getInput(WINDOW*);
		int setAlign(int iOption);
		WINDOW** getWindow();
		void getFocus();
		Position* getPosition();
};

/*	This is a type of text box, having multiline alphanumeric entity */

class TextArea:public TextBox{
	
	private:
		char* sInp;
                Behaviour *TextAreaB;
                Position  *TextAreaP;
		WINDOW* win;
		int i;
		int icount;
		char* str;
		WINDOW* wer;
		char ch;	
	
	public:
		TextArea() ;
                TextArea(int iWinL, int iWinB);
                TextArea(int iWinX, int iWinY, int iWinL, int iWinB);
                
		WINDOW** getWindow();
		void getFocus();
		Position* getPosition();
};


class ListBox:public Control{
        
	protected:
                int* label;
                bool bMult;
                int count;
		int iStartX,iStartY;
                int noOption;
               // int iDisplay;
                int selected;
                Behaviour *ListBoxB;
                Position  *ListBoxP;
                WINDOW* sub;
		char** str;
                WINDOW** items;
        public:
                ListBox(int noOption, bool type) ;
                ListBox() ;
                ListBox(int iStartX, int iStartY, int noOpt, bool type);

                int init();
                int clear();
                int idefault();
                int boxCreate();
		void getFocus();
		int delete_menu();
                int addItem(char*,int);
		int setBg(int iShade);
		int setColor(int iShade);
		int setBorder(int iBorOption);
                int getSelectedIndices();
		int setText(char*,int);
                char* getSelected();
		WINDOW** getWindow();
		Position* getPosition();

};

class ComboBox:public ListBox{
        private:
                Behaviour *ComboBoxB;
                Position  *ComboBoxP;
                int noOption;
                WINDOW* wnd;
                WINDOW* temp;
                char* iStr;
        public:
                ComboBox(int noOption) ;
                ComboBox() ;
                ComboBox(int iStartX, int iStartY, int noOpt);

                int clear();
                int idefault();
                int boxCreate();
                void getFocus();
                //int setBg(int iShade);
                int setColor(int iShade);
                int setBorder(int iBorOption);
                //int addItem(char*,int);
                WINDOW** getWindow();
		Position* getPosition();

};

/*	A Frame is a type of Container, which has a title bar	*/

class Frame:public Container{
	
	private:

		WINDOW* cuWin;	
		WINDOW* cuWinMain;	
		WINDOW* cuWinTitle;	
		WINDOW* cuWinCross;

		char ch;
		//Behaviour FrameB;
		Position pTemp;

		int iHTitleBar;
		int iDimY;
		int iDimX;	
		int iHCross;
		int iWCross;
		int iYCoCross;

		Control* cType;
		
	protected:

		int isetHTitleBar(int);
		int isetHCross(int);
		int isetWCross(int);
		int isetYCoCross(int);

	public:
	
		Frame();
		Frame(int,int,int,int);
			
		void add(Control*);
		void getFocus();

		int igetHTitleBar();
		int igetHCross();
		int igetWCross();
		int igetYCoCross();

 		Position* getPosition();
		WINDOW** getWindow();
};


class Button:public Control{
        
	private:
                char* sInp;
                Behaviour *ButtonB;
                Position  *ButtonP;
                WINDOW* win;
                char ch;
        public:
                Button();
                Button(int iWinL, int iWinB);
                Button(int iWinL, int iWinB,char* sText);
                Button(char* sText);
                Button(int iWinX, int iWinY, int iWinL, int iWinB,char* sText);

                //char* getText();

                
		int idefault();
		void (*triggerEvent)();	
		void getFocus();
                int boxCreate(Position *Arg,char *ArgsInp);
                int setColor(int iShade);
                int setBorder(int iBorOption);
  //              int addEvent(Event*);
		Position* getPosition();
		WINDOW** getWindow();
        //      char getEvent();
        //      int getInput(WINDOW*);
        //      int setAlign(int iOption);
};

#endif
