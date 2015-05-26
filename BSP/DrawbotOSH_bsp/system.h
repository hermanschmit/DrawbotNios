/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_qsys' in SOPC Builder design 'c5g_qsys'
 * SOPC Builder design path: /home/herman/Documents/C5G_Designs/C5G_drawbot_2/c5g_qsys.sopcinfo
 *
 * Generated: Tue May 19 22:21:45 PDT 2015
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x20040820
#define ALT_CPU_CPU_FREQ 125000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1e
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x20020020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 125000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x1e
#define ALT_CPU_NAME "nios2_qsys"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_RESET_ADDR 0x20020000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x20040820
#define NIOS2_CPU_FREQ 125000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1e
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x20020020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x1e
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_RESET_ADDR 0x20020000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_MEM_IF_LPDDR2_EMIF
#define __ALTERA_NIOS2_QSYS


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone V"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_BASE 0x20041080
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x20041080
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x20041080
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "c5g_qsys"


/*
 * baseaddress configuration
 *
 */

#define ALT_MODULE_CLASS_baseaddress altera_avalon_pio
#define BASEADDRESS_BASE 0x20041090
#define BASEADDRESS_BIT_CLEARING_EDGE_REGISTER 0
#define BASEADDRESS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define BASEADDRESS_CAPTURE 0
#define BASEADDRESS_DATA_WIDTH 32
#define BASEADDRESS_DO_TEST_BENCH_WIRING 0
#define BASEADDRESS_DRIVEN_SIM_VALUE 0
#define BASEADDRESS_EDGE_TYPE "NONE"
#define BASEADDRESS_FREQ 125000000
#define BASEADDRESS_HAS_IN 0
#define BASEADDRESS_HAS_OUT 1
#define BASEADDRESS_HAS_TRI 0
#define BASEADDRESS_IRQ -1
#define BASEADDRESS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define BASEADDRESS_IRQ_TYPE "NONE"
#define BASEADDRESS_NAME "/dev/baseaddress"
#define BASEADDRESS_RESET_VALUE 0
#define BASEADDRESS_SPAN 16
#define BASEADDRESS_TYPE "altera_avalon_pio"


/*
 * drawbot configuration
 *
 */

#define ALT_MODULE_CLASS_drawbot altera_avalon_pio
#define DRAWBOT_BASE 0x20041020
#define DRAWBOT_BIT_CLEARING_EDGE_REGISTER 0
#define DRAWBOT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DRAWBOT_CAPTURE 0
#define DRAWBOT_DATA_WIDTH 7
#define DRAWBOT_DO_TEST_BENCH_WIRING 0
#define DRAWBOT_DRIVEN_SIM_VALUE 0
#define DRAWBOT_EDGE_TYPE "NONE"
#define DRAWBOT_FREQ 125000000
#define DRAWBOT_HAS_IN 0
#define DRAWBOT_HAS_OUT 1
#define DRAWBOT_HAS_TRI 0
#define DRAWBOT_IRQ -1
#define DRAWBOT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DRAWBOT_IRQ_TYPE "NONE"
#define DRAWBOT_NAME "/dev/drawbot"
#define DRAWBOT_RESET_VALUE 0
#define DRAWBOT_SPAN 16
#define DRAWBOT_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x20041080
#define JTAG_UART_IRQ 1
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * key configuration
 *
 */

#define ALT_MODULE_CLASS_key altera_avalon_pio
#define KEY_BASE 0x20041060
#define KEY_BIT_CLEARING_EDGE_REGISTER 0
#define KEY_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEY_CAPTURE 1
#define KEY_DATA_WIDTH 4
#define KEY_DO_TEST_BENCH_WIRING 0
#define KEY_DRIVEN_SIM_VALUE 0
#define KEY_EDGE_TYPE "RISING"
#define KEY_FREQ 125000000
#define KEY_HAS_IN 1
#define KEY_HAS_OUT 0
#define KEY_HAS_TRI 0
#define KEY_IRQ 2
#define KEY_IRQ_INTERRUPT_CONTROLLER_ID 0
#define KEY_IRQ_TYPE "EDGE"
#define KEY_NAME "/dev/key"
#define KEY_RESET_VALUE 0
#define KEY_SPAN 16
#define KEY_TYPE "altera_avalon_pio"


/*
 * ledg configuration
 *
 */

#define ALT_MODULE_CLASS_ledg altera_avalon_pio
#define LEDG_BASE 0x20041050
#define LEDG_BIT_CLEARING_EDGE_REGISTER 0
#define LEDG_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDG_CAPTURE 0
#define LEDG_DATA_WIDTH 8
#define LEDG_DO_TEST_BENCH_WIRING 0
#define LEDG_DRIVEN_SIM_VALUE 0
#define LEDG_EDGE_TYPE "NONE"
#define LEDG_FREQ 125000000
#define LEDG_HAS_IN 0
#define LEDG_HAS_OUT 1
#define LEDG_HAS_TRI 0
#define LEDG_IRQ -1
#define LEDG_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDG_IRQ_TYPE "NONE"
#define LEDG_NAME "/dev/ledg"
#define LEDG_RESET_VALUE 0
#define LEDG_SPAN 16
#define LEDG_TYPE "altera_avalon_pio"


/*
 * ledr configuration
 *
 */

#define ALT_MODULE_CLASS_ledr altera_avalon_pio
#define LEDR_BASE 0x20041030
#define LEDR_BIT_CLEARING_EDGE_REGISTER 0
#define LEDR_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDR_CAPTURE 0
#define LEDR_DATA_WIDTH 10
#define LEDR_DO_TEST_BENCH_WIRING 0
#define LEDR_DRIVEN_SIM_VALUE 0
#define LEDR_EDGE_TYPE "NONE"
#define LEDR_FREQ 125000000
#define LEDR_HAS_IN 0
#define LEDR_HAS_OUT 1
#define LEDR_HAS_TRI 0
#define LEDR_IRQ -1
#define LEDR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDR_IRQ_TYPE "NONE"
#define LEDR_NAME "/dev/ledr"
#define LEDR_RESET_VALUE 0
#define LEDR_SPAN 16
#define LEDR_TYPE "altera_avalon_pio"


/*
 * lpddr2_status configuration
 *
 */

#define ALT_MODULE_CLASS_lpddr2_status altera_avalon_pio
#define LPDDR2_STATUS_BASE 0x20041070
#define LPDDR2_STATUS_BIT_CLEARING_EDGE_REGISTER 0
#define LPDDR2_STATUS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LPDDR2_STATUS_CAPTURE 0
#define LPDDR2_STATUS_DATA_WIDTH 3
#define LPDDR2_STATUS_DO_TEST_BENCH_WIRING 0
#define LPDDR2_STATUS_DRIVEN_SIM_VALUE 0
#define LPDDR2_STATUS_EDGE_TYPE "NONE"
#define LPDDR2_STATUS_FREQ 125000000
#define LPDDR2_STATUS_HAS_IN 1
#define LPDDR2_STATUS_HAS_OUT 0
#define LPDDR2_STATUS_HAS_TRI 0
#define LPDDR2_STATUS_IRQ -1
#define LPDDR2_STATUS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LPDDR2_STATUS_IRQ_TYPE "NONE"
#define LPDDR2_STATUS_NAME "/dev/lpddr2_status"
#define LPDDR2_STATUS_RESET_VALUE 0
#define LPDDR2_STATUS_SPAN 16
#define LPDDR2_STATUS_TYPE "altera_avalon_pio"


/*
 * mem_if_lpddr2_emif configuration
 *
 */

#define ALT_MODULE_CLASS_mem_if_lpddr2_emif altera_mem_if_lpddr2_emif
#define MEM_IF_LPDDR2_EMIF_BASE 0x0
#define MEM_IF_LPDDR2_EMIF_IRQ -1
#define MEM_IF_LPDDR2_EMIF_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MEM_IF_LPDDR2_EMIF_NAME "/dev/mem_if_lpddr2_emif"
#define MEM_IF_LPDDR2_EMIF_SPAN 536870912
#define MEM_IF_LPDDR2_EMIF_TYPE "altera_mem_if_lpddr2_emif"


/*
 * onchip_memory2 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_BASE 0x20020000
#define ONCHIP_MEMORY2_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_DUAL_PORT 0
#define ONCHIP_MEMORY2_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_INIT_CONTENTS_FILE "c5g_qsys_onchip_memory2"
#define ONCHIP_MEMORY2_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_IRQ -1
#define ONCHIP_MEMORY2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_NAME "/dev/onchip_memory2"
#define ONCHIP_MEMORY2_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_SIZE_VALUE 128000
#define ONCHIP_MEMORY2_SPAN 128000
#define ONCHIP_MEMORY2_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_WRITABLE 1


/*
 * onchip_picture_mem1 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_picture_mem1 altera_avalon_onchip_memory2
#define ONCHIP_PICTURE_MEM1_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_PICTURE_MEM1_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_PICTURE_MEM1_BASE 0x30000000
#define ONCHIP_PICTURE_MEM1_CONTENTS_INFO ""
#define ONCHIP_PICTURE_MEM1_DUAL_PORT 0
#define ONCHIP_PICTURE_MEM1_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_PICTURE_MEM1_INIT_CONTENTS_FILE "c5g_qsys_onchip_picture_mem1"
#define ONCHIP_PICTURE_MEM1_INIT_MEM_CONTENT 0
#define ONCHIP_PICTURE_MEM1_INSTANCE_ID "NONE"
#define ONCHIP_PICTURE_MEM1_IRQ -1
#define ONCHIP_PICTURE_MEM1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_PICTURE_MEM1_NAME "/dev/onchip_picture_mem1"
#define ONCHIP_PICTURE_MEM1_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_PICTURE_MEM1_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_PICTURE_MEM1_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_PICTURE_MEM1_SINGLE_CLOCK_OP 0
#define ONCHIP_PICTURE_MEM1_SIZE_MULTIPLE 1
#define ONCHIP_PICTURE_MEM1_SIZE_VALUE 262144
#define ONCHIP_PICTURE_MEM1_SPAN 262144
#define ONCHIP_PICTURE_MEM1_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_PICTURE_MEM1_WRITABLE 1


/*
 * switch configuration
 *
 */

#define ALT_MODULE_CLASS_switch altera_avalon_pio
#define SWITCH_BASE 0x20041040
#define SWITCH_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCH_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCH_CAPTURE 1
#define SWITCH_DATA_WIDTH 10
#define SWITCH_DO_TEST_BENCH_WIRING 0
#define SWITCH_DRIVEN_SIM_VALUE 0
#define SWITCH_EDGE_TYPE "RISING"
#define SWITCH_FREQ 125000000
#define SWITCH_HAS_IN 1
#define SWITCH_HAS_OUT 0
#define SWITCH_HAS_TRI 0
#define SWITCH_IRQ -1
#define SWITCH_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SWITCH_IRQ_TYPE "NONE"
#define SWITCH_NAME "/dev/switch"
#define SWITCH_RESET_VALUE 0
#define SWITCH_SPAN 16
#define SWITCH_TYPE "altera_avalon_pio"


/*
 * sysid_qsys configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys altera_avalon_sysid_qsys
#define SYSID_QSYS_BASE 0x20041088
#define SYSID_QSYS_ID -1091581186
#define SYSID_QSYS_IRQ -1
#define SYSID_QSYS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_NAME "/dev/sysid_qsys"
#define SYSID_QSYS_SPAN 8
#define SYSID_QSYS_TIMESTAMP 1407900282
#define SYSID_QSYS_TYPE "altera_avalon_sysid_qsys"


/*
 * timer configuration
 *
 */

#define ALT_MODULE_CLASS_timer altera_avalon_timer
#define TIMER_ALWAYS_RUN 0
#define TIMER_BASE 0x20041000
#define TIMER_COUNTER_SIZE 32
#define TIMER_FIXED_PERIOD 0
#define TIMER_FREQ 125000000
#define TIMER_IRQ 0
#define TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_LOAD_VALUE 124999
#define TIMER_MULT 0.001
#define TIMER_NAME "/dev/timer"
#define TIMER_PERIOD 1
#define TIMER_PERIOD_UNITS "ms"
#define TIMER_RESET_OUTPUT 0
#define TIMER_SNAPSHOT 1
#define TIMER_SPAN 32
#define TIMER_TICKS_PER_SEC 1000.0
#define TIMER_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
