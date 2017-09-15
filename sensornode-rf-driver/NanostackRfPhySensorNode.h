#ifndef NANOSTACK_RF_PHY_SENSOR_NODE_H_
#define NANOSTACK_RF_PHY_SENSOR_NODE_H_

#include <stdint.h>

#include "NanostackRfPhy.h"
#include "PinNames.h"
#include "mbed.h"

#define PE180_ADDRESS   (0x40<<1)
#define ADDRESS_CHIP_ID (0x00) //!< CHIP_ID register identifies the device. Expected value is 0xC1.
#define VALUE_CHIP_ID 0xC1
// 1 out, 0 input
#define GPIO_SET_DIR_LOW  0x19
#define GPIO_SET_DIR_MID  0x1A
#define GPIO_SET_DIR_HIGH 0x1B

#define GPIO_SET_LOW  0x10
#define GPIO_SET_MID  0x11
#define GPIO_SET_HIGH 0x12

#define GPIO_CLR_LOW	0x13
#define GPIO_CLR_MID  0x14
#define GPIO_CLR_HIGH 0x15

class NanostackRfPhySensorNode : public NanostackRfPhySpirit1 {
public:
    NanostackRfPhySensorNode(PinName spi_mosi, PinName spi_miso, PinName spi_sclk,
    		PinName dev_irq,  PinName dev_cs, PinName dev_sdn, PinName brd_led);
    ~NanostackRfPhySensorNode();

private:
	I2C *i2c;
	void writeReg( uint8_t register_address, const uint8_t value );
};

#endif /* NANOSTACK_RF_PHY_SENSOR_NODE_H_ */
