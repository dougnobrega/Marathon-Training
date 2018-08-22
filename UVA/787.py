def process(p):
	best = int(p[0])
	i = 0
	while i < len(p) - 1:
		j = i + 1
		sum = int(p[i])
		best = max(best,sum)
		while j < len(p) - 1:
			sum = sum * int(p[j])
			best = max(int(best),sum)
			j = j + 1
		i = i + 1
	return best
while True:
	try:
		p = input().split()
		ans = process(p)
		print (ans)
		p.clear()
	except EOFError:
		break
