
#include <unistd.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <time.h>
#include <errno.h>
#include <string.h>

#include <iostream>
#include <cstdlib>
#include <fstream>

#include <time.h>


#define PERM 0666
using namespace std;

// Структура для записи и чтения в/из очереди сообщений
struct Mess{   //type 1L
	long type;
	//int pid;
	int vint; 
	int gayka;
	int n;
};

struct Workers{   //type 2L
        long type;
	int num;
};

// Процесс, он же дейcтвующее лицо для других задач
class Vintovshik{
	Mess mRead, mSend; // сообщения для посылки и чтения
	Workers wRead, wSend;
	key_t key;         // ключ для создания очереди сообщений
	int mesid;        // идентификатор очерреди сообщений
	int id;
	struct msqid_ds *buf;
	ofstream log_file;
	int detalei;
public:
	Vintovshik(); 
	~Vintovshik();
	void act(int);
	void print_msg_1(Mess msg);
	void print_msg_2(Workers);

};


class Gaechnik
{
	int id;
	Mess mSend, mRead;
        Workers wRead, wSend;
	key_t key;
	int mesid;
	struct msqid_ds *buf;
        ofstream log_file;
        int detalei;
public:
	void print_msg_2(Workers);
	void print_msg_1(Mess msg);
	Gaechnik(int n);
	~Gaechnik();
	void act(int tm);
};

