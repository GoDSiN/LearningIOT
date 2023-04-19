from Adafruit_IO import Client, Feed
from InstructionService import generateInstruction
import json
import time

ADAFRUIT_IO_KEY = 'aio_jMNa06KPZnnGQARFbonKT5lR6i0t'

ADAFRUIT_IO_USERNAME = 'aomms'

aio = Client(ADAFRUIT_IO_USERNAME, ADAFRUIT_IO_KEY)

def temp_feed():
    temp_feed = aio.feeds(feed="temp")
    temp = aio.receive(temp_feed.key)
    temp_val = temp.value
    temp_time = temp.updated_at
    temp_data = {'temp_val' : temp_val, 'temp_time': temp_time}
    return temp_data
    
def dht_feed():
    dht_feed = aio.feeds(feed="dht")
    dht = aio.receive(dht_feed.key)
    dht_val = dht.value
    dht_time = dht.updated_at
    return {'dht_val' : dht_val, 'dht_time': dht_time}

def send_instruction(temp, dht):
    instruction = generateInstruction(temp, dht)
    instr_feed = aio.feeds(feed="instruction")
    aio.send_data(instr_feed.key, instruction)
    return instruction

def fetch_data():
    while True:
        temp = temp_feed()   
        dht = dht_feed()
        instr = send_instruction(temp.get('temp_val'), dht.get("dht_val"))
        print(temp)
        print(dht)
        print(instr)
        time.sleep(30)

