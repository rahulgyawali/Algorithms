stack = []

def empty() :
	if len(stack) == 0:
		return 1
	else :
		return 0

def push (x) :
	if len(stack) > n-1 :
		#print("overflow") 
		return 666
	else :
		stack.append(x)
		#print(stack)	
	
def pop() :
	if len(stack) == 0:
		#print("underflow")
		return 666
	else :
		x = stack.pop()
		#print("after pop")
		#print(stack)
		return x


g = []
vis = []

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

push(s)							#Push Source in queue

def dfs (g,stack,vis,s) :

		while(not(empty())) :
			x = pop()
			
			if (vis[x] == -1):
				print(x)
				vis[x] = 1

			for i in range (n) :
				if (g[x][i] == 1):
					if(vis[i] == -1) :
						push(i)
			

dfs(g,stack,vis,s)


			




