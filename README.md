 Write a client and a server program in C/C++ using TCP/IP. The server program generates randomly a rather huge number (close to INT_MAX, see for details limits.h), and the client(s) should decide if the number is prime or not. The checking mechanism should be as follows:  
 	1) The server is sending at a time the number x and a number y ={2…sqrt(x) } to each client
 	 2) The client should check if x is divisible by y –if so the number x is not prime (send to server)
 	  3) Otherwise the server should continue to send new pairs to each client until y  == sqrt(x) or x is divisible by y.  Each client should receive equal number of divisions to perform.  
 	  
 	 
Overview 

 Communication between two software programs can be done using sockets among others. A socket is identified by an IP address concatenated with a port number. The server waits for incoming clients requests by listening to a specified port. Once the request is received, the server accepts a connection from the client socket to complete the connection. Servers which implement specific services such as ftp, telnet, http listen on some dedicated ports (telnet (23), ftp (21), http (80), therefore use port numbers bigger than 1024 for that purpose. Ex. Use 5432 – probably nobody is using that. 
 
 
 Instructions 
 
  Both the client and the server program should be written in C/C++. The client program should connect via a socket to the running server program. If the server is not available (not running) the client should timeout and exit. The connection IP address (server), the port number, and the timeout should be read from a regular text file at each client [re]start. For each client the server should listen in a separate thread.
  
  
  Notes 
  
   The ini file (containing the ip, port, and timeout) should be given as command line parameter. If no file is given, use some default values.  