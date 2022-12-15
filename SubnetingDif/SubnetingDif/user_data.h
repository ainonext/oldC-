
#ifndef _USER_DATA_H_
#define _USER_DATA_H_
 
class user_data {
    public:
        int get_data_from_user(int *ip);
	protected:
		int a;
		int *ip;
		size_t found;
		char enet, net;
		int ipadr;
};
#endif /* _USER_DATA_H_ */
