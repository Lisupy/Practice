

import socket
import time
host  = "10.251.251.49"
buf = """GET / HTTP/1.1
Host: %s
Expect: 100-Continue

"""%(host)

if __name__ == "__main__":
   # raw_input([prompt])
    print buf
    s = socket.socket()
    s.connect((host,80))
    s.sendall(buf)
    #s.sendall(buf)
    print s.recv(1000)
	#s.sendall("1"*12);
    print s.recv(1000)