# multithread_work

The work of three workers is modeled using messsage queue during 1 minute:

Three workers construct details with two female screws and a male screw. Each of them knows how to fix only one certain type of screws. The workshop is not big, so only a worker has access to the detail at each moment. 

To run this code :
1) place all this files in one directory (in Linux)
2)open realization.cpp and write your paths for logfiles for each worker (in my code - log0, log1 и log2) in the beginning of each constructor (there are 2 ones)
3) Run makefile (type make in terminal) to get executables ev1, eg1 and eg2 for each worker 
4) Run files ev1, eg1 and eg2 (that correspond to files v1.cpp, g1.cpp and g2.cpp) each in its own terminal with a command line int parameter (the duration of worker's action)
5) All the info about actions is logged to files mentioned above by each "worker" (<- a process)
6) In terminal processe also log the moment of ecexution of their actions
7) The last worker writes in its terminal and its logfile the number of constructed details  
