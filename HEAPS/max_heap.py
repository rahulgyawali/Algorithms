
def parent (i) :
	return i/2
def left(i) :
	return 2*i
def right(i) :
	return 2*i +1

def max_heapify (A,x) :

	if(left(x) < len(A) and A[left(x)] > A[x] ) :
		largest = left(x)
	else :
		largest = x
	if(right(x) < len(A) and A[right(x)] > A[largest]) :
		largest = right(x)
	if(largest != x) :
		A[largest] , A[x] = A[x] , A[largest]
		max_heapify(A,largest)

def build_heap (A) :
	
	for i in range(len(A)/2,0,-1) :
		max_heapify(A,i)
		

def heap_sort (A) :
	B = []

	for i in range(len(A),1,-1) :
		temp = A[1]
		A[1] = A[len(A) -1]
		del A[len(A)-1]
		B.append(temp)
		max_heapify(A,1)
		
	return B

def heap_max(A) :
	return A[1]

def extract_max(A) :
	if(len(A) < 2) :
		print("Error")
	temp = A[1]
	A[1] = A[len(A)-1]
	del A[len(A)-1]
	max_heapify(A,1)
	return temp

def increase_key(A,x,key) :
	if(A[x] > key) :
		print("Error")
	A[x] = key
	
	while x > 1 and A[parent(x)] < A[x] :
		A[parent(x)] , A[x] = A[x] , A[parent(x)]
		x = parent(x)

def insert_key(A,x) :
	A.append(-99999)
	increase_key(A,len(A)-1,x)

A = [-1,1,3,6,2,7,8,16,9]
build_heap(A)
for i in A :
	print(i)
print("___________________")
X = heap_sort(A)
for i in range(len(X)-1,-1,-1):
	print(X[i])
A = [-1,1,3,6,2,7,8,16,9]
build_heap(A)
print("___________________")
print(str(heap_max(A)))
print("___________________")
insert_key(A,10)
for i in A :
	print(i)