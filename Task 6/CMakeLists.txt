cmake_minimum_required(VERSION 3.24)
project(Task_6)

include_directories(Factory/)
include_directories(Controls/)
include_directories(Forms/)
include_directories(WinControls/)
include_directories(LinuxControls/)
include_directories(MasOSControls/)
set(CMAKE_CXX_STANDARD 17)


add_executable(Task_6 main.cpp
        Controls/Button.h Controls/ScrollBar.h Controls/TextBox.h

        Factory/Factory.h Factory/WinFactory.h Factory/MacOSFactory.h Factory/LinuxFactory.h Factory/OS.h

        Forms/Form.h Forms/WinForm.h Forms/LinuxForm.h Forms/MacOSForm.h

        LinuxControls/LinuxButton.h LinuxControls/LinuxScrollBar.h LinuxControls/LinuxTextBox.h

        MasOSControls/MacOSButton.h MasOSControls/MacOsScrollBar.h MasOSControls/MacOSTextBox.h

        WinControls/WinButton.h WinControls/WinScrollBar.h WinControls/WinTextBox.h)