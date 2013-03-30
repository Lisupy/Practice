#! /usr/bin/python
#coding=utf-8
import sys
import pprint
import pysvn
import os
import codecs, sys
import locale

client = pysvn.Client()
svn_url = "" 
start_rev = 2000
end_rev = 3020
def cmp_func(svn_path, packet_path):
    if os.path.basename(svn_path["path"]) == os.path.basename(packet_path) :
        return True
    if "cgi-bin" in packet_path and "/ui/web_ui/src/" in svn_path["path"]:
        b1 = os.path.basename(packet_path)
        if ".cgi" in b1:
            b1 = b1[:-4]
        if b1 in  svn_path["path"]:
            return True
    if "/usr/ad/bin/" in packet_path and "/apps/" in svn_path["path"]:
        b1 = os.path.basename(packet_path)
        b2 = b1[3:-1]  # ad_statd ==>stat
        if b1 in svn_path["path"] or b2 in svn_path["path"]:
             return True
        
    return False
def find_html_log(html_path, log_dict):
    html_path = html_path.rstrip()
   # print "["+os.path.basename(html_path)+"]"
    l = [];
    for log in log_dict:
       # print "r"+str(log)+":"
        for svn_path in log_dict[log]["changed_paths"]:
           # print "[" + os.path.basename(path["path"]) +"]"
            if cmp_func(svn_path, html_path):
                l.append("r"+str(log)+log_dict[log]["message"]+"<" + log_dict[log]["author"]+">" + svn_path["path"])
    return l

def auto_diff(svn_url, start_rev, end_rev, csv):
    if end_rev == -1:
        end_rev=pysvn.Revision( pysvn.opt_revision_kind.head )
    else:
        end_rev=pysvn.Revision( pysvn.opt_revision_kind.number, end_rev)
    log_dict = dict((log.revision.number, log) for log in pysvn.Client().log(svn_url,
        revision_start=pysvn.Revision( pysvn.opt_revision_kind.number, start_rev ),
        revision_end=end_rev,
        discover_changed_paths=True,
        strict_node_history=True,
        limit=0))
    for line in csv:
        print line,
        l = find_html_log(line, log_dict)
        for log in list(set(l)):
            log = log.replace("\n", " ")
            print "," + log.rstrip()
        print "" 
if __name__ == '__main__':
    if (len(sys.argv) != 4):
        print sys.argv[0] + "    4.x " + "  customize_ver   " + "  xxx.rpt"
        exit(0)
    svn_url = "svn://200.200.0.4/ad/ad"+sys.argv[1]+"/Customize/"+sys.argv[2]
    svn_url = unicode(svn_url, 'utf-8')
    auto_diff(svn_url, 0, -1, open(sys.argv[3]))



