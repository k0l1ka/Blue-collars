#include "header.h"

int main(int argc, char **argv)
{
        int t = atoi(argv[1]);
	
        time_t started, now;
        started = time(NULL);

	Gaechnik g1(1);	

        cout<<"nut worker 1 started at moment " << started << endl;

        now = started + 1;

        cout<< "now is "<< now<<endl;

        // cout<<"begin while " << endl;

        while ( now - started < 60)
        {
//		cout<< "acting"<<endl;
                g1.act(t);
                now = time(NULL);
                cout<< "now is "<< now<<endl;
        }

        // cout<<"end while " << endl;

	return 0;
}
