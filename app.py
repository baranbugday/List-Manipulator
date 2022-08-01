import streamlit as st
import subprocess as sp
import os

st.set_page_config(page_title="Airties", layout="wide")
st.title("Input")
text_input = st.text_input("Enter your commad","")
st.title("Output")
if (text_input != ""): 
	output_stream = os.popen(f"{text_input}")
	output= output_stream.read()
	st.text_area(label="Output Data:", value=output, height=350)
	
	 

