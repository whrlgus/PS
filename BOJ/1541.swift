let a=Array(readLine()!)
var i=0,ret=0,num=0,k=1
while i<a.count{
	if "+-".contains(a[i]){
		ret+=k*num
		if a[i]=="-"{k=(-1)}
		num=0
	}else{num=num*10+Int(String(a[i]))!}
	i+=1
}
print(ret+k*num)
