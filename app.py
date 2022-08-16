import streamlit as st
import subprocess as sp
import os
import time

command="expect app.exp {} {} {} {}"

st.set_page_config(page_title="Airties", layout="wide")

bandwidth=st.sidebar.selectbox(
	'Bandwidth(MHz)',
	(20,40,80,160))

if (bandwidth ==20):
	channel = st.sidebar.selectbox(
     		'Select the channel',
     		(36,40,44,48,52,56,60,64,100,104,108,112,116,
     		120,124,128,132,136,140,144,149,153,157,161,165))
elif (bandwidth ==40):
	channel = st.sidebar.selectbox(
     		'Select the channel',
     		('36l','40u','44l','48u','52l','56u',
     		'60l','64u','100l','104u','108l',
     		'112u','116l','120u','124l','128u',
     		'132l','136u','140l','144u','149l'
     		,'153u','157l','161u'))
elif (bandwidth ==80):
	channel = st.sidebar.selectbox(
     		'Select the channel',
     		(36,40,44,48,52,56,60,64,100,104,108,112,116,
     		120,124,128,132,136,140,144,149,153,157,161))
else:
	channel = st.sidebar.selectbox(
     		'Select the channel',
     		(36,40,44,48,52,56,60,64,100,104,108,112,116,
     		120,124,128,))
     		
mod_rate = st.sidebar.slider(
	'Modulation Rate',
	0,11)

qdbm = st.sidebar.slider(
	'QDBM',
	0.0,25.0 , step=0.25)

if st.sidebar.button('Run', help='Runs the test commands and displays the terminal output.'):
		sp.call(command.format(bandwidth, channel, mod_rate, qdbm),  shell=True)
	
st.title("Output")

if (os.path.isfile("logoutput.txt") == True):
	f = open("logoutput.txt", 'r', encoding = 'utf-8')
	t_output= f.read()
	st.text_area(label="Terminal Telnet Log:", value=t_output, height=350)
	os.remove("logoutput.txt")
else:
	t_output= 'Waiting...'
	st.text_area(label="Terminal Telnet Log:", value=t_output, height=350)

	
	 

