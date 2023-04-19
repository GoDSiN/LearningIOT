
def generateInstruction(temp, dht):
    temp = float(temp)
    dht = float(dht)
    print(dht)
    if dht >= 30 and dht <= 60:
        return 0
    elif dht < 30:
        return 1
    elif dht >60:
        return -1
    else:
        return "NaN"

    