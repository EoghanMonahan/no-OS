/***************************************************************************//**
 *   @file   main.c
 *   @brief  Main file for Mbed platform of ad74416h project.
 *   @author Antoniu Miclaus (antoniu.miclaus@analog.com)
********************************************************************************
 * Copyright 2023(c) Analog Devices, Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  - Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  - Neither the name of Analog Devices, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *  - The use of this software may or may not infringe the patent rights
 *    of one or more patent holders.  This license does not release you
 *    from the requirement that you obtain separate licenses from these
 *    patent holders to use this software.
 *  - Use of the software either in source or binary form, must be run
 *    on or directly connected to an Analog Devices Inc. component.
 *
 * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

/******************************************************************************/
/***************************** Include Files **********************************/
/******************************************************************************/
#include "platform_includes.h"
#include "common_data.h"

#ifdef BASIC_EXAMPLE
#include "basic_example.h"
#endif

#ifdef TEST_EXAMPLE
#include "test_example.h"
#endif

#ifdef VOLTAGE_OUTPUT_EXAMPLE
#include "voltage_output.h"
#endif

#ifdef CURRENT_OUTPUT_EXAMPLE
#include "current_output.h"
#endif

#ifdef VOLTAGE_INPUT_EXAMPLE
#include "voltage_input.h"
#endif

#ifdef CURRENT_INPUT_EXT_EXAMPLE
#include "current_input_ext.h"
#endif

#ifdef CURRENT_INPUT_LOOP_EXAMPLE
#include "current_input_loop.h"
#endif

#ifdef MULTIPLE_DEVICES_EXAMPLE
#include "multiple_devices.h"
#endif

#ifdef DIGITAL_INPUT_LOGIC_EXAMPLE
#include "digital_input_logic.h"
#endif

#ifdef DIGITAL_INPUT_LOOP_EXAMPLE
#include "digital_input_loop.h"
#endif

#ifdef DIGITAL_OUTPUT_EXAMPLE
#include "digital_output.h"
#endif

#ifdef TEMPERATURE_2WIRE_RTD_EXAMPLE
#include "temperature_2wire_rtd.h"
#endif

#ifdef VOLTAGE_INPUT_IRQ_EXAMPLE
#include "voltage_input_irq.h"
#endif

#ifdef HART_EXAMPLE
#include "hart.h"
#endif


/***************************************************************************//**
 * @brief Main function for Mbed platform.
 *
 * @return ret - Result of the enabled examples.
*******************************************************************************/

int main()
{
	int ret;
	ad74416h_ip.spi_ip = ad74416h_spi_ip;
	ad74416h_ad1_ip.spi_ip = ad74416h_spi_ip;
	ad74416h_ad2_ip.spi_ip = ad74416h_spi_ip;
	ad74416h_ad3_ip.spi_ip = ad74416h_spi_ip;

#ifdef BASIC_EXAMPLE
	struct no_os_uart_desc* uart;
	ret = no_os_uart_init(&uart, &ad74416h_uart_ip);
	if (ret) {
		no_os_uart_remove(uart);
		return ret;
	}
	no_os_uart_stdio(uart);
	ret = basic_example_main();
	if (ret) {
		no_os_uart_remove(uart);
		return ret;
	}
#endif

#ifdef TEST_EXAMPLE
	struct no_os_uart_desc* uart;
	ret = no_os_uart_init(&uart, &ad74416h_uart_ip);
	if (ret) {
		no_os_uart_remove(uart);
		return ret;
	}
	no_os_uart_stdio(uart);
	ret = test_example_main();
	if (ret) {
		no_os_uart_remove(uart);
		return ret;
	}
#endif


#ifdef VOLTAGE_OUTPUT_EXAMPLE
	struct no_os_uart_desc* uart;
	ret = no_os_uart_init(&uart, &ad74416h_uart_ip);
	if (ret) {
		no_os_uart_remove(uart);
		return ret;
	}
	no_os_uart_stdio(uart);
	ret = voltage_output_example_main();
	if (ret) {
		no_os_uart_remove(uart);
		return ret;
	}
#endif

#ifdef CURRENT_OUTPUT_EXAMPLE
	struct no_os_uart_desc* uart;
	ret = no_os_uart_init(&uart, &ad74416h_uart_ip);
	if (ret) {
		no_os_uart_remove(uart);
		return ret;
	}
	no_os_uart_stdio(uart);
	ret = current_output_example_main();
	if (ret) {
		no_os_uart_remove(uart);
		return ret;
	}
#endif

#ifdef VOLTAGE_INPUT_EXAMPLE
	struct no_os_uart_desc* uart;
	ret = no_os_uart_init(&uart, &ad74416h_uart_ip);
	if(ret) {
		no_os_uart_remove(uart);
		return ret;
	}
	no_os_uart_stdio(uart);
	ret = voltage_input_example_main();
	if (ret) {
		no_os_uart_remove(uart);
		return ret;
	}
#endif

#ifdef CURRENT_INPUT_EXT_EXAMPLE
        struct no_os_uart_desc* uart;
        ret = no_os_uart_init(&uart, &ad74416h_uart_ip);
        if(ret) {
                no_os_uart_remove(uart);
                return ret;
        }
        no_os_uart_stdio(uart);
        ret = current_input_ext_example_main();
        if (ret) {
                no_os_uart_remove(uart);
                return ret;
        }
#endif

#ifdef MULTIPLE_DEVICES_EXAMPLE
        struct no_os_uart_desc* uart;
        ret = no_os_uart_init(&uart, &ad74416h_uart_ip);
        if(ret) {
                no_os_uart_remove(uart);
                return ret;
        }
        no_os_uart_stdio(uart);
        ret = multiple_devices_example_main();
        if (ret) {
                no_os_uart_remove(uart);
                return ret;
        }
#endif

#ifdef CURRENT_INPUT_LOOP_EXAMPLE
        struct no_os_uart_desc* uart;
        ret = no_os_uart_init(&uart, &ad74416h_uart_ip);
        if(ret) {
                no_os_uart_remove(uart);
                return ret;
        }
        no_os_uart_stdio(uart);
        ret = current_input_loop_example_main();
        if (ret) {
                no_os_uart_remove(uart);
                return ret;
        }
#endif

#ifdef DIGITAL_INPUT_LOGIC_EXAMPLE
        struct no_os_uart_desc* uart;
        ret = no_os_uart_init(&uart, &ad74416h_uart_ip);
        if(ret) {
                no_os_uart_remove(uart);
                return ret;
        }
        no_os_uart_stdio(uart);
        ret = digital_input_logic_example_main();
        if (ret) {
                no_os_uart_remove(uart);
                return ret;
        }
#endif

#ifdef DIGITAL_INPUT_LOOP_EXAMPLE
        struct no_os_uart_desc* uart;
        ret = no_os_uart_init(&uart, &ad74416h_uart_ip);
        if(ret) {
                no_os_uart_remove(uart);
                return ret;
        }
        no_os_uart_stdio(uart);
        ret = digital_input_loop_example_main();
        if (ret) {
                no_os_uart_remove(uart);
                return ret;
        }
#endif

#ifdef DIGITAL_OUTPUT_EXAMPLE
        struct no_os_uart_desc* uart;
        ret = no_os_uart_init(&uart, &ad74416h_uart_ip);
        if(ret) {
                no_os_uart_remove(uart);
                return ret;
        }
        no_os_uart_stdio(uart);
        ret = digital_output_example_main();
        if (ret) {
                no_os_uart_remove(uart);
                return ret;
        }
#endif


#ifdef TEMPERATURE_2WIRE_RTD_EXAMPLE
        struct no_os_uart_desc* uart;
        ret = no_os_uart_init(&uart, &ad74416h_uart_ip);
        if(ret) {
                no_os_uart_remove(uart);
                return ret;
        }
        no_os_uart_stdio(uart);
        ret = temperature_2wire_rtd_example_main();
        if (ret) {
                no_os_uart_remove(uart);
                return ret;
        }
#endif

#ifdef TEMPERATURE_3WIRE_RTD_EXAMPLE
        struct no_os_uart_desc* uart;
        ret = no_os_uart_init(&uart, &ad74416h_uart_ip);
        if(ret) {
                no_os_uart_remove(uart);
                return ret;
        }
        no_os_uart_stdio(uart);
        ret = temperature_3wire_rtd_example_main();
        if (ret) {
                no_os_uart_remove(uart);
                return ret;
        }
#endif

#ifdef VOLTAGE_INPUT_IRQ_EXAMPLE
        struct no_os_uart_desc* uart;
        ret = no_os_uart_init(&uart, &ad74416h_uart_ip);
        if(ret) {
                no_os_uart_remove(uart);
                return ret;
        }
        no_os_uart_stdio(uart);
        ret = voltage_input_irq_example_main();
        if (ret) {
                no_os_uart_remove(uart);
                return ret;
        }
#endif

#ifdef HART_EXAMPLE
	struct no_os_uart_desc* uart;
	ret = no_os_uart_init(&uart, &ad74416h_uart_ip);
	if (ret) {
		no_os_uart_remove(uart);
		return ret;
	}
	no_os_uart_stdio(uart);
	ret = hart_example_main();
	if (ret) {
		no_os_uart_remove(uart);
		return ret;
	}
#endif



#if (VOLTAGE_OUTPUT_EXAMPLE+BASIC_EXAMPLE+TEST_EXAMPLE+CURRENT_OUTPUT_EXAMPLE+VOLTAGE_INPUT_EXAMPLE+CURRENT_INPUT_EXT_EXAMPLE+MULTIPLE_DEVICES_EXAMPLE+CURRENT_INPUT_LOOP_EXAMPLE+DIGITAL_INPUT_LOGIC_EXAMPLE+DIGITAL_INPUT_LOOP_EXAMPLE+DIGITAL_OUTPUT_EXAMPLE+TEMPERATURE_2WIRE_RTD_EXAMPLE+TEMPERATURE_3WIRE_RTD_EXAMPLE+VOLTAGE_INPUT_IRQ_EXAMPLE+HART_EXAMPLE != 1)
#error Selected example projects cannot be enabled at the same time. \
Please enable only one example and re-build the project.
#endif
	return 0;
}
