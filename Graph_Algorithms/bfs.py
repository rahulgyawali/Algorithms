g = []
vis = []
queue = []

def enqueue (x) :
	if len(queue) > n-1 :
		return 666
	else :
		queue.append(x)
		
		
def dequeue() :
	if len(queue) == 0:
	
		return 666
	else :
		x = queue[0]
		del queue[0]

		return x

def empty() :
	if len(queue) == 0:
		return 1
	else :
		return 0

print('Enter no. of nodes')		#No. of nodes in graph

n = input()
n = (int(n))

print('Enter no. of edges')
e = input()
e = (int(e))

for i in range (n) :
	g.append([])
	for j in range (n) :
		g[i].append(0)

print('Enter the Connection between edges')   #Enter the Edges in graph

for i in range (e) :
	
		x = input()
		x = ( int(x))
		y = input()
		y = (int(y))
		g[x][y] = 1
		g[y][x] = 1

for i in range (n) :
	vis.append(-1)

print('Enter source node')		#Enter Source node

s = input()
s = (int(s))

vis[s] = 0

enqueue(s)							#Push Source in queue

def bfs (g,queue,vis,s) :

		while(not(empty())) :
			l = dequeue()
			vis[l] = 1
			print(l)
			for i in range (n) :
				if (g[l][i] == 1):
					if(vis[i] == -1) :
						enqueue(i)
						vis[i] = 0
			

bfs(g,queue,vis,s)


			




