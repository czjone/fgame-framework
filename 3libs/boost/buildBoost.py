import sys
import os, os.path
import commands

boost='boost_1_63_0';

def exc_shell(str,disOut):
	if disOut == True :
		process = os.popen(str);
		output = process.read();
		process.close();
	else:
		# (status,output)=commands.getstatusoutput(str);
		# print status, output;
		# print status;
		process = os.popen(str);
		output = process.read();
		process.close();
	return;
def  safeRemoveDir(pdir,disOut):
	if os.path.exists(pdir):
		exc_shell("rm -rf "+pdir,disOut);
	pass

def extract(fname):
	print ">>> extract boost downlowd zip...";
	fname_with_fileext=fname+".tar.bz2";
	safeRemoveDir(fname,True);
	cmd="tar -zxvf "+fname_with_fileext;
	exc_shell(cmd,True);
	pass

def cleanTempFils(boostname):
	print ">>> clean temp files";
	cmd="rm -rf "+boostname
	safeRemoveDir(cmd,True)
	# exc_shell(cmd,True);
	pass

def buildBoost(boostname):
	#todo build boost by makefile.
	platform = sys.platform
	os.chdir(boostname);
	if platform == 'win32':
		print 'Your platform is not supported!'
	elif platform == 'darwin':
		exc_shell('./b2',True);
	elif 'linux' in platform:
		print 'Your platform is not supported!'
	else:
		print 'Your platform is not supported!'
		sys.exit(1);
	os.chdir('../');
	pass

def compileBoostToolsBjam(boostname):
	platform = sys.platform
	os.chdir(boostname);
	if platform == 'win32':
		exc_shell('sh bootstrap.bat',True);
	elif platform == 'darwin':
		exc_shell('sh bootstrap.sh',True);
	elif 'linux' in platform:
		exc_shell('sh bootstrap.sh',True);
	else:
		print 'Your platform is not supported!'
		sys.exit(1);
	os.chdir('../');
	pass

def publishLib():
	#publish file to
	pass

def build(boostname):
	print "build ..."
	extract(boostname);
	compileBoostToolsBjam(boostname);
	buildBoost(boostname);
	cleanTempFils(boostname);
	pass

build(boost);