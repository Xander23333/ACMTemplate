child_rabbits = 1
adult_rabbits = 0
cnt = 0
for i in range(1,13):
    adult_rabbits, child_rabbits = adult_rabbits+child_rabbits, adult_rabbits
print(adult_rabbits + child_rabbits)