#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Buffer.o \
	${OBJECTDIR}/Control.o \
	${OBJECTDIR}/Data_Memory.o \
	${OBJECTDIR}/Double_Mux.o \
	${OBJECTDIR}/Instruction_Memory.o \
	${OBJECTDIR}/Mux.o \
	${OBJECTDIR}/Register_Memory.o \
	${OBJECTDIR}/Unknown.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/unknown.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/unknown.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/unknown ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Buffer.o: nbproject/Makefile-${CND_CONF}.mk Buffer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/Buffer.o Buffer.cpp

${OBJECTDIR}/Control.o: nbproject/Makefile-${CND_CONF}.mk Control.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/Control.o Control.cpp

${OBJECTDIR}/Data_Memory.o: nbproject/Makefile-${CND_CONF}.mk Data_Memory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/Data_Memory.o Data_Memory.cpp

${OBJECTDIR}/Double_Mux.o: nbproject/Makefile-${CND_CONF}.mk Double_Mux.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/Double_Mux.o Double_Mux.cpp

${OBJECTDIR}/Instruction_Memory.o: nbproject/Makefile-${CND_CONF}.mk Instruction_Memory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/Instruction_Memory.o Instruction_Memory.cpp

${OBJECTDIR}/Mux.o: nbproject/Makefile-${CND_CONF}.mk Mux.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/Mux.o Mux.cpp

${OBJECTDIR}/Register_Memory.o: nbproject/Makefile-${CND_CONF}.mk Register_Memory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/Register_Memory.o Register_Memory.cpp

${OBJECTDIR}/Unknown.o: nbproject/Makefile-${CND_CONF}.mk Unknown.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/Unknown.o Unknown.cpp

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/unknown.exe

# Subprojects
.clean-subprojects:
