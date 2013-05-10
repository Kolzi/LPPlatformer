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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1581688695/ImageManager.o \
	${OBJECTDIR}/src/Systems/RenderSystem.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/General/Level.o \
	${OBJECTDIR}/src/Components/BoundingBoxComponent.o \
	${OBJECTDIR}/src/General/SimpleIDGenerator.o \
	${OBJECTDIR}/src/Systems/MovementSystem.o \
	${OBJECTDIR}/src/Components/GravityComponent.o \
	${OBJECTDIR}/src/Components/ViewportComponent.o \
	${OBJECTDIR}/src/Components/Component.o \
	${OBJECTDIR}/src/General/Archetype.o \
	${OBJECTDIR}/src/Systems/CollisionSystem.o \
	${OBJECTDIR}/src/General/StringComponentConverter.o \
	${OBJECTDIR}/src/Components/CameraSourceComponent.o \
	${OBJECTDIR}/src/Components/PhysicsComponent.o \
	${OBJECTDIR}/src/Systems/GravitySystem.o \
	${OBJECTDIR}/src/Components/PositionComponent.o \
	${OBJECTDIR}/src/Systems/CameraSystem.o \
	${OBJECTDIR}/src/General/ArchetypesManager.o \
	${OBJECTDIR}/src/Systems/System.o \
	${OBJECTDIR}/src/Systems/PlayerInputSystem.o \
	${OBJECTDIR}/src/Components/SpriteComponent.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/platformer

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/platformer: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/platformer ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/1581688695/ImageManager.o: /home/marzena/NetBeansProjects/Platformer/src/General/ImageManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1581688695
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1581688695/ImageManager.o /home/marzena/NetBeansProjects/Platformer/src/General/ImageManager.cpp

${OBJECTDIR}/src/Systems/RenderSystem.o: src/Systems/RenderSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Systems
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Systems/RenderSystem.o src/Systems/RenderSystem.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/General/Level.o: src/General/Level.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/General
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/General/Level.o src/General/Level.cpp

${OBJECTDIR}/src/Components/BoundingBoxComponent.o: src/Components/BoundingBoxComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Components/BoundingBoxComponent.o src/Components/BoundingBoxComponent.cpp

${OBJECTDIR}/src/General/SimpleIDGenerator.o: src/General/SimpleIDGenerator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/General
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/General/SimpleIDGenerator.o src/General/SimpleIDGenerator.cpp

${OBJECTDIR}/src/Systems/MovementSystem.o: src/Systems/MovementSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Systems
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Systems/MovementSystem.o src/Systems/MovementSystem.cpp

${OBJECTDIR}/src/Components/GravityComponent.o: src/Components/GravityComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Components/GravityComponent.o src/Components/GravityComponent.cpp

${OBJECTDIR}/src/Components/ViewportComponent.o: src/Components/ViewportComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Components/ViewportComponent.o src/Components/ViewportComponent.cpp

${OBJECTDIR}/src/Components/Component.o: src/Components/Component.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Components/Component.o src/Components/Component.cpp

${OBJECTDIR}/src/General/Archetype.o: src/General/Archetype.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/General
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/General/Archetype.o src/General/Archetype.cpp

${OBJECTDIR}/src/Systems/CollisionSystem.o: src/Systems/CollisionSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Systems
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Systems/CollisionSystem.o src/Systems/CollisionSystem.cpp

${OBJECTDIR}/src/General/StringComponentConverter.o: src/General/StringComponentConverter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/General
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/General/StringComponentConverter.o src/General/StringComponentConverter.cpp

${OBJECTDIR}/src/Components/CameraSourceComponent.o: src/Components/CameraSourceComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Components/CameraSourceComponent.o src/Components/CameraSourceComponent.cpp

${OBJECTDIR}/src/Components/PhysicsComponent.o: src/Components/PhysicsComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Components/PhysicsComponent.o src/Components/PhysicsComponent.cpp

${OBJECTDIR}/src/Systems/GravitySystem.o: src/Systems/GravitySystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Systems
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Systems/GravitySystem.o src/Systems/GravitySystem.cpp

${OBJECTDIR}/src/Components/PositionComponent.o: src/Components/PositionComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Components/PositionComponent.o src/Components/PositionComponent.cpp

${OBJECTDIR}/src/Systems/CameraSystem.o: src/Systems/CameraSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Systems
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Systems/CameraSystem.o src/Systems/CameraSystem.cpp

${OBJECTDIR}/src/General/ArchetypesManager.o: src/General/ArchetypesManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/General
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/General/ArchetypesManager.o src/General/ArchetypesManager.cpp

${OBJECTDIR}/src/Systems/System.o: src/Systems/System.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Systems
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Systems/System.o src/Systems/System.cpp

${OBJECTDIR}/src/Systems/PlayerInputSystem.o: src/Systems/PlayerInputSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Systems
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Systems/PlayerInputSystem.o src/Systems/PlayerInputSystem.cpp

${OBJECTDIR}/src/Components/SpriteComponent.o: src/Components/SpriteComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Components/SpriteComponent.o src/Components/SpriteComponent.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/platformer

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
