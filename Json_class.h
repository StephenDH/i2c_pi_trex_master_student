#include <String.h>

#ifndef Json_Class_H
#define Json_Class_H

class Json_class{
public:
	String intValue(String* output, String* key, int value );

	String charValue(String* output, String* key, char value );

	String doubleValue(String* output, String* key, double value );
}