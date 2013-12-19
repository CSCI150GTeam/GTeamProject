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
CND_PLATFORM=MinGW-Windows
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
	${OBJECTDIR}/src/Application.o \
	${OBJECTDIR}/src/Editor.o \
	${OBJECTDIR}/src/Enemy.o \
	${OBJECTDIR}/src/Game.o \
	${OBJECTDIR}/src/Global.o \
	${OBJECTDIR}/src/Grid.o \
	${OBJECTDIR}/src/Level.o \
	${OBJECTDIR}/src/Menu.o \
	${OBJECTDIR}/src/Player.o \
	${OBJECTDIR}/src/Projectile.o \
	${OBJECTDIR}/src/Timer.o \
	${OBJECTDIR}/src/Utility.o \
	${OBJECTDIR}/src/command.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/multiLoop.o \
	${OBJECTDIR}/src/net.o


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
LDLIBSOPTIONS=-L/C\MinGW\lib -lmingw32 -lSDLmain -lSDL.dll -lSDL_image -lSDL_mixer -lSDL_ttf -lws2_32

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gteamproject.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gteamproject.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gteamproject ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Application.o: src/Application.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Application.o src/Application.cpp

${OBJECTDIR}/src/Editor.o: src/Editor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Editor.o src/Editor.cpp

${OBJECTDIR}/src/Enemy.o: src/Enemy.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Enemy.o src/Enemy.cpp

${OBJECTDIR}/src/Game.o: src/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Game.o src/Game.cpp

${OBJECTDIR}/src/Global.o: src/Global.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Global.o src/Global.cpp

${OBJECTDIR}/src/Grid.o: src/Grid.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Grid.o src/Grid.cpp

${OBJECTDIR}/src/Level.o: src/Level.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Level.o src/Level.cpp

${OBJECTDIR}/src/Menu.o: src/Menu.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Menu.o src/Menu.cpp

${OBJECTDIR}/src/Player.o: src/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Player.o src/Player.cpp

${OBJECTDIR}/src/Projectile.o: src/Projectile.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Projectile.o src/Projectile.cpp

${OBJECTDIR}/src/Timer.o: src/Timer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Timer.o src/Timer.cpp

${OBJECTDIR}/src/Utility.o: src/Utility.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Utility.o src/Utility.cpp

${OBJECTDIR}/src/command.o: src/command.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/command.o src/command.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/multiLoop.o: src/multiLoop.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/multiLoop.o src/multiLoop.cpp

${OBJECTDIR}/src/net.o: src/net.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -w -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/net.o src/net.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gteamproject.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
