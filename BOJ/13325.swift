import Foundation
let bufSize = 1024, buf=UnsafeMutablePointer<UInt8>.allocate(capacity: bufSize+1);
var idx=bufSize

func readInt()->Int{
	var ret:Int64=0
	var sign:Int64=1
	while true{
		if idx==bufSize{
			let len = fread(buf, 1, bufSize, stdin)
			buf[len] = 10;
			idx=0
		}
		if buf[idx] == 32 || buf[idx] == 10{break}
		if buf[idx] == 45{sign = -1}
		else{ret=ret*10+Int64(buf[idx])-48}
		idx+=1
	}
	idx+=1
	return Int(ret*sign);
}

func sol(){
	let k=readInt()
	var p=[0]
	for _ in 1...(1<<(k+1))-1{
		p.append(readInt())
	}
	
	var ans=p.reduce(0,{$0+$1})
	func foo(_ i:Int)->Int{
		if i>=(1<<k)-1{return 0}
		let ni=i*2+1,x=foo(ni)+p[ni],y=foo(ni+1)+p[ni+1]
		ans+=abs(x-y)
		return max(x,y)
	}
	foo(0)
	print(ans)
}
//sol()
