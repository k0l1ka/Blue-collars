#include "header.h"

int main(int argc, char **argv)
{
	int t = atoi(argv[1]);	

        time_t started, now;

        started = time(NULL);

	Vintovshik v;		
	 

	cout<<"bolt worker 1 started at moment " << started << endl;

        now = started + 1;

        cout<< "start at "<< now<<endl;

	// cout << "begin while" << endl;	

        while ( now - started < 60)
        {
//     	        cout << "acting"<<endl;
		v.act(t);
                now = time(NULL);
		cout<< "time is "<< now<<endl;
        }

        // cout<<"end while " << endl;


	return 0;
}
