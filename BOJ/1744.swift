func sol(){
	let n=Int(readLine()!)!
	var a=[Int](),pos=0,neg=0,ans=0
	for _ in 1...n{
		let num=Int(readLine()!)!
		if num==1{
			ans+=1
		}else{
			if num>0{pos+=1}
			else{neg+=1}
			a.append(num)
		}
	}
	
	a.sort{$0<$1}
	var i=0
	if neg>0{
		while neg>1&&i<a.count{
			ans+=(a[i]*a[i+1])
			i+=2
			neg-=2
		}
		if neg==1{
			ans+=a[i]
			i+=1
		}
	}
	if pos%2==1{
		ans+=a[i]
		i+=1
	}
	while i<a.count{
		ans+=(a[i]*a[i+1])
		i+=2
	}
	print(ans)
}
//sol()
