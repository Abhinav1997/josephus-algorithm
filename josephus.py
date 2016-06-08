def onezero(binary) :

	new_binary = ""

	for bin in binary:
		if bin == "0" :
			new_binary += "1"
		else :
			new_binary += "0"
	
	return new_binary

bin = "{0:b}"

initial = input('Enter the initial number of people : ')

init = bin.format(int(initial))
sub = onezero(init)
final = int(init, 2) - int(sub, 2)

print("The final person alive would be number " + str(final))
