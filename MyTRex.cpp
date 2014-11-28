#include "MyTRex.h"
#include "MyI2C.h"

namespace TRexLib{
	MyTRex::MyTRex(I2C* i2c, int i2caddress):TRex(I2C, i2caddress)
    {

    }
    bool MyTrex::readStatus(StatusDataPacket * status){
    	char buffer[]={getStatusDataPacket};
    	i2c->write(i2caddress,buffer,1);
    	wait(0.1);
    	char data[25];
    	i2c->read(i2caddress,data,25);
    	wait(0.1);
    	status=data;
    	return true;

    }
    bool MyTrex::writeCommand(CommandDataPacket * command){
    	char buffer[]={command};
    	i2c->write(i2caddress,buffer,sizeof(buffer));
    	return true;
    }