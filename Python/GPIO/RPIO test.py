import rpio

# setup input or putput
RPIO.setup(4, RPIO.OUT)

# output to pin
RPIO.output(4, True)

# setup channel with initial state
RPIO.setup(4, RPIO.OUT, initial=RPIO.LOW)

RPIO.cleanup()
