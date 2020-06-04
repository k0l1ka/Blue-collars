#include "header.h"

int main(int argc, char **argv)
{
        int t = atoi(argv[1]);

        time_t started, now;
        started = time(NULL);

        Gaechnik g2(2);

        cout<<"nut worker 2 started at moment " << started << endl;

        now = started + 1;

        cout<< "start at "<< now<<endl;

        // cout<<"begin while " << endl;

        while ( now - started < 60)
        {
//              cout<< "acting"<<endl;
                g2.act(t);
                now = time(NULL);
                cout<< "time is "<< now<<endl;
        }

        // cout<<"end while " << endl;

        return 0;
}

