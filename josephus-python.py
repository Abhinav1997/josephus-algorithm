import sys

def eliminate(nPeople, kill, nSurvivor = 1) :
	left = 0
	while len(nPeople) > nSurvivor :
		num = kill - left

		if(num > len(nPeople)) :
			while num > len(nPeople) :
				num = num - len(nPeople)

		while num <= len(nPeople) :
			nPeople[num - 1] = 0
			num = num + kill
		
		try :
			left = len(nPeople[(((len(nPeople) - 1) - nPeople[::-1].index(0)) + 1):])
		except ValueError :
			pass

		nPeople = list(filter((0).__ne__, nPeople))
	return nPeople

people = input('Enter the initial number of people : ')
killfreq = input('Enter the person number to be killed : ')
survivor = input('Enter number of survivors : ')

if int(survivor) == 0 :
	print("\n\nEveryone is dead!")
	sys.exit()
elif int(survivor) < 0 :
	survivor = 1

peopleList = [int(i+1) for i in range (int(people))]

survivorList = eliminate(peopleList, int(killfreq), int(survivor))

if len(survivorList) == 1 :
	print("\n\nThe survivor is number " + str(survivorList[0]))
else :
	print("\n\nThe survivor numbers are : ")
	for i in survivorList :
		print(i, end = " ")
