#pragma once

// 1. Force remove legacy Pro Micro I2C pins
#undef I2C1_SDA_PIN
#undef I2C1_SCL_PIN

// 2. Define custom RP2040 I2C pins (SDA = GP0, SCL = GP1)
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP0
#define I2C1_SCL_PIN GP1

// 3. Encoder Configuration
#define ENCODER_RESOLUTION 4
#define DEBOUNCE 5
