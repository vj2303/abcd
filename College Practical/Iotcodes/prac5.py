import time
import os

base_dir = "/sys/bus/w1/devices/28-000008bdd91e/w1_slave"

def read_temp_raw():
    f = open(base_dir, "r")
    lines = f.readlines()
    f.close()
    return lines

temp = []

def read_temp():
    lines = read_temp_raw()
    
    while lines[0].strip()[-3:] == "YES":
        time.sleep(1)
        lines = read_temp_raw()
        equal_pos = lines[1].find("t=")
        
        if equal_pos != -1:
            temp_string = lines[1][equal_pos+2:]
            temp_c = float(temp_string) / 1000
            temp_f = temp_c * (9.0/5.0) + 32.0
            temp.append(temp_f)
            return temp_f

try:
    while True:
        temperature = read_temp()
        print("Current Temperature: {:.2f}°F".format(temperature))

except KeyboardInterrupt:
    max_temp = temp[0]
    min_temp = temp[0]
    print('Readings: ', temp)
    for i in temp:
        if i > max_temp:
            max_temp = i
        if i < min_temp:
            min_temp = i
    print('Min Temperature: {:.2f}°F'.format(min_temp))
    print('Max Temperature: {:.2f}°F'.format(max_temp))