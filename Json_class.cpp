	#include "Json_class.h"


	namespace TRexLib{
		
		std::string Json_class::intValue(std::string* output, std::string key, int value ){
			output += "\"" + key + "\": " + value;
		}

		std::string Json_class::charValue(std::string* output, std::string key, char value ){
			output += "\"" + key + "\": " + value;
		}

		std::string Json_class::doubleValue(std::string* output, std::string key, double value ){
			output += "\"" + key + "\": " + value;
		}
		std::string Json_class::accelValue(std::string* output, std::string key, AcceleroMeter accel ){
			output += "\"" + key + "\": [" + accel.x+","+accel.y+","+accel.z+"],";
		}
		std::string Json_class::impValue(std::string* output, std::string key, Impact imp ){
			output += "\"" + key + "\": [" + imp.x+","+imp.y+","+imp.z+"],";
		}
	}