
#include "simplex1.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	simplex *ud = new simplex;
	ud->get_data_from_user();
	ud->init();
	ud->gen_plane();
	system ("Pause");
	return 0;
}

