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
	${OBJECTDIR}/src/Armor.o \
	${OBJECTDIR}/src/AudioManager.o \
	${OBJECTDIR}/src/Boss.o \
	${OBJECTDIR}/src/Editor.o \
	${OBJECTDIR}/src/Enemy.o \
	${OBJECTDIR}/src/FirstAid.o \
	${OBJECTDIR}/src/Game.o \
	${OBJECTDIR}/src/Ghost.o \
	${OBJECTDIR}/src/Global.o \
	${OBJECTDIR}/src/Knife.o \
	${OBJECTDIR}/src/Level.o \
	${OBJECTDIR}/src/MapGrid.o \
	${OBJECTDIR}/src/Pistol.o \
	${OBJECTDIR}/src/Player.o \
	${OBJECTDIR}/src/Shotgun.o \
	${OBJECTDIR}/src/Sword.o \
	${OBJECTDIR}/src/UI_View.o \
	${OBJECTDIR}/src/ViewManager.o \
	${OBJECTDIR}/src/main.o


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
LDLIBSOPTIONS=-L/C\MinGW\lib -lmingw32 -lSDLmain -lSDL.dll -lSDL_image -lSDL_mixer -lSDL_ttf

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gteamproject.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gteamproject.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gteamproject ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Application.o: src/Application.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Application.o src/Application.cpp

${OBJECTDIR}/src/Armor.o: src/Armor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Armor.o src/Armor.cpp

${OBJECTDIR}/src/AudioManager.o: src/AudioManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/AudioManager.o src/AudioManager.cpp

${OBJECTDIR}/src/Boss.o: src/Boss.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Boss.o src/Boss.cpp

${OBJECTDIR}/src/Editor.o: src/Editor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Editor.o src/Editor.cpp

${OBJECTDIR}/src/Enemy.o: src/Enemy.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Enemy.o src/Enemy.cpp

${OBJECTDIR}/src/FirstAid.o: src/FirstAid.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/FirstAid.o src/FirstAid.cpp

${OBJECTDIR}/src/Game.o: src/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Game.o src/Game.cpp

${OBJECTDIR}/src/Ghost.o: src/Ghost.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Ghost.o src/Ghost.cpp

${OBJECTDIR}/src/Global.o: src/Global.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Global.o src/Global.cpp

${OBJECTDIR}/src/Knife.o: src/Knife.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Knife.o src/Knife.cpp

${OBJECTDIR}/src/Level.o: src/Level.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Level.o src/Level.cpp

${OBJECTDIR}/src/MapGrid.o: src/MapGrid.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/MapGrid.o src/MapGrid.cpp

${OBJECTDIR}/src/Pistol.o: src/Pistol.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Pistol.o src/Pistol.cpp

${OBJECTDIR}/src/Player.o: src/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Player.o src/Player.cpp

${OBJECTDIR}/src/Shotgun.o: src/Shotgun.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Shotgun.o src/Shotgun.cpp

${OBJECTDIR}/src/Sword.o: src/Sword.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sword.o src/Sword.cpp

${OBJECTDIR}/src/UI_View.o: src/UI_View.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/UI_View.o src/UI_View.cpp

${OBJECTDIR}/src/ViewManager.o: src/ViewManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/ViewManager.o src/ViewManager.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -I/C\MinGW\include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main.o src/main.cpp

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
