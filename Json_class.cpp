	#include "Json_class.h"

	namespace TRexLib{
		
		String Json_class::intValue(String* output, String* key, int value ){
			output += "\"" + key + "\": " + value;
		}

		String Json_class::charValue(String* output, String* key, char value ){
			output += "\"" + key + "\": " + value;
		}

		String Json_class::doubleValue(String* output, String* key, double value ){
			output += "\"" + key + "\": " + value;
		}
	}