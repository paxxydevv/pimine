from flask import Flask, redirect, url_for
import subprocess 
app = Flask(__name__)
def run_cmd(command):
    subprocess.run(command, shell=True, check=True)

@app.route("/")
def home():
    return """
    <h1>Pimine basic control panel</h1>
    <a href='/shutdown'>Shutdown</a><br>
    <a href='/reboot'>Reboot</a>
    """

@app.route("/shutdown")
def shutdown():
    run_cmd("sudo shutdown now")
    return "Shutting down.."
@app.route("/reboot")
def reboot():
    run_cmd("sudo reboot now")
    return "Rebooting this may take a while.."
app.run(host="0.0.0.0, port 5000)
