#
# random-Vyper-bin.py
# Set a unique firmware name based on current date and time for Anycubic Vyper
#
Import("env")

from datetime import datetime

env['PROGNAME'] = datetime.now().strftime("main_board_%Y%m%d-%H%M%S")
