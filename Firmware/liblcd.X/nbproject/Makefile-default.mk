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
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=a
DEBUGGABLE_SUFFIX=
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/liblcd.X.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=a
DEBUGGABLE_SUFFIX=
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/liblcd.X.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=delay_micros.c LCD_autoscroll.c LCD_begin.c LCD_blink.c LCD_clear.c LCD_command.c LCD_cursor.c LCD_display.c LCD_display_clock.c LCD_home.c LCD_Light.c LCD_noAutoscroll.c LCD_noBlink.c LCD_noCursor.c LCD_nodisplay.c LCD_pin_reset.c LCD_pulseE.c LCD_putchar.c LCD_putstr.c LCD_putstrPos.c LCD_send.c LCD_setCursor.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/delay_micros.o ${OBJECTDIR}/LCD_autoscroll.o ${OBJECTDIR}/LCD_begin.o ${OBJECTDIR}/LCD_blink.o ${OBJECTDIR}/LCD_clear.o ${OBJECTDIR}/LCD_command.o ${OBJECTDIR}/LCD_cursor.o ${OBJECTDIR}/LCD_display.o ${OBJECTDIR}/LCD_display_clock.o ${OBJECTDIR}/LCD_home.o ${OBJECTDIR}/LCD_Light.o ${OBJECTDIR}/LCD_noAutoscroll.o ${OBJECTDIR}/LCD_noBlink.o ${OBJECTDIR}/LCD_noCursor.o ${OBJECTDIR}/LCD_nodisplay.o ${OBJECTDIR}/LCD_pin_reset.o ${OBJECTDIR}/LCD_pulseE.o ${OBJECTDIR}/LCD_putchar.o ${OBJECTDIR}/LCD_putstr.o ${OBJECTDIR}/LCD_putstrPos.o ${OBJECTDIR}/LCD_send.o ${OBJECTDIR}/LCD_setCursor.o
POSSIBLE_DEPFILES=${OBJECTDIR}/delay_micros.o.d ${OBJECTDIR}/LCD_autoscroll.o.d ${OBJECTDIR}/LCD_begin.o.d ${OBJECTDIR}/LCD_blink.o.d ${OBJECTDIR}/LCD_clear.o.d ${OBJECTDIR}/LCD_command.o.d ${OBJECTDIR}/LCD_cursor.o.d ${OBJECTDIR}/LCD_display.o.d ${OBJECTDIR}/LCD_display_clock.o.d ${OBJECTDIR}/LCD_home.o.d ${OBJECTDIR}/LCD_Light.o.d ${OBJECTDIR}/LCD_noAutoscroll.o.d ${OBJECTDIR}/LCD_noBlink.o.d ${OBJECTDIR}/LCD_noCursor.o.d ${OBJECTDIR}/LCD_nodisplay.o.d ${OBJECTDIR}/LCD_pin_reset.o.d ${OBJECTDIR}/LCD_pulseE.o.d ${OBJECTDIR}/LCD_putchar.o.d ${OBJECTDIR}/LCD_putstr.o.d ${OBJECTDIR}/LCD_putstrPos.o.d ${OBJECTDIR}/LCD_send.o.d ${OBJECTDIR}/LCD_setCursor.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/delay_micros.o ${OBJECTDIR}/LCD_autoscroll.o ${OBJECTDIR}/LCD_begin.o ${OBJECTDIR}/LCD_blink.o ${OBJECTDIR}/LCD_clear.o ${OBJECTDIR}/LCD_command.o ${OBJECTDIR}/LCD_cursor.o ${OBJECTDIR}/LCD_display.o ${OBJECTDIR}/LCD_display_clock.o ${OBJECTDIR}/LCD_home.o ${OBJECTDIR}/LCD_Light.o ${OBJECTDIR}/LCD_noAutoscroll.o ${OBJECTDIR}/LCD_noBlink.o ${OBJECTDIR}/LCD_noCursor.o ${OBJECTDIR}/LCD_nodisplay.o ${OBJECTDIR}/LCD_pin_reset.o ${OBJECTDIR}/LCD_pulseE.o ${OBJECTDIR}/LCD_putchar.o ${OBJECTDIR}/LCD_putstr.o ${OBJECTDIR}/LCD_putstrPos.o ${OBJECTDIR}/LCD_send.o ${OBJECTDIR}/LCD_setCursor.o

# Source Files
SOURCEFILES=delay_micros.c LCD_autoscroll.c LCD_begin.c LCD_blink.c LCD_clear.c LCD_command.c LCD_cursor.c LCD_display.c LCD_display_clock.c LCD_home.c LCD_Light.c LCD_noAutoscroll.c LCD_noBlink.c LCD_noCursor.c LCD_nodisplay.c LCD_pin_reset.c LCD_pulseE.c LCD_putchar.c LCD_putstr.c LCD_putstrPos.c LCD_send.c LCD_setCursor.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/liblcd.X.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX340F512H
MP_LINKER_FILE_OPTION=
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
${OBJECTDIR}/delay_micros.o: delay_micros.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/delay_micros.o.d 
	@${RM} ${OBJECTDIR}/delay_micros.o 
	@${FIXDEPS} "${OBJECTDIR}/delay_micros.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/delay_micros.o.d" -o ${OBJECTDIR}/delay_micros.o delay_micros.c   
	
${OBJECTDIR}/LCD_autoscroll.o: LCD_autoscroll.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_autoscroll.o.d 
	@${RM} ${OBJECTDIR}/LCD_autoscroll.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_autoscroll.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_autoscroll.o.d" -o ${OBJECTDIR}/LCD_autoscroll.o LCD_autoscroll.c   
	
${OBJECTDIR}/LCD_begin.o: LCD_begin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_begin.o.d 
	@${RM} ${OBJECTDIR}/LCD_begin.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_begin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_begin.o.d" -o ${OBJECTDIR}/LCD_begin.o LCD_begin.c   
	
${OBJECTDIR}/LCD_blink.o: LCD_blink.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_blink.o.d 
	@${RM} ${OBJECTDIR}/LCD_blink.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_blink.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_blink.o.d" -o ${OBJECTDIR}/LCD_blink.o LCD_blink.c   
	
${OBJECTDIR}/LCD_clear.o: LCD_clear.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_clear.o.d 
	@${RM} ${OBJECTDIR}/LCD_clear.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_clear.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_clear.o.d" -o ${OBJECTDIR}/LCD_clear.o LCD_clear.c   
	
${OBJECTDIR}/LCD_command.o: LCD_command.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_command.o.d 
	@${RM} ${OBJECTDIR}/LCD_command.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_command.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_command.o.d" -o ${OBJECTDIR}/LCD_command.o LCD_command.c   
	
${OBJECTDIR}/LCD_cursor.o: LCD_cursor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_cursor.o.d 
	@${RM} ${OBJECTDIR}/LCD_cursor.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_cursor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_cursor.o.d" -o ${OBJECTDIR}/LCD_cursor.o LCD_cursor.c   
	
${OBJECTDIR}/LCD_display.o: LCD_display.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_display.o.d 
	@${RM} ${OBJECTDIR}/LCD_display.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_display.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_display.o.d" -o ${OBJECTDIR}/LCD_display.o LCD_display.c   
	
${OBJECTDIR}/LCD_display_clock.o: LCD_display_clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_display_clock.o.d 
	@${RM} ${OBJECTDIR}/LCD_display_clock.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_display_clock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_display_clock.o.d" -o ${OBJECTDIR}/LCD_display_clock.o LCD_display_clock.c   
	
${OBJECTDIR}/LCD_home.o: LCD_home.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_home.o.d 
	@${RM} ${OBJECTDIR}/LCD_home.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_home.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_home.o.d" -o ${OBJECTDIR}/LCD_home.o LCD_home.c   
	
${OBJECTDIR}/LCD_Light.o: LCD_Light.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_Light.o.d 
	@${RM} ${OBJECTDIR}/LCD_Light.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_Light.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_Light.o.d" -o ${OBJECTDIR}/LCD_Light.o LCD_Light.c   
	
${OBJECTDIR}/LCD_noAutoscroll.o: LCD_noAutoscroll.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_noAutoscroll.o.d 
	@${RM} ${OBJECTDIR}/LCD_noAutoscroll.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_noAutoscroll.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_noAutoscroll.o.d" -o ${OBJECTDIR}/LCD_noAutoscroll.o LCD_noAutoscroll.c   
	
${OBJECTDIR}/LCD_noBlink.o: LCD_noBlink.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_noBlink.o.d 
	@${RM} ${OBJECTDIR}/LCD_noBlink.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_noBlink.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_noBlink.o.d" -o ${OBJECTDIR}/LCD_noBlink.o LCD_noBlink.c   
	
${OBJECTDIR}/LCD_noCursor.o: LCD_noCursor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_noCursor.o.d 
	@${RM} ${OBJECTDIR}/LCD_noCursor.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_noCursor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_noCursor.o.d" -o ${OBJECTDIR}/LCD_noCursor.o LCD_noCursor.c   
	
${OBJECTDIR}/LCD_nodisplay.o: LCD_nodisplay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_nodisplay.o.d 
	@${RM} ${OBJECTDIR}/LCD_nodisplay.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_nodisplay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_nodisplay.o.d" -o ${OBJECTDIR}/LCD_nodisplay.o LCD_nodisplay.c   
	
${OBJECTDIR}/LCD_pin_reset.o: LCD_pin_reset.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_pin_reset.o.d 
	@${RM} ${OBJECTDIR}/LCD_pin_reset.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_pin_reset.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_pin_reset.o.d" -o ${OBJECTDIR}/LCD_pin_reset.o LCD_pin_reset.c   
	
${OBJECTDIR}/LCD_pulseE.o: LCD_pulseE.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_pulseE.o.d 
	@${RM} ${OBJECTDIR}/LCD_pulseE.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_pulseE.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_pulseE.o.d" -o ${OBJECTDIR}/LCD_pulseE.o LCD_pulseE.c   
	
${OBJECTDIR}/LCD_putchar.o: LCD_putchar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_putchar.o.d 
	@${RM} ${OBJECTDIR}/LCD_putchar.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_putchar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_putchar.o.d" -o ${OBJECTDIR}/LCD_putchar.o LCD_putchar.c   
	
${OBJECTDIR}/LCD_putstr.o: LCD_putstr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_putstr.o.d 
	@${RM} ${OBJECTDIR}/LCD_putstr.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_putstr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_putstr.o.d" -o ${OBJECTDIR}/LCD_putstr.o LCD_putstr.c   
	
${OBJECTDIR}/LCD_putstrPos.o: LCD_putstrPos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_putstrPos.o.d 
	@${RM} ${OBJECTDIR}/LCD_putstrPos.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_putstrPos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_putstrPos.o.d" -o ${OBJECTDIR}/LCD_putstrPos.o LCD_putstrPos.c   
	
${OBJECTDIR}/LCD_send.o: LCD_send.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_send.o.d 
	@${RM} ${OBJECTDIR}/LCD_send.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_send.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_send.o.d" -o ${OBJECTDIR}/LCD_send.o LCD_send.c   
	
${OBJECTDIR}/LCD_setCursor.o: LCD_setCursor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_setCursor.o.d 
	@${RM} ${OBJECTDIR}/LCD_setCursor.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_setCursor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_setCursor.o.d" -o ${OBJECTDIR}/LCD_setCursor.o LCD_setCursor.c   
	
else
${OBJECTDIR}/delay_micros.o: delay_micros.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/delay_micros.o.d 
	@${RM} ${OBJECTDIR}/delay_micros.o 
	@${FIXDEPS} "${OBJECTDIR}/delay_micros.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/delay_micros.o.d" -o ${OBJECTDIR}/delay_micros.o delay_micros.c   
	
${OBJECTDIR}/LCD_autoscroll.o: LCD_autoscroll.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_autoscroll.o.d 
	@${RM} ${OBJECTDIR}/LCD_autoscroll.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_autoscroll.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_autoscroll.o.d" -o ${OBJECTDIR}/LCD_autoscroll.o LCD_autoscroll.c   
	
${OBJECTDIR}/LCD_begin.o: LCD_begin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_begin.o.d 
	@${RM} ${OBJECTDIR}/LCD_begin.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_begin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_begin.o.d" -o ${OBJECTDIR}/LCD_begin.o LCD_begin.c   
	
${OBJECTDIR}/LCD_blink.o: LCD_blink.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_blink.o.d 
	@${RM} ${OBJECTDIR}/LCD_blink.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_blink.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_blink.o.d" -o ${OBJECTDIR}/LCD_blink.o LCD_blink.c   
	
${OBJECTDIR}/LCD_clear.o: LCD_clear.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_clear.o.d 
	@${RM} ${OBJECTDIR}/LCD_clear.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_clear.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_clear.o.d" -o ${OBJECTDIR}/LCD_clear.o LCD_clear.c   
	
${OBJECTDIR}/LCD_command.o: LCD_command.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_command.o.d 
	@${RM} ${OBJECTDIR}/LCD_command.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_command.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_command.o.d" -o ${OBJECTDIR}/LCD_command.o LCD_command.c   
	
${OBJECTDIR}/LCD_cursor.o: LCD_cursor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_cursor.o.d 
	@${RM} ${OBJECTDIR}/LCD_cursor.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_cursor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_cursor.o.d" -o ${OBJECTDIR}/LCD_cursor.o LCD_cursor.c   
	
${OBJECTDIR}/LCD_display.o: LCD_display.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_display.o.d 
	@${RM} ${OBJECTDIR}/LCD_display.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_display.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_display.o.d" -o ${OBJECTDIR}/LCD_display.o LCD_display.c   
	
${OBJECTDIR}/LCD_display_clock.o: LCD_display_clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_display_clock.o.d 
	@${RM} ${OBJECTDIR}/LCD_display_clock.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_display_clock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_display_clock.o.d" -o ${OBJECTDIR}/LCD_display_clock.o LCD_display_clock.c   
	
${OBJECTDIR}/LCD_home.o: LCD_home.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_home.o.d 
	@${RM} ${OBJECTDIR}/LCD_home.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_home.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_home.o.d" -o ${OBJECTDIR}/LCD_home.o LCD_home.c   
	
${OBJECTDIR}/LCD_Light.o: LCD_Light.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_Light.o.d 
	@${RM} ${OBJECTDIR}/LCD_Light.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_Light.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_Light.o.d" -o ${OBJECTDIR}/LCD_Light.o LCD_Light.c   
	
${OBJECTDIR}/LCD_noAutoscroll.o: LCD_noAutoscroll.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_noAutoscroll.o.d 
	@${RM} ${OBJECTDIR}/LCD_noAutoscroll.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_noAutoscroll.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_noAutoscroll.o.d" -o ${OBJECTDIR}/LCD_noAutoscroll.o LCD_noAutoscroll.c   
	
${OBJECTDIR}/LCD_noBlink.o: LCD_noBlink.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_noBlink.o.d 
	@${RM} ${OBJECTDIR}/LCD_noBlink.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_noBlink.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_noBlink.o.d" -o ${OBJECTDIR}/LCD_noBlink.o LCD_noBlink.c   
	
${OBJECTDIR}/LCD_noCursor.o: LCD_noCursor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_noCursor.o.d 
	@${RM} ${OBJECTDIR}/LCD_noCursor.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_noCursor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_noCursor.o.d" -o ${OBJECTDIR}/LCD_noCursor.o LCD_noCursor.c   
	
${OBJECTDIR}/LCD_nodisplay.o: LCD_nodisplay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_nodisplay.o.d 
	@${RM} ${OBJECTDIR}/LCD_nodisplay.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_nodisplay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_nodisplay.o.d" -o ${OBJECTDIR}/LCD_nodisplay.o LCD_nodisplay.c   
	
${OBJECTDIR}/LCD_pin_reset.o: LCD_pin_reset.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_pin_reset.o.d 
	@${RM} ${OBJECTDIR}/LCD_pin_reset.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_pin_reset.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_pin_reset.o.d" -o ${OBJECTDIR}/LCD_pin_reset.o LCD_pin_reset.c   
	
${OBJECTDIR}/LCD_pulseE.o: LCD_pulseE.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_pulseE.o.d 
	@${RM} ${OBJECTDIR}/LCD_pulseE.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_pulseE.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_pulseE.o.d" -o ${OBJECTDIR}/LCD_pulseE.o LCD_pulseE.c   
	
${OBJECTDIR}/LCD_putchar.o: LCD_putchar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_putchar.o.d 
	@${RM} ${OBJECTDIR}/LCD_putchar.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_putchar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_putchar.o.d" -o ${OBJECTDIR}/LCD_putchar.o LCD_putchar.c   
	
${OBJECTDIR}/LCD_putstr.o: LCD_putstr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_putstr.o.d 
	@${RM} ${OBJECTDIR}/LCD_putstr.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_putstr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_putstr.o.d" -o ${OBJECTDIR}/LCD_putstr.o LCD_putstr.c   
	
${OBJECTDIR}/LCD_putstrPos.o: LCD_putstrPos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_putstrPos.o.d 
	@${RM} ${OBJECTDIR}/LCD_putstrPos.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_putstrPos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_putstrPos.o.d" -o ${OBJECTDIR}/LCD_putstrPos.o LCD_putstrPos.c   
	
${OBJECTDIR}/LCD_send.o: LCD_send.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_send.o.d 
	@${RM} ${OBJECTDIR}/LCD_send.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_send.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_send.o.d" -o ${OBJECTDIR}/LCD_send.o LCD_send.c   
	
${OBJECTDIR}/LCD_setCursor.o: LCD_setCursor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_setCursor.o.d 
	@${RM} ${OBJECTDIR}/LCD_setCursor.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD_setCursor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCD_setCursor.o.d" -o ${OBJECTDIR}/LCD_setCursor.o LCD_setCursor.c   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: archive
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/liblcd.X.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_AR} $(MP_EXTRA_AR_PRE) r dist/${CND_CONF}/${IMAGE_TYPE}/liblcd.X.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    
else
dist/${CND_CONF}/${IMAGE_TYPE}/liblcd.X.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_AR} $(MP_EXTRA_AR_PRE) r dist/${CND_CONF}/${IMAGE_TYPE}/liblcd.X.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
