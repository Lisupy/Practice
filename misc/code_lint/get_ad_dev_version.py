#!/usr/bin/env python

import sys,urllib,httplib,urlparse
import thread  
import time
import threading


all_ips = []

for i in range(1,254):
    ip = "10.252.252." + str(i)
    all_ips.append(ip)
    ip = "100.100.100." + str(i)
    all_ips.append(ip)
    ip = "200.200.144." + str(i)
    all_ips.append(ip)   
    ip = "200.200.145." + str(i)
    all_ips.append(ip)
    ip = "200.200.146." + str(i)
    all_ips.append(ip)
    ip = "200.200.147." + str(i)
    all_ips.append(ip)
    ip = "200.200.148." + str(i)
    all_ips.append(ip)
    

ad_devs = {}

def try_ad_ip(ip):
   # print 'Thread:(%d)\n'%(no)  
    try:
        conn=httplib.HTTPSConnection(ip,443,timeout=0.1)
        conn.request("GET", "/cgi-bin/login.cgi?action=log&fro=self")
        r1 = conn.getresponse()
        if r1.status == 200:
            data = r1.read()
            for l1 in data.split("\n"):
                if l1[:len("<title>")] == "<title>":
                    return l1[len("<title>"):-len(" </title>")]
            return
        
    except:
        return
        #print ip, ": device_not found"
        pass
    
def try_bigip(ip):
    try:
        conn=httplib.HTTPSConnection(ip,443,timeout=3)
        conn.request("GET", "/tmui/login.jsp")
        r1 = conn.getresponse()
        if r1.status == 200:            
            data = r1.read()
            for l1 in data.split("\n"):
                l1 = l1.strip()
                if l1[:len("<title>")] == "<title>":
                    return l1[len("<title>"):-len(" </title>")]
            return       
    except:
        return
        #print ip, ": device_not found"
        pass
    
    

mylock = thread.allocate_lock()

def thread_try_ip(ip):
    global ad_devs;
    ad = try_ad_ip(ip)
  
   # mylock.acquire()
  #  print ip, t
   # mylock.release()
    if ad != None:
        mylock.acquire()
        ad_devs[ip] = ad
        mylock.release()
    
    thread.exit_thread()



threads = []
for ip in all_ips:
    threads.append(threading.Thread(target=thread_try_ip, args=(ip,)))
    

for t in threads:
   t.start()

for t in threads:
   t.join()  

#print ad_devs
cnt = 0
ad_dev = sorted(ad_devs)
print "[",
flag = " "


for ip in ad_dev:
    #if ip in ad_devs:
    print flag,"{",
    flag = ","
    info =  ad_devs[ip].split("|")
    print '"ip":"%s", "usr":"%s", "ver":"%s"'%(ip, info[0].strip(), info[1].strip()),
    print "}",
print "]"
