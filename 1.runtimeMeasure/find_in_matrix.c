//pseudo code
/*
Alg findRow(A, x)
input matrix A of n
	  element x
output index i such that A[i]=x
		or -1 if there is no A[i] which is same with x

i<-0
while(i<n)
	if(R[i]=x)
		return i
	else
		i <- i+1
return -1

------------------------------------
Alg findMatrix(A, n)
input matrix A of nxn
	  element x
output location of x in A
		or failure message if there is no element x in A

r<-0
while(r<n)
	i <- findRow(A[i], x)
	if(i >= 0)
		write(r, ',', i)
		return
	else
		r<-r+1
write("not found")
return
*/
