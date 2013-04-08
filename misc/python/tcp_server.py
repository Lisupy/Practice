# coding=utf-8
import socket
import time
http_head = """HTTP/1.1 200 OK
Set-Cookie: aaa=b; expires=Sun, 22-Dec-2013 05:51:38 GMT; path=/

"""

http_data = ["1"*20,"http://www.sangfor.com","http","://www.sangfor:htt","p:///","1"*200]

HOST = ''                 # Symbolic name meaning all available interfaces
PORT = 8080              # Arbitrary non-privileged port
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind((HOST, PORT))
s.listen(1)
conn, addr = s.accept()


print 'Connected by', addr
while 1:
    print "Accept"
    data = conn.recv(1024)
    conn.send(http_head)
    time.sleep(2)
    conn.close()
    break
    
conn.close()
