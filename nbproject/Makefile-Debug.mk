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
	${OBJECTDIR}/src/animation/Animation_Test.o \
	${OBJECTDIR}/src/audio/Audio.o \
	${OBJECTDIR}/src/core/GameManager.o \
	${OBJECTDIR}/src/core/LevelGrid.o \
	${OBJECTDIR}/src/core/main.o \
	${OBJECTDIR}/src/gameplay/Level.o \
	${OBJECTDIR}/src/misc/DS_Grid.o


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
LDLIBSOPTIONS=-Llib -lmingw32 -lSDLmain -lSDL.dll -lSDL_ttf -lSDL_image -lSDL_mixer

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gteamproject.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gteamproject.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gteamproject ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/animation/Animation_Test.o: src/animation/Animation_Test.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/animation
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/animation/Animation_Test.o src/animation/Animation_Test.cpp

${OBJECTDIR}/src/audio/Audio.o: src/audio/Audio.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/audio
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/audio/Audio.o src/audio/Audio.cpp

${OBJECTDIR}/src/core/GameManager.o: src/core/GameManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/GameManager.o src/core/GameManager.cpp

${OBJECTDIR}/src/core/LevelGrid.o: src/core/LevelGrid.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/LevelGrid.o src/core/LevelGrid.cpp

${OBJECTDIR}/src/core/main.o: src/core/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/main.o src/core/main.cpp

${OBJECTDIR}/src/gameplay/Level.o: src/gameplay/Level.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/gameplay
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/gameplay/Level.o src/gameplay/Level.cpp

${OBJECTDIR}/src/misc/DS_Grid.o: src/misc/DS_Grid.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/misc
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/misc/DS_Grid.o src/misc/DS_Grid.cpp

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
