from flask import Flask
from controller.controller import app as controller_app
from service.adafruitService import fetch_data
import threading

app = Flask(__name__)
app.register_blueprint(controller_app)

if __name__ == '__main__':
    auto_fetch_thread = threading.Thread(target=fetch_data)
    auto_fetch_thread.start()
    app.run()