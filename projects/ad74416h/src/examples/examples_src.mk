ifeq (y,$(strip $(BASIC_EXAMPLE)))
CFLAGS += -DBASIC_EXAMPLE=1
SRCS += $(PROJECT)/src/examples/basic/basic_example.c
INCS += $(PROJECT)/src/examples/basic/basic_example.h
endif

ifeq (y,$(strip $(TEST_EXAMPLE)))
CFLAGS += -DTEST_EXAMPLE=1
SRCS += $(PROJECT)/src/examples/test/test_example.c
INCS += $(PROJECT)/src/examples/test/test_example.h
endif

ifeq (y,$(strip $(VOLTAGE_OUTPUT_EXAMPLE)))
CFLAGS += -DVOLTAGE_OUTPUT_EXAMPLE=1
SRCS += $(PROJECT)/src/examples/voltage_output/voltage_output.c
INCS += $(PROJECT)/src/examples/voltage_output/voltage_output.h
endif

ifeq (y,$(strip $(CURRENT_OUTPUT_EXAMPLE)))
CFLAGS += -DCURRENT_OUTPUT_EXAMPLE=1
SRCS += $(PROJECT)/src/examples/current_output/current_output.c
INCS += $(PROJECT)/src/examples/current_output/current_output.h
endif

ifeq (y,$(strip $(VOLTAGE_INPUT_EXAMPLE)))
CFLAGS += -DVOLTAGE_INPUT_EXAMPLE=1
SRCS += $(PROJECT)/src/examples/voltage_input/voltage_input.c
INCS += $(PROJECT)/src/examples/voltage_input/voltage_input.h
endif

ifeq (y,$(strip $(CURRENT_INPUT_EXT_EXAMPLE)))
CFLAGS += -DCURRENT_INPUT_EXT_EXAMPLE=1
SRCS += $(PROJECT)/src/examples/current_input_ext/current_input_ext.c
INCS += $(PROJECT)/src/examples/current_input_ext/current_input_ext.h
endif

ifeq (y,$(strip $(CURRENT_INPUT_LOOP_EXAMPLE)))
CFLAGS += -DCURRENT_INPUT_LOOP_EXAMPLE=1
SRCS += $(PROJECT)/src/examples/current_input_loop/current_input_loop.c
INCS += $(PROJECT)/src/examples/current_input_loop/current_input_loop.h
endif

ifeq (y,$(strip $(MULTIPLE_DEVICES_EXAMPLE)))
CFLAGS += -DMULTIPLE_DEVICES_EXAMPLE=1
SRCS += $(PROJECT)/src/examples/multiple_devices/multiple_devices.c
INCS += $(PROJECT)/src/examples/multiple_devices/multiple_devices.h
endif

ifeq (y,$(strip $(DIGITAL_INPUT_LOGIC_EXAMPLE)))
CFLAGS += -DDIGITAL_INPUT_LOGIC_EXAMPLE=1
SRCS += $(PROJECT)/src/examples/digital_input_logic/digital_input_logic.c
INCS += $(PROJECT)/src/examples/digital_input_logic/digital_input_logic.h
endif

ifeq (y,$(strip $(DIGITAL_INPUT_LOOP_EXAMPLE)))
CFLAGS += -DDIGITAL_INPUT_LOOP_EXAMPLE=1
SRCS += $(PROJECT)/src/examples/digital_input_loop/digital_input_loop.c
INCS += $(PROJECT)/src/examples/digital_input_loop/digital_input_loop.h
endif

ifeq (y,$(strip $(DIGITAL_OUTPUT_EXAMPLE)))
CFLAGS += -DDIGITAL_OUTPUT_EXAMPLE=1
SRCS += $(PROJECT)/src/examples/digital_output/digital_output.c
INCS += $(PROJECT)/src/examples/digital_output/digital_output.h
endif

ifeq (y,$(strip $(TEMPERATURE_2WIRE_RTD_EXAMPLE)))
CFLAGS += -DTEMPERATURE_2WIRE_RTD_EXAMPLE
SRCS += $(PROJECT)/src/examples/temperature_2wire_rtd/temperature_2wire_rtd.c
INCS += $(PROJECT)/src/examples/temperature_2wire_rtd/temperature_2wire_rtd.h
endif

ifeq (y,$(strip $(TEMPERATURE_3WIRE_RTD_EXAMPLE)))
CFLAGS += -DTEMPERATURE_3WIRE_RTD_EXAMPLE
SRCS += $(PROJECT)/src/examples/temperature_3wire_rtd/temperature_3wire_rtd.c
INCS += $(PROJECT)/src/examples/temperature_3wire_rtd/temperature_3wire_rtd.h
endif

ifeq (y,$(strip $(VOLTAGE_INPUT_IRQ_EXAMPLE)))
CFLAGS += -DVOLTAGE_INPUT_IRQ_EXAMPLE
SRCS += $(PROJECT)/src/examples/voltage_input_irq/voltage_input_irq.c
INCS += $(PROJECT)/src/examples/voltage_input_irq/voltage_input_irq.h
endif

ifeq (y,$(strip $(HART_EXAMPLE)))
CFLAGS += -DHART_EXAMPLE=1
SRCS += $(PROJECT)/src/examples/hart/hart.c
INCS += $(PROJECT)/src/examples/hart/hart.h
endif

INCS += $(INCLUDE)/no_os_list.h \
	$(PLATFORM_DRIVERS)/$(PLATFORM)_uart.h
