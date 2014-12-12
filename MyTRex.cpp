#include "MyTRex.h"
#include "MyI2C.h"
#include "MyStatusDataPacket.h"
#include "wait.h"

namespace TRexLib{
	MyTRex::MyTRex(I2C* i2c, int i2cAddress):TRex(i2c, i2cAddress)
    {
        this->i2c = i2c;
        this->i2cAddress = i2cAddress;

    }
    bool MyTRex::readStatus(StatusDataPacket * status){
    	char data[StatusDataPacket::SIZE_STATUS_DATA_PACKET];
    	i2c->read(i2cAddress,data,StatusDataPacket::SIZE_STATUS_DATA_PACKET);
    	//wait(0.1);
        for (int i = 0; i < StatusDataPacket::SIZE_STATUS_DATA_PACKET; i++) {
            printf("%d ", data[i]);
        }
        status->fromTRex(data);
    	return true;
    }
    bool MyTRex::writeCommand(CommandDataPacket * command){
    	char buffer[]={"command"};
    	i2c->write(i2cAddress,buffer,sizeof(buffer));
    	return true;
    }
}