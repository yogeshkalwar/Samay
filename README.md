# Samay
A project to create toolkit for user interface components, like awt in C++ using NCurses. 

#This is project for academic purpose not full fletch toolkit.

Discussion:
Yogesh: Date: 02 Oct 2019
  - Any toolkit/framework has three parts
      1) User of framework, like applications
      2) components of toolkit like controls
      3) Windowing system, here its ncurses
      
   - Before designing we have to figure out how the toolkit will be used? I am thinking to create single threaded 
   event based toolkit.
   - It will have.
      1) Application class
      2) Delegate mechanism
      3) Event responder controls .that's it.
   
   - Container (or Layout) - Is container is guicomponent? No. It is not GuiComponent, its a container which contains the control and manages their positions or flow. its group of views.
   like Linear - Horizontal / Vertical. Grid. Flow. Frame... etc
   - 
   
   
   Naming - for layouts/containers - "ContainerLayout" ? LinearContainerLayout, FrameContainerLayout, GridContainerLayout.
            SLinearContainer, SFrameContainer
          - SApplication
          - SApplicationDelegate
          - EventResponder (for top parent of View)
          - SView
          - SControl
          - SWindow
          - SFrame
          - SContentView
          - SContainer (like ViewGroup) parent of all containers.
          
          
