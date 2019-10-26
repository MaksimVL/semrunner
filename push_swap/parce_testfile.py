import re

text = "Test result on 1..5 randoms: [36m       5xt "

string = r"    [\d]{1,3}[[]"
string = r"    ([\d]).t*"

match = re.search(string, text)
if match:
	print('Found "{}" in "{}"'.format(string, text))
	text_pos = match.span()
	print(text[match.start():match.end()])
	i = int(text[match.start():match.end()])
	print("i = ", i)
