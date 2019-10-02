# makefile for samayGUI program

samay: GUIComponent.o Control.o Label.o Container.o Frame.o Controller.o CheckBox.o TextBox.o TextArea.o ListBox.o ComboBox.o GroupCheckBox.o Button.o
	g++ -lcurses App4.cpp GUIComponent.o Control.o Label.o Container.o Frame.o Controller.o CheckBox.o TextBox.o TextArea.o ListBox.o ComboBox.o GroupCheckBox.o Button.o -o samay

GUIComponent.o:	GUIComponent.cpp samayGUI.h 

Control.o:	Control.cpp samayGUI.h

Label.o:	Label.cpp samayGUI.h

Container.o:	Container.cpp samayGUI.h

Frame.o:	Frame.cpp samayGUI.h

Controller.o:	Controller.cpp samayGUI.h

CheckBox.o:	CheckBox.cpp samayGUI.h

TextBox.o:	TextBox.cpp samayGUI.h

TextArea.o:	TextArea.cpp samayGUI.h

ListBox.o:	ListBox.cpp samayGUI.h

ComboBox.o:	ComboBox.cpp samayGUI.h

GroupCheckBox.o:	GroupCheckBox.cpp samayGUI.h

Button.o:	Button.cpp samayGUI.h

clean:
	rm -f *.o samay core


