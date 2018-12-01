#include "header.h"

int main(int argc, char **argv)
{
        int t = atoi(argv[1]);
	
        time_t started, now;
        started = time(NULL);

	Gaechnik g1(1);	

        cout<<"g1 started  " << started << endl;

        now = started + 1;

        cout<< "now   "<< now<<endl;

        cout<<"begin while " << endl;

        while ( now - started < 60)
        {
//		cout<< "acting"<<endl;
                g1.act(t);
                now = time(NULL);
                cout<< "now   "<< now<<endl;
        }

        cout<<"end while " << endl;

	return 0;
}
