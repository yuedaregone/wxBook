# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\cmake-3.7.0-win64-x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\cmake-3.7.0-win64-x64\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Study\github\wxBook\wxBook

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Study\github\wxBook\build

# Include any dependencies generated for this target.
include CMakeFiles\wxBook.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\wxBook.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\wxBook.dir\flags.make

CMakeFiles\wxBook.dir\src\Config.cpp.obj: CMakeFiles\wxBook.dir\flags.make
CMakeFiles\wxBook.dir\src\Config.cpp.obj: D:\Study\github\wxBook\wxBook\src\Config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Study\github\wxBook\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wxBook.dir/src/Config.cpp.obj"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1410~1.250\bin\HostX86\x86\cl.exe  @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\wxBook.dir\src\Config.cpp.obj /FdCMakeFiles\wxBook.dir\ /FS -c D:\Study\github\wxBook\wxBook\src\Config.cpp
<<

CMakeFiles\wxBook.dir\src\Config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wxBook.dir/src/Config.cpp.i"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1410~1.250\bin\HostX86\x86\cl.exe  > CMakeFiles\wxBook.dir\src\Config.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Study\github\wxBook\wxBook\src\Config.cpp
<<

CMakeFiles\wxBook.dir\src\Config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wxBook.dir/src/Config.cpp.s"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1410~1.250\bin\HostX86\x86\cl.exe  @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\wxBook.dir\src\Config.cpp.s /c D:\Study\github\wxBook\wxBook\src\Config.cpp
<<

CMakeFiles\wxBook.dir\src\Config.cpp.obj.requires:

.PHONY : CMakeFiles\wxBook.dir\src\Config.cpp.obj.requires

CMakeFiles\wxBook.dir\src\Config.cpp.obj.provides: CMakeFiles\wxBook.dir\src\Config.cpp.obj.requires
	$(MAKE) -f CMakeFiles\wxBook.dir\build.make /nologo -$(MAKEFLAGS) CMakeFiles\wxBook.dir\src\Config.cpp.obj.provides.build
.PHONY : CMakeFiles\wxBook.dir\src\Config.cpp.obj.provides

CMakeFiles\wxBook.dir\src\Config.cpp.obj.provides.build: CMakeFiles\wxBook.dir\src\Config.cpp.obj


CMakeFiles\wxBook.dir\src\Main.cpp.obj: CMakeFiles\wxBook.dir\flags.make
CMakeFiles\wxBook.dir\src\Main.cpp.obj: D:\Study\github\wxBook\wxBook\src\Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Study\github\wxBook\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/wxBook.dir/src/Main.cpp.obj"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1410~1.250\bin\HostX86\x86\cl.exe  @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\wxBook.dir\src\Main.cpp.obj /FdCMakeFiles\wxBook.dir\ /FS -c D:\Study\github\wxBook\wxBook\src\Main.cpp
<<

CMakeFiles\wxBook.dir\src\Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wxBook.dir/src/Main.cpp.i"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1410~1.250\bin\HostX86\x86\cl.exe  > CMakeFiles\wxBook.dir\src\Main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Study\github\wxBook\wxBook\src\Main.cpp
<<

CMakeFiles\wxBook.dir\src\Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wxBook.dir/src/Main.cpp.s"
	C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1410~1.250\bin\HostX86\x86\cl.exe  @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\wxBook.dir\src\Main.cpp.s /c D:\Study\github\wxBook\wxBook\src\Main.cpp
<<

CMakeFiles\wxBook.dir\src\Main.cpp.obj.requires:

.PHONY : CMakeFiles\wxBook.dir\src\Main.cpp.obj.requires

CMakeFiles\wxBook.dir\src\Main.cpp.obj.provides: CMakeFiles\wxBook.dir\src\Main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\wxBook.dir\build.make /nologo -$(MAKEFLAGS) CMakeFiles\wxBook.dir\src\Main.cpp.obj.provides.build
.PHONY : CMakeFiles\wxBook.dir\src\Main.cpp.obj.provides

CMakeFiles\wxBook.dir\src\Main.cpp.obj.provides.build: CMakeFiles\wxBook.dir\src\Main.cpp.obj


# Object files for target wxBook
wxBook_OBJECTS = \
"CMakeFiles\wxBook.dir\src\Config.cpp.obj" \
"CMakeFiles\wxBook.dir\src\Main.cpp.obj"

# External object files for target wxBook
wxBook_EXTERNAL_OBJECTS =

wxBook.exe: CMakeFiles\wxBook.dir\src\Config.cpp.obj
wxBook.exe: CMakeFiles\wxBook.dir\src\Main.cpp.obj
wxBook.exe: CMakeFiles\wxBook.dir\build.make
wxBook.exe: CMakeFiles\wxBook.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Study\github\wxBook\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable wxBook.exe"
	"C:\Program Files\cmake-3.7.0-win64-x64\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\wxBook.dir --manifests  -- C:\PROGRA~2\MICROS~4\2017\COMMUN~1\VC\Tools\MSVC\1410~1.250\bin\HostX86\x86\link.exe /nologo @CMakeFiles\wxBook.dir\objects1.rsp @<<
 /out:wxBook.exe /implib:wxBook.lib /pdb:D:\Study\github\wxBook\build\wxBook.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\wxBook.dir\build: wxBook.exe

.PHONY : CMakeFiles\wxBook.dir\build

CMakeFiles\wxBook.dir\requires: CMakeFiles\wxBook.dir\src\Config.cpp.obj.requires
CMakeFiles\wxBook.dir\requires: CMakeFiles\wxBook.dir\src\Main.cpp.obj.requires

.PHONY : CMakeFiles\wxBook.dir\requires

CMakeFiles\wxBook.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\wxBook.dir\cmake_clean.cmake
.PHONY : CMakeFiles\wxBook.dir\clean

CMakeFiles\wxBook.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Study\github\wxBook\wxBook D:\Study\github\wxBook\wxBook D:\Study\github\wxBook\build D:\Study\github\wxBook\build D:\Study\github\wxBook\build\CMakeFiles\wxBook.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\wxBook.dir\depend

