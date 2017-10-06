def stringSimilarity(inputs):
	counts = []
    
        for inp in inputs:
            count = 0 
            subs = []

            for i in range(len(inp)):
                    subs.append(inp[i:])

            for s in subs:
                    for i in range(len(s)):
                            curr = s[i:]
		            print(curr)
                            if inp.find(curr) == 0:
                                    print(len(curr))
                                    count += len(curr)
                                    break

            print(count)
            counts.append(count)
			

stringSimilarity("ababaa")
