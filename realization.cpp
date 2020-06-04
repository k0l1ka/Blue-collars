#include"header.h"


void Vintovshik:: print_msg_2(Workers msg)
{
//      log_file = freopen("/home/hz/q/", "w+", stdout);
        clock_t t = clock();
        log_file << "moment: " << t << endl;

        log_file<< "message 2:" << endl << endl;

        log_file << "type: "<< msg.type<< endl;

        log_file << "num of workers = " << msg.num << endl << endl;

/*        if (msgctl(mesid, IPC_STAT, buf) == 0)
        {
                log_file << "Number of msgs in the queue " << buf->msg_qnum << endl;
        }
*/
//      fclose(log_file);
};




void Vintovshik:: print_msg_1(Mess msg)
{
//      log_file = freopen("/home/hz/q/", "w+", stdout);
        clock_t t = clock();
        log_file << "moment: " << t << endl;

        log_file<< "message 1:" << endl << endl;

        log_file << "type: "<< msg.type<< endl;


        log_file << "Number of bolts: " << msg.bolt << endl;
        log_file << "Number of nuts: " << msg.nut << endl;
        log_file << "Number of detailes: " << msg.n << endl << endl;

/*	if (msgctl(mesid, IPC_STAT, buf) == 0)
        {
                log_file << "Number of msgs in the queue " << buf->msg_qnum << endl;
        }
*/
//      fclose(log_file);
};



void Gaechnik:: print_msg_2(Workers msg)
{
//      log_file = freopen("/home/hz/q/", "w+", stdout);
        clock_t t = clock();
        log_file << "moment: " << t << endl;

        log_file<< "message 2:" << endl << endl;

        log_file << "type: "<< msg.type<< endl;

        log_file << "num of workers = " << msg.num << endl << endl;

/*        if (msgctl(mesid, IPC_STAT, buf) == 0)
        {
                log_file << "Number of msgs in the queue " << buf->msg_qnum << endl;
        }
*/
//      fclose(log_file);
};



void Gaechnik:: print_msg_1(Mess msg)
{
//      log_file = freopen("/home/hz/q/", "w+", stdout);
        clock_t t = clock();
        log_file << "moment: " << t << endl;

        log_file<< "message 1:" << endl << endl;

        log_file << "type: "<< msg.type<< endl;


        log_file << "Number of bolts: " << msg.bolt << endl;
        log_file << "Number of nuts: " << msg.nut << endl;
        log_file << "Number of detailes: " << msg.n << endl << endl;
/*
        if (msgctl(mesid, IPC_STAT, buf) == 0)
        {
                log_file << "Number of msgs in the queue " << buf->msg_qnum << endl;
        }
*/
//      fclose(log_file);
};





Vintovshik::~Vintovshik()
{
//	log_file = freopen("/home/hz/Рабочий стол/rh/v_log", "w+", stdout);
	wSend.type = wRead.type = 2L;

	log_file << "bolt: desctuctor" << endl;

        if (msgrcv(mesid,(void*)&wRead, sizeof(Workers), wRead.type,0) < 0)
	{ 
		log_file << "bolt: Can't read message" << endl;
		exit(1);
	}	
	log_file << "bolt: mesage 2 readed" << endl;

        print_msg_2(wRead);
        
	if(wRead.num > 1)
	{
        	wSend.num = wRead.num - 1;
	        wSend.type = 2L;
                log_file << "bolt: Sends  m2" << endl;

        	if (msgsnd(mesid,(void*)&wSend,sizeof(Workers),0) < 0)
        	{
                	log_file<<"bolt: Can't write message\n";
			exit(1);
		}
		
		log_file << "bolt: Sended message_2" << endl;	
		print_msg_2(wSend);
	}
        else
        {
		if(msgctl(mesid,IPC_RMID,0)<0)
                {
                        log_file << "bolt:  Can't delete queue\n";
                        exit(1);
                }


                log_file << "bolt:  Queue was deleted" << endl;

                cout << endl << detalei << " detailes made." << endl;
                log_file << endl << detalei << " detailes made." << endl;
	
	}

        log_file << "bolt: desctuctor ended" << endl;

	
        log_file.close();


	
//	fclose(log_file);
};








Vintovshik::Vintovshik()
{
//	 log_file = freopen("/home/hz/Рабочий стол/rh/v_log", "w+", stdout);
	id = 0;

///	!!!	ЗДЕСЬ можно ВВЕСТИ ПУТЬ ДО ФАЙЛА С ИМЕНЕМ log0	!!!	///
//	ofstream log_file("/home/hz/q/logs/log0");
	
	FILE *temp = fopen("log_bolt", "wb");
	fclose(temp);
        log_file.open ("log_bolt");


	log_file<<"bolt constructor: "<< endl; 

	if ((key = ftok("/tmp",'A'))<0)
	{
		log_file << "bolt worker cannot get key\n";
		exit(1);
	}


//	key = 100;	

	if((mesid = msgget(key,PERM|IPC_CREAT|IPC_EXCL))<0)
	{

		
		if(errno == EEXIST)
		{
			log_file <<"bolt: queue already created\n";

			if ((mesid = msgget(key, PERM))< 0)
			{
				 log_file << " bolt: cannot create message queue\n";            
				 exit(1);
			}
		}
		else
		{
			 log_file << "bolt: can't create message queue\n";
			 exit(1);
		}
	}

	log_file << "bolt: message id "<< mesid << endl;
	
		mSend.type = mRead.type = 1L;

             	mSend.bolt = 1;
		mSend.nut = 0;
		detalei = mSend.n = 0;
		
					
		if (msgsnd(mesid,(void*)&mSend,sizeof(Mess),0) < 0)
		{
			log_file << "bolt:  cannot write message\n";
			exit(1);
		}
		log_file << "bolt: send message_1 \n ";
		
		print_msg_1(mSend);

		//__________________________________________
		
		wSend.type = wRead.type = 2L;

                wSend.num = 1;
                

                if (msgsnd(mesid,(void*)&wSend,sizeof(Workers),0) < 0)
                {
                        log_file << "bolt:  cannot write message\n";
                        exit(1);
                }
                log_file << "bolt: send message_2 \n ";

                print_msg_2(wSend);

	//	fclose(log_file);
};

					









void Vintovshik :: act (int tm) // time for sleep of process
{
//	 log_file = freopen("/home/hz/Рабочий стол/rh/v_log", "w+", stdout);
	log_file<<"bolt: act" << endl;
	mRead.type = mSend.type = 1L;

	log_file << "bolt: read message_1" << endl;   
	
	int er = msgrcv(mesid,(void*)&mRead, sizeof(Mess), mRead.type, 0);
	
	if (er > 0)
	{
		log_file << "bolt: read message_1"<< endl;
		
		print_msg_1(mRead);





			if( (mRead.bolt == 0) && (mRead.nut == 2))
			{
	        		mSend.type = 1L;			
				mSend.bolt = 0; 
				mSend.nut = 0;
				detalei = mSend.n = mRead.n + 1;
				      
			}
			else
			{
					mSend.type = 1L;
					mSend.bolt = 1;
					mSend.nut = mRead.nut;
					detalei = mSend.n = mRead.n;
			}


		if(msgsnd(mesid, (void*)&mSend, sizeof(Mess), 0) < 0)
		{
			log_file << "bolt: Error| cannot write message\n";
			exit(1);	
		}

		log_file << "bolt: send message_1\n";  
		print_msg_1(mSend);
	 


		
		  
	}

	else
	{
		log_file << "bolt: cannot read\n"; 
		exit(1);
	}



	sleep(tm);
//	fclose(log_file);
};
								   

//__________________________________________________________________________________________________


Gaechnik::Gaechnik(int n)
{
	id = n;
//	if(id == 1)
//		log_file = freopen("/home/hz/Рабочий стол/rh/g1_log", "w+", stdout);
//	if(id == 2)
//		log_file = freopen("/home/hz/Рабочий стол/rh/g2_log", "w+", stdout);

	
	if (id == 1)
	{
///     !!!    ЗДЕСЬ надо дважды  ВВЕСТИ ПУТЬ ДО ФАЙЛА С ИМЕНЕМ log1        !!!     ///

//	       ofstream log_file("/home/hz/q/logs/log1");

	        FILE *temp = fopen("log_nut_1", "wb");
        	fclose(temp);

	       log_file.open ("log_nut_1");
	}

	if (id == 2)
	{
///     !!!     ЗДЕСЬ надо дважды ВВЕСТИ ПУТЬ ДО ФАЙЛА С ИМЕНЕМ log2        !!!     ///

//	        ofstream log_file("/home/hz/q/logs/log2");


	        FILE *temp = fopen("log_nut_2", "wb");
        	fclose(temp);

	        log_file.open ("log_nut_2");
	}

        log_file<<"nut: constructor "<< id << endl;

        if ((key = ftok("/tmp",'A'))<0)
        {
                log_file <<"nut"<< id<<" : cannot get key\n";
                exit(1);
        }


//	key = 100;     

        if((mesid = msgget(key,PERM|IPC_CREAT|IPC_EXCL))<0)
        {

                if(errno == EEXIST)
                {
                        log_file << "nut "<< id << ": queue already created" << endl;

                        if ((mesid = msgget(key,PERM))< 0)
                        {
                                log_file << "nut"<< id <<": cannot create message queue" << endl;
                                exit(1);
                        }			
                }
                else
                {
                        log_file << "nut"<< id <<": cannot create message queue" << endl;
                        exit(1);
                }
        }


        	mSend.type = mRead.type = 1L;


	        log_file << "nut: message id "<< mesid << endl;



        	log_file << "constuctor:  nut" << id <<" reads message_1" << endl;
        	if (msgrcv(mesid,(void*)&mRead,sizeof(Mess), mRead.type, 0) < 0)
        	{
                	log_file << "nut"<< id <<": cannot read message\n";
                	exit(1);
        	}
		log_file << "nut"<< id <<": read message_1" << endl;

		print_msg_1(mRead);





		wSend.type = wRead.type = 2L;

                log_file << "constuctor:  nut" << id <<" read message_2" << endl;
                if (msgrcv(mesid,(void*)&wRead,sizeof(Workers), wRead.type, 0) < 0)
                {
                        log_file << "nut"<< id <<": cannot read message\n";
                        exit(1);
                }
                log_file << "nut"<< id <<": read message_2" << endl;

                print_msg_2(wRead);


		

        	mSend.type = 1L;
		
		if (mRead.bolt == 1 && mRead.nut == 1)
		{
			mSend.bolt = 0;
			mSend.nut = 0;
			detalei = mSend.n = mRead.n + 1;
		}
		else
		{
			if (mRead.nut < 2)
			{
				mSend.bolt = mRead.bolt;
        	    		mSend.nut = mRead.nut + 1;
				detalei = mSend.n = mRead.n;
			}
		}

		if(msgsnd(mesid, (void*)&mSend, sizeof(Mess), 0) < 0)
		{
			log_file << "nut"<< id <<": cannot write message" << endl;
			exit(1);
		}
		log_file << "nut " << id <<": sent message_1" << endl;
		
                print_msg_1(mSend);

		

		wSend.num = wRead.num + 1;		
		wSend.type = 2L;
		if (msgsnd(mesid, (void*)&wSend, sizeof(Workers), 0) < 0)
                {
                        log_file << "nut"<< id <<": cannot write message" << endl;
                        exit(1);
                }
                log_file << "nut " << id <<": sent message_2" << endl;

                print_msg_2(wSend);


//	fclose(log_file);
};










Gaechnik::~Gaechnik()
{
	wSend.type = wRead.type = 2L;

	log_file << "nut: desctuctor" << endl;

        if (msgrcv(mesid,(void*)&wRead, sizeof(Workers), wRead.type,0) < 0)
        {
                log_file << "nut: cannot read message" << endl;
                exit(1);
        }
        log_file << "nut: read message_2" << endl;

        print_msg_2(wRead);



        if(wRead.num > 1)
        {
                wSend.num = wRead.num - 1;
                wSend.type = 2L;
                if (msgsnd(mesid,(void*)&wSend,sizeof(Workers),0) < 0)
                {
                        log_file<<"nut: cannot write message\n";
                        exit(1);
                }
                log_file << "nut: sent message_2" << endl;
                print_msg_2(wSend);
        }
        else
        {
                if(msgctl(mesid,IPC_RMID,0)<0)
                {
                        log_file << "nut: cannot delete queue\n";
                        exit(1);
                }

		
                log_file << "nut:  queue was deleted" << endl;
        	
				cout << endl << detalei << " detailes made." << endl;
                log_file << endl << detalei << " detailes made." << endl;

	}

        log_file << "nut: end of desctuctor" << endl;


        log_file.close();



//      fclose(log_file);
};







 
void Gaechnik::act(int tm)
{
//	if(id == 1)
//                log_file = freopen("/home/hzff/Рабочий стол/rh/g1_log", "w+", stdout);
//        if(id == 2)
//                log_file = freopen("/home/hz/Рабочий стол/rh/g2_log", "w+", stdout);
	
	mRead.type = mSend.type = 1L;

        log_file << "nut: "<< id << " read message_1" << endl;

       	if (msgrcv(mesid,(void*)&mRead, sizeof(Mess), mRead.type, 0) < 0)
	{
		log_file << "nut "<< id  <<": cannot read message" << endl;
		exit(1);
	}

	log_file << "nut" << id <<": read message_1" << endl;

	print_msg_1(mRead);

                if (mRead.bolt == 1 && mRead.nut == 1)
                {
                        mSend.bolt = 0;
                        mSend.nut = 0;
                        detalei = mSend.n = mRead.n + 1;
                }
                else
                {
                        if (mRead.nut < 2)
                        {
                                mSend.bolt = mRead.bolt;
                                mSend.nut = mRead.nut + 1;
                                detalei = mSend.n = mRead.n;
                        }
                }



                if (msgsnd(mesid, (void*)&mSend, sizeof(Mess), 0) < 0)
                {
                        log_file << "nut "<< id <<": cannot write message" << endl;
                        exit(1);
                }
                log_file << "nut " << id <<": sent message_1" << endl;

                print_msg_1(mSend);
	


	sleep(tm);

//	fclose(log_file);
};
