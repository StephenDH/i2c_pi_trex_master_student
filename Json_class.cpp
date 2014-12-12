	#include "Json_class.h"
	#include <string>
	#include <sstream>


	namespace TRexLib{
		
		std::string Json_class::intValue(std::string* output, std::string key, int value ){
			std::ostringstream os ;
			os << value ;
			output->append( "\"" + key + "\": " + os.str());
		}

		std::string Json_class::charValue(std::string* output, std::string key, char value ){
			output->append( "\"" + key + "\": " + value);
		}

		std::string Json_class::doubleValue(std::string* output, std::string key, double value ){
			std::ostringstream os ;
			os << value ;
			output->append( "\"" + key + "\": " + os.str());
		}
		std::string Json_class::accelValue(std::string* output, std::string key, AcceleroMeter accel ){
			std::ostringstream osx ;
			osx << accel.x ;
			std::ostringstream osy ;
			osy << accel.y ;
			std::ostringstream osz ;
			osz << accel.z ;
			output->append( "\"" + key + "\": [" + osx.str()+","+osy.str()+","+osz.str()+"],");
		}
		std::string Json_class::impValue(std::string* output, std::string key, Impact imp ){
			std::ostringstream osx ;
			osx << imp.x ;
			std::ostringstream osy ;
			osy << imp.y ;
			std::ostringstream osz ;
			osz << imp.z ;
			output->append( "\"" + key + "\": [" + osx.str()+","+osy.str()+","+osz.str()+"],");
		}
	}