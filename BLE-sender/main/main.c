#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "config.h"
#include "core/lib.h"
#include "core/ESP32/protocols/BLE/data-gatt-struct.h"

struct gatt ble;

long count, init_t;

int main ()
{	
    config(&ble);			/* Configure Name of the device, Endpoint address and Wifi credentials (if its a WiFi Connection), return string with the endpoint */	
    initPeripherals(&count);	/* Init GPIOs, I2C and ADC */
    createServer_BLE(&ble);	/* Will drop out of this structure only when it has connected to the network and checks the existence of the endpoint */

    while (1)
    {	
	    init_t = take_time();

	    pnp_sensors();		/* re init sensors to be able to plug n play in real time */

	    updateData(&count, &ble);

	    t_delay(interval, take_time() - init_t);  /* compensated delay */
    }    
    return 0;
}
