func sol(){
	let a=Array(readLine()!)+")"
	var i=0
	func getLen()->Int{
		var len=0
		while a[i] != ")"{
			if a[i] == "("{
				i+=1
				len+=Int(String(a[i-2]))!*getLen()-1
			}else{len+=1}
			i+=1
		}
		return len
	}
	print(getLen())
}
//sol()
