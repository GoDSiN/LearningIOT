from flask import Flask, Blueprint
from service import adafruitService as adaService
from service import InstructionService

app = Blueprint('controller', __name__)

@app.route("/get-data", methods = ['GET'])
def get_data():
    
    temp_recieved = adaService.temp_feed()
    dht_recieved = adaService.dht_feed()
    
    print(temp_recieved)
    print(dht_recieved)
    
    instruction = adaService.send_instruction(temp_recieved.get('temp_val'), dht_recieved.get("dht_val"))
    print(instruction)
    
    return {'temp' : temp_recieved, 'dht': dht_recieved, 'instruction': instruction}
    