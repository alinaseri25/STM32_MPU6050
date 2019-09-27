#ifndef __MPU6050_H
#define __MPU6050_H

#include "stm32f1xx_hal.h"
#include "cmsis_os.h"

class MPU6050
{
	public:
		MPU6050(I2C_HandleTypeDef *_hi2c,IWDG_HandleTypeDef *_hiwdg);
		void Read_Accel(void);
		void Read_Gyro(void);
		float GetAx(void);
		float GetAy(void);
		float GetAz(void);
		float GetGx(void);
		float GetGy(void);
		float GetGz(void);
		void init();
	private:
		I2C_HandleTypeDef *hi2c;
		IWDG_HandleTypeDef *hiwdg;
		uint8_t MPU6050_ADDR;
		uint8_t SMPLRT_DIV_REG;
		uint8_t GYRO_CONFIG_REG;
		uint8_t ACCEL_CONFIG_REG;
		uint8_t ACCEL_XOUT_H_REG;
		uint8_t TEMP_OUT_H_REG;
		uint8_t GYRO_XOUT_H_REG;
		uint8_t PWR_MGMT_1_REG;
		uint8_t WHO_AM_I_REG;
	
		int16_t Accel_X_RAW;
		int16_t Accel_Y_RAW;
		int16_t Accel_Z_RAW;

		int16_t Gyro_X_RAW;
		int16_t Gyro_Y_RAW;
		int16_t Gyro_Z_RAW;

		float Ax, Ay, Az, Gx, Gy, Gz;
};

#endif
