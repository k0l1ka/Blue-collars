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


        log_file << "vintov: " << msg.vint << endl;
        log_file << "gaek: " << msg.gayka << endl;
        log_file << "detalei: " << msg.n << endl << endl;

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


        log_file << "vintov: " << msg.vint << endl;
        log_file << "gaek: " << msg.gayka << endl;
        log_file << "detalei: " << msg.n << endl << endl;
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

	log_file << "vint: desctuctor" << endl;

        if (msgrcv(mesid,(void*)&wRead, sizeof(Workers), wRead.type,0) < 0)
	{ 
		log_file << "vint: Can't read message" << endl;
		exit(1);
	}	
	log_file << "vint: mesage 2 readed" << endl;

        print_msg_2(wRead);
        
	if(wRead.num > 1)
	{
        	wSend.num = wRead.num - 1;
	        wSend.type = 2L;
                log_file << "vint: Sends  m2" << endl;

        	if (msgsnd(mesid,(void*)&wSend,sizeof(Workers),0) < 0)
        	{
                	log_file<<"vint: Can't write message\n";
			exit(1);
		}
		
		log_file << "vint: Sended m2" << endl;	
		print_msg_2(wSend);
	}
        else
        {
		if(msgctl(mesid,IPC_RMID,0)<0)
                {
                        log_file << "vint:  Can't delete queue\n";
                        exit(1);
                }


                log_file << "vint:  Queue was deleted" << endl;

                cout << "Sdelano detalei " << detalei << endl;
                log_file << "Sdelano detalei " << detalei << endl;
	
	}

        log_file << "vint: desctuctor ended" << endl;

	
        log_file.close();


	
//	fclose(log_file);
};








Vintovshik::Vintovshik()
{
//	 log_file = freopen("/home/hz/Рабочий стол/rh/v_log", "w+", stdout);
	id = 0;

///	!!!	ЗДЕСЬ можно ВВЕСТИ ПУТЬ ДО ФАЙЛА С ИМЕНЕМ log0	!!!	///
//	ofstream log_file("/home/hz/q/logs/log0");
	
	FILE *temp = fopen("/home/hz/q/logs/log0", "wb");
	fclose(temp);
        log_file.open ("/home/hz/q/logs/log0");


	log_file<<"Конструктор Vintovshik: "<< endl; 

	if ((key = ftok("/tmp",'A'))<0)
	{
		log_file << "Vintovshik Can't get key\n";
		exit(1);
	}


//	key = 100;	

	if((mesid = msgget(key,PERM|IPC_CREAT|IPC_EXCL))<0)
	{

		
		if(errno == EEXIST)
		{
			log_file <<"Vintovshik Очередь уже создана\n";

			if ((mesid = msgget(key, PERM))< 0)
			{
				 log_file << " Vintovshik Can't create message's queue\n";            
				 exit(1);
			}
		}
		else
		{
			 log_file << "Vintovshik Can't create message's queue\n";
			 exit(1);
		}
	}

	log_file << "vintovshik mesid "<< mesid << endl;
	
		mSend.type = mRead.type = 1L;

             	mSend.vint = 1;
		mSend.gayka = 0;
		detalei = mSend.n = 0;
		
					
		if (msgsnd(mesid,(void*)&mSend,sizeof(Mess),0) < 0)
		{
			log_file << "vint:  Can't write message\n";
			exit(1);
		}
		log_file << "Vintovshik send mes 1 \n ";
		
		print_msg_1(mSend);

		//__________________________________________
		
		wSend.type = wRead.type = 2L;

                wSend.num = 1;
                

                if (msgsnd(mesid,(void*)&wSend,sizeof(Workers),0) < 0)
                {
                        log_file << "vint:  Can't write message\n";
                        exit(1);
                }
                log_file << "Vintovshik send mes 2 \n ";

                print_msg_2(wSend);

	//	fclose(log_file);
};

					









void Vintovshik :: act (int tm) // time for sleep of process
{
//	 log_file = freopen("/home/hz/Рабочий стол/rh/v_log", "w+", stdout);
	log_file<<"act vintovshik" << endl;
	mRead.type = mSend.type = 1L;

	log_file << "vint reads m1" << endl;   
	
	int er = msgrcv(mesid,(void*)&mRead, sizeof(Mess), mRead.type, 0);
	
	if (er > 0)
	{
		log_file << "vint read m1"<< endl;
		
		print_msg_1(mRead);





			if( (mRead.vint == 0) && (mRead.gayka == 2))
			{
	        		mSend.type = 1L;			
				mSend.vint = 0; 
				mSend.gayka = 0;
				detalei = mSend.n = mRead.n + 1;
				      
			}
			else
			{
					mSend.type = 1L;
					mSend.vint = 1;
					mSend.gayka = mRead.gayka;
					detalei = mSend.n = mRead.n;
			}


		if(msgsnd(mesid, (void*)&mSend, sizeof(Mess), 0) < 0)
		{
			log_file << "vint:  Error : Can't write message\n";
			exit(1);	
		}

		log_file << "Vintovshik send m1\n";  
		print_msg_1(mSend);
	 


		
		  
	}

	else
	{
		log_file << "vint:  Не могу читать\n"; 
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

	        FILE *temp = fopen("/home/hz/q/logs/log1", "wb");
        	fclose(temp);

	       log_file.open ("/home/hz/q/logs/log1");
	}

	if (id == 2)
	{
///     !!!     ЗДЕСЬ надо дважды ВВЕСТИ ПУТЬ ДО ФАЙЛА С ИМЕНЕМ log2        !!!     ///

//	        ofstream log_file("/home/hz/q/logs/log2");


	        FILE *temp = fopen("/home/hz/q/logs/log2", "wb");
        	fclose(temp);

	        log_file.open ("/home/hz/q/logs/log2");
	}

        log_file<<"Конструктор Gaechnik "<< id << endl;

        if ((key = ftok("/tmp",'A'))<0)
        {
                log_file <<"gayka"<< id<<" : Can't get key\n";
                exit(1);
        }


//	key = 100;     

        if((mesid = msgget(key,PERM|IPC_CREAT|IPC_EXCL))<0)
        {

                if(errno == EEXIST)
                {
                        log_file << "gayka "<< id << ": Очередь уже создана" << endl;

                        if ((mesid = msgget(key,PERM))< 0)
                        {
                                log_file << "gayka"<< id <<": Can't create message's queue" << endl;
                                exit(1);
                        }			
                }
                else
                {
                        log_file << "gayka"<< id <<": Can't create message's queue" << endl;
                        exit(1);
                }
        }


        	mSend.type = mRead.type = 1L;


	        log_file << "gayka mesid "<< mesid << endl;



        	log_file << "constuctor:  gaechnik" << id <<" reads m1" << endl;
        	if (msgrcv(mesid,(void*)&mRead,sizeof(Mess), mRead.type, 0) < 0)
        	{
                	log_file << "gayka"<< id <<": Can't read message\n";
                	exit(1);
        	}
		log_file << "gayka"<< id <<": Readed m1" << endl;

		print_msg_1(mRead);





		wSend.type = wRead.type = 2L;

                log_file << "constuctor:  gaechnik" << id <<" reads m2" << endl;
                if (msgrcv(mesid,(void*)&wRead,sizeof(Workers), wRead.type, 0) < 0)
                {
                        log_file << "gayka"<< id <<": Can't read message\n";
                        exit(1);
                }
                log_file << "gayka"<< id <<": Readed m2" << endl;

                print_msg_2(wRead);


		

        	mSend.type = 1L;
		
		if (mRead.vint == 1 && mRead.gayka == 1)
		{
			mSend.vint = 0;
			mSend.gayka = 0;
			detalei = mSend.n = mRead.n + 1;
		}
		else
		{
			if (mRead.gayka < 2)
			{
				mSend.vint = mRead.vint;
        	    		mSend.gayka = mRead.gayka + 1;
				detalei = mSend.n = mRead.n;
			}
		}

		if(msgsnd(mesid, (void*)&mSend, sizeof(Mess), 0) < 0)
		{
			log_file << "gayka"<< id <<": Can't write message" << endl;
			exit(1);
		}
		log_file << "gayka " << id <<": Sended m1" << endl;
		
                print_msg_1(mSend);

		

		wSend.num = wRead.num + 1;		
		wSend.type = 2L;
		if (msgsnd(mesid, (void*)&wSend, sizeof(Workers), 0) < 0)
                {
                        log_file << "gayka"<< id <<": Can't write message" << endl;
                        exit(1);
                }
                log_file << "gayka " << id <<": Sended m2" << endl;

                print_msg_2(wSend);


//	fclose(log_file);
};










Gaechnik::~Gaechnik()
{
	wSend.type = wRead.type = 2L;

	log_file << "gaechnik: desctuctor" << endl;

        if (msgrcv(mesid,(void*)&wRead, sizeof(Workers), wRead.type,0) < 0)
        {
                log_file << "gaechnik: Can't read message" << endl;
                exit(1);
        }
        log_file << "gaechnik: mesage 2 readed" << endl;

        print_msg_2(wRead);



        if(wRead.num > 1)
        {
                wSend.num = wRead.num - 1;
                wSend.type = 2L;
                if (msgsnd(mesid,(void*)&wSend,sizeof(Workers),0) < 0)
                {
                        log_file<<"gaechnik: Can't write message\n";
                        exit(1);
                }
                log_file << "gaechnik: Sended m2" << endl;
                print_msg_2(wSend);
        }
        else
        {
                if(msgctl(mesid,IPC_RMID,0)<0)
                {
                        log_file << "gaechnik:  Can't delete queue\n";
                        exit(1);
                }

		
                log_file << "gaechnik:  Queue was deleted" << endl;
        	
		cout << "Sdelano detalei " << detalei << endl;
                log_file << "Sdelano detalei " << detalei << endl;

	}

        log_file << "gaechnik: desctuctor ended" << endl;


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

        log_file << "act: gaechnik "<< id << " reads m1" << endl;

       	if (msgrcv(mesid,(void*)&mRead, sizeof(Mess), mRead.type, 0) < 0)
	{
		log_file << "gayka "<< id  <<": Can't read message" << endl;
		exit(1);
	}

	log_file << "gayka" << id <<": Readed m1" << endl;

	print_msg_1(mRead);

                if (mRead.vint == 1 && mRead.gayka == 1)
                {
                        mSend.vint = 0;
                        mSend.gayka = 0;
                        detalei = mSend.n = mRead.n + 1;
                }
                else
                {
                        if (mRead.gayka < 2)
                        {
                                mSend.vint = mRead.vint;
                                mSend.gayka = mRead.gayka + 1;
                                detalei = mSend.n = mRead.n;
                        }
                }



                if (msgsnd(mesid, (void*)&mSend, sizeof(Mess), 0) < 0)
                {
                        log_file << "gayka"<< id <<": Can't write message" << endl;
                        exit(1);
                }
                log_file << "gayka " << id <<": Sended m1" << endl;

                print_msg_1(mSend);
	


	sleep(tm);

//	fclose(log_file);
};
