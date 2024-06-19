/***************************************************************************//**
 *   @file   basic_example.c
 *   @brief  Basic example header for eval-ad74416h project
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
#include "hart.h"
#include "common_data.h"
#include "ad74416h.h"
#include "no_os_delay.h"
#include "no_os_gpio.h"
#include "no_os_print_log.h"

/******************************************************************************/
/************************ Functions Declarations ******************************/
/******************************************************************************/
/***************************************************************************//**
 * @brief Basic example main execution.
 *
 * @return ret - Result of the example execution. If working correctly, will
 *               execute continuously the while(1) loop and will not return.
*******************************************************************************/

char cHartState = HART_STATE_TX;      // State machine switch

int hart_example_main()
{
	struct ad74416h_desc *ad74416h_desc;
	int ret;
	uint16_t hart_data_tx;
	uint16_t hart_data_rx;
	char output_buffer[10];
	ret = ad74416h_init(&ad74416h_desc, &ad74416h_ip);
	if (ret)
		goto error;

	pr_info("ad74416h successfully initialized!\r\n");

	ret = ad74416h_gpio_set(ad74416h_desc, AD74416H_CH_C, NO_OS_GPIO_HIGH);
	if (ret) {
		pr_info("Error setting GPIO C\r\n");
		goto error_ad74416h;
	}

	pr_info("ad74416h GPO2 set to HIGH\r\n");

	ret = HART_Configure(ad74416h_desc);
	if (ret) {
		pr_info("Error configuring HART C\r\n");
		goto error_ad74416h;
	}
	pr_info("HART configured\r\n");

	while(1) {
		switch (cHartState)
		{
		// ----------------------------------------------------------------------
		// Wait for HART Carrier Detected. 
		// When active, switch UART from J3 to HART modem (and start receiving)
		// ----------------------------------------------------------------------
		case HART_STATE_IDLE:   // Wait for carrier detect 
			if (HART_ALERTb_Status(ad74416h_desc))   // 
			{
				cHartState = HART_STATE_RX;
			} // 
			no_os_udelay(10000);
		break;  // HART_STATE_IDLE


		case HART_STATE_RX: 
			hart_data_rx = 0;
			HART_ReadHartFrame(ad74416h_desc, &hart_data_rx);
			cHartState = HART_STATE_IDLE; 
			// output[0] = hart_data_rx & 0xFF;
			// output[1] = hart_data_rx >> 8;
			sprintf(output_buffer, "%d", hart_data_rx);
			pr_info(output_buffer);
			no_os_udelay(10000);
		break;  // HART_STATE_RX

		case HART_STATE_TX:

			hart_data_tx = 11111;
			pr_info("Transmitting data\r\n");
			ret = HART_SendHartfame(ad74416h_desc, &hart_data_tx, sizeof(hart_data_tx));
			if (ret) {
				pr_info("Error transmitting HART data C\r\n");
				goto error_ad74416h;
			}

			cHartState = HART_STATE_IDLE; 
			no_os_udelay(10000);
		break; // HART_STATE_TX
		} // switch (cHartState)


	}

	return 0;

error_ad74416h:
	ad74416h_remove(ad74416h_desc);
	return ret;
error:
	pr_info("Error!\r\n");
	return ret;
}
