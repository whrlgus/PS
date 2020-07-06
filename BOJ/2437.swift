func sol(){
	let n=Int(readLine()!)!
	var a=readLine()!.split(separator: " ").map{Int($0)!}
	a.sort{$0<$1}
	var range=0
	for i in 0..<n{
		if range+1<a[i]{break}
		range+=a[i]
	}
	print(range+1)
}
//sol()

