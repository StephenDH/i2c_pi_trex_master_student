#include "DataPacket.h"
#include "Side.h"
#include "AcceleroMeter.h"
#include "Json_class.h"
#include "StatusDataPacket.h"
#include <string>
#ifndef MY_StatusDataPacket_HEADER
#define MY_StatusDataPacket_HEADER

namespace TRexLib{
	class MyStatusDataPacket: public StatusDataPacket{
		 public:
		 	MyStatusDataPacket();
		 	std::string toJSON(void);
		 	void fromJSON(std::string json);
		 	void toTRex(char * buffer);
		 	void fromTRex(char * data);
	};
}

#endif
