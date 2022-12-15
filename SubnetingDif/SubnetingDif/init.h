#ifndef _INIT_H_
#define _INIT_H_
 
#include <sstream>
 
#include "user_data.h"
class init : public user_data {
	int address();
	void networks();
	unsigned char power_of_two();
	int *ip;
	char enet, net;
	int ipadr;
	unsigned char sub_mask;
	unsigned char ip_sub_mask;
	unsigned char building;
	unsigned char mask_end;
	unsigned char mask_offset;
	unsigned char subnet_bytes;
	int room;
	unsigned char room_bytes;
}
#endif /* _INIT_H_ */