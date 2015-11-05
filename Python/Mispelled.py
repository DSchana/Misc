N = int(input())
nums = []
words = []

for i in range(N):
	userIn = input()
	nums.append(int(userIn[:userIn.index(" ")]))
	words.append(userIn[userIn.index(" "):])

for i in range(N):
	del(words[i][nums[i]]) #IforgethowtodothisbutYOLO
	print(i+1, words[i])
