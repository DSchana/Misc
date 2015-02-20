# classes.py

class Bird:
    def __init__(self, kind, call, maj):  # initialize class with bird type and bird call sound
        self.call = call  # create variable in this instance of bird to hold the call and kind variable info
        self.kind = kind
        self.maj = maj
    def doCall(self):  # self is used to do this method to the current instance of bird
        print("a %s goes %s" %(self.kind, self.call))
    def majesticness(self):
        print("a %s's majesticness is %s" %(self.kind, self.maj))

class Parrot(Bird):
    def __init__(self):
        Bird.__init__(self, "Parrot", "Polly want a cracker", "very")  # call the Bird class's constructor with parrot attributes

class Cuckoo(Bird):
    def __init__(self):
        Bird.__init__(self, "Cuckoo", "Cuckoo", "none")

parrot = Parrot()  # create instances of the birds
cuckoo = Cuckoo()
Peacook = Bird("Peacook", "Majestic", "OVER 9000!!!!!!")

parrot.doCall()  # do the meathod of Bird
cuckoo.doCall()
Peacook.doCall()

print("")

parrot.majesticness()  # do the meathod of Bird
cuckoo.majesticness()
Peacook.majesticness()