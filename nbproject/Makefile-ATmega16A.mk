#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-ATmega16A.mk)" "nbproject/Makefile-local-ATmega16A.mk"
include nbproject/Makefile-local-ATmega16A.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=ATmega16A
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/CallPoint.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/CallPoint.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/app.c src/Requests.c src/Events.c src/userSystem.c src/configuration.c src/PowerOn.c src/network.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/app.o ${OBJECTDIR}/src/Requests.o ${OBJECTDIR}/src/Events.o ${OBJECTDIR}/src/userSystem.o ${OBJECTDIR}/src/configuration.o ${OBJECTDIR}/src/PowerOn.o ${OBJECTDIR}/src/network.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/app.o.d ${OBJECTDIR}/src/Requests.o.d ${OBJECTDIR}/src/Events.o.d ${OBJECTDIR}/src/userSystem.o.d ${OBJECTDIR}/src/configuration.o.d ${OBJECTDIR}/src/PowerOn.o.d ${OBJECTDIR}/src/network.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/app.o ${OBJECTDIR}/src/Requests.o ${OBJECTDIR}/src/Events.o ${OBJECTDIR}/src/userSystem.o ${OBJECTDIR}/src/configuration.o ${OBJECTDIR}/src/PowerOn.o ${OBJECTDIR}/src/network.o

# Source Files
SOURCEFILES=src/app.c src/Requests.c src/Events.c src/userSystem.c src/configuration.c src/PowerOn.c src/network.c

# Pack Options 
PACK_COMPILER_OPTIONS=-I "${DFP_DIR}/include"
PACK_COMMON_OPTIONS=-B "${DFP_DIR}/gcc/dev/atmega16a"



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-ATmega16A.mk ${DISTDIR}/CallPoint.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega16A
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/app.o: src/app.c  .generated_files/flags/ATmega16A/17f249c160174cc486185b03e9af26ccef6cd30f .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/app.o.d 
	@${RM} ${OBJECTDIR}/src/app.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/app.o.d" -MT "${OBJECTDIR}/src/app.o.d" -MT ${OBJECTDIR}/src/app.o  -o ${OBJECTDIR}/src/app.o src/app.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/Requests.o: src/Requests.c  .generated_files/flags/ATmega16A/f9fbb87f844365ff09904111430be49a2dc40bcc .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/Requests.o.d 
	@${RM} ${OBJECTDIR}/src/Requests.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/Requests.o.d" -MT "${OBJECTDIR}/src/Requests.o.d" -MT ${OBJECTDIR}/src/Requests.o  -o ${OBJECTDIR}/src/Requests.o src/Requests.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/Events.o: src/Events.c  .generated_files/flags/ATmega16A/329afa862fd18fe3e6bcc4e33e77c785bfda30f9 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/Events.o.d 
	@${RM} ${OBJECTDIR}/src/Events.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/Events.o.d" -MT "${OBJECTDIR}/src/Events.o.d" -MT ${OBJECTDIR}/src/Events.o  -o ${OBJECTDIR}/src/Events.o src/Events.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/userSystem.o: src/userSystem.c  .generated_files/flags/ATmega16A/ed703b3d96180137c60d732e0e55220b41b508d6 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/userSystem.o.d 
	@${RM} ${OBJECTDIR}/src/userSystem.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/userSystem.o.d" -MT "${OBJECTDIR}/src/userSystem.o.d" -MT ${OBJECTDIR}/src/userSystem.o  -o ${OBJECTDIR}/src/userSystem.o src/userSystem.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/configuration.o: src/configuration.c  .generated_files/flags/ATmega16A/3ab790de600b342f8f542ab55024742040d46d59 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configuration.o.d 
	@${RM} ${OBJECTDIR}/src/configuration.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/configuration.o.d" -MT "${OBJECTDIR}/src/configuration.o.d" -MT ${OBJECTDIR}/src/configuration.o  -o ${OBJECTDIR}/src/configuration.o src/configuration.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/PowerOn.o: src/PowerOn.c  .generated_files/flags/ATmega16A/e4205e0660b4a230e298046b85dc82754c0bcb41 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/PowerOn.o.d 
	@${RM} ${OBJECTDIR}/src/PowerOn.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/PowerOn.o.d" -MT "${OBJECTDIR}/src/PowerOn.o.d" -MT ${OBJECTDIR}/src/PowerOn.o  -o ${OBJECTDIR}/src/PowerOn.o src/PowerOn.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/network.o: src/network.c  .generated_files/flags/ATmega16A/6976fe8d5bcc989fa7ca0d0efd883569adf80dff .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/network.o.d 
	@${RM} ${OBJECTDIR}/src/network.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/network.o.d" -MT "${OBJECTDIR}/src/network.o.d" -MT ${OBJECTDIR}/src/network.o  -o ${OBJECTDIR}/src/network.o src/network.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/src/app.o: src/app.c  .generated_files/flags/ATmega16A/1eac4d926432ca1bb71bc73fc65cd3a765e54f18 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/app.o.d 
	@${RM} ${OBJECTDIR}/src/app.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/app.o.d" -MT "${OBJECTDIR}/src/app.o.d" -MT ${OBJECTDIR}/src/app.o  -o ${OBJECTDIR}/src/app.o src/app.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/Requests.o: src/Requests.c  .generated_files/flags/ATmega16A/25d0646cb73215d082137d4d2536fc080f6beb8a .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/Requests.o.d 
	@${RM} ${OBJECTDIR}/src/Requests.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/Requests.o.d" -MT "${OBJECTDIR}/src/Requests.o.d" -MT ${OBJECTDIR}/src/Requests.o  -o ${OBJECTDIR}/src/Requests.o src/Requests.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/Events.o: src/Events.c  .generated_files/flags/ATmega16A/386d4b50bd458d601b27c3700424d48624b7bbe .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/Events.o.d 
	@${RM} ${OBJECTDIR}/src/Events.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/Events.o.d" -MT "${OBJECTDIR}/src/Events.o.d" -MT ${OBJECTDIR}/src/Events.o  -o ${OBJECTDIR}/src/Events.o src/Events.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/userSystem.o: src/userSystem.c  .generated_files/flags/ATmega16A/51fd834808fb67e2fa1ff9c1cd645858b924122 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/userSystem.o.d 
	@${RM} ${OBJECTDIR}/src/userSystem.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/userSystem.o.d" -MT "${OBJECTDIR}/src/userSystem.o.d" -MT ${OBJECTDIR}/src/userSystem.o  -o ${OBJECTDIR}/src/userSystem.o src/userSystem.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/configuration.o: src/configuration.c  .generated_files/flags/ATmega16A/362d39c1eb024d7e162e72c36fc9ddf42d523ff2 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configuration.o.d 
	@${RM} ${OBJECTDIR}/src/configuration.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/configuration.o.d" -MT "${OBJECTDIR}/src/configuration.o.d" -MT ${OBJECTDIR}/src/configuration.o  -o ${OBJECTDIR}/src/configuration.o src/configuration.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/PowerOn.o: src/PowerOn.c  .generated_files/flags/ATmega16A/78e79a1950dcc7d09e0c11edc375091530bcbd57 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/PowerOn.o.d 
	@${RM} ${OBJECTDIR}/src/PowerOn.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/PowerOn.o.d" -MT "${OBJECTDIR}/src/PowerOn.o.d" -MT ${OBJECTDIR}/src/PowerOn.o  -o ${OBJECTDIR}/src/PowerOn.o src/PowerOn.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/network.o: src/network.c  .generated_files/flags/ATmega16A/584cbeffcc49a1a0d2453b033371bc87e34a64a6 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/network.o.d 
	@${RM} ${OBJECTDIR}/src/network.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/network.o.d" -MT "${OBJECTDIR}/src/network.o.d" -MT ${OBJECTDIR}/src/network.o  -o ${OBJECTDIR}/src/network.o src/network.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/CallPoint.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  lib/mega2.X.a  
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega16a ${PACK_COMMON_OPTIONS}  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}\CallPoint.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/CallPoint.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    lib\mega2.X.a  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
${DISTDIR}/CallPoint.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  lib/mega2.X.a 
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega16a ${PACK_COMMON_OPTIONS}  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}\CallPoint.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/CallPoint.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    lib\mega2.X.a  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/CallPoint.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/CallPoint.X.${IMAGE_TYPE}.hex"
	
	
	
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
