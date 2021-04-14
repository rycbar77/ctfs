#cmps={{83,80,73,80,76,125,61,96,107,85,62,63,121,122,101,33,123,82,101,114,54,100,101,97,85,111,39,97}}
#print(\"Give Me Your Flag LOL!:\")
#flag=io.read()
#if string.len(flag)~=28 then
#	print(\"Wrong flag!\")
#	os.exit()
#end
#for i=1,string.len(flag) do
#	local x=string.byte(flag,i)
#	if i%2==0 then
#		x=x~i
#	else
#		x=x+6
#	end
#	if x~=cmps[i] then
#		print(\"Wrong flag!\")
#		os.exit()
#	end
#end
#print(\"Right flag!\")
#os.exit()

cmps = [83, 80, 73, 80, 76, 125, 61, 96, 107, 85, 62, 63, 121, 122, 101, 33, 123, 82, 101, 114, 54, 100, 101, 97, 85,
        111, 39, 97]
flag=''
for i in range(28):
    x = cmps[i]
    if (i + 1) % 2 == 0:
        x ^= (i + 1)
    else:
        x -= 6
    flag+=chr(x)
print(flag)