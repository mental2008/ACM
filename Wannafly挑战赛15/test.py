import random

filename = 'in.txt'

with open(filename, 'w') as f:
    f.write(str(11) + ' ' + str(11) + '\n')
    for i in range(1, 12):
        f.write(str(i) + '\n')
