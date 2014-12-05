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
    	char buffer[]={"getStatusDataPacket"};
    	i2c->write(i2cAddress,buffer,1);
    	wait(0.1);
    	char data[25];
    	i2c->read(i2cAddress,data,25);
    	wait(0.1);
        status->fromTRex(data);
    	return true;
    }
    bool MyTRex::writeCommand(CommandDataPacket * command){
    	char buffer[]={"command"};
    	i2c->write(i2cAddress,buffer,sizeof(buffer));
    	return true;
    }
}