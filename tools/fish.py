#!/usr/bin/python
# coding=utf-8
class fishTools(object):
	def __init__(self, arg):
		super(fishTools, self).__init__()
		self.arg = arg
		

def _check_python_version():
    major_ver = sys.version_info[0]
    if major_ver > 2:
        print ("The python version is %d.%d. But python 2.x is required. (Version 2.7 is well tested)\n"
               "Download it here: https://www.python.org/" % (major_ver, sys.version_info[1]))
        return False

    return True


 def _check_tools_environment():
 	return False

 def _log_(msg):
 	pass
