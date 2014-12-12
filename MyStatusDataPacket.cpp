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
		// Set the start byte from the data*.
		this->setErrorFlags(data[STATUS_ERROR]);
		// Set the error flag from the data*.
		this->setBatteryVoltage(((data[STATUS_BATTERY_MSB] << 8) + data[STATUS_BATTERY_LSB])/100.0);
		// Set the battery flag from the data*.
		this->setMotorCurrent(LEFT,((data[STATUS_LEFT_MOTOR_CURRENT_MSB]<<8)+data[STATUS_LEFT_MOTOR_CURRENT_LSB])/1000.0);
		// Set the left motor current from the data*.
		this->setMotorCurrent(RIGHT,((data[STATUS_RIGHT_MOTOR_CURRENT_MSB]<<8)+data[STATUS_RIGHT_MOTOR_CURRENT_LSB])/1000.0);
		// Set the right motor current from the data*.
		this->setEncoderCount(LEFT,((data[STATUS_LEFT_ENCODER_COUNT_MSB]<<8)+data[STATUS_LEFT_ENCODER_COUNT_LSB]));
		// Set the left encoder count from the data*.
		this->setEncoderCount(RIGHT,((data[STATUS_RIGHT_MOTOR_CURRENT_MSB]<<8)+data[STATUS_RIGHT_MOTOR_CURRENT_LSB]));
		// Set the right encoder count from the data*.

		AcceleroMeter accelero;
		accelero.x=((data[STATUS_ACCELEROMETER_X_MSB]<<8)+data[STATUS_ACCELEROMETER_X_LSB]);
		accelero.y=((data[STATUS_ACCELEROMETER_Y_MSB]<<8)+data[STATUS_ACCELEROMETER_Y_LSB]);
		accelero.z=((data[STATUS_ACCELEROMETER_Z_MSB]<<8)+data[STATUS_ACCELEROMETER_Z_LSB]);
		this->setAcceleroMeter(accelero);
		Impact imp;
		imp.x=((data[STATUS_IMPACT_X_MSB]<<8)+data[STATUS_IMPACT_X_LSB]);
		imp.y=((data[STATUS_IMPACT_Y_MSB]<<8)+data[STATUS_IMPACT_Y_LSB]);
		imp.z=((data[STATUS_IMPACT_Z_MSB]<<8)+data[STATUS_IMPACT_Z_LSB]);
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
		return json;
	}
}