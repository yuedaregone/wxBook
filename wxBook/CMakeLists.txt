cmake_minimum_required(VERSION 3.5)
#project name
project(wxBook)

#head file path
SET(WXINC ${WXWIN}/include ${WXWIN}/lib/vc_lib/mswud src)
INCLUDE_DIRECTORIES(${WXINC})

#source directory
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

#set environment variable
SET(WXBOOK ${DIR_SRCS})

#set extern libraries
SET(WXLIB ${WXWIN}/lib/vc_lib)
SET(LIBRARIES wxmsw30ud_core.lib wxbase30ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib wininet.lib)

#link path
LINK_DIRECTORIES(${WXLIB})

#add executable file
ADD_EXECUTABLE(wxBook ${WXBOOK})

SET_TARGET_PROPERTIES(wxBook PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:windows")

#add link library
TARGET_LINK_LIBRARIES(wxBook ${LIBRARIES})
