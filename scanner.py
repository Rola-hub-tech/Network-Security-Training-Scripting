# Scanner (Scan online hosts in the network and their open ports) ##
import os
import socket

def pingIPs(subnetMask):
    onlineHosts = []
    for i in range(1, 255):
        if (os.system("ping " + str(subnetMask) + "." + str(i) + " -n 1")) == 0:
            print("The host " + str(subnetMask) + "." + str(i) + " is online.")
            print("Open ports: ")
            ip = str(subnetMask) + "." + str(i)
            onlineHosts.append(ip)
            scanPorts(ip)
    return onlineHosts

def scanPorts(ip):
    for port in range(80, 101):
        socket_con = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        connection = socket_con.connect_ex((ip, port))
        if connection == 0:
            print(port)

subnetMask = input("Enter subnetmask: ")
pingIPs(subnetMask)