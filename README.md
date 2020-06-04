The process of rocket assembly is modeled using message queue.

Workers construct rocket using bolts and nuts. One worker installs bolts and two others install nuts. All they act one by one. Each worker can install one detail at his turn. 
Workers communicate using message queue. They assemble blocks consisting of 2 nuts and a bolt consistently and cannot begin new block while the last one was not finished.

### To run this code:

-- execute makefile (type make in terminal) to get executables - nut1, nut2 and bolt - representing 3 workers 

-- run executables nut1, nut2 and bolt each one in its own terminal with a command line parameter of type integer equal to the duration of one worker's action

-- All the info about assembly process is logged in 3 files during "1 minute" of work 

-- The last worker writes in its terminal and log-file the number of assembled blocks consisting of 2 nuts and a bolt
