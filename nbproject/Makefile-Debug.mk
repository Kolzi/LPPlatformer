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
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/Components/BoundingBoxComponent.o \
	${OBJECTDIR}/src/Components/CameraSourceComponent.o \
	${OBJECTDIR}/src/Components/Component.o \
	${OBJECTDIR}/src/Components/GravityComponent.o \
	${OBJECTDIR}/src/Components/PhysicsComponent.o \
	${OBJECTDIR}/src/Components/PositionComponent.o \
	${OBJECTDIR}/src/Components/SpriteComponent.o \
	${OBJECTDIR}/src/Components/ViewportComponent.o \
	${OBJECTDIR}/src/Systems/CameraSystem.o \
	${OBJECTDIR}/src/Systems/CollisionSystem.o \
	${OBJECTDIR}/src/Systems/GravitySystem.o \
	${OBJECTDIR}/src/Systems/MovementSystem.o \
	${OBJECTDIR}/src/Systems/PlayerInputSystem.o \
	${OBJECTDIR}/src/Systems/RenderSystem.o \
	${OBJECTDIR}/src/Systems/System.o


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
LDLIBSOPTIONS=-lsfml-graphics -lsfml-window -lsfml-system

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lpplatformer

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lpplatformer: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lpplatformer ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/Components/BoundingBoxComponent.o: src/Components/BoundingBoxComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Components/BoundingBoxComponent.o src/Components/BoundingBoxComponent.cpp

${OBJECTDIR}/src/Components/CameraSourceComponent.o: src/Components/CameraSourceComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Components/CameraSourceComponent.o src/Components/CameraSourceComponent.cpp

${OBJECTDIR}/src/Components/Component.o: src/Components/Component.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Components/Component.o src/Components/Component.cpp

${OBJECTDIR}/src/Components/GravityComponent.o: src/Components/GravityComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Components/GravityComponent.o src/Components/GravityComponent.cpp

${OBJECTDIR}/src/Components/PhysicsComponent.o: src/Components/PhysicsComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Components/PhysicsComponent.o src/Components/PhysicsComponent.cpp

${OBJECTDIR}/src/Components/PositionComponent.o: src/Components/PositionComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Components/PositionComponent.o src/Components/PositionComponent.cpp

${OBJECTDIR}/src/Components/SpriteComponent.o: src/Components/SpriteComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Components/SpriteComponent.o src/Components/SpriteComponent.cpp

${OBJECTDIR}/src/Components/ViewportComponent.o: src/Components/ViewportComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Components/ViewportComponent.o src/Components/ViewportComponent.cpp

${OBJECTDIR}/src/Systems/CameraSystem.o: src/Systems/CameraSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Systems
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Systems/CameraSystem.o src/Systems/CameraSystem.cpp

${OBJECTDIR}/src/Systems/CollisionSystem.o: src/Systems/CollisionSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Systems
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Systems/CollisionSystem.o src/Systems/CollisionSystem.cpp

${OBJECTDIR}/src/Systems/GravitySystem.o: src/Systems/GravitySystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Systems
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Systems/GravitySystem.o src/Systems/GravitySystem.cpp

${OBJECTDIR}/src/Systems/MovementSystem.o: src/Systems/MovementSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Systems
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Systems/MovementSystem.o src/Systems/MovementSystem.cpp

${OBJECTDIR}/src/Systems/PlayerInputSystem.o: src/Systems/PlayerInputSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Systems
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Systems/PlayerInputSystem.o src/Systems/PlayerInputSystem.cpp

${OBJECTDIR}/src/Systems/RenderSystem.o: src/Systems/RenderSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Systems
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Systems/RenderSystem.o src/Systems/RenderSystem.cpp

${OBJECTDIR}/src/Systems/System.o: src/Systems/System.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Systems
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Systems/System.o src/Systems/System.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lpplatformer

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
