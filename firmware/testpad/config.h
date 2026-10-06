#pragma once


#undef I2C1_SDA_PIN
#undef I2C1_SCL_PIN


#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP0
#define I2C1_SCL_PIN GP1


#define ENCODER_RESOLUTION 4
#define DEBOUNCE 5
