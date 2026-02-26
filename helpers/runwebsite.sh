set -e
cd "$(dirname "$0")"
echo "Installing needed dependencies for the website.."
python3 -m venv venv
source venv/bin/activate
pip install flask flask-httpauth psutil
echo "Running the website now.."
python3 helpers/runwebsite.py

