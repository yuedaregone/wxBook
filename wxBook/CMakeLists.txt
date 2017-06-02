cmake_minimum_required(VERSION 3.5)
#project name
project(wxBook)

#head file path
SET(INC $(WXWIN))
INCLUDE_DIRECTORIES( src $(INC) )

#source directory
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

#set environment variable
SET(WXBOOK ${DIR_SRCS})

#set extern libraries
#SET(LIBRARIES libm.so)

#add executable file
ADD_EXECUTABLE(wxBook ${WXBOOK})

#add link library
#TARGET_LINK_LIBRARIES(../Debug ${LIBRARIES})
