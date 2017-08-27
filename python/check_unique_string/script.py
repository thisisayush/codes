data_file = open('data.txt', "r")
enrollNumbers = data_file.read().split(' ')
counter = 0
for x in enrollNumbers:
    innerCounter = 0
    for y in enrollNumbers:
        if x == y and counter!=innerCounter:
            print(str(x) + " at index "+ str(counter))
        innerCounter = innerCounter + 1 
    counter = counter + 1 