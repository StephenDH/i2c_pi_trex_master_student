#include "MyStatusDataPacket.h"
#include "MyI2C.h"
namespace TRexLib{
	MyStatusDataPacket::MyStatusDataPacket();

	void MyStatusDataPacket::toTRex(char * buffer){

	}
	void MyStatusDataPacket::fromTRex(char * data){
		this->setStatusByte(data[STATUS_START]);
		this->setErrorFlags(data[STATUS_ERROR]);
		this->setBatteryVoltage((STATUS_BATTERY_MSB <<8 + STATUS_BATTERY_LSB)/100.0);
		this->setMotorCurrent(LEFT,(STATUS_LEFT_MOTOR_CURRENT_MSB<<8+STATUS_LEFT_MOTOR_CURRENT_LSB)/1000.0);
		this->setMotorCurrent(RIGHT,(STATUS_RIGHT_MOTOR_CURRENT_MSB<<8+STATUS_RIGHT_MOTOR_CURRENT_LSB)/1000.0);
		this->setsetEncoderCount(LEFT,(STATUS_LEFT_MOTOR_ENCODER_COUNT<<8+STATUS_LEFT_MOTOR_ENCODER_COUNT));
		this->setsetEncoderCount(RIGHT,(STATUS_RIGHT_MOTOR_ENCODER_COUNT<<8+STATUS_RIGHT_MOTOR_ENCODER_COUNT));

		AcceleroMeter accelero;
		accelero.x=(STATUS_ACCELEROMETER_X_MSB<<8+STATUS_ACCELEROMETER_X_LSB);
		accelero.y=(STATUS_ACCELEROMETER_Y_MSB<<8+STATUS_ACCELEROMETER_Y_LSB);
		accelero.z=(STATUS_ACCELEROMETER_Z_MSB<<8+STATUS_ACCELEROMETER_Z_LSB);
		this->setAcceleroMeter(accelero);
		Impact imp;
		imp.x=(STATUS_IMPACT_X_MSB<<8+STATUS_IMPACT_X_LSB);
		imp.y=(STATUS_IMPACT_Y_MSB<<8+STATUS_IMPACT_Y_LSB);
		imp.z=(STATUS_IMPACT_Z_MSB<<8+STATUS_IMPACT_Z_LSB);
		this->setImpact(imp);
	}
	void MyStatusDataPacket::fromJSON(std::string json){
		
	}