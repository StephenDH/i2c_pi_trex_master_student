#include "MyStatusDataPacket.h"
#include "MyI2C.h"
#include "Json_class.h"
#include "StatusDataPacket.h"
namespace TRexLib{
	MyStatusDataPacket::MyStatusDataPacket(){

	}

	void MyStatusDataPacket::toTRex(char * buffer){

	}
	void MyStatusDataPacket::fromTRex(char * data){
		this->setStartByte(data[STATUS_START]);
		this->setErrorFlags(data[STATUS_ERROR]);
		this->setBatteryVoltage((STATUS_BATTERY_MSB <<8 + STATUS_BATTERY_LSB)/100.0);
		this->setMotorCurrent(LEFT,(STATUS_LEFT_MOTOR_CURRENT_MSB<<8+STATUS_LEFT_MOTOR_CURRENT_LSB)/1000.0);
		this->setMotorCurrent(RIGHT,(STATUS_RIGHT_MOTOR_CURRENT_MSB<<8+STATUS_RIGHT_MOTOR_CURRENT_LSB)/1000.0);
		this->setEncoderCount(LEFT,(STATUS_LEFT_ENCODER_COUNT_MSB<<8+STATUS_LEFT_ENCODER_COUNT_LSB));
		this->setEncoderCount(RIGHT,(STATUS_RIGHT_MOTOR_CURRENT_MSB<<8+STATUS_RIGHT_MOTOR_CURRENT_LSB));

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
	std::string MyStatusDataPacket::toJSON(void){
		Json_class json_functie;
		std::string json="{\"device_path\": \"/dev/i2c-1\", \"i2c_address\": 7,";
		json_functie.doubleValue(&json,"battery_voltage",this->getBatteryVoltage());
		json=+",";
		json=+" \"motor_current\": {";
		json_functie.doubleValue(&json,"left",this->getMotorCurrent(LEFT));
		json=+",";
		json_functie.doubleValue(&json,"right",this->getMotorCurrent(RIGHT));
		json=+"},";
		json=+" \"encoder_count\": {";
		json_functie.doubleValue(&json,"left",this->getEncoderCount(LEFT));
		json=+",";
		json_functie.doubleValue(&json,"right",this->getEncoderCount(RIGHT));
		json=+"},";
		json_functie.accelValue(&json,"accelero_meter",this->getAcceleroMeter());
		json_functie.impValue(&json,"impact",this->getImpact());

	}
}