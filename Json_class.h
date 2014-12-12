#include <string>
#include <sstream>
#include "AcceleroMeter.h"
#ifndef Json_Class_H
#define Json_Class_H
namespace TRexLib{
class Json_class{
public:
	std::string intValue(std::string* output, std::string key, int value );

	std::string charValue(std::string* output, std::string key, char value );

	std::string doubleValue(std::string* output, std::string key, double value );
	std::string accelValue(std::string* output,std::string key, AcceleroMeter accel);
	std::string impValue(std::string* output, std::string key, Impact imp );
};
}
#endif