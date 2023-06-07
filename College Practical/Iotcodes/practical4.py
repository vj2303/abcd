import os
import glob
import time
import matplotlib.pyplot as plt

os.system('modprobe w1-gpio')
os.system('modprobe w1-therm')

base_dir = '/sys/bus/w1/devices/'
device_folder = glob.glob(base_dir + '28*')[0]
device_file = device_folder + '/w1_slave'

temp_list = []

def read_temp_raw():
    f = open(device_file, 'r')
    lines = f.readlines()
    f.close()
    return lines

def read_temp():
    lines = read_temp_raw()
    while lines[0].strip()[-3:] != 'YES':
        time.sleep(0.2)
        lines = read_temp_raw()
    equals_pos = lines[1].find('t=')
    if equals_pos != -1:
        temp_string = lines[1][equals_pos+2:]
        temp_c = float(temp_string) / 1000.0
        temp_list.append(temp_c)
        return temp_c

def compare():
    min_t = min(temp_list)
    max_t = max(temp_list)
    print('Min temp =', min_t)
    print('Max temp =', max_t)

def graph():
    x = list(range(len(temp_list)))
    y = temp_list
    plt.plot(x, y)
    plt.xlabel('Time')
    plt.ylabel('Temperature (°C)')
    plt.title('Temperature Variation')
    plt.show()

try:
    while True:
        temperature = read_temp()
        if temperature is not None:
            print('Temperature:', temperature, '°C')
        time.sleep(1)

except KeyboardInterrupt:
    compare()
    graph()
