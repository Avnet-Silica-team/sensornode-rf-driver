#if MBED_CONF_RTOS_PRESENT

#include "NanostackRfPhySpirit1.h"
#include "NanostackRfPhySensorNode.h"

#include "mbed_trace.h"
#define TRACE_GROUP  "SPIRIT"

NanostackRfPhySensorNode::NanostackRfPhySensorNode(PinName spi_mosi, PinName spi_miso, PinName spi_sclk,
                                             PinName dev_irq,  PinName dev_cs, PinName dev_sdn, PinName brd_led) : NanostackRfPhySpirit1( spi_mosi, spi_miso, spi_sclk, dev_irq, dev_cs, dev_sdn, brd_led )
{
    /* Nothing to do */
    tr_debug("%s (%d)", __func__, __LINE__);
	i2c = new I2C( I2C_SDA, I2C_SCL );
    i2c->frequency( 400000 );
    writeReg( GPIO_SET_DIR_LOW, 0 );
    writeReg( GPIO_SET_DIR_MID, 1 );  // only IO8 setted as output
    writeReg( GPIO_SET_DIR_HIGH, 0 );
  
    writeReg(GPIO_SET_MID, 1 );  // IO8 setted, spirit off
    uint32_t start = us_ticker_read();
	while( us_ticker_read() - start < 5000U );
    writeReg(GPIO_CLR_MID, 1 );  // IO8 cleared, spirit on
}

NanostackRfPhySensorNode::~NanostackRfPhySensorNode()
{
    /* Nothing to do */
    tr_debug("%s (%d)", __func__, __LINE__);
}

void NanostackRfPhySensorNode::writeReg( uint8_t register_address, uint8_t value )
{   
    char w2_data[2];
    
    w2_data[0] = register_address;
    w2_data[1] = value;
    i2c->write( PE180_ADDRESS, w2_data, 2 );      
}

#endif /* MBED_CONF_RTOS_PRESENT */
