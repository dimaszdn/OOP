cmake_minimum_required(VERSION 3.24)
project(Task_6)

include_directories(inc/)
include_directories(Controls/)
include_directories(Forms/)
include_directories(WinControls/)
include_directories(LinuxControls/)
include_directories(MasOSControls/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Task_6 main.cpp Controls/Controls.h
        inc/Factory.h
        Forms/Form.h
        Controls/TextBox.h
        Controls/Button.h
        WinControls/WinTextBox.h
        WinControls/WinButton.h
        Forms/WinForm.h
        inc/WinFactory.h
        inc/OS.h
        Forms/LinuxForm.h
        Forms/MacOSForm.h
        LinuxControls/LinuxButton.h
        LinuxControls/LinuxTextBox.h
        inc/LinuxFactory.h
        MasOSControls/MacOSButton.h
        MasOSControls/MacOSTextBox.h
        inc/MacOSFactory.h)
