set -e
echo "This script is required to make a rule in your system so it can run shutdown, reboot withouth any problem, You can safely delete the rule by running pimine with the --clean argument."
USER_NAME=$(whoami)
echo "$USER_NAME ALL=(ALL) NOPASSWD: /sbin/shutdown, /sbin/reboot" | \
sudo tee /etc/sudoers.d/pimine
sudo chmod 440 /etc/sudoers.d/pimine
cd "$(dirname "$0")"
echo "Configuring dependencies for the website.."
python3 -m venv venv
source venv/bin/activate
pip install flask flask-httpauth psutil
echo "Running the website now.."
python3 helpers/runwebsite.py

