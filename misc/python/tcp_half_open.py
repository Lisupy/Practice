

import socket
import time




if __name__ == "__main__":
	s = socket.socket()
	s.connect(("200.200.80.157", 80))
	rv = fcntl.fcntl(f, fcntl.F_GETFL, 0)
	fcntl.fcntl(s, fcntl.F_SETFL, 
	
	
	#s.bind(("10.252.252.144",80))
	#s.close()
	#s.shutdown(socket.SHUT_RDWR)
	while(1):
		pass