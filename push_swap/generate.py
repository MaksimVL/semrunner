count_elements = 5

import random

lst = []
for i in range(1, count_elements + 1):
	lst.append(i)
random.shuffle(lst)
with open('stack1', 'w') as fd:
	for i in lst:
		fd.write(str(i))
		fd.write("\n")
